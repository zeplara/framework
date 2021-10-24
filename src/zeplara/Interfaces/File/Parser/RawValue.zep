namespace Zeplara\Interfaces\File\Parser;

interface RawValue
{
    /**
     * @return string
     */
    public function getValue();

    /**
     * @return LinesIterator
     */
    public function getLines();
}