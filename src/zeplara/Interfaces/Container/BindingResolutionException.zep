namespace Zeplara\Interfaces\Container;

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
