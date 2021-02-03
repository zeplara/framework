namespace Zeplara\Http;

use Zeplara\Support\Arr;
use InvalidArgumentException;
use Psr\Http\Message\UriInterface;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\ServerRequestInterface;

final class ServerRequest extends Request implements ServerRequestInterface
{
    /**
     * @var array
     */
    protected serverParams { get };
    /**
     * @var array
     */
    protected cookieParams { get };
    /**
     * @var array
     */
    protected queryParams { get };
    /**
     * @var array
     */
    protected uploadedFiles { get };
    /**
     * @var array
     */
    protected parsedBody { get };
    /**
     * @var array
     */
    protected attributes = [] { get };

    /**
     * @param string method
     * @param UriInterface uri
     * @param StreamInterface body
     * @param array serverParams
     * @param array parsedBody
     * @param array queryParams
     * @param array cookieParams
     * @param array uploadedFiles
     * @param array headers
     * @param string protocolVersion
     */
    public function __construct
    (
        string! method,
        <UriInterface> uri,
        <StreamInterface> body,
        array! serverParams = [],
        array! parsedBody = [],
        array! queryParams = [],
        array! cookieParams = [],
        array! uploadedFiles = [],
        array! headers = [],
        string! protocolVersion = "1.1"
    )
    {
        this->assertUploadedFiles(uploadedFiles);

        let this->serverParams = serverParams,
            this->parsedBody = parsedBody,
            this->queryParams = queryParams,
            this->cookieParams = cookieParams,
            this->uploadedFiles = uploadedFiles;

        parent::__construct(method, uri, body, headers, protocolVersion);
    }

    /**
     * @param array cookies
     * @return static
     */
    public function withCookieParams(array! cookies)
    {
        var $clone;
        let $clone = clone this,
            $clone->cookieParams = cookies;

        return $clone;            
    }

    /**
     * @param array query
     * @return static
     */
    public function withQueryParams(array! query)
    {
        var $clone;
        let $clone = clone this,
            $clone->queryParams = query;

        return $clone;   
    }

    /**
     * @param array files
     * @return static
     */
    public function withUploadedFiles(array! files)
    {
        var $clone;
        
        this->assertUploadedFiles(files);

        let $clone = clone this,
            $clone->uploadedFiles = files;

        return $clone;   
    }

    /**
     * @param array parsedBody
     * @return static
     */
    public function withParsedBody(parsedBody)
    {
        var $clone;
        let $clone = clone this,
            $clone->parsedBody = parsedBody;

        return $clone;   
    }

    /**
     * @param name
     * @param null defaultValue
     * @return static
     */
    public function getAttribute(name, defaultValue = NULL)
    {
        if !isset this->attributes[name] {
            return defaultValue;
        }

        return this->attributes[name];
    }

    /**
     * @param name
     * @param value
     * @return static
     */
    public function withAttribute(name, value)
    {
        var $clone;

        let $clone = clone this,
            $clone->attributes[name] = value;

        return $clone;            
    }

    /**
     * @param name
     * @return static
     */
    public function withoutAttribute(name)
    {
        var $clone;

        let $clone = clone this;
        
        unset $clone->attributes[name];

        return $clone;            
    }

    /**
     * @var array uploadedFiles
     * @return void
     */
    private function assertUploadedFiles(uploadedFiles)
    {
        var uploadedFile;
        let uploadedFiles = Arr::flatten(uploadedFiles);
        for uploadedFile in uploadedFiles {
            if typeof uploadedFile != "object" || (uploadedFile instanceof UploadedFile) === false {
                throw new InvalidArgumentException("The uploadedFiles values should be instance of \Zeplara\Http\UploadedFile::class");
            }
        }
    }
}