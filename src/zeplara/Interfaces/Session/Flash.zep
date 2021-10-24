namespace Zeplara\Interfaces\Session;

use Zeplara\Interfaces\Repository;

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