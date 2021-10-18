namespace Zeplara\File\Parser;

use Zeplara\Contracts\File\Parser\CompiledValue as CompiledValueContract;

final class CompiledValue implements CompiledValueContract
{
    /**
     * @var mixed
     */
    protected value { get };
    /**
     * @var RawValue
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