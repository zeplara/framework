namespace Zeplara\Http;

use RuntimeException;
use Psr\Http\Message\StreamInterface;

final class Stream implements StreamInterface
{
    /**
     * @var int|null
     */
     protected size;
     /**
      * @var bool
      */
     protected seekable;
     /**
      * @var bool
      */
     protected readable;
     /**
      * @var bool
      */
     protected writable;
     /**
      * @var $resource
      */
     private $resource;

    /**
     * Stream constructor.
     *
     * @param resource $resource
     */
    public function __construct(resource! $resource)
    {
        var meta;
        let this->$resource = $resource,
            meta = stream_get_meta_data($resource);
        
        if isset meta["seekable"] {
            let this->seekable = meta["seekable"];
        }

        let this->readable = (bool) preg_match("/r|a\+|ab\+|w\+|wb\+|x\+|xb\+|c\+|cb\+/", meta["mode"]),
            this->writable = (bool) preg_match("/a|w|r\+|rb\+|rw|x|c/", meta["mode"]);
    }

    /**
     * @return int|null
     */
    public function getSize()
    {
        if typeof this->size == "NULL" && typeof this->$resource != "NULL" {
            var stats;
            let stats = fstat(this->$resource);
            if isset stats["size"] {
                let this->size = stats["size"];
            }
        }

        return this->size;
    }

    /**
     * @return bool|int
     */
    public function tell()
    {
        var tell;
        
        this->assertDetachedStream();
        
        let tell = ftell(this->$resource);

        if tell === false {
            throw new RuntimeException("Uncaught position a stream.");
        }
        
        return tell;
    }

    /**
     * @return bool
     */
    public function eof()
    {
        this->assertDetachedStream();
        
        return feof(this->$resource);
    }

    /**
     * Returns whether or not the stream is seekable.
     *
     * @return bool
     */
    public function isSeekable()
    {
        return this->seekable;
    }

    /**
     * @param int offset
     * @param int whence
     * @return void
     */
    public function seek(offset, whence = 0)
    {
        this->assertDetachedStream();
        if !this->seekable || fseek(this->$resource, offset, whence) === -1 {
            throw new RuntimeException("Could not seek in stream.");
        }
    }

    /**
     * @return void
     */
    public function rewind()
    {
        this->seek(0);
    }

    /**
     * Returns whether or not the stream is writable.
     *
     * @return bool
     */
    public function isWritable()
    {
        return this->writable;
    }

    /**
     * @param string value
     * @return bool|int
     */
    public function write(value)
    {
        var write;
        this->assertDetachedStream();
        
        if !this->writable {
            throw new RuntimeException("The resource is not writable.");
        }

        let write = fwrite(this->$resource, value);
        if write === false {
            throw new RuntimeException("Could'nt write to stream.");
        }
        
        let this->size = null;
        return write;
    }

    /**
     * Returns whether or not the stream is readable.
     *
     * @return bool
     */
    public function isReadable()
    {
        return this->readable;
    }

    /**
     * @param int length
     * @return string
     */
    public function read(length)
    {
        var data;
        this->assertDetachedStream();
        if length <= 0 {
            return "";
        }
        if !this->readable {
            throw new RuntimeException("The resource is not readable.");
        }

        let data = fread(this->$resource, length);

        if data === false {
            throw new RuntimeException("Could'nt read from stream.");
        }
 
        return data;
    }

    /**
     * @return string
     */
    public function getContents()
    {
        var content;

        this->assertDetachedStream();
        
        let content = stream_get_contents(this->$resource);
        if content === false {
            throw new RuntimeException("Uncaught to read the stream.");
        }
        
        return content;
    }

    /**
     * @param null key
     * @return array|mixed|null
     */
    public function getMetadata(key = null)
    {
        if typeof this->$resource == "NULL" {
            if typeof key == "NULL" {
                return key;
            }
            return [];
        }
        var metaData;
        
        let metaData = stream_get_meta_data(this->$resource);
        if typeof key == "NULL" {
            return metaData;
        }
        if isset metaData[key] {
            return metaData[key];
        }
        
        return null;
    }

    /**
     * @return resource|null
     */
    public function detach()
    {
        var $resource;
        
        let $resource = this->$resource,
            this->size = null,
            this->$resource = null,
            this->seekable = false,
            this->readable = false,
            this->writable = false;
        
        return $resource;
    }

    /**
     * @return void
     */
    public function close()
    {
        if typeof this->$resource != "NULL"  {
            fclose(this->$resource);
            this->detach();
        }
    }

    /**
     * @return string
     */
    public function __toString()
    {
        try {
            this->rewind();
            return this->getContents();
        } catch RuntimeException {
            return "";
        }
    }

    /**
     * {@inheritdoc}
     */
    public function __destruct()
    {
        this->close();
    }

    /**
     * @return void
     */
    protected function assertDetachedStream()
    {
        if typeof this->$resource == "NULL" {
            throw new RuntimeException("The stream has been detach.");
        }
    }
}