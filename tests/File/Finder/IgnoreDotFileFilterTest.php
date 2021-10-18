<?php

namespace Zeplara\Tests\File\Finder;

use PHPUnit\Framework\TestCase;
use Zeplara\Contracts\File\SplFileInfo;
use Zeplara\File\Finder\IgnoreDotFileFilter;

class IgnoreDotFileFilterTest extends TestCase
{
    public function setUp() : void
    {
        $this->filter = new IgnoreDotFileFilter;
    }

    public function testIsAccepted()
    {
        self::assertTrue($this->filter->accept($this->getSplFileInfo(true, "test.php")));
    }

    public function testIsNotAccepted()
    {
        self::assertFalse($this->filter->accept($this->getSplFileInfo(true)));
        self::assertFalse($this->filter->accept($this->getSplFileInfo(true, ".env")));
    }

    private function getSplFileInfo($isFile = true, $fileName = "")
    {
        return new class($isFile, $fileName) implements SplFileInfo {
            public function __construct($isFile = true, $fileName = "")
            {
                $this->isFile = $isFile;
                $this->fileName = $fileName;
            }

            public function isFile()
            {
                return $this->isFile;
            }

            public function __toString()
            {
                return $this->fileName;
            }
        };
    }
}