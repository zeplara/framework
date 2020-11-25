namespace Zeplara\Contracts\Container;

use Throwable;
use Psr\Container\ContainerExceptionInterface;

interface InvalidAbstractException extends Throwable
{
    /**
     * @return mixed
     */
    public function getAbstract();
}