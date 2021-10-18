namespace Zeplara\Contracts\File\Parser;

interface CompiledValue
{
    /**
     * @return mixed
     */
    public function getValue();

    /**
     * @return RawValue
     */
    public function getRawValue();
}