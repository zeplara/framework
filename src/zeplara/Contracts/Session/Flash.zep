namespace Zeplara\Contracts\Session;

use Zeplara\Contracts\Repository;

interface Flash extends Repository
{
    /**
     * @return string
     */
    public function getName();

    /**
     * @return Manager
     */
    public function getManager();
}