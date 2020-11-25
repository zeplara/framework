namespace Zeplara\Container;

use Closure;
use ReflectionClass;
use ReflectionMethod;
use ReflectionFunction;
use ReflectionException;
use Zeplara\Contracts\Container\Container as ContainerContract;

class Container implements ContainerContract
{
    /**
     * @var array
     */
    protected bindings = [];
    /**
     * @var array
     */
    private aliasBindings = [];
    /**
     * @var array
     */
    private bindingAliases = []; 
    /**
     * @var array
     */
    private bindingsResolved = [];

    /**
     * @param key
     * @return mixed
     */
    public function get(key)
    {
        let key = this->resolveKey(key);

        if this->has(key) === false {
            throw new ContainerException("Binding [%s] does not exists."->format(key));
        }

        if isset this->bindingsResolved[key] {
            return this->bindingsResolved[key];
        }

        return this->resolveBinding(key, this->bindings[key]);
    }

    /**
     * @param key
     * @return bool 
     */
    public function has(key)
    {
        return isset this->bindings[this->resolveKey(key)];
    }

    /**
     * @param key
     * @param value
     * @param bool resolve
     * @return void
     */
    public function set(key, value, bool! resolve = false)
    {
        if resolve === false {
            if typeof value == "string" && this->has(value) {
                let value = isset this->aliasBindings[value] ? this->aliasBindings[value] : value;
                
                if this->has(key) && (isset this->aliasBindings[key] === false || this->aliasBindings[key] !== value) {
                    throw new ContainerException("Cannot make alias [%s] when that alias already exists as root binding or as alias."->format(key));
                }

                this->put(key);

                let this->aliasBindings[key] = value,
                    this->bindingAliases[value][] = key;
            } else {
                this->put(key);

                let this->bindings[key] = value;
            }
        } else {
            this->put(key);
            
            if is_callable(value) {
                let value = call_user_func(value);
            }

            let this->bindings[key] = value;
            let this->bindingsResolved[key] = value;
        }   
    }

    /**
     * @param key
     * @return void
     */
    public function put(key)
    {
        if isset this->aliasBindings[key] {
            unset this->bindingAliases[this->aliasBindings[key]][array_search(key, this->bindingAliases[this->aliasBindings[key]])];
            unset this->aliasBindings[key];
        } else {
            unset this->bindings[key];
            unset this->bindingsResolved[key];

            if isset this->bindingAliases[key] {
                var alias;
                for alias in this->bindingAliases[key] {
                    unset this->aliasBindings[alias];
                }

                unset this->bindingAliases[key];
            }
        }
    }
 
    /**
     * @param $abstract
     * @param array arguments
     * @return mixed
     */
    public function make($abstract, array! arguments = [])
    {
        var reflection, constructor;
        if typeof $abstract == "string" {
            let $abstract = this->resolveKey($abstract);

            if this->has(this->resolveKey($abstract)) {
                return this->get($abstract);
            }

            if strpos($abstract, ".") !== false {
                return this->make(explode(".", $abstract, 2), arguments);
            }

            try {
                let reflection = new ReflectionClass($abstract);
            } catch ReflectionException {
                try {
                    let reflection = new ReflectionFunction($abstract);
                } catch ReflectionException {
                    throw new InvalidAbstractException($abstract);
                }
            }
        } elseif is_callable($abstract) {
            if typeof $abstract == "object" && ($abstract instanceof Closure) === false {
                return this->make([$abstract, "__invoke"], arguments);
            }

            if typeof $abstract != "array" {
                let reflection = new ReflectionFunction($abstract);
            } else {
                let reflection = new ReflectionMethod($abstract[0], $abstract[1]);
                if reflection->isStatic() === false && typeof $abstract[0] == "string" {
                    let $abstract[0] = this->make($abstract[0]);
                }
            }
        } else {
            throw new InvalidAbstractException($abstract);
        }

        if (reflection instanceof ReflectionClass) === false {
            return call_user_func_array($abstract, this->parseArguments(reflection, arguments));
        }

        let constructor = reflection->getConstructor();

        if typeof constructor == "NULL" {
            return new {$abstract};
        }

        return reflection->newInstanceArgs(this->parseArguments(constructor, arguments));
    }

    /**
     * @param string key
     * @return mixed
     */
    public function offsetGet(key)
    {
        return this->get(key);
    }

    /**
     * @param string key
     * @return bool
     */
    public function offsetExists(key)
    {
        return this->has(key);
    }

    /**
     * @param string key
     * @param value
     * @return void
     */
    public function offsetSet(key, value)
    {
        this->set(key, value);
    }

    /**
     * @param string key
     * @return void
     */
    public function offsetUnset(key)
    {
        this->put(key);
    }

    /**
     * @param string key
     * @return mixed
     */
    public function __get(key)
    {
        return this->get(key);
    }
    
    /**
     * @param string key
     * @return bool
     */
    public function __isset(key)
    {
        return this->has(key);
    }
 
    /**
     * @param string key
     * @param value
     * @return void
     */
    public function __set(key, value)
    {
        this->set(key, value);
    }
 
    /**
     * @param string key
     * @return void
     */
    public function __unset(key)
    {
        this->put(key);
    }

    /**
     * @param reflector
     * @param array arguments
     */
    protected function parseArguments(reflector, array! arguments = [])
    {
        var e, i, params, index,
            parameters, parameter, refClass;

        let index = 0, 
            params = reflector->getParameters(),
            parameters = [];

        for i, parameter in params {
            let refClass = parameter->getClass();
            
            if isset arguments[parameter->name] {
                let parameters[i] = arguments[parameter->name];
            } elseif typeof refClass != "NULL" {
                if isset arguments[index] && typeof arguments[index] == "object" && arguments[index] instanceof refClass->name {
                    let parameters[i] = arguments[index],
                        index++;
                } else {
                    try {
                         let parameters[i] = this->make(refClass->name);
                    } catch BindingResolutionException, e {
                        if parameter->isDefaultValueAvailable() === false {
                            throw e;
                        }
 
                        let parameters[i] = null;
                    }

                }
            } elseif array_key_exists(index, arguments) {
                if isset params[i + 1] && (parameter->isDefaultValueAvailable() && parameter->isOptional() === false) {
                    let parameters[i] = parameter->getDefaultValue();
                } else {
                    let parameters[i] = arguments[index],
                        index++;
                }
            } elseif array_key_exists(i, arguments) {
                if isset params[i + 1] && (parameter->isDefaultValueAvailable() && parameter->isOptional() === false) {
                    let parameters[i] = parameter->getDefaultValue();
                } else {
                    let parameters[i] = arguments[i],
                        index = i + 1;
                }
            } else {
                if parameter->isDefaultValueAvailable() === false {
                    throw new BindingResolutionException(reflector, parameter);
                } 

                let parameters[i] = parameter->getDefaultValue();
            }
        }
 
        if parameters {
            return parameters;
        }

        return arguments;
    }

    /**
     * @param key
     * @param binding
     * @return mixed
     * @throws ReflectionException
     */
    protected function resolveBinding(key, binding)
    {
        if typeof binding == "object" && binding instanceof Closure {
            let this->bindingsResolved[key] = call_user_func(binding, this);
            return this->bindingsResolved[key];
        } 
        
        if typeof binding == "string" {

            if key === binding {
                unset this->bindings[key];
                let this->bindingsResolved[key] = this->make(binding),
                    this->bindings[key] = binding;
                return this->bindingsResolved[key];
            }

            if isset this->aliasBindings[binding] && this->aliasBindings[binding] === key {
                unset this->aliasBindings[binding];
                let this->bindingsResolved[key] = this->make(binding), 
                    this->aliasBindings[binding] = key;
                return this->bindingsResolved[key];
            }
        }

        let this->bindingsResolved[key] = this->make(binding);
        
        return this->bindingsResolved[key];
    }

    /**
     * @param key
     * @return string
     */
    protected function resolveKey(key)
    {
        if isset this->aliasBindings[key] === false || key === this->aliasBindings[key] {
            return key;
        }

        return this->resolveKey(this->aliasBindings[key]);
    }
}