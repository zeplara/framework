namespace Zeplara\Support\File\Finder;

use Zeplara\Support\File\SplFileInfo;

abstract class AbstractFilter
{
    /**
     * @param SplFileInfo fileInfo
     * @return bool
     */
    abstract public function accept(<SplFileInfo> fileInfo) -> bool;
}