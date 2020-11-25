namespace Zeplara\Support\File\Finder;

use Zeplara\Support\File\SplFileInfo;

final class ReadableFilter extends AbstractFilter
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