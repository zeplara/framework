namespace Zeplara\Routing;

use Zeplara\Interfaces\Routing\Regex as RegexContract;

final class Regex implements RegexContract
{
    /**
     * @var string
     */
    protected regex { get };
    /**
     * @var array
     */
    protected variables { get };

    /**
     * @param string regex
     * @param array variables
     */
    public function __construct(string! regex, array! variables = [])
    {
        let this->regex = regex,
            this->variables = variables; 
    }

    /**
     * @param string value
     * @return array
     */
    public function match(value)
    {
        var matches;

        preg_match(this->regex, value, matches);

        return matches;
    }
}