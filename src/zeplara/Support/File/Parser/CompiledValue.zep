namespace Zeplara\Support\File\Parser;

final class CompiledValue
{
    /**
     * @var mixed
     */
    protected value { get };
    /**
     * @var string
     */
    protected rawValue { get };
    

    /**
     * @param value
     * @param string rawValue
     */
    public function __construct(value, string! rawValue)
    {
        let this->value = value,
            this->rawValue = new RawValue(rawValue);
    }
}