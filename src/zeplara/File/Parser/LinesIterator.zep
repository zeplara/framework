namespace Zeplara\File\Parser;

use ArrayIterator;
use Zeplara\Contracts\File\Parser\LinesIterator as LinesIteratorContract;

final class LinesIterator extends ArrayIterator implements LinesIteratorContract
{
    /**
     * @param string contents
     */
    public function __construct(string! contents)
    {
        parent::__construct(explode("\n", str_replace(["\r\n", "\r"], "\n", contents)));
    }
}