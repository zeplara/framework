namespace Zeplara\Interfaces\Routing;

interface Group extends Attribute
{
    /**
     * @param Router router
     * @param mixed handler
     * @return void
     */
    public static function load(<Router> router, handler);
}