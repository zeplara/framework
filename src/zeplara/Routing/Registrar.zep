namespace Zeplara\Routing;

use Zeplara\Support\Arr;
use InvalidArgumentException;
use Zeplara\Contracts\Routing\Registrar as RegistrarContract;

/**
 * @method Registrar|string scheme(string $value = null)
 * @method Registrar|string host(string $value = null)
 * @method Registrar|string prefix(string $value = null)
 * @method Registrar|string namespace(string $value = null)
 * @method Registrar|array requirements(array $requirements)
 * @method Registrar where(string $key, $value)
 * @method Registrar|array middleware(...$args)
 * @method Registrar|string name(string $name = null)
 */
final class Registrar extends Attribute implements RegistrarContract
{
    /**
     * @var Router
     */
    protected router { get };
    
    /**
     * @param Router router
     */
    public function __construct(<Router> router)
    {
        let this->router = router;
    }

    /**
     * @param string pattern
     * @param callback
     * @param array attributes
     * @return Route
     */
    public function get(pattern, callback, array! attributes = [])
    {
        return this->register(pattern, callback, ["GET", "HEAD"], attributes);
    }

    /**
     * @param string pattern
     * @param callback
     * @param array attributes
     * @return Route
     */
    public function post(pattern, callback, array! attributes = [])
    {
        return this->register(pattern, callback, ["POST"], attributes);
    }

    /**
     * @param string pattern
     * @param callback
     * @param array attributes
     * @return Route
     */
    public function put(pattern, callback, array! attributes = [])
    {
        return this->register(pattern, callback, ["PUT"], attributes);
    }

    /**
     * @param string pattern
     * @param callback
     * @param array attributes
     * @return Route
     */
    public function delete(pattern, callback, array! attributes = [])
    {
        return this->register(pattern, callback, ["DELETE"], attributes);
    }

    /**
     * @param string pattern
     * @param callback
     * @param array attributes
     * @return Route
     */
    public function patch(pattern, callback, array! attributes = [])
    {
        return this->register(pattern, callback, ["PATCH"], attributes);
    }

    /**
     * @param string pattern
     * @param callback
     * @param array attributes
     * @return Route
     */
    public function options(pattern, callback, array! attributes = [])
    {
        return this->register(pattern, callback, ["OPTIONS"], attributes);
    }

    /**
     * @param string pattern
     * @param callback
     * @param array attributes
     * @return Route
     */
    public function any(pattern, callback, array! attributes = [])
    {  
        return this->register(pattern, callback, ["HEAD", "GET", "POST", "PUT", "DELETE", "PATCH", "OPTIONS"], attributes);
    }

    /**
     * @param handler
     * @return void
     */
    public function group(handler)
    {
        this->router->group(handler, this->attributes);
    }

    /**
     * @param string pattern
     * @param callback
     * @param array methods
     * @param array attributes
     * @return Route
     */
    public function register(pattern, callback, array! methods, array! attributes = [])
    {
        var route;

        let route = this->router->createRoute(pattern, callback, methods, array_merge(this->attributes, attributes));
        
        this->router->addRoute(route);

        return route;
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
    protected function setHostAttribute(string! value)
    {
        let this->attributes["host"] = value;
    }
 
    /**
     * @param string value
     * @return void
     */
    protected function setPrefixAttribute(string! value)
    {
        let this->attributes["prefix"] = "/".trim(trim(Arr::get(this->attributes, "prefix", ""), "/")."/".trim(value, "/"),"/");
    }
    
    /**
     * @param string value
     * @return void
     */
    protected function setNamespaceAttribute(string! value)
    {
        let this->attributes["namespace"] = "\\".trim(trim(Arr::get(this->attributes, "namespace", ""), "\\")."\\".trim(value, "\\"),"\\");
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
     * @param string key
     * @param value
     */
    protected function setWhereAttribute(string! key, value)
    {
        this->setRequirementsAttribute([key: value]);
    }
 
    /**
     * @return void
     */
    protected function setMiddlewareAttribute()
    {
        let this->attributes["middleware"] = array_unique(array_merge(Arr::get(this->attributes, "middleware", []), func_get_args()), SORT_REGULAR);
    }
 
    /**
     * @param string value
     * @return void
     */
    protected function setNameAttribute(string! value)
    {
        let this->attributes["name"] = value;
    }
}