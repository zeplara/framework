namespace Zeplara\Http;

use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\UploadedFileInterface;
use Psr\Http\Message\UploadedFileFactoryInterface;

final class UploadedFileFactory implements UploadedFileFactoryInterface
{
    /**
     * @param StreamInterface stream
     * @param int size
     * @param int error
     * @param string clientFilename
     * @param string clientMediaType
     * @return UploadedFileInterface
     */
    public function createUploadedFile(
        <StreamInterface> stream,
        int size = null,
        int error = 0,
        string clientFilename = null,
        string clientFileMediaType = null
    ) -> <UploadedFileInterface>
    {
        return self::create(stream, clientFilename, clientFileMediaType, size, error);
    }

    /**
     * @param StreamInterface stream
     * @param int size
     * @param int error
     * @param string clientFilename
     * @param string clientMediaType
     * @return UploadedFileInterface
     */
    public static function create(
        <StreamInterface> stream,
        int size = null,
        int error = 0,
        string clientFilename = null,
        string clientFileMediaType = null
    ) -> <UploadedFileInterface>
    {
        return new UploadedFile(stream, clientFilename, clientFileMediaType, size, error);
    }
}