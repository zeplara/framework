namespace Zeplara\Contracts\Config;

interface Loader
{
    /**
     * @param string file
     * @return array
     */
    public static function load(file);
}