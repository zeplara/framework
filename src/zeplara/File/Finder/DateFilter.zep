namespace Zeplara\File\Finder;

use DateTimeInterface;
use InvalidArgumentException;
use Zeplara\Interfaces\File\SplFileInfo;
use Zeplara\Interfaces\File\Finder\Filter;

final class DateFilter implements Filter
{
    /**
     * @var mixed
     */
    private time;
    /**
     * @var string
     */
    private operator;
    
    /**
     * DateFilter constructor.
     *
     * @param time
     * @param operator
     */
    public function __construct(time, operator)
    {
        if is_numeric(time) === false {
            let time = strtotime(time);
            if time === false {
                throw new InvalidArgumentException("The time is invalid type.");
            }
        }

        if time instanceof DateTimeInterface {
            let time = time->format("U");
        }

        let this->time = time,
            this->operator = operator;
    }

    /**
     * @param SplFileInfo fileInfo
     * @return bool
     */
    public function accept(<SplFileInfo> fileInfo) -> bool
    {
        var time, result;

        let time = fileInfo->getMTime();
        
        switch this->operator {
            case "<":
                let result = time < this->time;
                break;
            case ">":
                let result = time > this->time;
                break;
            case "<=":
                let result = time <= this->time;
                break;
            case ">=":
                let result = time >= this->time;
                break;
            case "!=":
            case "<>":
                let result = time != this->time;
                break;
            case "!==":
                let result = time !== this->time;
                break;
            case "==":
                let result = time == this->time;
                break;
            case "===":
                let result = time === this->time;
                break;
            default:
                throw new InvalidArgumentException("The operator is invalid.");
        }

        return result;
    }
}