namespace Zeplara\Contracts\Container;

use Reflector;
use ReflectionParameter;

interface BindingResolutionException
{
    /**
     * @return Reflector
     */
    public function getReflector();

    /**
     * @return ReflectionParameter
     */
    public function getParameter();
}
