namespace Zeplara\Encryption;

use Zeplara\Support\Str;
use InvalidArgumentException;
use Zeplara\Contracts\Encryption\Encrypter as EncrypterContract;

final class Encrypter implements EncrypterContract
{
    /**
     * @var string
     */
    protected key { get };

    /**
     * @var string
     */
    protected cipher { get };

    /**
     * @var array
     */
    private static cipherMethods = [
        "AES-128-CBC": "AES-128-CBC",
        "AES-128-CBC-HMAC-SHA1": "AES-128-CBC-HMAC-SHA1",
        "AES-128-CBC-HMAC-SHA256": "AES-128-CBC-HMAC-SHA256",
        "AES-128-CFB": "AES-128-CFB",
        "AES-128-CFB1": "AES-128-CFB1",
        "AES-128-CFB8": "AES-128-CFB8",
        "AES-128-CTR": "AES-128-CTR",
        "AES-128-OFB": "AES-128-OFB",
        "AES-192-CBC": "AES-192-CBC",
        "AES-192-CFB": "AES-192-CFB",
        "AES-192-CFB1": "AES-192-CFB1",
        "AES-192-CFB8": "AES-192-CFB8",
        "AES-192-CTR": "AES-192-CTR",
        "AES-192-OFB": "AES-192-OFB",
        "AES-256-CBC": "AES-256-CBC",
        "AES-256-CBC-HMAC-SHA1": "AES-256-CBC-HMAC-SHA1",
        "AES-256-CBC-HMAC-SHA256": "AES-256-CBC-HMAC-SHA256",
        "AES-256-CFB": "AES-256-CFB",
        "AES-256-CFB1": "AES-256-CFB1",
        "AES-256-CFB8": "AES-256-CFB8",
        "AES-256-CTR": "AES-256-CTR",
        "AES-256-OFB": "AES-256-OFB",
        "ARIA-128-CBC": "ARIA-128-CBC",
        "ARIA-128-CFB": "ARIA-128-CFB",
        "ARIA-128-CFB1": "ARIA-128-CFB1",
        "ARIA-128-CFB8": "ARIA-128-CFB8",
        "ARIA-128-CTR": "ARIA-128-CTR",
        "ARIA-128-OFB": "ARIA-128-OFB",
        "ARIA-192-CBC": "ARIA-192-CBC",
        "ARIA-192-CFB": "ARIA-192-CFB",
        "ARIA-192-CFB1": "ARIA-192-CFB1",
        "ARIA-192-CFB8": "ARIA-192-CFB8",
        "ARIA-192-CTR": "ARIA-192-CTR",
        "ARIA-192-OFB": "ARIA-192-OFB",
        "ARIA-256-CBC": "ARIA-256-CBC",
        "ARIA-256-CFB": "ARIA-256-CFB",
        "ARIA-256-CFB1": "ARIA-256-CFB1",
        "ARIA-256-CFB8": "ARIA-256-CFB8",
        "ARIA-256-CTR": "ARIA-256-CTR",
        "ARIA-256-OFB": "ARIA-256-OFB",
        "BF-CBC": "BF-CBC",
        "BF-CFB": "BF-CFB",
        "BF-OFB": "BF-OFB",
        "CAMELLIA-128-CBC": "CAMELLIA-128-CBC",
        "CAMELLIA-128-CFB": "CAMELLIA-128-CFB",
        "CAMELLIA-128-CFB1": "CAMELLIA-128-CFB1",
        "CAMELLIA-128-CFB8": "CAMELLIA-128-CFB8",
        "CAMELLIA-128-CTR": "CAMELLIA-128-CTR",
        "CAMELLIA-128-OFB": "CAMELLIA-128-OFB",
        "CAMELLIA-192-CBC": "CAMELLIA-192-CBC",
        "CAMELLIA-192-CFB": "CAMELLIA-192-CFB",
        "CAMELLIA-192-CFB1": "CAMELLIA-192-CFB1",
        "CAMELLIA-192-CFB8": "CAMELLIA-192-CFB8",
        "CAMELLIA-192-CTR": "CAMELLIA-192-CTR",
        "CAMELLIA-192-OFB": "CAMELLIA-192-OFB",
        "CAMELLIA-256-CBC": "CAMELLIA-256-CBC",
        "CAMELLIA-256-CFB": "CAMELLIA-256-CFB",
        "CAMELLIA-256-CFB1": "CAMELLIA-256-CFB1",
        "CAMELLIA-256-CFB8": "CAMELLIA-256-CFB8",
        "CAMELLIA-256-CTR": "CAMELLIA-256-CTR",
        "CAMELLIA-256-OFB": "CAMELLIA-256-OFB",
        "CAST5-CBC": "CAST5-CBC",
        "CAST5-CFB": "CAST5-CFB",
        "CAST5-OFB": "CAST5-OFB",
        "CHACHA20": "CHACHA20",
        "CHACHA20-POLY1305": "CHACHA20-POLY1305",
        "DES-CBC": "DES-CBC",
        "DES-CFB": "DES-CFB",
        "DES-CFB1": "DES-CFB1",
        "DES-CFB8": "DES-CFB8",
        "DES-EDE-CBC": "DES-EDE-CBC",
        "DES-EDE-CFB": "DES-EDE-CFB",
        "DES-EDE-OFB": "DES-EDE-OFB",
        "DES-EDE3-CBC": "DES-EDE3-CBC",
        "DES-EDE3-CFB": "DES-EDE3-CFB",
        "DES-EDE3-CFB1": "DES-EDE3-CFB1",
        "DES-EDE3-CFB8": "DES-EDE3-CFB8",
        "DES-EDE3-OFB": "DES-EDE3-OFB",
        "DES-OFB": "DES-OFB",
        "DESX-CBC": "DESX-CBC",
        "RC2-40-CBC": "RC2-40-CBC",
        "RC2-64-CBC": "RC2-64-CBC",
        "RC2-CBC": "RC2-CBC",
        "RC2-CFB": "RC2-CFB",
        "RC2-OFB": "RC2-OFB",
        "SEED-CBC": "SEED-CBC",
        "SEED-CFB": "SEED-CFB",
        "SEED-OFB": "SEED-OFB",
        "SM4-CBC": "SM4-CBC",
        "SM4-CFB": "SM4-CFB",
        "SM4-CTR": "SM4-CTR",
        "SM4-OFB": "SM4-OFB"
    ];

    /**
     * @var array
     */
    private static ivLengthCache = [];

    /**
     * @param string key
     * @param string cipher
     * @throws EncryptionException
     */
    public function __construct(string! key, string! cipher)
    {
        let cipher = Str::upper(cipher);

        if !isset self::cipherMethods[cipher] {
            this->throwEncryptionException("Cipher %s is not supported."->format(cipher));
        }
        
        let this->key = key,
            this->cipher = cipher;
    }

    /**
     * @param value
     * @return string
     * @throws EncryptionException
     */
    public function encrypt(value)
    {   
        var iv;
        
        error_clear_last();     
        set_error_handler([this, "throwEncryptError"]);
        
        let iv = this->generateIv(),
            value = openssl_encrypt(serialize(value), this->cipher, this->key, 0, iv);

        if value === false {
            this->throwEncryptError();
        }

        let value = base64_encode(json_encode(["iv": base64_encode(iv), "value": value]));

        if json_last_error() !== JSON_ERROR_NONE {
            this->throwEncryptError();
        }

        restore_error_handler();

        return value;
    }

    /**
     * @param string value
     * @return mixed
     */
    public function decrypt(value)
    {
        if typeof value != "string" {
            throw new InvalidArgumentException("The encrypted value must be string.");
        }

        error_clear_last();
        set_error_handler([this, "throwDecryptError"]);

        let value = base64_decode(value);

        if value === false {
            this->throwDecryptError();
        }

        let value = json_decode(value, true);

        if json_last_error() !== JSON_ERROR_NONE {
            this->throwDecryptError();
        }

        let value = (array) value;

        if isset value["iv"] === false && isset value["value"] === false {
            this->throwDecryptError();
        }

        let value["iv"] = base64_decode(value["iv"]);

        if this->isValidIv(value["iv"]) === false {
            this->throwDecryptError();
        }

        let value = openssl_decrypt(value["value"], this->cipher, this->key, 0, value["iv"]);

        if value === false {
            this->throwDecryptError();
        }

        let value = unserialize(value);

        restore_error_handler();
        
        return value;
    }

    /**
     * @return int
     */
    private function IvLength()
    {
        if !isset self::ivLengthCache[this->cipher] {
            let self::ivLengthCache[this->cipher] = openssl_cipher_iv_length(this->cipher);
        }

        return (int) self::ivLengthCache[this->cipher];
    }

    /**
     * @return string
     */
    private function generateIv()
    {
        return openssl_random_pseudo_bytes(this->ivLength());
    }

    /**
     * @param string iv
     * @return bool
     */
    private function isValidIv(iv)
    {
        var ivLength;
        let ivLength = this->ivLength();

        return ivLength === (int) mb_strlen(mb_strcut(iv, 0, ivLength, "8bit"), "8bit");
    }

    /**
     * @param string message
     * @throws EncryptionException
     */
    private function throwEncryptionException(message)
    {
        throw new EncryptionException(message);
    }

    /**
     * @throws EncryptionException
     */
    private function throwEncryptError()
    {
        this->throwEncryptionException("Could not encrypt data.");
    }

    /**
     * @throws EncryptionException
     */
    private function throwDecryptError()
    {
        this->throwEncryptionException("Could not decrypt data.");
    }
}