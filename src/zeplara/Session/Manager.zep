namespace Zeplara\Session;

use RuntimeException;
use Zeplara\Support\Str;
use SessionHandlerInterface;
use Zeplara\Support\AbstractRepository;
use Zeplara\Interfaces\Session\Manager as ManagerContract;

final class Manager extends AbstractRepository implements ManagerContract
{
    /**
     * @var string
     */
    protected id { get };
    /**
     * @var string
     */
    protected name { get };
    /**
     * @var string
     */
    protected prefix { get };
    /**
     * @var SessionHandlerInterface
     */
    protected handler { get };
    /**
     * @var bool
     */
    protected started = false;

    /**
     * Manager constructor.
     *
     * @param SessionHandlerInterface handler
     * @param name
     * @param string prefix
     * @param string id
     */
    public function __construct(<SessionHandlerInterface> handler, name, prefix = "", id = "")
    {
        let this->handler = handler,
            this->name = name;

        this->setPrefix(prefix);
        this->setId(id);
    }

    /**
     * @param id
     * @return void
     */
    final public function setId(id)
    {
        let this->id = (is_string(id) && ctype_alnum(id) === true && strlen(id) === 40) ? id : this->generateSessionId();
    }

    /**
     * @param string prefix
     * @return void
     */
    final public function setPrefix(prefix)
    {
        let this->prefix = trim(prefix, "\\/");
    }

    /**
     * @return bool
     */
    final public function isStarted()
    {
        return this->started;
    }

    /**
     * @return void
     */
    final public function start()
    {
        if this->started === true {
            throw new RuntimeException("Cannot start the session already started.");
        }

        var data;

        let data = this->handler->read(this->prefix.this->id);

        if data !== "" {
            error_clear_last();

            set_error_handler(function () {
                //
            });

            let data = unserialize(data);

            if data !== false {
                this->setItems(data);
            }

            restore_error_handler();
        }

        let this->started = true;
    }

    /**
     * @param bool destroy
     * @return bool
     */
    final public function regenerate(destroy = false)
    {
        if this->started === false {
            throw new RuntimeException("Cannot regenerate the session id before start the session.");
        }

        if destroy === true {
            this->handler->destroy(this->prefix.this->id);
        }

        this->setId(this->generateSessionId());
    }

    /**
     * @return void
     */
    final public function save()
    {
        if this->started === false {
            throw new RuntimeException("Cannot save the session before start the session.");
        }

        this->handler->write(this->prefix.this->id, serialize(this->items));

        let this->started = false;
    }

    /**
     * @return string
     */
    private function generateSessionId()
    {
        return Str::random(40);
    }
}