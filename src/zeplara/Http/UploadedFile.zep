namespace Zeplara\Http;

use RuntimeException;
use InvalidArgumentException;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\UploadedFileInterface;

final class UploadedFile implements UploadedFileInterface
{
    /**
     * @var bool
     */
    protected moved = false;
    /**
     * @var StreamInterface
     */
    protected stream { get };
    /**
     * @var int|null
     */
    protected size { get };
    /**
     * @var int
     */
    protected error { get };
    /**
     * @var string
     */
    protected clientFilename { get };
    /**
     * @var string
     */
    protected clientMediaType { get };
    /**
     * @var array
     */
    private static errors = [
        0 : "There is no error, the file uploaded with success.",
        1 : "The uploaded file exceeds the size directive in php.ini.",
        2 : "The uploaded file exceeds the size directive that was specified in the HTML form.",
        3 : "The uploaded file was only partially uploaded.",
        4 : "No file was uploaded.",
        6 : "Missing a temporary folder.",
        7 : "Failed to write file to disk.",
        8 : "A PHP extension stopped the file upload."
    ];

    /**
     * @param StreamInterface stream
     * @param string clientFilename
     * @param string clientMediaType
     * @param int size
     * @param int error
     */
    public function __construct
    (
        <StreamInterface> stream,
        string! clientFilename,
        string! clientMediaType,
        size,
        int! error = 0
    )
    {
        if !isset self::errors[error] {
            throw new InvalidArgumentException("The error uploaded file is invalid.");
        }

        if !is_int(size) {
            if typeof size != "NULL" {
                throw new InvalidArgumentException("The size must be null or int.");
            } else {
                let size = stream->getSize();
            }
        }

        let this->stream = stream,
            this->size = size,
            this->error = error,
            this->clientFilename = clientFilename,
            this->clientMediaType = clientMediaType;
    }

    /**
     * @var string targetPath
     */
    public function moveTo(targetPath)
    {
        var handle, size;

        if this->error !== 0 {
            throw new RuntimeException(self::errors[this->error]);
        }

        if this->moved === true {
            throw new RuntimeException("The file has been moved.");
        }

        if typeof targetPath != "string" || targetPath === "" {
            throw new InvalidArgumentException("The target path should be string type.");
        }
        
        if this->size {
            let size = this->size;
        } else {
            let size = 1048576;
        }

        error_clear_last();
        set_error_handler(function () {
            // silent fopen warning due in zephir is not supported error control operator (@)
        },  E_WARNING);

        let handle = fopen(targetPath, "wb+");

        restore_error_handler();

        if handle === false {
            throw new RuntimeException("The target path is not writable.");
        }

        this->stream->rewind();

        while !this->stream->eof() {
            fwrite(handle, this->stream->read(size));
        }

        fclose(handle);

        let this->moved = true;
    }

    /**
     * @return bool
     */
    public function isMoved()
    {
        return this->moved;
    }
}