<?php

namespace Zeplara\Tests\Support;

use Zeplara\Support\Arr;
use PHPUnit\Framework\TestCase;

class ArrTest extends TestCase
{
    public function testGet()
    {
        $lists = [
            'key1' => [
                'key1_nested1' => 'key1_nested1_value',
            ],
            'key2.key2_nested1' => 'key2_nested1_value',
            'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3' => [
                'key_2.nested_4' => 'key2_nested4_value'
            ]
        ];

        self::assertSame('key1_nested1_value', Arr::get($lists, 'key1.key1_nested1'));
        self::assertSame('key2_nested1_value', Arr::get($lists, 'key2.key2_nested1'));
        self::assertNull(Arr::get($lists, 'key3.key3_nested1'));
        self::assertSame('value', Arr::get($lists, 'key3.key3_nested1', 'value'));
        self::assertArrayHasKey('key_2.nested_4', Arr::get($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3'));
        self::assertSame(['key_2.nested_4' => 'key2_nested4_value'], Arr::get($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3'));
        self::assertSame('key2_nested4_value', Arr::get($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3.key_2.nested_4'));
    }

    public function testHas()
    {
        $lists = [
            'key1' => [
                'key1_nested1' => 'key1_nested1_value',
            ],
            'key2.key2_nested1' => 'key2_nested1_value',
            'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3' => [
                'key_2.nested_4' => 'key2_nested4_value'
            ]
        ];

        self::assertTrue(Arr::has($lists, 'key1'));
        self::assertTrue(Arr::has($lists, 'key1.key1_nested1'));
        self::assertFalse(Arr::has($lists, 'key2'));
        self::assertTrue(Arr::has($lists, 'key2.key2_nested1'));
        self::assertTrue(Arr::has($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3'));
        self::assertTrue(Arr::has($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3.key_2.nested_4'));
    }

    public function testPut()
    {
        $lists = [
            'key1' => [
                'key1_nested1' => 'key1_nested1_value',
            ],
            'key2.key2_nested1' => 'key2_nested1_value',
            'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3' => [
                'key_2.nested_4' => 'key2_nested4_value'
            ]
        ];
        

        $lists = Arr::put($lists, 'key1.key1_nested1');
        self::assertArrayHasKey('key1', $lists);
        self::assertArrayNotHasKey('key1_nested1', $lists['key1']);
        $lists = Arr::put($lists, 'key1');
        self::assertArrayNotHasKey('key1', $lists);
        $lists = Arr::put($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3.key_2.nested_4');
        self::assertArrayHasKey('key2.key_2_nested_1.key_2_nested_2.key_2.nested_3', $lists);
        self::assertArrayNotHasKey('key_2.nested_4', $lists['key2.key_2_nested_1.key_2_nested_2.key_2.nested_3']);
        $lists = Arr::put($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3');
        self::assertArrayNotHasKey('key2.key_2_nested_1.key_2_nested_2.key_2.nested_3', $lists);
        $lists = Arr::put($lists, 'key2.key2_nested1');
        self::assertArrayNotHasKey('key2.key2_nested1', $lists);
        self::assertCount(0, $lists);
    }

    public function testSet()
    {
        $lists = [
            'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3' => [
                'key_2.nested_4' => 'key2_nested4_value'
            ]
        ];
        $lists_expected = [
            'key1' => [
                'key1_nested1' => 'key1_nested1_value',
            ],
            'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3' => [
                'key_2.nested_4' => 'key2_nested4_value'
            ]
        ];

        $lists = Arr::set($lists, 'key1.key1_nested1', 'key1_nested1_value');
        self::assertArrayHasKey('key1', $lists);
        self::assertArrayHasKey('key1_nested1', $lists['key1']);
        $lists = Arr::set($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3.key_2.nested_4', 'key2_nested4_value_replace');
        self::assertSame('key2_nested4_value_replace', $lists['key2.key_2_nested_1.key_2_nested_2.key_2.nested_3']['key_2.nested_4']);
    }

    public function testFlatten()
    {
        $array = ['foo', 'bar', 'baz'];
        self::assertSame(['foo', 'bar', 'baz'], Arr::flatten($array));
        $array = [['foo', 'bar'], 'baz'];
        self::assertSame(['foo', 'bar', 'baz'], Arr::flatten($array));
        $array = [['foo', null], 'baz', null];
        self::assertSame(['foo', null, 'baz', null], Arr::flatten($array));
        $array = [['foo', 'bar'], ['baz']];
        self::assertSame(['foo', 'bar', 'baz'], Arr::flatten($array));
        $array = [['foo', ['bar']], ['baz']];
        self::assertSame(['foo', 'bar', 'baz'], Arr::flatten($array));
    }

    public function testWrap()
    {
        self::assertIsArray(Arr::wrap('foo'));

        self::assertIsArray(Arr::wrap(['foo']));

        self::assertSame(['foo'], Arr::wrap(['foo']));
    }

    public function testFirst()
    {
        self::assertSame('foo', Arr::first(['foo', 'bar']));
        self::assertNull(Arr::first([]));
        self::assertSame('foo', Arr::first([], 'foo'));
    }

    public function testLast()
    {
        self::assertSame('bar', Arr::last(['foo', 'bar']));
        self::assertNull(Arr::last([]));
        self::assertSame('bar', Arr::last([], 'bar'));
    }
}