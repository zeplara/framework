namespace Zeplara\Interfaces\Cookie;

interface Queue
{
    /**
     * @param string key
     * @return bool
     */
    public function has(key);

    /**
     * @param string key
     * @return Cookie
     */
    public function get(key);

    /**
     * @param Cookie cookie
     * @return void
     */
    public function set(<Cookie> cookie);

    /**
     * @param string key
     * @return void
     */
    public function put(key);

    /**
     * @return array
     */
    public function getCookies();
}