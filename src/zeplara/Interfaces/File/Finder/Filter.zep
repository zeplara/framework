namespace Zeplara\Interfaces\File\Finder;

use Zeplara\Interfaces\File\SplFileInfo;

interface Filter
{
    /**
     * @param SplFileInfo fileInfo
     * @return bool
     */
    public function accept(<SplFileInfo> fileInfo) -> bool;
}