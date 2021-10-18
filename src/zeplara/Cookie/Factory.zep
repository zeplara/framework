namespace Zeplara\Cookie;

final class Factory
{
    /**
     * {@inheritdoc}
     */
    private function __construct()
    {
    
    }

    /**
     * @param name
     * @param string value
     * @param int expiration
     * @param string path
     * @param string domain
     * @param bool secure
     * @param bool httpOnly
     * @param null sameSite
     * @return Cookie
     */
    public static function make(name, value = "", expiration = 0, path = "/", domain = "", secure = false, httpOnly = true, sameSite = null)
    {
        return new Cookie(name, value, expiration, path, domain, secure, httpOnly, sameSite);
    }

    /**
     * @param name
     * @param string value
     * @param string path
     * @param string domain
     * @param bool secure
     * @param bool httpOnly
     * @param null sameSite
     * @return Cookie
     */
    public static function forever(name, value = "", path = "/", domain = "", secure = false, httpOnly = true, sameSite = null)
    {
        return self::make(name, value, time() + 315360000, path, domain, secure, httpOnly, sameSite);
    }

    /**
     * @param name
     * @param string path
     * @param string domain
     * @param bool secure
     * @param bool httpOnly
     * @param null sameSite
     * @return Cookie
     */
    public static function forget(name, path = "/", domain = "", secure = false, httpOnly = true, sameSite = null)
    {
        return self::make(name, "", time() - 3600, path, domain, secure, httpOnly, sameSite);
    }
}