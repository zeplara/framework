namespace Zeplara\File\Parser;

use Zeplara\Interfaces\File\Parser\RawValue as RawValueContract;

final class RawValue implements RawValueContract
{
    /**
     * @param string value
     */
    protected value { get };
    /**
     * @var LinesIterator
     */
    protected lines { get };

    /**
     * @param string value
     */
    public function __construct(string! value)
    {
        let this->value = value,
            this->lines = new LinesIterator(value);
    }
}