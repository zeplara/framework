namespace Zeplara\Support\Facades;

use RuntimeException;

abstract class Facade
{
    /**
     * {@inheritdoc}
     */
    private function __construct()
    {
        //
    }

    /**
     * @throws RuntimeException
     */
    protected static function getAccessor()
    {
        throw new RuntimeException("%s class does not implement %s method."->format(get_called_class(), __FUNCTION__));
    }
}