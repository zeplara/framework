namespace Zeplara\Routing;

use Zeplara\Interfaces\Routing\CompiledRoute as CompiledRouteContract;

final class CompiledRoute implements CompiledRouteContract
{
    /**
     * @var Regex
     */
    protected host;
    /**
     * @var Regex
     */
    protected path;

    /** 
     * @param Regex host
     * @param Regex path
     */
    public function __construct(<Regex> host, <Regex> path)
    {
        let this->host = host,
            this->path = path;
    }

    /**
     * @return Regex
     */
    public function getHost()
    {
        return this->host;
    }

    /**
     * @return Regex
     */
    public function getPath()
    {
        return this->path;
    }
}