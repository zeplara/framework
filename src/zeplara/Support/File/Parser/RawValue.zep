namespace Zeplara\Support\File\Parser;

final class RawValue
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