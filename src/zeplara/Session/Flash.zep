namespace Zeplara\Session;

use RuntimeException;
use Zeplara\Support\AbstractRepository;
use Zeplara\Interfaces\Session\Manager;
use Zeplara\Interfaces\Session\Flash as FlashContract;

final class Flash extends AbstractRepository
{
    /**
     * @var string
     */
    protected name { get };
    /**
     * @var Manager
     */
    protected manager { get };

    /**
     * @param Manager manager
     * @param string name
     */
    public function __construct(<Manager> manager, name)
    {
        if manager->isStarted() === false {
            throw new RuntimeException("The session is not started.");
        }

        this->setItems(manager->get(name, []));
        manager->put(name);

        let this->manager = manager,
            this->name = name;
    }

    /**
     * @param string key
     * @param value
     * @return void
     */
    public function set(key, value)
    {
        parent::set(key, value);
        
        this->manager->set(this->resolveKey(key), value);
    }

    /**
     * @param string key
     * @return string
     */
    private function resolveKey(key)
    {
        return this->name.".".key;
    }
}