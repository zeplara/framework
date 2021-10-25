namespace Zeplara\Support\Facades;

use RuntimeException;
use Zeplara\Interfaces\Container\Container;

abstract class AbstractFacade
{
    /**
     * @var Container|null
     */
    protected static container;
    /**
     * @var array
     */
    private static instances;
    
    /**
     * {@inheritdoc}
     */
    private function __construct()
    {
        //
    }

    /**
     * @return object
     * @throws RuntimeException
     */
    final public static function getRoot()
    {
        var accessor;

        let accessor = static::getAccessor();

        if typeof accessor == "object" {
            return accessor;
        }

        if typeof self::container == "NULL" {
            throw new RuntimeException("The container has not been set.");
        }

        if !isset self::instances[accessor] {
            let self::instances[accessor] = self::container->make(accessor);
        }

        return self::instances[accessor];
    }

    /**
     * @param Container container
     * @return void
     */
    final public static function setContainer(<Container> container)
    {
        let self::container = container;
    }

    /**
     * @param string name
     * @param array arguments
     * @return mixed
     */
    final public static function __callStatic(name, array! arguments = [])
    {
        return call_user_func_array([self::getRoot(), name], arguments);
    }

    /**
     * @throws RuntimeException
     */
    protected static function getAccessor() -> object|string
    {
        throw new RuntimeException("%s class does not implement %s method."->format(get_called_class(), __FUNCTION__));
    }
}