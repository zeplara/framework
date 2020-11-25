namespace Zeplara\Support\File\Parser;

use ArrayIterator;

final class LinesIterator extends ArrayIterator
{
    /**
     * @param string contents
     */
    public function __construct(string! contents)
    {
        parent::__construct(explode("\n", str_replace(["\r\n", "\r"], "\n", contents)));
    }
}