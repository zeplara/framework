namespace Zeplara\Support\File\Finder;

use Zeplara\Support\File\SplFileInfo;

final class WritableFilter extends AbstractFilter
{   
    /**
     * @param SplFileInfo fileInfo
     * @return bool
     */
    public function accept(<SplFileInfo> fileInfo) -> bool
    {
        return fileInfo->isWritable();
    }
}