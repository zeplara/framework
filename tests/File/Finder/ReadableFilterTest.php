<?php

namespace Zeplara\Tests\File\Finder;

use PHPUnit\Framework\TestCase;
use Zeplara\Interfaces\File\SplFileInfo;
use Zeplara\File\Finder\ReadableFilter;

class ReadableFilterTest extends TestCase
{
    public function setUp() : void
    {
        $this->filter = new ReadableFilter;
    }

    public function testIsAccepted()
    {
        self::assertTrue($this->filter->accept($this->getSplFileInfo()));
    }

    public function testIsNotAccepted()
    {
        self::assertFalse($this->filter->accept($this->getSplFileInfo(false)));
    }

    private function getSplFileInfo($readable = true)
    {
        return new class($readable) implements SplFileInfo {
            public function __construct($readable)
            {
                $this->readable = $readable;
            }

            public function isReadable()
            {
                return $this->readable;
            }
        };
    }
}