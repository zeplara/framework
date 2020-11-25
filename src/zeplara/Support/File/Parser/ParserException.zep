namespace Zeplara\Support\File\Parser;

use ErrorException;

class ParserException extends ErrorException
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