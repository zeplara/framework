namespace Zeplara\Support\File\Finder;

use InvalidArgumentException;
use Zeplara\Support\File\SplFileInfo;

final class FileExtensionFilter extends AbstractFilter
{
    /**
     * @var int
     */
    const EXPECTED = 1;
    /**
     * @var int
     */
    const NOT_EXPECTED = 0;

    /**
     * @var array
     */
    private extensions;
    /**
     * @var int
     */
    private state;

    /**
     * @param array extensions
     * @param int state
     */
    public function __construct(array! extensions, int! state = self::EXPECTED)
    {
        if in_array(state, [self::EXPECTED, self::NOT_EXPECTED]) === false {
            throw new InvalidArgumentException("The state is invalid.");
        }

        let this->extensions = extensions,
            this->state = state;
    }
    
    /**
     * @param SplFileInfo fileInfo
     * @return bool
     */
    public function accept(<SplFileInfo> fileInfo) -> bool
    {
        if fileInfo->isFile() {
            return (this->state === self::NOT_EXPECTED ? (in_array(strtolower(fileInfo->getExtension()), array_map("strtolower", this->extensions)) === false) : in_array(strtolower(fileInfo->getExtension()), array_map("strtolower", this->extensions)));
        }

        return true;
    }
}