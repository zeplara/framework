namespace Zeplara\Contracts;

use Zeplara\Contracts\Container\Container;

interface Application extends Container
{
    /**
     * @var string
     */
    const VERSION = "1.0.0";

    /**
     * @return string
     */
    public function getBasePath();
}