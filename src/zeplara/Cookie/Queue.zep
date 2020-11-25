namespace Zeplara\Cookie;

use InvalidArgumentException;
use Zeplara\Contracts\Cookie\Cookie;
use Zeplara\Contracts\Cookie\Queue as QueueContract;

class Queue implements QueueContract
{
    /**
     * @var array
     */
    protected cookies { get };

    /**
     * @param string key
     * @return bool
     */
    public function has(key)
    {
        return isset this->cookies[key];
    }

    /**
     * @param string key
     * @return Cookie
     */
    public function get(key)
    {
        if this->has(key) === false {
            throw new InvalidArgumentException("Cookie %s does not exists."->format(key));
        }

        return this->cookies[key];
    }

    /**
     * @param Cookie cookie
     * @return void
     */
    public function set(<Cookie> cookie)
    {
        let this->cookies[cookie->getName()] = cookie;
    }

    /**
     * @param string key
     * @return void
     */
    public function put(key)
    {
        unset this->cookies[key];
    }
}