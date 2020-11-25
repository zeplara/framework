namespace Zeplara\Pipeline;

use Zeplara\Support\Arr;
use Zeplara\Contracts\Container\Container;
use Zeplara\Contracts\Pipeline\Pipeline as PipelineContract;

final class Pipeline implements PipelineContract
{
    /**
     * @var Container
     */
    protected container { get };
    /**
     * @var array
     */
    protected pipes = [] { get, set };

    /**
     * Pipeline constructor.
     *
     * @param Container container
     * @param array pipes
     */
    public function __construct(<Container> container, array! pipes = [])
    {
        let this->container = container;

        this->setPipes(pipes);
    }

    /**
     * @param pipe
     * @return void
     */
    public function addPipe(pipe)
    {
        let this->pipes[] = pipe;
    }

    /**
     * @param callable destination
     * @param array arguments
     * @return mixed
     */
    public function send(callable! destination, array! arguments = [])
    {
        return call_user_func_array(
            array_reduce(
                array_reverse(this->pipes), 
                [this, "reduceCallback"], 
                destination
            ), 
            Arr::wrap(arguments)
        );
    }

    /**
     * @param callable handler
     * @param pipe
     * @return Carry
     */
    protected function reduceCallback(callable! handler, pipe)
    {
        if is_callable(pipe) === false {
            let pipe = this->container->make(pipe);
        }

        return new Carry(this->container, handler, pipe);
    }
}