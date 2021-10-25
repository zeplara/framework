namespace Zeplara\Support\Facades;

class Router extends AbstractFacade
{
    protected static function getAccessor() -> object|string
    {
        return "Zeplara\\Interfaces\\Routing\\Router";
    }   
}