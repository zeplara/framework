namespace Zeplara\Http;

use InvalidArgumentException;
use Psr\Http\Message\UriInterface;

final class Uri implements UriInterface
{
    /**
     * @var string
     */
    protected scheme { get };
    /**
     * @var string
     */
    protected host { get };
    /**
     * @var int|null
     */
    protected port { get };
    /**
     * @var array
     */
    protected userInfo { get };
    /**
     * @var string
     */
    protected path { get };
    /**
     * @var string
     */
    protected query { get };
    /**
     * @var string
     */
    protected fragment { get };

    /**
     * @param scheme
     * @param host
     * @param null port
     * @param string path
     * @param string query
     * @param string fragment
     * @param string user
     * @param string password
     */
    public function __construct(
        scheme = "",
        host = "",
        port = null,
        path = "/",
        query = "",
        fragment = "",
        user = "",
        password = ""
    )
    {
        let this->scheme = this->filterScheme(scheme),
            this->host = this->filterHost(host),
            this->port = this->filterPort(port),
            this->path = this->filterPath(path),
            this->query = this->filterQueryOrFragment(query),
            this->fragment = this->filterQueryOrFragment(fragment),
            this->userInfo = this->filterUserInfo(user);
        
        if password {
            let this->userInfo .= ":".this->filterUserInfo(password);
        }
    }

    /**
     * @return string
     */
    public function getAuthority()
    {
        var authority;
        let authority = this->host;
        if this->userInfo {
            let authority = this->userInfo."@".authority;
        }
        if typeof this->port != "NULL" {
            let authority .= ":".this->port;
        }
        
        return authority;
    }

    /**
     * @param string scheme
     * @return static
     */
    public function withScheme(scheme)
    {
        var $clone;
        
        let $clone = clone this,
            $clone->scheme = $clone->filterScheme(scheme),
            $clone->port = $clone->filterPort(this->port);
        
        return $clone;
    }

    /**
     * @param string user
     * @param null password
     * @return static
     */
    public function withUserInfo(user, password = null)
    {
        var $clone;
        
        let $clone = clone this,
            $clone->userInfo = $clone->filterUserInfo(user);
        
        if typeof password != "NULL"  {
            let $clone->userInfo .= ":".$clone->filterUserInfo(password);
        }

        return $clone;
    }

    /**
     * @param string host
     * @return static
     */
    public function withHost(host)
    {
        var $clone;
        let $clone = clone this,
            $clone->host = $clone->filterHost(host);

        return $clone;
    }

    /**
     * @param int|null port
     * @return static
     */
    public function withPort(port)
    {
        var $clone;
        let $clone = clone this,
            $clone->port = $clone->filterPort(port);

        return $clone;
    }

    /**
     * @param string path
     * @return static
     */
    public function withPath(path)
    {
        var $clone;
        let $clone = clone this,
            $clone->path = $clone->filterPath(path);

        return $clone;
    }

    /**
     * @param string query
     * @return static
     */
    public function withQuery(query)
    {
        var $clone;

        let $clone = clone this,
            $clone->query = $clone->filterQueryOrFragment(query);

        return $clone;
    }

    /**
     * @param string fragment
     * @return static
     */
    public function withFragment(fragment)
    {
        var $clone;
        let $clone = clone this,
            $clone->fragment = $clone->filterQueryOrFragment(fragment);

        return $clone;
    }

    /**
     * @return string
     */
    public function __toString()
    {
        var uri, authority;
        let uri = "",
            authority = this->getAuthority();
        
        if this->scheme !== "" {
            let uri .= this->scheme.":";
        }
        
        if authority || this->scheme == "file" {
            let uri .= "//".authority;
        }

        let uri .= this->path;

        if this->query {
            let uri .= "?".this->query;
        }

        if this->fragment {
            let uri .= "#".this->fragment;
        }

        return uri;
    }

    /**
     * @param scheme
     * @return string
     */
    private function filterScheme(scheme)
    {
        if typeof scheme != "string" {
            throw new InvalidArgumentException("The scheme or fragment must be an string.");
        }

        let scheme = trim(scheme);

        if scheme !== "" {
            var sepIdx;
            let scheme = strtolower(scheme), 
                sepIdx = strpos(scheme, ":");

            if sepIdx !== false {
                let scheme = substr(scheme, 0, sepIdx);
            }
        }
        
        return scheme;
    }

    /**
     * @param host
     * @return string
     */
    private function filterHost(host)
    {
        if typeof host != "string" {
            throw new InvalidArgumentException("The host is invalid type.");
        }

        return strtolower(host);
    }

    /**
     * @param int|null port
     * @return int|null
     */
    private function filterPort(port)
    {
        if this->scheme === "" {
            let port = null;
        }
        
        if typeof port == "NULL" {
            return port;
        }

        if is_numeric(port) && port >= 1 && port <= 65535 {
            var defaultPortByScheme;
            let defaultPortByScheme = getservbyname(this->scheme, "tcp");

            let port = (int) port;

            if defaultPortByScheme === false || port === defaultPortByScheme {
                let port = null;
            }

            return port;
        }

        throw new InvalidArgumentException("The port value must be an integer between 1 and 65535.");
    }

    /**
     * @param path
     * @return string|string[]|null
     */
    private function filterPath(path)
    {
        if typeof path != "string" {
            throw new InvalidArgumentException("The path must be an string.");
        }

        return preg_replace_callback(
            "/(?:[^a-zA-Z0-9_\-\.~:@&=\+\$,\/;%]+|%(?![A-Fa-f0-9]{2}))/",
            [this, "rawUrlEncodeFilter"],
            "/".trim(path, "/")
        );
    }

    /**
     * @param value
     * @return string|string[]|null
     */
    private function filterQueryOrFragment(value)
    {
        if typeof value != "string" {
            throw new InvalidArgumentException("The query or fragment must be an string.");
        }
        
        return preg_replace_callback(
            "/(?:[^a-zA-Z0-9_\-\.~!\$&\"\(\)\*\+,;=%:@\/\?]+|%(?![A-Fa-f0-9]{2}))/",
            [this, "rawUrlEncodeFilter"],
            value
        );
    }

    /**
     * @param userInfo
     * @return string|string[]|null
     */
    private function filterUserInfo(userInfo)
    {
        if typeof userInfo != "string" {
            throw new InvalidArgumentException("The user info must be an string.");
        }
        return preg_replace_callback(
            "/(?:[^a-zA-Z0-9_\-\.~!\$&\"\(\)\*\+,;=]+|%(?![A-Fa-f0-9]{2}))/u",
            [this, "rawUrlEncodeFilter"],
            userInfo
        );
    }

    /**
     * @param array matches
     * @return string
     */
    private function rawUrlEncodeFilter(array! matches)
    {
        return rawurlencode(matches[0]);
    }
}