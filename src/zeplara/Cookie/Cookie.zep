namespace Zeplara\Cookie;

use DateTimeInterface;
use Zeplara\Support\Str;
use InvalidArgumentException;
use Zeplara\Contracts\Cookie\Cookie as CookieContract;

final class Cookie implements CookieContract
{
    /**
     * @var string
     */
    protected name { get };
    /**
     * @var string
     */
    protected value { get };
    /**
     * @var int
     */
    protected expiration { get };
    /**
     * @var string
     */
    protected path { get };
    /**
     * @var string
     */
    protected domain { get };
    /**
     * @var bool
     */
    protected secure;
    /**
     * @var bool
     */
    protected httpOnly;
    /**
     * @var string
     */
    protected sameSite { get };

    /**
     * Cookie constructor.
     *
     * @param name
     * @param string value
     * @param int expiration
     * @param string path
     * @param string domain
     * @param bool secure
     * @param bool httpOnly
     * @param string sameSite
     */
    public function __construct(
        string! name,
        value = "",
        expiration = 0,
        path = "/",
        domain = "",
        secure = false,
        httpOnly = true,
        sameSite = self::SAMESITE_LAX
    )
    {
        if name === "" || preg_match("/[=,; \\t\\r\\n\\013\\014]/", name) {
            throw new InvalidArgumentException("The name is invalid.");
        }

        let this->name = name;
        
        this->setValue(value);
        this->setExpiration(expiration);
        this->setPath(path);
        this->setDomain(domain);
        this->setSecure(secure);
        this->setHttpOnly(httpOnly);
        this->setSameSite(sameSite);
    }

    /**
     * @return bool
     */
    public function isSecure()
    {
        return this->secure === true;
    }

    /**
     * @return bool
     */
    public function isHttpOnly()
    {
        return this->httpOnly === true;
    }

    /**
     * @param value
     * @return void
     */
    public function setValue(value)
    {
        if value === null {
            let value = "";
        }

        if typeof value != "string" {
            throw new InvalidArgumentException("The value must be an string type.");
        }

        let this->value = value;
    }

    /**
     * @param DateTimeInterface|int|string expiration
     * @return void
     */
    public function setExpiration(expiration)
    {
        if typeof expiration == "object" && expiration instanceof DateTimeInterface {
            let expiration = expiration->format("U");
        } elseif is_numeric(expiration) === false {
            let expiration = strtotime(expiration);
            if expiration === false {
                 throw new InvalidArgumentException("The expiration time is invalid type.");
            }
        }

        let this->expiration = expiration > 0 ? (int) expiration : 0;
    }

    /**
     * @param path
     * @return void
     */
    public function setPath(path)
    {
        if path === "" || path === null {
            let path = "/";
        }
        if typeof path != "string" {
            throw new InvalidArgumentException("The path must be an string type.");
        }
        let this->path = preg_replace_callback(
            "/(?:[^a-zA-Z0-9_\-\.~:@&=\+\,\/;%]+|%(?![A-Fa-f0-9]{2}))/",
            [this, "rawUrlEncodeFilter"],
            path
        );
    }

    /**
     * @param domain
     * @return void
     */
    public function setDomain(domain)
    {
        if typeof domain == "NULL" {
            let domain = "";
        }
        if typeof domain != "string" {
            throw new InvalidArgumentException("The domain must be an string type.");
        }
        
        let this->domain = domain;
    }

    /**
     * @param bool secure
     * @return void
     */
    public function setSecure(secure)
    {
        if typeof secure != "boolean" {
            throw new InvalidArgumentException("The secure must be an boolean type.");
        }
        
        let this->secure = secure;
    }

    /**
     * @param bool httpOnly
     * @return void
     */
    public function setHttpOnly(httpOnly)
    {
        if typeof httpOnly != "boolean" {
            throw new InvalidArgumentException("The httpOnly must be an boolean type.");
        }

        let this->httpOnly = httpOnly;
    }

    /**
     * @param sameSite
     * @return void
     */
    public function setSameSite(sameSite)
    {
        if sameSite === "" {
            let sameSite = null;
        }
        if typeof sameSite != "NULL" {
            let sameSite = Str::capitalize(sameSite);
            
            if in_array(sameSite, [self::SAMESITE_NONE, self::SAMESITE_LAX, self::SAMESITE_STRICT]) === false {
                throw new InvalidArgumentException("The samesite is invalid.");
            }

            let this->sameSite = sameSite;   
        }
    }

    /**
     * @return string
     */
    public function __toString()
    {
        var format;
        let format = urlencode(this->name)."=";
        if this->value === "" {
            let format .= "deleted; Expires=%s; Max-Age=0"->format(gmdate("D, d-M-Y H:i:s T", time() - 31536001));
        } else {
            var maxAge;
            let maxAge = this->expiration - time(),
                maxAge = maxAge > 0 ? maxAge : 0,
                format .= rawurlencode(this->value);

            if this->expiration !== 0 {
                let format .= "; Expires=%s; Max-Age=%s"->format(gmdate("D, d-M-Y H:i:s T", this->expiration), maxAge);
            }
        }
        if this->path !== "" {
            let format .= "; Path=".this->path;
        }

        if this->domain !== "" {
            let format .= "; Domain=".this->domain;
        }
        
        if this->secure {
            let format .= "; Secure";
        }
        if this->httpOnly {
            let format .= "; HttpOnly";
        }
        
        if this->sameSite {
            let format .= "; SameSite=".this->sameSite;
        }
        
        return format;
    }

    /**
     * @param array matches
     * @return string
     */
    private function rawUrlEncodeFilter(matches)
    {
        return rawurlencode(matches[0]);
    }
}