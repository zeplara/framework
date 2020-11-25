namespace Zeplara\Http;

use Psr\Http\Message\UriInterface;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\ServerRequestFactoryInterface;

final class ServerRequestFactory implements ServerRequestFactoryInterface
{
    /**
     * @param string method
     * @param uri
     * @param array serverParams
     * @return ServerRequestInterface
     */
    public function createServerRequest(string! method, uri, array! serverParams = []) -> <ServerRequestInterface>
    {
        return self::create(method, uri, null,  serverParams);
    }

    /**
     * @param string method
     * @param uri
     * @param array serverParams
     * @return ServerRequestInterface
     */
    public static function create
    (
        string method = null,
        uri = null,
        <StreamInterface> body = null,
        array! serverParams = [],
        array! parsedBody = [],
        array! queryParams = [],
        array! cookieParams = [],
        array! uploadedFiles = [],
        array! headers = [],
        string! protocolVersion = "1.1"
    )
    {
        if typeof method == "NULL" {
            let method = (string) _SERVER["REQUEST_METHOD"];
        }

        if (uri instanceof UriInterface) === false {
            let uri = UriFactory::create(uri);
        }

        if typeof body == "NULL" {
            let body = StreamFactory::create("php://input", "r+");
        }

        if empty serverParams {
            let serverParams = _SERVER;
        }

        if empty parsedBody {
            let parsedBody = _POST;
        }

        if empty queryParams {
            let queryParams = _GET;
        }

        if empty cookieParams {
            let cookieParams = _COOKIE;
        }

        if empty uploadedFiles {
            let uploadedFiles = (array) self::parseUploadedFiles();
        }

        if empty headers {
            let headers = (array) self::getAllHeaders();
        }
        
        return new ServerRequest(method, uri, body, serverParams, parsedBody, queryParams, cookieParams, uploadedFiles, headers, protocolVersion);
    }

    /**
     * @param array files
     * @return array
     */
    private static function parseUploadedFiles()
    {
        var files, key, value;
        let files = [];

        for key, value in _FILES {
            if typeof value["error"] == "array" {
                var k, v;
                for k, v in value["error"] {
                    if !isset files[key] {
                        let files[key] = [];
                    }
                    let files[key][] = UploadedFileFactory::create(
                        StreamFactory::create(value["tmp_name"][k], "r"),
                        value["size"][k],
                        v,
                        value["name"][k],
                        value["type"][k]
                    );
                }
            } else {
                let files[key] = UploadedFileFactory::create(
                    StreamFactory::create(value["tmp_name"], "r"),
                    value["size"],
                    value["error"],
                    value["name"],
                    value["type"]
                );
            }
        }

        return files;
    }

    /**
     * @return array
     */
    private static function getAllHeaders()
    {
        if function_exists("getallheaders") {
            return getallheaders();
        }

        if function_exists("apache_request_headers") {
            return apache_request_headers();
        }

        var key, value, headers, copy_server;
        let headers = [],
            copy_server = [
                "CONTENT_MD5"    : "Content-Md5",
                "CONTENT_TYPE"   : "Content-Type",
                "CONTENT_LENGTH" : "Content-Length"
            ];

        for key, value in _SERVER {
            if substr(key, 0, 5) == "HTTP_" {
                let key = substr(key, 5);
                if !isset copy_server[key] || !isset _SERVER[key] {
                    let headers[key] = value;
                }
            } elseif isset copy_server[key] {
                let headers[copy_server[key]] = value;
            }
        }

        if !isset headers["Authorization"] {
            if isset _SERVER["REDIRECT_HTTP_AUTHORIZATION"] {
                let headers["Authorization"] = _SERVER["REDIRECT_HTTP_AUTHORIZATION"];
            } elseif isset _SERVER["PHP_AUTH_USER"] {
                var basic_pass;
                fetch basic_pass, _SERVER["PHP_AUTH_PW"];
                let headers["Authorization"] = "Basic " . base64_encode(_SERVER["PHP_AUTH_USER"] . ":" . basic_pass);
            } elseif isset _SERVER["PHP_AUTH_DIGEST"] {
                let headers["Authorization"] = _SERVER["PHP_AUTH_DIGEST"];
            }
        }

        return headers;
    }
}