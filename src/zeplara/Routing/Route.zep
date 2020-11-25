namespace Zeplara\Routing;

use InvalidArgumentException;
use Zeplara\Contracts\Routing\Route as RouteContract;

/**
 * @method Route|string scheme(string $value = null)
 * @method Route|string host(string $value = null)
 * @method Route|array requirements(array $requirements)
 * @method Route where(string $key, $value)
 * @method Route|array middleware(...$args)
 * @method Route|string name(string $name = null)
 */
final class Route extends Attribute implements RouteContract
{
    /**
     * @var string
     */
    protected pattern { get };
    /**
     * @var array
     */
    protected methods { get };
    /**
     * @var mixed
     */
    protected callback { get };
     /**
     * @var CompiledRoute|null
     */
    private compiled;

    /**
     * @param string pattern
     * @param callback
     * @param array methods
     * @param array attributes
     */
    public function __construct(pattern, callback, array! methods, array! attributes = [])
    {
        let this->pattern = pattern,
            this->callback = callback,
            this->methods = methods;

        this->setAttributes(attributes);
    }

    /**
     * @return CompiledRoute
     */
    public function compile()
    {
        if typeof this->compiled == "NULL" {
            let this->compiled = RouteCompiler::compile(this);
        }

        return this->compiled;
    }

    /**
     * @return string
     */
    protected function getSchemeAttribute()
    {
        if isset this->attributes["scheme"] {
            return this->attributes["scheme"];
        }

        return "";
    }

    /**
     * @param string value
     * @return void
     */
    protected function setSchemeAttribute(string! value)
    {
        var sepIdx;
        let value = strtolower(value), 
            sepIdx = strpos(value, ":");

        if sepIdx !== false {
            let value = substr(value, 0, sepIdx);
        }

        let this->attributes["scheme"] = value;
    }

    /**
     * @param string value
     * @return void
     */
    protected function initSchemeAttribute(string! value)
    {
        this->setSchemeAttribute(value);
    }

    /**
     * @return string
     */
    protected function getHostAttribute()
    {
        if isset this->attributes["host"] {
            return this->attributes["host"];
        }

        return "";
    }

    /**
     * @param string value
     * @return void
     */
    protected function setHostAttribute(string! value)
    {
        let this->attributes["host"] = value;
    }

    /**
     * @param string value
     * @return void
     */
    protected function initHostAttribute(string! value)
    {
        this->setHostAttribute(value);
    }

    /**
     * @return array
     */
    protected function getRequirementsAttribute()
    {
        if isset this->attributes["requirements"] {
            return this->attributes["requirements"];
        }

        return [];
    }

    /**
     * @param array value
     * @return void
     */
    protected function setRequirementsAttribute(array! requirements)
    {
        var key, value;
        
        if !isset this->attributes["requirements"] {
            let this->attributes["requirements"] = [];
        }

        for key, value in requirements {
            if is_numeric(key) {
                throw new InvalidArgumentException("The requirements key should be string type.");
            }

            let this->attributes["requirements"][key] = value;
        }
    }

    /**
     * @param array requirements
     * @return void
     */
    protected function initRequirementsAttribute(array! requirements)
    {
        this->setRequirementsAttribute(requirements);
    }

    /**
     * @param string key
     * @param value
     */
    protected function setWhereAttribute(string! key, value)
    {
        this->setRequirementsAttribute([key: value]);
    }

    /**
     * @return array
     */
    protected function getMiddlewareAttribute()
    {
        if isset this->attributes["middleware"] {
            return this->attributes["middleware"];
        }

        return [];
    }

    /**
     * @return void
     */
    protected function setMiddlewareAttribute()
    {
        let this->attributes["middleware"] = array_unique(array_merge(this->getMiddlewareAttribute(), func_get_args()), SORT_REGULAR);
    }

    /**
     * @param array middleware
     * @return void
     */
    protected function initMiddlewareAttribute(array! middleware)
    {
        call_user_func_array([this, "setMiddlewareAttribute"], middleware);
    }

    /**
     * @return string
     */
    protected function getNameAttribute()
    {
        if isset this->attributes["name"] {
            return this->attributes["name"];
        }

        return "";
    }

    /**
     * @param string value
     * @return void
     */
    protected function setNameAttribute(string! value)
    {
        let this->attributes["name"] = this->getNameAttribute().value;
    }

    /**
     * @param string value
     * @return void
     */
    protected function initNameAttribute(string! value)
    {
        this->setNameAttribute(value);
    }
}