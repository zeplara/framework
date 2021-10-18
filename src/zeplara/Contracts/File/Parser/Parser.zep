namespace Zeplara\Contracts\File\Parser;

interface Parser
{
    /**
     * @param string contents
     * @return mixed
     * @throws ParserException
     */
    public function parse(string! contents);

    /**
     * @param string file
     * @return mixed
     * @throws \InvalidArgumentException|ParserException
     */
    public function parseFile(string! file);
}