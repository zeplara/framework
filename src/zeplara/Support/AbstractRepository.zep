namespace Zeplara\Support;

abstract class AbstractRepository
{
    /**
     * @var array
     */
    protected items = [] { get, set };

    /**
     * @param key
     * @return bool
     */
    public function has(key)
    {
        return Arr::has(this->items, key);
    }

    /**
     * @param key
     * @param null defaultValue
     * @return mixed
     */
    public function get(key, defaultValue = null)
    {
        return Arr::get(this->items, key, defaultValue);
    }

    /**
     * @param key
     * @param value
     * @return void
     */
    public function set(key, value)
    {
        let this->items = Arr::set(this->items, key, value);
    }

    /**
     * @param key
     * @return void
     */
    public function put(key)
    {
        let this->items = Arr::put(this->items, key);
    }

    /**
     * @param offset
     * @return bool
     */
    public function offsetExists(offset)
    {
        return this->has(offset);
    }

    /**
     * @param offset
     * @return mixed
     */
    public function offsetGet(offset)
    {
        return this->get(offset);
    }

    /**
     * @param offset
     * @param value
     * @return void
     */
    public function offsetSet(offset, value)
    {
        this->set(offset, value);
    }

    /**
     * @param offset
     * @return void
     */
    public function offsetUnset(offset)
    {
        this->put(offset);
    }

    /**
     * @param string key
     * @return mixed
     */
    public function __get(key)
    {
        return this->get(key);
    }
    
    /**
     * @param string key
     * @return bool
     */
    public function __isset(key)
    {
        return this->has(key);
    }

    /**
     * @param string key
     * @param value
     * @return void
     */
    public function __set(key, value)
    {
        this->set(key, value);
    }

    /**
     * @param string key
     * @return void
     */
    public function __unset(key)
    {
        this->put(key);
    }
}