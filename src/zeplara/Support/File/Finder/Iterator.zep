namespace Zeplara\Support\File\Finder;

use FilterIterator;
use UnexpectedValueException;
use Iterator as IteratorContract;

final class Iterator extends FilterIterator
{   
    /**
     * @var array
     */
    protected filters { get };

    /**
     * @param IteratorContract iterator
     * @param array filters
     */
    public function __construct(<IteratorContract> iterator, array! filters)
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
            if typeof filter != "object" || (filter instanceof AbstractFilter) === false {
                throw new UnexpectedValueException("The filter must be instanceof %s\\AbstractFilter"->format(__NAMESPACE__));
            }
            if filter->accept(fileInfo) === false {
                return false;
            }
        }

        return true;
    }
}