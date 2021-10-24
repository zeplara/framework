namespace Zeplara\Interfaces;

use ArrayAccess;

interface Repository extends ArrayAccess
{
    /**
     * @return array
     */
    public function getItems();

    /**
     * @param array items
     * @return void
     */
    public function setItems(array! items);

    /**
     * @param key
     * @return bool
     */
    public function has(key);

    /**
     * @param key
     * @param null defaultValue
     * @return mixed
     */
    public function get(key, defaultValue = null);

    /**
     * @param key
     * @param value
     * @return void
     */
    public function set(key, value);

    /**
     * @param key
     * @return void
     */
    public function put(key);


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