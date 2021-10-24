namespace Zeplara\File\Finder;

use Zeplara\Interfaces\File\SplFileInfo;
use Zeplara\Interfaces\File\Finder\Filter;

final class ReadableFilter implements Filter
{   
    /**
     * @param SplFileInfo fileInfo
     * @return bool
     */
    public function accept(<SplFileInfo> fileInfo) -> bool
    {
        return fileInfo->isReadable();
    }
}