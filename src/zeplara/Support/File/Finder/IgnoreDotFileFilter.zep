namespace Zeplara\Support\File\Finder;

use Zeplara\Support\File\SplFileInfo;

final class IgnoreDotFileFilter extends AbstractFilter
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