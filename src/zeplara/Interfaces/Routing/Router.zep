namespace Zeplara\Interfaces\Routing;

interface Router
{
    /**
     * @return array
     */
    public function getRoutes();

    /**
     * @param array routes
     * @return void
     */
    public function setRoutes(array! routes);

    /**
     * @param Route route
     * @return void
     */
    public function addRoute(<Route> route);
    
    /**
     * @param string pattern
     * @param callback
     * @param array methods
     * @param array attributes
     * @return Route
     */
    public function createRoute(pattern, callback, array! methods, array! attributes = []);

    /**
     * @param handler
     * @param array attributes
     * @return void
     */
    public function group(handler, array! attributes = []);

    /**
     * @param string name
     * @param array arguments
     * @return mixed
     */
    public function __call(name, array! arguments = []);
}