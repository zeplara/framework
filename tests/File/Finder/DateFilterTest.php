<?php

namespace Zeplara\Tests\File\Finder;

use InvalidArgumentException;
use PHPUnit\Framework\TestCase;
use Zeplara\File\Finder\DateFilter;
use Zeplara\Interfaces\File\SplFileInfo;

class DateFilterTest extends TestCase
{
    public function testInvalidOperator()
    {
        $this->expectException(InvalidArgumentException::class);
        $this->expectExceptionMessage('The operator is invalid.');

        $this->getDateFilterInstance(time(), '=')->accept($this->getSplFileInfo());
    }

    public function testLessThan()
    {
        self::assertTrue(
            $this->getDateFilterInstance(time(), '<')->accept($this->getSplFileInfo(time() - 60))
        );
    }

    public function testGreatherThan()
    {
        self::assertTrue(
            $this->getDateFilterInstance(time() - 60, '>')->accept($this->getSplFileInfo())
        );
    }

    public function testLessOrEquals()
    {
        self::assertTrue(
            $this->getDateFilterInstance(time(), '<=')->accept($this->getSplFileInfo(time() - 60))
        );

        $time = time();

        self::assertTrue(
            $this->getDateFilterInstance($time, '<=')->accept($this->getSplFileInfo($time))
        );
    }

    public function testGratherOrEquals()
    {
        self::assertTrue(
            $this->getDateFilterInstance(time() - 60, '>=')->accept($this->getSplFileInfo())
        );

        $time = time();

        self::assertTrue(
            $this->getDateFilterInstance($time, '>=')->accept($this->getSplFileInfo($time))
        );
    }

    public function testNotEquals()
    {
        self::assertTrue(
            $this->getDateFilterInstance(time() - 60, '!=')->accept($this->getSplFileInfo())
        );

        self::assertTrue(
            $this->getDateFilterInstance(time() - 60, '<>')->accept($this->getSplFileInfo())
        );

        $time = time();

        self::assertFalse(
            $this->getDateFilterInstance($time, '!=')->accept($this->getSplFileInfo($time))
        );

        self::assertFalse(
            $this->getDateFilterInstance((string) $time, '!=')->accept($this->getSplFileInfo($time))
        );

        self::assertFalse(
            $this->getDateFilterInstance($time, '<>')->accept($this->getSplFileInfo($time))
        );

        self::assertFalse(
            $this->getDateFilterInstance((string) $time, '<>')->accept($this->getSplFileInfo($time))
        );
    }

    public function testNotSame()
    {
        self::assertTrue(
            $this->getDateFilterInstance(time() - 60, '!==')->accept($this->getSplFileInfo())
        );

        $time = time();

        self::assertFalse(
            $this->getDateFilterInstance($time, '!==')->accept($this->getSplFileInfo($time))
        );

        self::assertTrue(
            $this->getDateFilterInstance((string) $time, '!==')->accept($this->getSplFileInfo($time))
        );
    }

    public function testEquals()
    {
        $time = time();

        self::assertTrue(
            $this->getDateFilterInstance($time, '==')->accept($this->getSplFileInfo($time))
        );

        self::assertTrue(
            $this->getDateFilterInstance((string) $time, '==')->accept($this->getSplFileInfo($time))
        );
    }

    public function testSame()
    {
        $time = time();

        self::assertTrue(
            $this->getDateFilterInstance($time, '===')->accept($this->getSplFileInfo($time))
        );

        self::assertFalse(
            $this->getDateFilterInstance((string) $time, '===')->accept($this->getSplFileInfo($time))
        );
    }

    private function getDateFilterInstance($time, $operator = null)
    {
        return new DateFilter($time, $operator);
    }

    private function getSplFileInfo($mTime = null)
    {
        return new class($mTime) implements SplFileInfo {
            protected $mTime;

            public function __construct($mTime = null)
            {
                $this->mTime = $mTime ?: time();
            }

            public function getMTime()
            {
                return $this->mTime;
            }
        };
    }
}
