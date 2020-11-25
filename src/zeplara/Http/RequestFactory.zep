namespace Zeplara\Http;

use Psr\Http\Message\UriInterface;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\RequestInterface;
use Psr\Http\Message\RequestFactoryInterface;

final class RequestFactory implements RequestFactoryInterface
{
    /**
     * @param string method
     * @param string|UriInterface uri
     * @return RequestInterface
     */
    public function createRequest(string! method, uri) -> <RequestInterface>
    {
        return self::create(method, uri);
    }

    /**
     * @param string method
     * @param string|UriInterface uri
     * @param StreamInterface body
     * @param array headers
     * @param string protocolVersion
     * @return RequestInterface
     */
    public static function create
    (
        string! method = "GET", 
        uri = null,
        <StreamInterface> body = null, 
        array! headers = [], 
        string! protocolVersion = "1.1"
    )
    {
        if (uri instanceof UriInterface) === false {
            let uri = UriFactory::create(uri);
        }
        
        if typeof body == "NULL" {
            let body = StreamFactory::create("php://temp", "wb+");
        }

        return new Request(method, uri, body, headers, protocolVersion);
    }
}