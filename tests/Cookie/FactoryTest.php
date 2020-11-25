<?php

namespace Zeplara\Tests\Cookie;

use Zeplara\Cookie\Factory;
use PHPUnit\Framework\TestCase;
use Zeplara\Contracts\Cookie\Cookie;

class FactoryTest extends TestCase
{
    public function testMake()
    {
        $cookie = Factory::make('name');
        self::assertSame('name', $cookie->getName());
        self::assertSame('', $cookie->getValue());
        self::assertSame(0, $cookie->getExpiration());
        self::assertSame('/', $cookie->getPath());
        self::assertSame('', $cookie->getDomain());
        self::assertFalse($cookie->isSecure());
        self::assertTrue($cookie->isHttpOnly());
        self::assertNull($cookie->getSameSite());

        $cookie = Factory::make('name', 'value', ($expiration = time() * 30), '/zeplara', '.domain.com', true, false, Cookie::SAMESITE_LAX);
        self::assertSame('name', $cookie->getName());
        self::assertSame('value', $cookie->getValue());
        self::assertSame($expiration, $cookie->getExpiration());
        self::assertSame('/zeplara', $cookie->getPath());
        self::assertSame('.domain.com', $cookie->getDomain());
        self::assertTrue($cookie->isSecure());
        self::assertFalse($cookie->isHttpOnly());
        self::assertSame(Cookie::SAMESITE_LAX, $cookie->getSameSite());
    }

    public function testForever()
    {
        self::assertEquals(Factory::make('name', '', time() + (10 * 365 * 24 * 60 * 60)), Factory::forever('name'));
        
        self::assertEquals(Factory::make('name', 'value', time() + (10 * 365 * 24 * 60 * 60)), Factory::forever('name', 'value'));
    }

    public function testForget()
    {
        self::assertEquals(Factory::make('name', '', time() - 3600), Factory::forget('name'));
        self::assertEquals(Factory::make('name', '', time() - 3600), Factory::forget('name'));
    }
}