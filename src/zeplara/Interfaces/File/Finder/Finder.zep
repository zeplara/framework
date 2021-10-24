namespace Zeplara\Interfaces\File\Finder;

use IteratorAggregate;

interface Finder extends IteratorAggregate
{
    /**
     * @return string
     */
    public function getPath();

    /**
     * @return int
     */
    public function getDepth();

    /**
     * @return array
     */
    public function getFilters();

    /**
     * @var int depth
     * @return void
     */
    public function setDepth(int! depth);

    /**
     * @var array filters
     * @return void
     */
    public function setFilters(array! filters);

    /**
     * @param Filter filter
     * @return void
     */
    public function addFilter(<Filter> filter);
}