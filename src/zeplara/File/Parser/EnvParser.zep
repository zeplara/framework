namespace Zeplara\File\Parser;

use Zeplara\Support\Arr;
use Zeplara\Support\Str;
use Zeplara\Interfaces\File\Parser\Parser;

final class EnvParser extends AbstractParser
{   
    /**
     * @var string
     */
    const VARIABLE_VALUE_REGEX = "\\$\\{([a-zA-Z0-9_.]+)\\}";

    /**
     * @var array
     */
    private static compilerMethodsCache = [];

    /**
     * @param string contents
     * @return array
     * @throws ParserException
     */
    public function parse(string! contents)
    {
        var i, x, y, key, val, value, 
            lines, parts, values, rawKey, 
            compiled, linesCount, shouldSkipKey;

        let values = [],
            lines = new LinesIterator(contents),
            linesCount = lines->count();

        for i, _ in lines {
            if trim(lines[i]) !== "" {
                let x = i + 1,
                    parts = array_map("trim", explode("=", lines[i], 2)),
                    rawKey = trim(Arr::get(parts, 0, "")),
                    key = trim(this->clearComments(rawKey)),
                    shouldSkipKey = rawKey !== "" && key === "",
                    value = trim(this->clearComments(Arr::get(parts, 1, ""))),
                    val = value,
                    lines[i] = "%s=%s"->format(rawKey, value);

                if shouldSkipKey === false && (bool) preg_match("~\\A[a-zA-Z0-9_.]+\\z~", key) === false {
                    this->throwParserException("Syntax error [%s], is invalid key."->format(key), "", i + 1);
                }

                while x < linesCount {
                    let val .= "\n" . lines[x],
                        x++;
                }

                let compiled = this->compileValue(val, values, i + 1);
                
                if typeof compiled == "NULL" {
                    this->throwParserExceptionUIMV(lines[i], i + 1);
                }

                let x = i,
                    y = compiled->getRawValue()->getLines()->count() + i - 1;

                while x <= y {

                    if x === y {
                        if trim(substr(lines[x], strlen(Arr::last((array) compiled->getRawValue()->getLines())) + (x === i ? (strlen(rawKey) + 1) : 0))) !== "" {
                            this->throwParserExceptionUIMV(lines[x], i + 1);
                        }
                    }
                            
                    let lines[x] = "",
                        x++;
                }

                let value = compiled->getValue();

                if shouldSkipKey === false {
                    let values[key] = value;
                }

            }
        }

        return values;
    }

    /**
     * @param string value
     * @param array values
     * @param int line
     * @return CompiledValue|null
     */
    private function compileArrayValue(value, values, line)
    {
        var matches;
        
        preg_match("~\\[((?>\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^\\[\\]]|(?R))*)\\]~", value, matches, PREG_OFFSET_CAPTURE);

        if matches && matches[0][1] === 0 {
            var match, items, contents, boundary, boundaries, compiled, signedKey, contentsLen;

            let items = [],
                signedKey = 0,
                boundaries = [],
                value = matches[0][0],
                contents = this->clearComments(matches[1][0]),
                contentsLen = strlen(contents);

            preg_match_all("~\\[(?>\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^\\[\\]]|(?R))*\\]~", contents, matches, PREG_OFFSET_CAPTURE | PREG_SET_ORDER);

            for match in matches {
                let boundary = "--boundary-%s--"->format(Str::random(32)),
                    boundaries[boundary] = match[0][0],
                    contents = substr_replace(contents, boundary, match[0][1] + (strlen(contents) - contentsLen), strlen(match[0][0]));
            }

            preg_match_all("~\s*(?:((?:\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^\\:,])++)\\:)?(?:((?:\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^,])++),?)\s*~smu", contents, matches, PREG_OFFSET_CAPTURE | PREG_SET_ORDER);

            for match in matches {
                if trim(match[0][0]) === "" {
                    continue;
                }
                
                let match[1] = Arr::get(match, 1, ["", -1]),
                    match[2] = Arr::get(match, 2, ["", -1]),
                    match[0][2] = this->findLineByPos(contents, match[0][1]) + line - 1,
                    match[1][2] = this->findLineByPos(contents, match[1][1]) + line - 1,
                    match[2][2] = this->findLineByPos(contents, match[2][1]) + line - 1;
                
                let match[1][0] = trim(match[1][0]),
                    match[2][0] = trim(match[2][0]);

                if match[2][0] === "" {
                    this->throwParserException("Syntax error [%s]."->format(match[0][0]), "", match[0][2]);
                }

                let match[2][0] = Arr::get(boundaries, match[2][0], match[2][0]);

                if match[1][1] === -1 {
                    while isset items[signedKey] {
                        let signedKey++;
                    }

                    let match[1][0] = signedKey,
                        signedKey++;
                } elseif is_numeric(match[1][0]) {
                    let signedKey = match[1][0] + 1;
                }

                let compiled = this->compileValue((string) match[1][0], values, match[1][2]);

                if typeof compiled == "NULL" || trim(substr(match[1][0], strlen(compiled->getRawValue()->getValue()))) !== "" {
                    this->throwParserException("Syntax error [%s]."->format(match[1][0]), "", match[1][2]);
                } else {
                    let match[1][0] = compiled->getValue();
                }

                let compiled = this->compileValue(match[2][0], values, match[2][2]);

                if typeof compiled == "NULL" || trim(substr(match[2][0], strlen(compiled->getRawValue()->getValue()))) !== "" {
                    this->throwParserException("Syntax error [%s]."->format(match[2][0]), "", match[2][2]);
                } else {
                    let match[2][0] = compiled->getValue();
                }

                let items[match[1][0]] = match[2][0];
            }

            return new CompiledValue(items, value);
        }
    }

    /**
     * @param string value
     * @param array values
     * @param int line
     * @return CompiledValue|null
     */
    private function compileStringValue(value, values, line)
    {
        var matches;

        preg_match("~^(?:\"([^\"\\\\]*(?:\\\\.[^\"\\\\]*)*)\"|'([^'\\\\]*(?:\\\\.[^'\\\\]*)*)')~", value, matches);

        if matches {
            if isset matches[2] {
                let matches[1] = matches[2];
            }

            error_clear_last();

            set_error_handler(function () use (line) {
                // Got warning when using func_get_arg()
                // Got error variable array when access index from arguments of func_get_args()
                throw new \Zeplara\File\Parser\ParserException(\Zeplara\Support\Arr::get(func_get_args(), 1), "", line);
            });

            let matches[1] = preg_replace_callback("~%s~"->format(self::VARIABLE_VALUE_REGEX), function (matches) use (values) {
                return (string) \Zeplara\Support\Arr::get(values, matches[1], matches[0]);
            }, matches[1]);

            restore_error_handler();

            return new CompiledValue(stripslashes(matches[1]), matches[0]);
        }
    }

    /**
     * @param string value
     * @param array values
     * @param int line
     * @return CompiledValue|null
     */
    private function compileBooleanValue(value, values, line)
    {
        let value = Str::lower(Arr::first(explode("\n", value)));
        
        if in_array(value, ["true", "false"]) {
            return new CompiledValue(value == "true" ? true : false, value);
        }
    }

    /**
     * @param string value
     * @param array values
     * @param int line
     * @return CompiledValue|null
     */
    private function compileNullValue(value, values, line)
    {
        let value = Str::lower(Arr::first(explode("\n", value)));

        if in_array(value, ["", "null"]) {
            return new CompiledValue(null, value);
        }
    }

    /**
     * @param string value
     * @param array values
     * @param int line
     * @return CompiledValue|null
     */
    private function compileIntegerOrFloatValue(value, values, line)
    {
        let value = Arr::first(explode("\n", value));

        if is_numeric(value) {
            return new CompiledValue(((bool) preg_match("~^[-\\+]?(?:(?:\\.[0-9]+)|(?:[0-9]+\\.(?:[0-9]+)?)|(?:(?:[0-9]+[eE][0-9]+)))$~", value) ? (float) value : (int) value), value);
        }
    }

    /**
     * @param string value
     * @param array values
     * @param int line
     * @return CompiledValue|null
     */
    private function compileVariableValue(value, values, line)
    {
        var matches;
    
        let value = Arr::first(explode("\n", value));
        
        preg_match("~^%s$~"->format(self::VARIABLE_VALUE_REGEX), value, matches, PREG_OFFSET_CAPTURE);

        if matches && Arr::has(values, matches[1][0]) {
            return new CompiledValue(Arr::get(values, matches[1][0]), matches[0][0]);
        }
    }

    /**
     * @param string value
     * @param int line
     * @throws ParserException
     */
    private function throwParserExceptionUIMV(value, line)
    {
        this->throwParserException("Syntax error [%s], Unexpected Inline Multiple Variable."->format(value), "", line);
    }

    /**
     * @param string value
     * @param array values
     * @param int line
     * @return CompiledValue|null
     */
    private function compileValue(value, values, line)
    {
        if empty self::compilerMethodsCache {
            let self::compilerMethodsCache = preg_grep("~compile.+Value~i", get_class_methods(this));
        }

        var compiler, compiled;

        for compiler in self::compilerMethodsCache {
            let compiled = call_user_func([this, compiler], value, values, line);

            if typeof compiled != "NULL" {
                return compiled;
            }
        }

        let value = Arr::first(explode("\n", value));

        if strpos(value, " ") === false {
            return new CompiledValue(value, value);
        }
    }

    /**
     * @param string value
     * @return string
     */
    private function clearComments(value)
    {
        return preg_replace("~(?:\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*')(*SKIP)(*FAIL)|\\#(?:\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^\\#\\\\\n]|(?:[^\\#\\\\\n]|\\\\.)*)*\\#?~smu", "", value);
    }

    /**
     * @param string value
     * @param int pos
     * @return int
     */
    private function findLineByPos(value, pos)
    {
        let pos = pos <= 0 ? 1 : pos,
            value = Arr::get(str_split(value, pos), 0, "");

        return strlen(value) - strlen(str_replace("\n", "", value)) + 1;
    }
}