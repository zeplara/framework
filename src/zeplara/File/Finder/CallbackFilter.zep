namespace Zeplara\File\Finder;

use Zeplara\Interfaces\File\SplFileInfo;
use Zeplara\Interfaces\File\Finder\Filter;

final class CallbackFilter implements Filter
{
    /**
     * @var callable
     */
    private callback;
    
    /**
     * @param callable callback
     */
    public function __construct(callable! callback)
    {
        let this->callback = callback;
    }

    /**
     * @return bool
     */
    public function accept(<SplFileInfo> fileInfo) -> bool
    {
        return call_user_func(this->callback, fileInfo);
    }
}