namespace Zeplara\Support\File\Finder;

use Zeplara\Support\File\SplFileInfo;

final class CallbackFilter extends AbstractFilter
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