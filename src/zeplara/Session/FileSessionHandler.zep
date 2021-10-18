namespace Zeplara\Session;

use SessionHandlerInterface;
use InvalidArgumentException;
use Zeplara\File\Finder\Finder;

final class FileSessionHandler implements SessionHandlerInterface
{
    /**
     * @var string
     */
    private path;

    /**
     * FileSessionHandler constructor.
     *
     * @param path
     */
    public function __construct(path)
    {
        if is_writable(path) === false {
            throw new InvalidArgumentException(sprintf(
                "Directory %s is not writable", path
            ));
        }

        let this->path = rtrim(path, "\/");
    }

    /**
     * @return bool
     */
    public function close()
    {
        return true;
    }

    /**
     * @param string session_id
     * @return bool
     */
    public function destroy(session_id)
    {
        var file;

        let file = this->path.DIRECTORY_SEPARATOR.session_id;

        if is_file(file) {
            error_clear_last();

            set_error_handler(function () {
            
            });
            
            unlink(file);
        
            restore_error_handler();
        }

        return true;
    }

    /**
     * @param int maxlifetime
     * @return bool
     */
    public function gc(maxlifetime)
    {
        var file, files;

        let files = Finder::instance(this->path)
                        ->ignoreDotFiles()
                        ->files()
                        ->date(time() - maxlifetime, "<=");

        error_clear_last();

        set_error_handler(function () {
            // silent
        });

        for file in files {
            unlink(file->getRealPath());
        }

        restore_error_handler();

        return true;
    }

    /**
     * @param string save_path
     * @param string name
     * @return bool
     */
    public function open(save_path, name)
    {
        return true;
    }

    /**
     * @param string session_id
     * @return string
     */
    public function read(session_id)
    {
        var file;

        let file = this->path.DIRECTORY_SEPARATOR.session_id;

        if is_file(file) === false {
            return "";
        }

        return file_get_contents(file);
    }

    /**
     * @param string session_id
     * @param string session_data
     * @return bool
     */
    public function write(session_id, session_data)
    {
        if file_put_contents(this->path.DIRECTORY_SEPARATOR.session_id, session_data, LOCK_EX) === false {
            return false;
        }

        return true;
    }
}