namespace Zeplara\File\Finder;

use Zeplara\Contracts\File\SplFileInfo;
use Zeplara\Contracts\File\Finder\Filter;

final class LinkFilter implements Filter
{
    /**
     * @param SplFileInfo fileInfo
     * @return bool
     */
    public function accept(<SplFileInfo> fileInfo) -> bool 
    {
        return fileInfo->isLink();
    }
}