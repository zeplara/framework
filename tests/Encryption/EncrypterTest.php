<?php

namespace Zeplara\Tests\Encryption;

use Throwable;
use ReflectionProperty;
use Zeplara\Support\Str;
use Zeplara\Support\Arr;
use PHPUnit\Framework\TestCase;
use Zeplara\Encryption\Encrypter;
use Zeplara\Encryption\EncryptionException;

class EncrypterTest extends TestCase
{
    /**
     * @dataProvider provideCipherMethods
     */
    public function testEncryptDecrypt($cipher)
    {
        $encrypter = new Encrypter(Str::random(openssl_cipher_iv_length($cipher)), $cipher);

        static::assertEquals('hello world', $encrypter->decrypt($encrypter->encrypt('hello world')));
    }

    /**
     * @dataProvider provideInvalidCipherMethods
     */
    public function testInvalidCipher($cipher)
    {
        $this->expectException(EncryptionException::class);
        $this->expectExceptionMessage(sprintf(
            "Cipher %s is not supported.", $cipher
        ));
        try {
            $encrypter = new Encrypter(Str::random(openssl_cipher_iv_length($cipher)), $cipher);
        } catch (Throwable $e) {
            throw $e;
        }

        static::assertNull(isset($encrypter) ? $encrypter : null);
    }

    public function provideCipherMethods()
    {
        return array_map([Arr::class, 'wrap'], $this->getSupportedCipherMethods());
    }

    public function provideInvalidCipherMethods()
    {
        return array_map([Arr::class, 'wrap'], array_diff(array_map([Str::class, 'upper'], openssl_get_cipher_methods()), $this->getSupportedCipherMethods()));
    }

    private function getSupportedCipherMethods()
    {
        $ref = new ReflectionProperty(Encrypter::class, 'cipherMethods');
        $ref->setAccessible(ReflectionProperty::IS_PUBLIC);
        return $ref->getValue();
    }
}