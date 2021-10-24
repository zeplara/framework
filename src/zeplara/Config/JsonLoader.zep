namespace Zeplara\Config;

use Zeplara\Interfaces\Config\Loader;

final class JsonLoader implements Loader
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

        var items;

        let items = json_decode(file_get_contents(file, false, null, 0, filesize(file)), true);

        if json_last_error() !== JSON_ERROR_NONE {
            throw new LoaderException(json_last_error_msg(), file, 0);
        }

        return items;
    }
}