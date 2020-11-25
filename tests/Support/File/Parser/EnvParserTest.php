<?php

namespace Zeplara\Tests\Support\File\Parser;

use PHPUnit\Framework\TestCase;
use Zeplara\Support\File\Parser\EnvParser;
use Zeplara\Support\File\Parser\ParserException;

class EnvParserTest extends TestCase
{
    public function testBasicValue()
    {    
        $env = EnvParser::parse('APP_NAME=Zeplara');

        static::assertIsArray($env);
        static::assertArrayHasKey('APP_NAME', $env);
        static::assertEquals('Zeplara', $env['APP_NAME']);
    }

    public function testNullValue()
    {
        $null = EnvParser::parse('APP_KEY')['APP_KEY'];
        static::assertNull($null);

        $null = EnvParser::parse('APP_KEY ')['APP_KEY'];
        static::assertNull($null);

        $null = EnvParser::parse('APP_KEY=')['APP_KEY'];
        static::assertNull($null);

        $null = EnvParser::parse('APP_KEY = ')['APP_KEY'];
        static::assertNull($null);
    }

    public function testBooleanValue()
    {
        $debug = EnvParser::parse('APP_DEBUG=true')['APP_DEBUG'];
        
        static::assertIsBool($debug);
        static::assertTrue($debug);
    }

    public function testFloatValue()
    {
        $value = EnvParser::parse('CACHE_TIMEOUT=1.5')['CACHE_TIMEOUT'];

        static::assertIsFloat($value);

        $value = EnvParser::parse('CACHE_TIMEOUT=.5')['CACHE_TIMEOUT'];

        static::assertIsFloat($value);

        $value = EnvParser::parse('CACHE_TIMEOUT=-1.5')['CACHE_TIMEOUT'];

        static::assertIsFloat($value);

        $value = EnvParser::parse('CACHE_TIMEOUT=+1.5')['CACHE_TIMEOUT'];

        static::assertIsFloat($value);

        $value = EnvParser::parse('CACHE_TIMEOUT=+.5')['CACHE_TIMEOUT'];

        static::assertIsFloat($value);

        $value = EnvParser::parse('CACHE_TIMEOUT=1e7')['CACHE_TIMEOUT'];

        static::assertIsFloat($value);

        $value = EnvParser::parse('CACHE_TIMEOUT=1E7')['CACHE_TIMEOUT'];

        static::assertIsFloat($value);
    }

    public function testQuotedValue()
    {
        $value = EnvParser::parse('APP_NAME="Zeplara PHP Framework"')['APP_NAME'];

        static::assertIsString($value);

        static::assertEquals('Zeplara PHP Framework', $value);

        $value = EnvParser::parse('APP_DESCRIPTION="Hello i\"m Zeplara"')['APP_DESCRIPTION'];


        static::assertEquals('Hello i"m Zeplara', $value);    
    }

    public function testArrayValue()
    {
        $export = function($fn, $var, $indent="") {
            switch (gettype($var)) {
                case "string":
                    return '"' . addcslashes($var, "\\\$\"\r\n\t\v\f") . '"';
                case "array":
                    $indexed = array_keys($var) === range(0, count($var) - 1);
                    $r = [];
                    foreach ($var as $key => $value) {
                        $r[] = "$indent    "
                            . ($indexed ? "" : $fn($fn, $key) . " : ")
                            . $fn($fn, $value, "$indent    ");
                    }
                    return "[\n" . implode(",\n", $r) . "\n" . $indent . "]";
                case "boolean":
                    return $var ? "TRUE" : "FALSE";
                default:
                    return var_export($var, TRUE);
            }
        };

        $lists = [
            [
                "id" => 1,
                "name" => "example",
                "domain" => "example.com",
                "childrens" => [
                    [
                        "id" => 2,
                        "name" => "lorem",
                        "domain" => "lorem.example.com"
                    ]
                ],
            ],
            [
                "id" => 3,
                "name" => "hello world",
                "domain" => "hello_world.com",
            ]
        ];

        $values = EnvParser::parse(sprintf('APP_LISTS=%s', $export($export, $lists, "")))['APP_LISTS'];

        $similar = function ($fn, $a, $b) {
            foreach ($a as $key => $value) {
                if (is_array($value)) {
                    $fn($fn, $a[$key], $b[$key]);
                    continue;
                }

                self::assertEquals($value, $b[$key]);
            }
        };

        $similar($similar, $lists, $values);

        static::assertIsArray($values);
    }

    public function testInvalidKeyFormat()
    {
        $env = null;
        try {
            $env = EnvParser::parse('APP-NAME=Zepalra');
        } catch (ParserException $e) {
            static::assertInstanceOf(ParserException::class, $e);
            static::assertEquals(1, $e->getLine());
        }
        static::assertNull($env);
        
        $env = null;
        try {
            $env = EnvParser::parse('`APP-NAME=Zepalra');
        } catch (ParserException $e) {
            static::assertInstanceOf(ParserException::class, $e);
            static::assertEquals(1, $e->getLine());
        }
        static::assertNull($env);

        $env = null;
        try {
            $env = EnvParser::parse('APP NAME=Zepalra');
        } catch (ParserException $e) {
            static::assertInstanceOf(ParserException::class, $e);
            static::assertEquals(1, $e->getLine());
        }
        static::assertNull($env);

        $env = null;
        try {
            $env = EnvParser::parse('APP NAME');
        } catch (ParserException $e) {
            static::assertInstanceOf(ParserException::class, $e);
            static::assertEquals(1, $e->getLine());
        }
        static::assertNull($env);        
    }

    public function testErrorMultipleVariableBasicValue()
    {
        $this->expectException(ParserException::class);
        $this->expectExceptionMessage('Syntax error [APP_NAME=Zepalra PHP Framework], Unexpected Inline Multiple Variable.');

        EnvParser::parse('APP_NAME=Zepalra PHP Framework');
    }

    public function testErrorMultipleVariableQuotedValue()
    {
        $this->expectException(ParserException::class);
        $this->expectExceptionMessage('Syntax error [APP_NAME="Zepalra PHP Framework" No], Unexpected Inline Multiple Variable.');

        EnvParser::parse('APP_NAME="Zepalra PHP Framework" No');
    }

    public function testErrorMultipleVariableArrayValue()
    {
        $this->expectException(ParserException::class);
        
        EnvParser::parse(<<<EOL
            STUDENT_LISTS = [
                "Mochammad Riyadh Ilham Akbar Pasya",
                "Jhon Doe"
            ] blah
        EOL);
    }

    public function testErrorSyntaxArrayValue()
    {
        $env = null;
        try {
            $env = EnvParser::parse(<<<EOL
                STUDENT_LISTS = [
                    "Mochammad Riyadh Ilham Akbar Pasya" "Jhon Doe"
                ]
            EOL);
        } catch (ParserException $e) {
            static::assertInstanceOf(ParserException::class, $e);
            static::assertEquals('Syntax error ["Mochammad Riyadh Ilham Akbar Pasya" "Jhon Doe"].', $e->getMessage());
            static::assertEquals(2, $e->getLine());
        }
        static::assertNull($env);

        $env = null;
        try {
            $env = EnvParser::parse(<<<EOL
                STUDENT_LISTS = [
                    [
                        "name" => "Mochammad Riyadh Ilham"
                    ],
                    [
                        "Name" : "Jhon Doe"
                    ]
                ]
            EOL);
        } catch (ParserException $e) {
            static::assertInstanceOf(ParserException::class, $e);
            static::assertEquals(3, $e->getLine());
            static::assertEquals('Syntax error ["name" => "Mochammad Riyadh Ilham"].', $e->getMessage());
        }
        static::assertNull($env);

        $env = null;
        try {
            $env = EnvParser::parse(<<<EOL
                STUDENT_LISTS = [
                    [
                        "name": Mochammad Riyadh Ilham,
                    ],
                    [
                        "Name" : "Jhon Doe"
                    ]
                ]
            EOL);
        } catch (ParserException $e) {
            static::assertInstanceOf(ParserException::class, $e);
            static::assertEquals(3, $e->getLine());
            static::assertEquals("Syntax error [Mochammad Riyadh Ilham].", $e->getMessage());
        }
        static::assertNull($env);
    }

    public function testCommentedKey()
    {
        $env = EnvParser::parse(<<<EOL
            #COMMENT_KEY_BASIC=abc
            #COMMENT_KEY_QUOTED="abc def"
            #COMMENT_KEY_FLOAT=1.5
            #COMMENT_KEY_ARRAY=[
                1,
                [
                    "hello",
                    "lists": [
                        1,
                        [
                            2, 3
                        ]
                    ]
                ]
            ]
            #COMMENT_KEY_BOOL=true
            #COMMENT_KEY_NULL_EMPTY_VALUE=
            #COMMENT_KEY_NULL_WITH_VALUE=null
        EOL);

        foreach ([
            'BASIC',
            'QUOTED',
            'FLOAT',
            'ARRAY',
            'BOOL',
            'NULL_EMPTY_VALUE',
            'NULL_WITH_VALUE'
        ] as $key) {
            static::assertArrayNotHasKey(sprintf('COMMENT_KEY_%s', $key), $env);
        }

        static::assertEmpty($env);
    }

    public function testCommentedValueBasic()
    {
        $value = EnvParser::parse('APP_NAME=#comment#Zeplara')['APP_NAME'];
        self::assertEquals('Zeplara', $value);

        $value = EnvParser::parse('APP_NAME=#comment# Zeplara')['APP_NAME'];
        self::assertEquals('Zeplara', $value);
    }

    public function testCommentedValueQuoted()
    {
        $value = EnvParser::parse('APP_NAME=#comment#"Zeplara PHP Framework"')['APP_NAME'];
        self::assertEquals('Zeplara PHP Framework', $value);

        $value = EnvParser::parse('APP_NAME=#comment# "Zeplara PHP Framework"')['APP_NAME'];
        self::assertEquals('Zeplara PHP Framework', $value);

        $value = EnvParser::parse('APP_NAME=#comment# "Zeplara #not_replaced_comment PHP Framework"')['APP_NAME'];
        self::assertEquals('Zeplara #not_replaced_comment PHP Framework', $value);
    }

    public function testCommentedValueBool()
    {
        $value = EnvParser::parse('APP_DEBUG=#comment#true')['APP_DEBUG'];
        self::assertTrue($value);

        $value = EnvParser::parse('APP_DEBUG=#comment# true')['APP_DEBUG'];
        self::assertTrue($value);

        $value = EnvParser::parse('APP_DEBUG=#comment#false')['APP_DEBUG'];
        self::assertFalse($value);

        $value = EnvParser::parse('APP_DEBUG=#comment# false')['APP_DEBUG'];
        self::assertFalse($value);
    }

    public function testCommentedValueNull()
    {
        $value = EnvParser::parse('APP_KEY=#comment')['APP_KEY'];
        self::assertNull($value);

        $value = EnvParser::parse('APP_KEY=#comment#')['APP_KEY'];
        self::assertNull($value);

        $value = EnvParser::parse('APP_KEY=#comment#null')['APP_KEY'];
        self::assertNull($value);
    }

    public function testCommentedValueArray()
    {
        $values = EnvParser::parse(<<<EOL
            APP_LISTS=[
                #comment
                "key": #comment#"value",
                "nested": [
                    #comment
                ]
            ]
        EOL)['APP_LISTS'];
        
        self::assertEquals('value', $values['key']);
        self::assertArrayHasKey('nested', $values);
        self::assertIsArray($values['nested']);
        self::assertCount(0, $values['nested']);
    }

    public function testBasicValueVariable()
    {
        $env = EnvParser::parse(<<<EOL
        APP_NAME=Zeplara
        APP_NAME_PUB=\${APP_NAME}
        EOL);

        self::assertEquals($env['APP_NAME'], $env['APP_NAME_PUB']);
    }

    public function testStringValueVariable()
    {
        $env = EnvParser::parse(<<<EOL
        APP_NAME=Zeplara
        APP_NAME_PUB="\${APP_NAME} PHP Framework"
        EOL);

        self::assertEquals(sprintf('%s PHP Framework', $env['APP_NAME']), $env['APP_NAME_PUB']);
    }

    public function testBooleanValueVariable()
    {
        $env = EnvParser::parse(<<<EOL
        APP_DEBUG=True
        APP_DEBUG_PUB=\${APP_DEBUG}
        EOL);

        self::assertIsBool($env['APP_DEBUG_PUB']);
        self::assertTrue($env['APP_DEBUG_PUB']);

        $env = EnvParser::parse(<<<EOL
        APP_DEBUG=False
        APP_DEBUG_PUB=\${APP_DEBUG}
        EOL);

        self::assertIsBool($env['APP_DEBUG_PUB']);
        self::assertFalse($env['APP_DEBUG_PUB']);
    }

    public function testIntValueVariable()
    {
        $env = EnvParser::parse(<<<EOL
        CACHE_TIMEOUT=5200
        CACHE_TIMEOUT_PUB=\${CACHE_TIMEOUT}
        EOL);

        self::assertIsInt($env['CACHE_TIMEOUT_PUB']);
        self::assertEquals(5200, $env['CACHE_TIMEOUT_PUB']);
    }

    public function testFloatValueVariable()
    {
        $env = EnvParser::parse(<<<EOL
        CACHE_TIMEOUT=5200.5
        CACHE_TIMEOUT_PUB=\${CACHE_TIMEOUT}
        EOL);

        self::assertIsFloat($env['CACHE_TIMEOUT_PUB']);
        self::assertEquals(5200.5, $env['CACHE_TIMEOUT_PUB']);
    }

    public function testArrayValueVariable()
    {
        $env = EnvParser::parse(<<<EOL
        APP_NAME=Zeplara
        APP_LISTS = [
            [
                "name": \${APP_NAME},
                "expiration": null,
                "domain": "zeplara.me"
            ]
        ]
        APP_CONFIG=[
            "name": \${APP_NAME},
            "lists": \${APP_LISTS}
        ]
        EOL);

        self::assertEquals($env['APP_NAME'], $env['APP_LISTS'][0]['name']);
        self::assertEquals($env['APP_NAME'], $env['APP_CONFIG']['name']);
        self::assertEquals($env['APP_LISTS'], $env['APP_CONFIG']['lists']);
    }
}