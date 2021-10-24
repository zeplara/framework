namespace Zeplara\Session;

use Zeplara\Cookie\Factory;
use SessionHandlerInterface;
use Zeplara\Interfaces\Cookie\Queue;
use Psr\Http\Message\ServerRequestInterface;

final class CookieSessionHandler implements SessionHandlerInterface
{
    /**
     * @var Queue
     */
    private queue;
    /**
     * @var ServerRequestInterface
     */
    private request;

    /**
     * @param Queue queue
     * @param ServerRequestInterface request
     */
    public function __construct(<Queue> queue, <ServerRequestInterface> request)
    {
        let this->queue = queue,
            this->request = request;
    }

    /**
     * @return bool
     */
    public function close()
    {
        return true;
    }

    /**
     * @param int maxlifetime
     * @return bool
     */
    public function gc(maxlifetime)
    {
        return true;
    }

    /**
     * @param string save_path
     * @param string name
     * @return bool
     */
    public function open(save_path, name)
    {
        return true;
    }

    /**
     * @param string session_id
     * @return mixed|string|null
     */
    public function read(session_id)
    {
        var cookie;

        fetch cookie, this->request->getCookieParams()[session_id];

        return (string) cookie;
    }

    /**
     * @param string session_id
     * @param string session_data
     * @return bool
     */
    public function write(session_id, session_data)
    {
        this->queue->set(Factory::make(session_id, session_data));

        return true;
    }

    /**
     * @param string session_id
     * @return bool
     */
    public function destroy(session_id)
    {
        this->queue->set(Factory::forget(session_id));
        
        return true;
    }
}