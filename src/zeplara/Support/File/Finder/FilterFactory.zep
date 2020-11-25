namespace Zeplara\Support\File\Finder;

use Zeplara\Support\Arr;

final class FilterFactory
{   
    /**
     * {@inheritdoc}
     */
    private function __construct()
    {
    
    }

    /**
     * @return FileFilter
     */
    public static function file()
    {
        return new FileFilter;
    }

    /**
     * @return FileFilter
     */
    public static function files()
    {
        return self::file();
    }

    /**
     * @return IgnoreDotFileFilter
     */
    public static function ignoreDotFile()
    {
        return new IgnoreDotFileFilter;
    }

    /**
     * @return IgnoreDotFileFilter
     */
    public static function ignoreDotFiles()
    {
        return self::ignoreDotFile();
    }

    /**
     * @param mixed extensions
     * @param int state
     * @return FileExtensionFilter
     */
    public static function extension(extensions, state = FileExtensionFilter::EXPECTED)
    {
        return new FileExtensionFilter(Arr::wrap(extensions), state);
    }

    /**
     * @param array extensions
     * @param int state
     * @return FileExtensionFilter
     */
    public static function extensions(array! extensions, state = FileExtensionFilter::EXPECTED)
    {
        return self::extension(extensions, state);
    }

    /**
     * @return DirectoryFilter
     */
    public static function directory()
    {
        return new DirectoryFilter;
    }

    /**
     * @return DirectoryFilter
     */
    public static function directories()
    {
        return self::directory();
    }
    
    /**
     * @return DirectoryFilter
     */
    public static function dir()
    {
        return self::directory();
    }

    /**
     * @return DirectoryFilter
     */
    public static function dirs()
    {
        return self::directory();
    }

    /**
     * @return ExecutableFilter
     */
    public static function executable()
    {
        return new ExecutableFilter;
    }

    /**
     * @return LinkFilter
     */
    public static function link()
    {
        return new LinkFilter;
    }

    /**
     * @return LinkFilter
     */
    public static function links()
    {
        return self::link();
    }

    /**
     * @return ReadableFilter
     */
    public static function readable()
    {
        return new ReadableFilter;
    }

    /**
     * @return WritableFilter
     */
    public static function writable()
    {
        return new WritableFilter;
    }

    /**
     * @param callable callback
     * @return CallbackFilter
     */
    public static function callback(callable! callback)
    {
        return new CallbackFilter(callback);
    }

    /**
     * @param mixed time
     * @param string operator
     * @return DateFilter
     */
    public static function date(time, operator = null)
    {
        return new DateFilter(time, operator);
    }
}