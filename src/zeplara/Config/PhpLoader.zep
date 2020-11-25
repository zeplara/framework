namespace Zeplara\Config;

use Throwable;
use Zeplara\Contracts\Config\Loader;

final class PhpLoader implements Loader
{
    /**
     * @param string file
     * @return array
     * @throws LoaderException
     */
    public static function load(file)
    {
        if file_exists(file) === false {
            throw new LoaderException("File [%s] does not exist."->format(file), file);
        }

        var e;
        
        try {
            return require file;
        } catch Throwable, e {
            throw new LoaderException(e->getMessage(), e->getFile(), e->getLine());
        }
    }
}