namespace Zeplara\File\Finder;

use Zeplara\Interfaces\File\SplFileInfo;
use Zeplara\Interfaces\File\Finder\Filter;

final class IgnoreDotFileFilter implements Filter
{
    /**
     * @param SplFileInfo fileInfo
     * @return bool
     */
    public function accept(<SplFileInfo> fileInfo) -> bool
    {
        if fileInfo->isFile() {
            return pathinfo(fileInfo, PATHINFO_FILENAME) !== "";
        }

        return true;
    }
}