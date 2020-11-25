namespace Zeplara\Http;

use RuntimeException;
use InvalidArgumentException;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\StreamFactoryInterface;

final class StreamFactory implements StreamFactoryInterface
{
    /**
     * @param string content
     * @return StreamInterface
     */
    public function createStream(string! content = "") -> <StreamInterface>
    {
        var stream;

        let stream = this->createStreamFromFile("php://temp", "wb+");
        stream->write(content);

        return stream;
    }

    /**
     * @param string filename
     * @param string mode
     * @return StreamInterface
     */
    public function createStreamFromFile(string! filename, string! mode = "r") -> <StreamInterface>
    {
        var handler;

        error_clear_last();
        set_error_handler(function () {
            // silent fopen warning due in zephir is not supported error control operator (@)
        },  E_WARNING);

        let handler = fopen(filename, mode);

        restore_error_handler();

        if handler === false {
            throw new RuntimeException("The file couldn't be opened.");
        }

        return this->createStreamFromResource(handler);
    }

    /**
     * @param resource $resource
     * @return StreamInterface
     */
    public function createStreamFromResource($resource) -> <StreamInterface>
    {
        return new Stream($resource);
    }

    /**
     * @param string|resource filenameOrResourceOrContent
     * @param string|null mode
     * @return StreamInterface
     */
    public static function create(filenameOrResourceOrContent, mode = null)
    {
        var newSelf;

        let newSelf = new self;

        if typeof filenameOrResourceOrContent == "resource" {
            return newSelf->createStreamFromResource(filenameOrResourceOrContent);
        }

        if typeof filenameOrResourceOrContent != "string" {
            throw new InvalidArgumentException("The filenameOrResourceOrContent must be string or resource type.");
        }

        if typeof mode == "NULL" {
            return newSelf->createStream(filenameOrResourceOrContent);
        }

        return newSelf->createStreamFromFile(filenameOrResourceOrContent, mode);
    }
}