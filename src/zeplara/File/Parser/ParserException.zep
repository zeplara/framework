namespace Zeplara\File\Parser;

use ErrorException;

use Zeplara\Contracts\File\Parser\ParserException as ParserExceptionContract;

final class ParserException extends ErrorException implements ParserExceptionContract
{
    /**
     * ParserException constructor.
     *
     * @param string message
     * @param string filename
     * @param int lineno
     */
    public function __construct(message, filename = "", lineno = 0)
    {
        parent::__construct(message, 0, 1, filename, lineno);
    }
}