namespace Zeplara\Routing;

use Zeplara\Support\Str;
use BadMethodCallException;
use InvalidArgumentException;
use Zeplara\Interfaces\Routing\Attribute as AttributeContract;

abstract class AbstractAttribute implements AttributeContract
{
    /**
     * @var array
     */
    protected attributes = [] { get };
    /**
     * @var array
     */
    private static methodsCache = [];

    /**
     * @param array attributes
     * @return void
     */
    public function setAttributes(array! attributes)
    {
        var key, value, method;

        for key, value in attributes {
            if is_numeric(key) {
                throw new InvalidArgumentException("The key of attributes should be string type.");
            }
            let method = "init%sAttribute"->format(Str::studly(key));
            
            if this->methodExists(method) === false {
                this->throwBadMethodCallException(method);
            }

            this->{method}(value);
        }
    }

    /**
     * @param string name
     * @param array arguments
     * @return mixed
     */
    public function __call(name, array! arguments = [])
    {
        var method;
        if empty arguments {
            let method = "get%sAttribute"->format(Str::studly(name));

            if this->methodExists(method) === false {
                this->throwBadMethodCallException(method);
            }

            // Call method with call user function due core segment fault issue when
            // call method with this->{method}()
            return call_user_func([this, method]);
        }

        let method = "set%sAttribute"->format(Str::studly(name));
            
        if this->methodExists(method) === false {
            this->throwBadMethodCallException(method);
        }

        call_user_func_array([this, method], arguments);

        return this;
    }

    /**
     * @param string method
     * @return bool
     */
    private function methodExists(method)
    {
        var calledClass;
        let calledClass = get_called_class();

        if !isset self::methodsCache[calledClass] {
            let self::methodsCache[calledClass] = array_fill_keys(get_class_methods(this), true);
        }

        return isset self::methodsCache[calledClass][method];
    }

    /**
     * @param string method
     */
    private function throwBadMethodCallException(method)
    {
        throw new BadMethodCallException("Method %s::%s does not exists."->format(get_called_class(), method));
    }
}