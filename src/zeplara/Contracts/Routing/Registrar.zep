namespace Zeplara\Contracts\Routing;

interface Registrar extends Attribute
{
    /**
     * @return Router
     */
     public function getRouter();

     /**
      * @param handler
      * @return void
      */
     public function group(handler);

    /**
     * @param string pattern
     * @param callback
     * @param array methods
     * @param array attributes
     * @return Route
     */
    public function register(pattern, callback, array! methods, array! attributes = []);
}