namespace Zeplara\Contracts\Pipeline;

interface Pipeline
{
    /**
     * @return \Zeplara\Contracts\Container\Container
     */
    public function getContainer();

    /**
     * @return array
     */
    public function getPipes();

    /**
     * @param array pipes
     * @return void
     */
    public function setPipes(array! pipes);

    /**
     * @return void
     */
    public function addPipe(pipe);

    /**
     * @return mixed
     */
    public function send(callable! destination, array! arguments = []);
}