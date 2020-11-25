namespace Zeplara\Container;

use InvalidArgumentException;
use Zeplara\Contracts\Container\InvalidAbstractException as InvalidAbstractExceptionContract;

class InvalidAbstractException extends InvalidArgumentException implements InvalidAbstractExceptionContract
{
    /**
     * @var mixed
     */
    protected $abstract;

    /**
     * @param $abstract
     */
    public function __construct($abstract)
    {
        let this->$abstract = $abstract;

        parent::__construct("Abstract is not provided.");
    }

    /**
     * @return mixed
     */
    public function getAbstract()
    {
        return this->$abstract;
    }
}