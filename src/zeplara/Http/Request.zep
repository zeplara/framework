namespace Zeplara\Http;

use InvalidArgumentException;
use Psr\Http\Message\UriInterface;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\RequestInterface;

class Request extends AbstractMessage implements RequestInterface
{
    /**
     * @var UriInterface 
     */
    protected uri { get };
    /**
     * @var string
     */
    protected method { get };
    /**
     * @var mixed
     */
    protected requestTarget { get };

    /**
     * @param string method
     * @param UriInterface uri
     * @param StreamInterface body
     * @param array headers
     * @param string protocolVersion
     */
    public function __construct
    (
        string! method,
        <UriInterface> uri,
        <StreamInterface> body,
        array! headers = [],
        string! protocolVersion = "1.1"
    )
    {
        let this->method = method,
            this->uri = uri;
            
        parent::__construct(body, headers, protocolVersion);
    }

    /**
     * @param requestTarget
     * @return static
     */
    public function withRequestTarget(requestTarget)
    {
        if typeof requestTarget != "string" {
            throw new InvalidArgumentException("The requestTarget should be string type.");
        }
        var $clone;
        let $clone = clone this,
            $clone->requestTarget = requestTarget;

        return $clone;
    }

    /**
     * @param string method
     * @return static
     */
    public function withMethod(method)
    {
        var $clone;
        let $clone = clone this,
            $clone->method = method;

        return $clone;
    }

    /**
     * @param UriInterface uri
     * @param bool preserveHost
     * @return static
     */
    public function withUri(<UriInterface> uri, preserveHost = false)
    {
        var $clone, host;
        let $clone = clone this,
            $clone->uri = uri;

        let host = uri->getHost();

        if host !== "" {
            var port;
            let port = uri->getPort();
            
            if typeof port != "NULL" {
                let host .= ":".port;
            }

            if preserveHost === false || $clone->hasHeader("host") === false {
                let $clone = $clone->withHeader("host", host);
            }
        }

        return $clone;
    }
}