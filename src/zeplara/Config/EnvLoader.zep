namespace Zeplara\Config;

use Zeplara\Contracts\Config\Loader;
use Zeplara\Support\File\Parser\EnvParser;
use Zeplara\Support\File\Parser\ParserException;

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
            return EnvParser::parseFile(file);
        } catch ParserException, e {
            throw new LoaderException(e->getMessage(), e->getFile(), e->getLine());
        }
    }
}