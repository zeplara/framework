namespace Zeplara\Support\File\Parser;

use RuntimeException;
use InvalidArgumentException;

abstract class AbstractParser
{
    /**
     * {@inheritdoc}
     */
    final private function __construct()
    {
        // 
    }

    /**
     * @param string contents
     * @return mixed
     * @throws ParserException|RuntimeException
     */
    public static function parse(string! contents)
    {
        throw new RuntimeException("%s class does not implement %s method."->format(get_called_class(), __FUNCTION__));
    }

    /**
     * @param string file
     * @return mixed
     * @throws InvalidArgumentException
     * @throws ParserException|RuntimeException
     */
    public static function parseFile(string! file)
    {
        if file_exists(file) === false {
            throw new InvalidArgumentException("File %s does not exists."->format(file));
        }

        var e;

        try {
            return static::parse(file_get_contents(file));
        } catch ParserException, e {
            self::throwParserException(e->getMessage(), file, e->getLine());
        }
    }

    /**
     * @param string message
     * @param string file
     * @param int line
     * @throws ParserException
     */
    protected static function throwParserException(message, file = "", line = 0)
    {
        throw new ParserException(message, file, line);
    }
}