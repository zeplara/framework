namespace Zeplara\Routing;

use InvalidArgumentException;
use Zeplara\Contracts\Routing\Group as GroupContract;
use Zeplara\Contracts\Routing\Router as RouterContract;

/**
 * @method Group|string scheme(string $value = null)
 * @method Group|string host(string $value = null)
 * @method Group|string prefix(string $value = null)
 * @method Group|string namespace(string $value = null)
 * @method Group|array requirements(array $requirements)
 * @method Group where(string $key, $value)
 * @method Group|array middleware(...$args)
 */
final class Group extends Attribute implements GroupContract
{
    /**
     * @param RouterContract router
     * @param mixed handler
     * @return void
     */
    public static function load(<RouterContract> router, handler)
    {
        if is_callable(handler) {
            {handler}(router);
        } else {
            // Currently when the file is not exists not show the error
            if file_exists(handler) === false {
                throw new InvalidArgumentException("File [%s] does not exists."->format(handler));
            }
            require handler;
        }
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
     * @param string value
     * @return void
     */
    protected function initHostAttribute(string! value)
    {
        this->setHostAttribute(value);
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
    protected function initPrefixAttribute(string! value)
    {
        this->setPrefixAttribute(value);
    }

    /**
     * @return string
     */
    protected function getPrefixAttribute()
    {
        if isset this->attributes["prefix"] {
            return this->attributes["prefix"];
        }

        return "";
    }

    /**
     * @param string value
     * @return void
     */
    protected function setPrefixAttribute(string! value)
    {
        let this->attributes["prefix"] = "/".trim(trim(this->getPrefixAttribute(), "/")."/".trim(value, "/"),"/");
    }

    /**
     * @param string value
     * @return void
     */
    protected function initNamespaceAttribute(string! value)
    {
        this->setNamespaceAttribute(value);
    }

    /**
     * @return string
     */
    protected function getNamespaceAttribute()
    {
        if isset this->attributes["namespace"] {
            return this->attributes["namespace"];
        }

        return "";
    }
    
    /**
     * @param string value
     * @return void
     */
    protected function setNamespaceAttribute(string! value)
    {
        let this->attributes["namespace"] = "\\".trim(trim(this->getNamespaceAttribute(), "\\")."\\".trim(value, "\\"),"\\");
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
     * @param array middleware
     * @return void
     */
    protected function initMiddlewareAttribute(array! middleware)
    {
        call_user_func_array([this, "setMiddlewareAttribute"], middleware);
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
}