namespace Zeplara\Contracts\Routing;

interface CompiledRoute
{
    /**
     * @return Regex
     */
    public function getHost();
    
    /**
     * @return Regex
     */
    public function getPath();
}