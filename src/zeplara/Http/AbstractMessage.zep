namespace Zeplara\Http;

use Zeplara\Support\Arr;
use Zeplara\Support\Str;
use InvalidArgumentException;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\MessageInterface;

abstract class AbstractMessage implements MessageInterface
{
    /**
     * @var StreamInterface
     */
    protected body { get };
    /**
     * @var array
     */
    protected headers { get };
    /**
     * @var string
     */
    protected protocolVersion { get };

    /**
     * @param StreamInterface body
     * @param array headers
     * @param string protocolVersion
     */
    public function __construct
    (
        <StreamInterface> body, 
        array! headers = [], 
        string! protocolVersion = "1.1"
    )
    {
        var key, value;

        this->assertProtocolVersion(protocolVersion);

        let this->body = body,
            this->protocolVersion = protocolVersion;

        // currently in zephir is not fetch the default property when we declare the get shortcut.
        let this->headers = [];

        for key, value in headers {
            let this->headers[Str::kebab(key)] = Arr::wrap(value);
        }
    }

    /**
     * @param StreamInterface body
     * @return static
     */
    public function withBody(<StreamInterface> body)
    {
        var $clone;
        let $clone = clone this,
            $clone->body = body;

        return $clone;
    }

    /**
     * @param string name
     * @return bool
     */
    public function hasHeader(name)
    {
        return isset this->headers[Str::kebab(name)];
    }

    /**
     * @param string name
     * @return array
     */
    public function getHeader(name)
    {
        var headers;
        
        if fetch headers, this->headers[Str::kebab(name)] {
            return Arr::wrap(headers);
        }

        return [];
    }

    /**
     * @param string name
     * @return string
     */
    public function getHeaderLine(name)
    {
        return implode(", ", Arr::flatten(this->getHeader(name)));
    }

    /**
     * @param string name
     * @param value
     * @return static
     */
    public function withHeader(name, value)
    {
        var $clone;
        let $clone = clone this,
            name = Str::kebab(name);

        let $clone->headers[name] = Arr::wrap(value);

        return $clone;
    }

    /**
     * @param string name
     * @param value
     * @return static
     */
    public function withAddedHeader(name, value)
    {
        return this->withHeader(name, array_merge(this->getHeader(name), Arr::wrap(value)));
    }

    /**
     * @param string name
     * @return static
     */
    public function withoutHeader(name)
    {
        var $clone;
        let $clone = clone this;

        unset $clone->headers[Str::kebab(name)];
        
        return $clone;
    }

    /**
     * @param string version
     * @return static
     */
    public function withProtocolVersion(version)
    {
        var $clone;

        this->assertProtocolVersion(version);
        
        let $clone = clone this,
            $clone->protocolVersion = version;
        
        return $clone;
    }

    /**
     * @param version
     * @return void
     */
    private function assertProtocolVersion(version)
    {
        if !in_array(version, ["1.0", "1.1", "2.0", "2"]) {
            throw new InvalidArgumentException("The protocol version is invalid.");
        }
    }
}