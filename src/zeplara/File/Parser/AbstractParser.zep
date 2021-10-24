namespace Zeplara\File\Parser;

use RuntimeException;
use InvalidArgumentException;
use Zeplara\Interfaces\File\Parser\Parser;

abstract class AbstractParser implements Parser
{
    /**
     * @param string file
     * @return mixed
     * @throws InvalidArgumentException|ParserException
     */
    public function parseFile(string! file)
    {
        if file_exists(file) === false {
            throw new InvalidArgumentException("File %s does not exists."->format(file));
        }

        var e;

        try {
            return this->parse(file_get_contents(file));
        } catch ParserException, e {
            this->throwParserException(e->getMessage(), file, e->getLine());
        }
    }

    /**
     * @param string message
     * @param string file
     * @param int line
     * @throws ParserException
     */
    protected function throwParserException(message, file = "", line = 0)
    {
        throw new ParserException(message, file, line);
    }
}