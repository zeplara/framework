namespace Zeplara\Http;

use InvalidArgumentException;
use Psr\Http\Message\UriInterface;
use Psr\Http\Message\UriFactoryInterface;

final class UriFactory implements UriFactoryInterface
{
    /**
     * @param string uri
     * @return UriInterface
     */
    public function createUri(string! uri = "") -> <UriInterface>
    {
        return self::create(uri);
    }

    /**
     * @param string|array|null uri
     * @return UriInterface
     */
    public static function create(uri = null)
    {
        var scheme, host, port, path, query, fragment, user, pass;

        let scheme = "http",
            host = "localhost",
            port = null,
            path = "/",
            query = "",
            fragment = "",
            user = "",
            pass = "";

        if typeof uri == "NULL" {
            let uri = [],
                uri["scheme"] = scheme,
                uri["host"] = host,
                uri["port"] = port,
                uri["path"] = path,
                uri["query"] = query,
                uri["user"] = user,
                uri["pass"] = pass;

            if isset _SERVER["HTTPS"] && _SERVER["HTTPS"] != "off" {
                let uri["scheme"] = "https";
            }

            if isset _SERVER["HTTP_HOST"] {
                var parsed;

                let parsed = parse_url("%s://%s"->format(scheme, _SERVER["HTTP_HOST"]));

                if isset parsed["host"] {
                    let uri["host"] = parsed["host"];
                }

                if isset parsed["port"] {
                    let uri["port"] = parsed["port"];
                }
            } elseif isset _SERVER["SERVER_NAME"] {
                let uri["host"] = _SERVER["SERVER_NAME"];
            } elseif isset _SERVER["SERVER_ADDR"] {
                let uri["host"] = _SERVER["SERVER_ADDR"];
            }

            if typeof uri["port"] == "NULL" && isset _SERVER["SERVER_PORT"] {
                let uri["port"] = _SERVER["SERVER_PORT"];
            }

            if isset _SERVER["REQUEST_URI"] {
                var parsed;

                let parsed = explode("?", _SERVER["REQUEST_URI"], 2),
                    uri["path"] = parsed[0];

                if isset parsed[1] {
                    let uri["query"] = parsed[1];
                }
            }

            if uri["query"] === "" && isset _SERVER["QUERY_STRING"] {
                let uri["query"] = _SERVER["QUERY_STRING"];
            }
        }

        if typeof uri == "string" {
            let uri = parse_url(uri);

            if uri === false{
                throw new InvalidArgumentException("The url is invalid.");
            }
        }
        
        if typeof uri != "array" {
            throw new InvalidArgumentException("The uri should be string or array or null tyoe.");
        }

        if isset uri["scheme"] {
            let scheme = uri["scheme"];
        }

        if isset uri["host"] {
            let host = uri["host"];
        }

        if isset uri["port"] {
            let port = uri["port"];
        }

        if isset uri["path"] {
            let path = uri["path"];
        }

        if isset uri["query"] {
            let query = uri["query"];
        }

        if isset uri["fragment"] {
            let fragment = uri["fragment"];
        }

        if isset uri["user"] {
            let user = uri["user"];
        }

        if isset uri["pass"] {
            let pass = uri["pass"];
        }

        return new Uri(scheme, host, port, path, query, fragment, user, pass);
    }
}