namespace Zeplara\Container;

use Reflector;
use ReflectionParameter;
use Zeplara\Contracts\Container\BindingResolutionException as BindingResolutionExceptionContract;

class BindingResolutionException extends ContainerException implements BindingResolutionExceptionContract
{
    /**
     * @var Reflector
     */
    protected reflector { get };
    /**
     * @var ReflectionParameter
     */
    protected parameter { get };

    /**
     * @param Reflection reflector
     * @param ReflectionParameter parameter
     */
    public function __construct(<Reflector> reflector, <ReflectionParameter> parameter)
    {
        let this->reflector = reflector,
            this->parameter = parameter;

        parent::__construct(parameter." ".reflector);
    }
}
