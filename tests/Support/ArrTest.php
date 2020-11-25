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

        static::assertEquals('key1_nested1_value', Arr::get($lists, 'key1.key1_nested1'));
        static::assertEquals('key2_nested1_value', Arr::get($lists, 'key2.key2_nested1'));
        static::assertNull(Arr::get($lists, 'key3.key3_nested1'));
        static::assertEquals('value', Arr::get($lists, 'key3.key3_nested1', 'value'));
        static::assertArrayHasKey('key_2.nested_4', Arr::get($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3'));
        static::assertEquals(['key_2.nested_4' => 'key2_nested4_value'], Arr::get($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3'));
        static::assertEquals('key2_nested4_value', Arr::get($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3.key_2.nested_4'));
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

        static::assertTrue(Arr::has($lists, 'key1'));
        static::assertTrue(Arr::has($lists, 'key1.key1_nested1'));
        static::assertFalse(Arr::has($lists, 'key2'));
        static::assertTrue(Arr::has($lists, 'key2.key2_nested1'));
        static::assertTrue(Arr::has($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3'));
        static::assertTrue(Arr::has($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3.key_2.nested_4'));
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
        static::assertArrayHasKey('key1', $lists);
        static::assertArrayNotHasKey('key1_nested1', $lists['key1']);
        $lists = Arr::put($lists, 'key1');
        static::assertArrayNotHasKey('key1', $lists);
        $lists = Arr::put($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3.key_2.nested_4');
        static::assertArrayHasKey('key2.key_2_nested_1.key_2_nested_2.key_2.nested_3', $lists);
        static::assertArrayNotHasKey('key_2.nested_4', $lists['key2.key_2_nested_1.key_2_nested_2.key_2.nested_3']);
        $lists = Arr::put($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3');
        static::assertArrayNotHasKey('key2.key_2_nested_1.key_2_nested_2.key_2.nested_3', $lists);
        $lists = Arr::put($lists, 'key2.key2_nested1');
        static::assertArrayNotHasKey('key2.key2_nested1', $lists);
        static::assertCount(0, $lists);
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
        static::assertArrayHasKey('key1', $lists);
        static::assertArrayHasKey('key1_nested1', $lists['key1']);
        $lists = Arr::set($lists, 'key2.key_2_nested_1.key_2_nested_2.key_2.nested_3.key_2.nested_4', 'key2_nested4_value_replace');
        static::assertEquals('key2_nested4_value_replace', $lists['key2.key_2_nested_1.key_2_nested_2.key_2.nested_3']['key_2.nested_4']);
    }

    public function testFlatten()
    {
        $array = ['foo', 'bar', 'baz'];
        static::assertEquals(['foo', 'bar', 'baz'], Arr::flatten($array));
        $array = [['foo', 'bar'], 'baz'];
        static::assertEquals(['foo', 'bar', 'baz'], Arr::flatten($array));
        $array = [['foo', null], 'baz', null];
        static::assertEquals(['foo', null, 'baz', null], Arr::flatten($array));
        $array = [['foo', 'bar'], ['baz']];
        static::assertEquals(['foo', 'bar', 'baz'], Arr::flatten($array));
        $array = [['foo', ['bar']], ['baz']];
        static::assertEquals(['foo', 'bar', 'baz'], Arr::flatten($array));
    }

    public function testWrap()
    {
        static::assertIsArray(Arr::wrap('foo'));

        static::assertIsArray(Arr::wrap(['foo']));

        static::assertEquals(['foo'], Arr::wrap(['foo']));
    }

    public function testFirst()
    {
        static::assertEquals('foo', Arr::first(['foo', 'bar']));
        static::assertNull(Arr::first([]));
        static::assertEquals('foo', Arr::first([], 'foo'));
    }

    public function testLast()
    {
        static::assertEquals('bar', Arr::last(['foo', 'bar']));
        static::assertNull(Arr::last([]));
        static::assertEquals('bar', Arr::last([], 'bar'));
    }
}