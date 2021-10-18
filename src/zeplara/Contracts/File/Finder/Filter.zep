namespace Zeplara\Contracts\File\Finder;

use Zeplara\Contracts\File\SplFileInfo;

interface Filter
{
    /**
     * @param SplFileInfo fileInfo
     * @return bool
     */
    public function accept(<SplFileInfo> fileInfo) -> bool;
}