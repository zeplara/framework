namespace Zeplara\Support\File\Finder;

use ArrayIterator;
use IteratorAggregate;
use Zeplara\Support\Arr;
use Zeplara\Support\Str;
use BadMethodCallException;
use Zeplara\Support\File\SplFileInfo;

final class FileFinder implements IteratorAggregate
{
    /**
     * @var string
     */
    protected path { get };
    /**
     * @var mixed
     */
    protected depth { get, set };
    /**
     * @var array
     */
    protected filters { get, set };

    /**
     * @param string path
     * @param depth
     * @param array filters
     */
    public function __construct(path, depth = 512, array! filters = [])
    {
        let this->path = this->normalizePath(path);
        
        this->setDepth(depth);
        
        this->setFilters(filters);
    }

    /**
     * @param filter
     * @return void
     */
    public function addFilter(filter)
    {
        let this->filters[] = filter;
    }

    /**
     * @return Iterator
     */
    public function getIterator()
    {
        return new Iterator(new ArrayIterator(this->loadPath(this->path, this->depth)), this->filters);
    }
    
    /**
     * @param string name
     * @param array arguments
     * @return mixed
     */
    public function __call(name, array! arguments = [])
    {
        var factory;
        let factory = __NAMESPACE__."\\FilterFactory";
        
        if method_exists(factory, name) === true {
            this->addFilter(call_user_func_array([factory, name], arguments));
        } else {
            var filter, methodName;

            let filter = Arr::last(this->filters),
                methodName = Str::studly(name);

            if substr(methodName, 0, 3) == "Set" {
                let methodName = "set".substr(methodName, 3);
            } else {
                let methodName = "set".methodName;
            }
            
            if typeof filter == "NULL" {
                throw new BadMethodCallException("Method %s::%s does not exists."->format(factory, name));
            } elseif method_exists(filter, methodName) === false {
                throw new BadMethodCallException("Method %s::%s does not exists."->format(get_class(filter), methodName));
            }

            call_user_func_array([filter, methodName], arguments);
        }
        
        return this;
    }

    /**
     * @param string path
     * @param int depth
     * @param array filters
     * @return static
     */
    public static function instance(path, depth = 512, array! filters = [])
    {
        return new self(path, depth, filters);
    }

    /**
     * @param string path
     * @param int depth
     * @param array filters
     * @return static
     */
    public static function create(path, depth = 512, array! filters = [])
    {
        return self::instance(path, depth, filters);
    }

    /**
     * @param string path
     * @param int depth
     * @param array filters
     * @return static
     */
    public static function make(path, depth = 512, array! filters = [])
    {
        return self::instance(path, depth, filters);
    }

    /**
     * @param string path
     * @param int depth
     * @return array
     * @throws \Exception
     */
    private function loadPath(path, int! depth)
    {
        var handle, entry, entries, separator;
        
        let separator = DIRECTORY_SEPARATOR;

        if substr(path, -1) == "/" {
            let separator = "/";
        }
        
        error_clear_last();
        set_error_handler(function () {            
            var args;
            let args = func_get_args();
            throw new \Exception(args[1]);
        });
        
        let entries = [],
            handle = opendir(path);

        while true {
            let entry = readdir(handle);
            
            if entry === false {
                break;
            }

            if entry == "." || entry == ".." {
                continue;
            }

            let entry = this->normalizePath(rtrim(path, "\\/").separator.entry),
                entries[] = new SplFileInfo(entry);

            if is_dir(entry) && depth > 0 {
                let depth--,
                    entries = array_merge(entries, this->loadPath(entry, depth));
            }
        }

        closedir(handle);
        restore_error_handler();
        
        return entries;
    }

    /**
     * @param string path
     * @return string
     */
    private function normalizePath(path)
    {   
        let path = rtrim(path, "\\/");
        if (bool) preg_match("/^(?:ssh2\\.)?s?ftp\\:\\/\\//", path) {
            let path = path."/";
        }

        return path;
    }
}