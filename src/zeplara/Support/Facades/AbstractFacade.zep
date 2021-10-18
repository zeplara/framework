namespace Zeplara\Support\Facades;

use RuntimeException;
use Zeplara\Contracts\Container\Container;

abstract class AbstractFacade
{
    protected static container;
    
    /**
     * {@inheritdoc}
     */
    private function __construct()
    {
        //
    }

    /**
     * @param Container container
     * @return void
     */
    public static function setContainer(<Container> container)
    {
        let self::container = container;
    }

    public static function __callStatic(name, array paramters = [])
    {
        
    }

    /**
     * @throws RuntimeException
     */
    protected static function getAccessor()
    {
        throw new RuntimeException("%s class does not implement %s method."->format(get_called_class(), __FUNCTION__));
    }
}