namespace Zeplara\Support\File\Finder;

use DateTimeInterface;
use InvalidArgumentException;
use Zeplara\Support\File\SplFileInfo;

final class DateFilter extends AbstractFilter
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
     * @param null operator
     */
    public function __construct(time, operator = null)
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