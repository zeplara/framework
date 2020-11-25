namespace Zeplara\Pipeline;

use Zeplara\Contracts\Container\Container;

final class Carry
{   
    /**
     * @var callable
     */
    private handler;
    /**
     * @var callable
     */
    private pipe;
    /**
     * @var Container 
     */
    private container;

    /**
     * @param Container container
     * @param callable handler
     * @param callable pipe
     */
    public function __construct(<Container> container, callable! handler, callable! pipe)
    {
        let this->container = container,
            this->handler = handler,
            this->pipe = pipe;
    }

    /**
     * @return mixed
     */
    public function __invoke()
    {
        var args;
        
        let args = (array) func_get_args(),
            args[] = this->handler;

        return this->container->make(this->pipe, args);
    }
}