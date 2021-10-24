namespace Zeplara\File\Finder;

use FilterIterator;
use UnexpectedValueException;
use Iterator as BaseIteratorContract;
use Zeplara\Interfaces\File\Finder\Filter;
use Zeplara\Interfaces\File\Finder\Iterator as IteratorContract;

final class Iterator extends FilterIterator implements IteratorContract
{   
    /**
     * @var array
     */
    protected filters { get };

    /**
     * @param BaseIteratorContract iterator
     * @param array filters
     */
    public function __construct(<BaseIteratorContract> iterator, array! filters)
    {
        let this->filters = filters;
        parent::__construct(iterator);
    }

    /**
     * @return bool
     */
    public function accept()
    {
        return this->isAccepted(this->current());
    }

    /**
     * @param SplFileInfo fileInfo
     * @return bool
     */
    private function isAccepted(<SplFileInfo> fileInfo)
    {
        var filter;

        for filter in this->filters {
            if is_callable(filter) {
                let filter = FilterFactory::callback(filter);
            }
            if typeof filter != "object" || (filter instanceof Filter) === false {
                throw new UnexpectedValueException("The filter must be instanceof \\Zeplara\\Contracts\\File\\Finder\\Filter");
            }
            if filter->accept(fileInfo) === false {
                return false;
            }
        }

        return true;
    }
}