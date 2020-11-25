namespace Zeplara\Contracts\Container;

use ArrayAccess;
use Psr\Container\ContainerInterface;

interface Container extends ContainerInterface, ArrayAccess
{
    /**
     * @param key
     * @param value
     * @param bool resolve
     * @return void
     */
    public function set(key, value, bool! resolve = false);

    /**
     * @param key
     * @return void
     */
    public function put(key);

    /**
     * @param abstrct
     * @param array arguments
     * @return mixed
     */
    public function make(abstrct, array! arguments = []);

    /**
     * @param string key
     * @return mixed
     */
    public function __get(key);
    
    /**
     * @param string key
     * @return bool
     */
    public function __isset(key);

    /**
     * @param string key
     * @param value
     * @return void
     */
    public function __set(key, value);

    /**
     * @param string key
     * @return void
     */
    public function __unset(key);
}