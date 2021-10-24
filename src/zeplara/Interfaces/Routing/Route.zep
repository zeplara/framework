namespace Zeplara\Interfaces\Routing;

interface Route extends Attribute
{
    /**
     * @return string
     */
    public function getPattern();

    /**
     * @return array
     */
    public function getMethods();

    /**
     * @return mixed
     */
    public function getCallback();

    /**
     * @return CompiledRoute
     */
    public function compile();
}