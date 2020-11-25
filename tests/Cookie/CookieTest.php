<?php

namespace Zeplara\Tests\Cookie;

use DateTime;
use Throwable;
use DateTimeImmutable;
use DateTimeInterface;
use Zeplara\Cookie\Cookie;
use InvalidArgumentException;
use PHPUnit\Framework\TestCase;

class CookieTest extends TestCase
{
    public function testName()
    {
        $cookie = new Cookie('name');

        static::assertEquals('name', $cookie->getName());
    }

    /**
     * @dataProvider provideInvalidName
     */
    public function testInvalidName($name)
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('The name is invalid.');
        try {
            $cookie = new Cookie($name);        
        } catch (Throwable $e) {
            throw $e;
        }

        static::assertNull(isset($cookie) ? $cookie : null);
    }


    public function testValue()
    {
        $cookie = new Cookie('name', 'value');
        static::assertEquals('value', $cookie->getValue());
    
        $cookie = new Cookie('name', null);
        static::assertEquals('', $cookie->getValue());
    }

    public function testInvalidValue()
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('The value must be an string type.');
        $cookie = new Cookie('name', ['value']);
    }

    /**
     * @dataProvider provideValidExpiration
     */
    public function testExpiration($expiration)
    {
        $cookie = new Cookie('name', '', $expiration);
        if ($expiration instanceof DateTimeInterface) {
            $expiration = $expiration->format('U');
        } elseif (!is_numeric($expiration)) {
            $expiration = strtotime($expiration);
        }
        
        static::assertEquals($expiration, $cookie->getExpiration());
    }

    public function testInvalidExpiration()
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('The expiration time is invalid type.');
        new Cookie('name', 'foo', 'bar');
    }

    public function testPath()
    {
        $cookie = new Cookie('foo', 'bar', 0);
        static::assertEquals('/', $cookie->getPath());

        $cookie->setPath('/public');
        static::assertEquals('/public', $cookie->getPath()); 

        $cookie->setPath('public');
        static::assertEquals('public', $cookie->getPath());     

        $cookie->setPath('public/');
        static::assertEquals('public/', $cookie->getPath());

        $cookie->setPath(null);
        static::assertEquals('/', $cookie->getPath());  

        $cookie->setPath('');
        static::assertEquals('/', $cookie->getPath());
    }

    public function testInvalidPath()
    {
        try {
            $cookie = new Cookie('foo', 'bar', 0, ['/']);
        } catch (Throwable $e) {
            $this->expectException(InvalidArgumentException::class);
            $this->expectExceptionMessage('The path must be an string type.');       
            throw $e;
        }

        static::assertNull(isset($cookie) ? $cookie : null);
    }

    public function testValidDomain()
    {
        $cookie = new Cookie('foo', 'bar', 0, '/', 'example.com');
        static::assertEquals('example.com', $cookie->getDomain());

        $cookie->setDomain(null);
        static::assertEquals('', $cookie->getDomain());

        $cookie->setDomain('');
        static::assertEquals('', $cookie->getDomain());
    }

    public function testInvalidDomain()
    {
        try {
            $cookie = new Cookie('foo', 'bar', 0, '/', ['example.com']);
        } catch (Throwable $e) {
            $this->expectException(InvalidArgumentException::class);
            $this->expectExceptionMessage('The domain must be an string type.');
            throw $e;
        }
    
        static::assertNull(isset($cookie) ? $cookie : null);
    }

    public function testIsSecure()
    {
        $cookie = new Cookie('name', 'value', 0, '/', '', true);
        
        static::assertTrue($cookie->isSecure());

        $cookie->setSecure(false);

        static::assertFalse($cookie->isSecure());

        $cookie->setSecure(true);

        static::assertTrue($cookie->isSecure());
    }

    public function testIsHttpOnly()
    {
        $cookie = new Cookie('name', 'value', 0, '/', '', false, true, null);

        static::assertTrue($cookie->isHttpOnly());
    
        $cookie->setHttpOnly(false);

        static::assertFalse($cookie->isHttpOnly());

        $cookie->setHttpOnly(true);

        static::assertTrue($cookie->isHttpOnly());
    }

    /**
     * @dataProvider provideValidSameSite
     */
    public function testValidSameSite($sameSite, $expected)
    {
        
        $cookie = new Cookie('name', '', 0, '/', '', false, true, $sameSite);

        static::assertEquals($expected, $cookie->getSameSite());

        $cookie->setSameSite($sameSite);

        static::assertEquals($expected, $cookie->getSameSite());
    }

    /**
     * @dataProvider provideInvalidSameSite
     */
    public function testInvalidSameSite($sameSite)
    {

        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('The samesite is invalid.');

        try {
            $cookie = new Cookie('name', '', 0, '/', '', false, true, $sameSite);        
        } catch (Throwable $e) {
            throw $e;
        }

        static::assertNull(isset($cookie) ? $cookie : null);
    }

    /**
     * @dataProvider provideCookieToString
     */
    public function testCookieToString($cookie, $expected)
    {
        static::assertEquals($expected, (string) $cookie);
    }

    public function provideInvalidName()
    {
        return [
            [',name'],
            [';name'],
            [' name'],
            ["\tname"],
            ["\rname"],
            ["\nname"],
            ["\013name"],
            ["\014name"],
            ['test name']
        ];
    }

    public function provideValidSameSite()
    {
        return [
            ['Lax', Cookie::SAMESITE_LAX],
            ['None', Cookie::SAMESITE_NONE],
            ['Strict', Cookie::SAMESITE_STRICT],
            ['LAX', Cookie::SAMESITE_LAX],
            ['NONE', Cookie::SAMESITE_NONE],
            ['STRICT', Cookie::SAMESITE_STRICT],
            ['lax', Cookie::SAMESITE_LAX],
            ['none', Cookie::SAMESITE_NONE],
            ['strict', Cookie::SAMESITE_STRICT],
            ['LAx', Cookie::SAMESITE_LAX],
            ['NOne', Cookie::SAMESITE_NONE],
            ['STrict', Cookie::SAMESITE_STRICT],
            ['NONe', Cookie::SAMESITE_NONE],
            ['STRict', Cookie::SAMESITE_STRICT],
            ['STRIct', Cookie::SAMESITE_STRICT],
            ['STRICt', Cookie::SAMESITE_STRICT],
            [null, null]
        ];
    }

    public function provideInvalidSameSite()
    {
        return array_map(function ($args) {
            unset($args[1]);
            $args[0] = $args[0].$args[0];
            return $args;
        }, array_filter($this->provideValidSameSite(), function ($args) {
            return is_string($args[0]);
        }));
    }

    public function provideValidExpiration()
    {
        return [
            ['+1minute'],
            ['+1 minute'],
            ['+1minutes'],
            ['+1 minutes'],
            [new DateTime()],
            [new DateTimeImmutable()],
            [time() + (60 * 60) * 12]
        ];
    }

    public function provideCookieToString()
    {
        return [
            [
                new Cookie('foo'),
                sprintf('foo=deleted; Expires=%s; Max-Age=0; Path=/; HttpOnly; SameSite=Lax', gmdate("D, d-M-Y H:i:s T", time() - 31536001))
            ],

            [
                new Cookie('foo', 'bar'),
                'foo=bar; Path=/; HttpOnly; SameSite=Lax'
            ],

            [
                ($cookie = new Cookie('foo', 'bar', '+1day')),
                sprintf('foo=bar; Expires=%s; Max-Age=%s; Path=/; HttpOnly; SameSite=Lax', gmdate("D, d-M-Y H:i:s T", $cookie->getExpiration()), $cookie->getExpiration() - time())
            ],

            [
                ($cookie = new Cookie('foo', 'bar', '-1day')),
                sprintf('foo=bar; Expires=%s; Max-Age=0; Path=/; HttpOnly; SameSite=Lax', gmdate("D, d-M-Y H:i:s T", $cookie->getExpiration()))
            ],

            [
                ($cookie = new Cookie('foo', 'bar', '+1day', '/public')),
                sprintf('foo=bar; Expires=%s; Max-Age=%s; Path=/public; HttpOnly; SameSite=Lax', gmdate("D, d-M-Y H:i:s T", $cookie->getExpiration()), $cookie->getExpiration() - time())
            ],

            [
                ($cookie = new Cookie('foo', 'bar', '+1day', '/public', 'example.com')),
                sprintf('foo=bar; Expires=%s; Max-Age=%s; Path=/public; Domain=example.com; HttpOnly; SameSite=Lax', gmdate("D, d-M-Y H:i:s T", $cookie->getExpiration()), $cookie->getExpiration() - time())
            ],

            [
                ($cookie = new Cookie('foo', 'bar', '+1day', '/public', 'example.com', true)),
                sprintf('foo=bar; Expires=%s; Max-Age=%s; Path=/public; Domain=example.com; Secure; HttpOnly; SameSite=Lax', gmdate("D, d-M-Y H:i:s T", $cookie->getExpiration()), $cookie->getExpiration() - time())
            ],

            [
                ($cookie = new Cookie('foo', 'bar', '+1day', '/public', 'example.com', true, false)),
                sprintf('foo=bar; Expires=%s; Max-Age=%s; Path=/public; Domain=example.com; Secure; SameSite=Lax', gmdate("D, d-M-Y H:i:s T", $cookie->getExpiration()), $cookie->getExpiration() - time())
            ],

            [
                ($cookie = new Cookie('foo', 'bar', '+1day', '/public', 'example.com', true, false, Cookie::SAMESITE_STRICT)),
                sprintf('foo=bar; Expires=%s; Max-Age=%s; Path=/public; Domain=example.com; Secure; SameSite=Strict', gmdate("D, d-M-Y H:i:s T", $cookie->getExpiration()), $cookie->getExpiration() - time())
            ],

            [
                ($cookie = new Cookie('foo', 'bar', '+1day', '/public', 'example.com', true, false, Cookie::SAMESITE_NONE)),
                sprintf('foo=bar; Expires=%s; Max-Age=%s; Path=/public; Domain=example.com; Secure; SameSite=None', gmdate("D, d-M-Y H:i:s T", $cookie->getExpiration()), $cookie->getExpiration() - time())
            ],

            [
                ($cookie = new Cookie('foo', 'bar', '+1day', '/public', 'example.com', true, false, null)),
                sprintf('foo=bar; Expires=%s; Max-Age=%s; Path=/public; Domain=example.com; Secure', gmdate("D, d-M-Y H:i:s T", $cookie->getExpiration()), $cookie->getExpiration() - time())
            ]
        ];
    }
}