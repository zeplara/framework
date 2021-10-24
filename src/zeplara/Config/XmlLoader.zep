namespace Zeplara\Config;

use Zeplara\Interfaces\Config\Loader;

final class XmlLoader implements Loader
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

        var items, error;
        libxml_use_internal_errors(true);

        let items = json_decode(json_encode(simplexml_load_file(file, null, LIBXML_NOERROR)), true),
            error = libxml_get_last_error();

        if error !== false {
            libxml_clear_errors();
            throw new LoaderException(error->message, error->file, error->line);
        }

        return items;
    }
}