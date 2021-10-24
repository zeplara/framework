namespace Zeplara\Routing;

use InvalidArgumentException;
use Zeplara\Interfaces\Routing\Route as RouteContract;
use Zeplara\Interfaces\Routing\Router as RouterContract;

/**
 * @method Route get(string $pattern, $callback, array $attributes = [])
 * @method Route post(string $pattern, $callback, array $attributes = [])
 * @method Route put(string $pattern, $callback, array $attributes = [])
 * @method Route delete(string $pattern, $callback, array $attributes = [])
 * @method Route patch(string $pattern, $callback, array $attributes = [])
 * @method Route options(string $pattern, $callback, array $attributes = [])
 * @method Route any(string $pattern, $callback, array $attributes = [])
 * @method Route register(string $pattern, $callback, array $methods, array $attributes = [])
 * @method Registrar|string scheme(string $value = null)
 * @method Registrar|string host(string $value = null)
 * @method Registrar|string prefix(string $value = null)
 * @method Registrar|string namespace(string $value = null)
 * @method Registrar|array requirements(array $requirements)
 * @method Registrar where(string $key, $value)
 * @method Registrar|array middleware(...$args)
 * @method Registrar|string name(string $name = null)
 */
final class Router implements RouterContract
{
    /**
     * @var array
     */
    protected routes = [] { get };
    /**
     * @var Group
     */
    private static group;

    /**
     * @param array routes
     */
    public function __construct(array! routes = [])
    {
        this->setRoutes(routes);

        let self::group = new Group;
    }

    /**
     * @param array routes
     * @return void
     */
    public function setRoutes(array! routes)
    {
        var route;
        
        for route in routes {
            
            if typeof route != "object" || (route instanceof RouteContract) === false {
                throw new InvalidArgumentException("The value must be instanceof Route.");
            }
            
            this->addRoute(route);
        }
    }

    /**
     * @param RouteContract route
     * @return void
     */
    public function addRoute(<RouteContract> route)
    {
        let this->routes[] = route;
    }

    /**
     * @param string pattern
     * @param callback
     * @param array methods
     * @param array attributes
     * @return Route
     */
    public function createRoute(pattern, callback, array! methods, array! attributes = [])
    {
        var scheme, host, $namespace, requirements, middleware;

        let scheme = self::group->scheme(),
            host = self::group->host(),
            middleware = self::group->middleware(),
            $namespace = self::group->{"namespace"}(),
            requirements = self::group->requirements(),
            pattern = "/".trim(trim(self::group->prefix(), "/")."/".trim(pattern, "/"),"/");

        if scheme && !isset attributes["scheme"] {
            let attributes["scheme"] = scheme;
        }

        if host && !isset attributes["host"] {
            let attributes["host"] = self::group->host();
        }

        if $namespace {
            if typeof callback == "string"  {
                let callback = "\\".trim(trim($namespace, "\\")."\\".trim(callback, "\\"), "\\");
            } elseif typeof callback == "array" && count(callback) === 2 && typeof callback[0] == "string" && is_callable(callback) === false {
                let callback[0] = "\\".trim(trim($namespace, "\\")."\\".trim(callback[0], "\\"), "\\");
            }
        }

        if middleware {
            if !isset attributes["middleware"] {
                let attributes["middleware"] = middleware;
            } else {
                let attributes["middleware"] = array_unique(array_merge(middleware, attributes["middleware"]), SORT_REGULAR);
            }
        }

        if requirements {
            if !isset attributes["requirements"] {
                let attributes["requirements"] = requirements;
            } else {
                let attributes["requirements"] = array_merge(requirements, attributes["requirements"]);
            }
        }
        
        return new Route(pattern, callback, methods, attributes);
    }

    /**
     * @param handler
     * @param array attributes
     * @return void
     */
    public function group(handler, array! attributes = [])
    {
        var groupClone;
        
        let groupClone = clone self::group;

        self::group->setAttributes(attributes);

        Group::load(this, handler);

        let self::group = groupClone;
    }

    /**
     * @param string name
     * @param array arguments
     * @return mixed
     */
    public function __call(name, array! arguments = [])
    {
        return call_user_func_array([new Registrar(this), name], arguments);
    }
}