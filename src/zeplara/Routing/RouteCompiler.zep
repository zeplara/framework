namespace Zeplara\Routing;

use Zeplara\Interfaces\Routing\Route as RouteContract;
use Zeplara\Interfaces\Routing\RouteCompiler as RouteCompilerContract;

final class RouteCompiler implements RouteCompilerContract
{
    /**
     * @var int
     */
    const MAX_VARIABLE_LEN = 32;
    
    /**
     * @param RouteContract route
     * @return CompiledRoute
     */
    public static function compile(<RouteContract> route)
    {
        var requirements;
        let requirements = route->requirements();

        return new CompiledRoute(
            self::parseRegex(route->host(), ".", "sDui", requirements),
            self::parseRegex(route->getPattern(), "/", "sDu", requirements)
        );
    }

    /**
     * @param string pattern
     * @param string separator
     * @param string flags
     * @param array requirements
     * @return Regex
     * @throws RouteCompilerException
     */
    private static function parseRegex(pattern, separator, flags, requirements = [])
    {
        var i, match, requirement, regex, regexp, matches, variables, prevIdx, nextIdx, lastIdx, separatorRegex, nextSeparatorOfRequirement;
        
        let regex = "",
            separator = preg_quote(separator),
            variables = [],
            separatorRegex = "/|,|;|\\.|\\:|\\-|_|~|\\+|\\*|\\=|@|\\|";
        
        preg_match_all("#((?>(?:(?!\\{\w+\\?{0,}\\}).)*(?<!%1$s))*)((?:%1$s)*)\\{(\w+)((?:\\?)*)\\}((?:%1$s)*)((?:(?:(?!\\{\w+\\?{0,}\\}).)*(?(?!$)(?<!%1$s)))*)#"->format(separatorRegex), pattern, matches, PREG_OFFSET_CAPTURE | PREG_SET_ORDER);
        
        let lastIdx = count(matches) - 1;

        for i, match in matches {
            let nextIdx = i + 1,
                prevIdx = i - 1;

            if match[4][0] !== "" && (isset matches[nextIdx] && matches[nextIdx][4][0] === "") {
                throw new RouteCompilerException("Cannot set optional pattern \"{%s}\" when the next pattern \"{%s}\" is required."->format(match[3][0].match[4][0], matches[nextIdx][3][0]));
            }

            if strlen(match[3][0]) > self::MAX_VARIABLE_LEN {
                throw new RouteCompilerException("Variable \"%s\" is too long. maximum is %d characters."->format(match[3][0], self::MAX_VARIABLE_LEN));
            }

            if (bool) preg_match("/^\d/", match[3][0]) === true {
                throw new RouteCompilerException("Variable \"%s\" cannot start with digit."->format(match[3][0]));
            }

            if in_array(match[3][0], variables) === true {
                throw new RouteCompilerException("Variable \"%s\" must be unique."->format(match[3][0]));
            }

            let variables[] = match[3][0];

            if match[1][0] !== "" {
                let match[1][0] = preg_quote(match[1][0]);
            }

            if match[2][0] !== "" {
                let match[2][0] = preg_quote(match[2][0]);
                if (match[4][0] !== "" && ((match[1][0] !== "" && match[6][0] !== "") || (isset matches[prevIdx] && matches[prevIdx][6][0] !== "" && (match[6][0] !== "" || i !== lastIdx)) || (i === 0 && i === lastIdx && match[1][0] !== "" && match[6][0] !== ""))) || (i === 0 && match[1][0] === "") || (match[1][0] !== "" && isset matches[nextIdx] && matches[nextIdx][2][0] === "" && self::hasNextStaticPrefixOnNextMatch(nextIdx, lastIdx, matches) === true) || match[4][0] === "" {
                    let match[1][0] = match[1][0].match[2][0],
                        match[2][2] = preg_quote(match[2][0]),
                        match[2][0] = "";
                }
            }

            if match[5][0] !== "" {
                if match[6][0] === "" && (isset matches[nextIdx] && matches[nextIdx][4][0] !== "" && matches[nextIdx][2][0] === "" && self::hasNextStaticPrefixOnNextMatch(nextIdx, lastIdx, matches) === false) {
                    let matches[nextIdx][2][0] = match[5][0],
                        match[5][2] = preg_quote(match[5][0]),
                        match[5][0] = "";
                } elseif match[4][0] !== "" && ((match[2][0] === "" && !isset match[2][2]) && match[6][0] !== "" && self::hasStaticPrefixWithoutSeparatorOnPrevMatch(prevIdx, matches) || match[1][0] !== "" && match[2][0] === "" && !isset match[2][2] && match[6][0] !== "") {
                    let match[6][0] = match[5][0].match[6][0],
                        match[5][2] = preg_quote(match[5][0]),
                        match[5][0] = "";
                } else {
                    let match[5][0] = preg_quote(match[5][0]);
                }
            }

            if match[6][0] !== "" {
                let match[6][0] = preg_quote(match[6][0]);
            }

            if fetch requirement, requirements[match[3][0]] {
                var count;

                if substr(requirement, 0, 1) == "^" {
                    let requirement = (string) substr(requirement, 1);
                }

                if substr(requirement, -1) == "$" {
                    let requirement = (string) substr(requirement, 0, -1);
                }

                do {
                    let requirement = preg_replace_callback("#\\(((?!\\?\\:|\\*\\)|\\+\\)|\\?\\)).+)\\)#", function (matches) {
                        return "(?:%s)"->format(matches[1]);
                    }, requirement, -1, count);
                } while (count);
            } else {
                let nextSeparatorOfRequirement = (isset match[5][2] ? match[5][2] : match[5][0]);
                if strpos(nextSeparatorOfRequirement, separator) === false {
                    let nextSeparatorOfRequirement = separator.nextSeparatorOfRequirement;
                } else {
                    let nextSeparatorOfRequirement = implode("", array_unique(str_split(separator.nextSeparatorOfRequirement)));
                }

                let requirement = "[^%s]+"->format(nextSeparatorOfRequirement);

                if (match[5][0] !== "" || isset match[5][2] === true) || (i === lastIdx && match[6][0] === "") {
                    let requirement .= "+";
                }
            }

            let regexp = "%s(?P<%s>%s)%s"->format(match[2][0], match[3][0], requirement, match[5][0]);

            if match[2][0] !== "" || (match[5][0] !== "" && match[4][0] !== "") {
                let regexp = "(?:%s)"->format(regexp);
            }

            if match[4][0] !== "" {
                let regexp .= "?";
            }

            let regex .= match[1][0].regexp.match[6][0];
        }

        if regex === "" {
            let regex = preg_quote(pattern);
        }

        return new Regex("{^%s$}%s"->format(regex, flags), variables);
    }

    /**
     * @param nextIdx
     * @param lastIdx
     * @param matches
     * @return bool
     */
    private static function hasNextStaticPrefixOnNextMatch(nextIdx, lastIdx, matches)
    {
        while nextIdx <= lastIdx {
            if matches[nextIdx][6][0] !== "" {
                return true;
            }
            
            let nextIdx++;
        }

        return false;
    }

    /**
     * @param prevIdx
     * @param matches
     * @return bool
     */
    private static function hasStaticPrefixWithoutSeparatorOnPrevMatch(prevIdx, matches)
    {
        var nextIdx, lastIdx;
        
        let lastIdx = prevIdx;

        while prevIdx >= 0 {
            if (matches[prevIdx][1][0] !== "" && matches[prevIdx][2][0] === "" && (matches[prevIdx][5][0] === "" || matches[prevIdx][6][0] === "")) || matches[prevIdx][6][0] !== "" {

                let nextIdx = prevIdx + 1;
            
                while nextIdx <= lastIdx {
                    if matches[nextIdx][2][0] !== "" {
                        return false;
                    }
                    let nextIdx++;   
                }

                return true;
            }
            
            let prevIdx--;
        }

        return false;
    }
}