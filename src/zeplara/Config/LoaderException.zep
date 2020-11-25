namespace Zeplara\Config;

use ErrorException;
use Zeplara\Contracts\Config\LoaderException as LoaderExceptionContract;

final class LoaderException extends ErrorException implements LoaderExceptionContract
{
    /**
     * LoaderException constructor.
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