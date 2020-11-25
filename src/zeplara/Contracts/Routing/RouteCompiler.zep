namespace Zeplara\Contracts\Routing;

interface RouteCompiler
{
    /**
     * @param Route route
     * @return CompiledRoute
     * @throws RouteCompilerException
     */
    public static function compile(<Route> route);
}