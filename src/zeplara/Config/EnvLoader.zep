namespace Zeplara\Config;

use Zeplara\Contracts\Config\Loader;
use Zeplara\File\Parser\EnvParser;
use Zeplara\File\Parser\ParserException;

final class EnvLoader implements Loader
{
    /**
     * @param string file
     * @return array
     * @throws LoaderException
     */
    public static function load(file)
    {
        var e;

        try {
            return (new EnvParser)->parseFile(file);
        } catch ParserException, e {
            throw new LoaderException(e->getMessage(), e->getFile(), e->getLine());
        }
    }
}