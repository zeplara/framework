namespace Zeplara\Http;

use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\ResponseInterface;
use Psr\Http\message\ResponseFactoryInterface;

final class ResponseFactory implements ResponseFactoryInterface
{
    /**
     * @param int code
     * @param string reasonPhrase
     * @return ResponseInterface
     */
    public function createResponse(int! code = 200, string! reasonPhrase = "") -> <ResponseInterface>
    {
        return self::create(code, reasonPhrase);
    }

    /**
     * @param int code
     * @param string reasonPhrase
     * @param StreamInterface body
     * @param array headers
     * @param string protocolVersion
     * @return ResponseInterface
     */
    public static function create(int! code = 200, string! reasonPhrase = "", <StreamInterface> body = null, array! headers = [], string! protocolVersion = "1.1")
    {
        if typeof body == "NULL" {
            let body = StreamFactory::create("php://temp", "wb+");
        }

        return new Response(body, code, reasonPhrase, headers, protocolVersion);
    }
}