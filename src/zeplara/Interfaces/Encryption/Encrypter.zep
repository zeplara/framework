namespace Zeplara\Interfaces\Encryption;

interface Encrypter
{
    /**
     * @return string
     */
    public function getKey();

    /**
     * @return string
     */
    public function getCipher();

    /**
     * @param value
     * @return string
     * @throws EncryptionException
     */
    public function encrypt(value);

    /**
     * @param string value
     * @return mixed
     * @throws EncryptionException
     */
    public function decrypt(value);
}