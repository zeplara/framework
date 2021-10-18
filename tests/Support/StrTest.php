<?php

namespace Zeplara\Tests\Support;

use Zeplara\Support\Str;
use InvalidArgumentException;
use PHPUnit\Framework\TestCase;

class StrTest extends TestCase
{
    public function testStudly()
    {
        $rawString = '';
        $studlyString = '';
        foreach (range(1, 10) as $range) {
            static::assertSame(($studlyString .= sprintf('Str%d', $range)), Str::studly(($rawString .= sprintf('%sstr%d', $rawString ? ' ' : '', $range))));
        }
    }

    public function testSnake()
    {
        $rawString = '';
        $snakeString = '';
        foreach (range(1, 10) as $range) {
            static::assertSame(($snakeString .= sprintf('%sstr%d', $snakeString ? '_' : '', $range)), Str::snake(($rawString .= sprintf('%sstr%d', $rawString ? ' ' : '', $range))));
        }
    }

    public function testKebab()
    {
        $rawString = '';
        $snakeString = '';
        foreach (range(1, 10) as $range) {
            static::assertSame(($snakeString .= sprintf('%sstr%d', $snakeString ? '-' : '', $range)), Str::kebab(($rawString .= sprintf('%sstr%d', $rawString ? ' ' : '', $range))));
        }
    }

    public function testLower()
    {
        $rawString = '';
        $snakeString = '';
        foreach (range(1, 10) as $range) {
            static::assertSame(($snakeString .= sprintf('%sstr%d', $snakeString ? ' ' : '', $range)), Str::lower(($rawString .= sprintf('%sStr%d', $rawString ? ' ' : '', $range))));
        }
    }

    public function testUpper()
    {
        $rawString = '';
        $snakeString = '';
        foreach (range(1, 10) as $range) {
            static::assertSame(($snakeString .= sprintf('%sSTR%d', $snakeString ? ' ' : '', $range)), Str::upper(($rawString .= sprintf('%sstr%d', $rawString ? ' ' : '', $range))));
        }
    }

    public function testTitle()
    {
        $rawString = '';
        $snakeString = '';
        foreach (range(1, 10) as $range) {
            static::assertSame(($snakeString .= sprintf('%sStr%d', $snakeString ? ' ' : '', $range)), Str::title(($rawString .= sprintf('%sStr%d', $rawString ? ' ' : '', $range))));
        }
    }

    public function testAscii()
    {
        static::assertSame('@', Str::ascii('@'));
        static::assertSame('u', Str::ascii('ü'));
        static::assertSame('h H sht SHT a A ia yo', Str::ascii('х Х щ Щ ъ Ъ иа йо', 'bg'));
        static::assertSame('ae oe ue AE OE UE', Str::ascii('ä ö ü Ä Ö Ü', 'de'));
        static::assertSame('a a i s t A A I S T', Str::ascii('ă â î ș ț Ă Â Î Ș Ț'));
    }

    public function testSlug()
    {
        $rawString = '';
        $snakeString = '';
        foreach (range(1, 10) as $range) {
            static::assertSame(($snakeString .= sprintf('%sstr%d', $snakeString ? '-' : '', $range)), Str::slug(($rawString .= sprintf('%sstr%d', $rawString ? '-' : '', $range))));
        }
    }

    public function testUuid()
    {

    }

    public function testCapitalize()
    {
        foreach ([
            ['ilham pasya', 'Ilham pasya'],
            ['ilham Pasya', 'Ilham pasya'],
            ['Ilham Pasya', 'Ilham pasya']
        ] as $value) {
            static::assertSame($value[1], Str::capitalize($value[0]));
        }
    }

    public function testRandom()
    {
       for ($i = 1; $i < 100; ++$i) {
            static::assertSame($i, strlen(Str::random($i)));
       }
    }

    public function testRandomInvalidLength()
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('The length must be greater than zero.');
    
        Str::random(0);
    }
}