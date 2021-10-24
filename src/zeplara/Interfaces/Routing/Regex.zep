namespace Zeplara\Interfaces\Routing;

interface Regex
{
    /**
     * @return string
     */
    public function getRegex();

    /**
     * @param string value
     * @return array
     */
    public function match(value);

    /**
     * @return array
     */
    public function getVariables();
}