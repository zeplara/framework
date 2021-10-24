<?php

namespace Zeplara\Tests\File\Finder;

use PHPUnit\Framework\TestCase;
use Zeplara\Interfaces\File\SplFileInfo;
use Zeplara\File\Finder\DirectoryFilter;

class DirectoryFilterTest extends TestCase
{
    public function setUp() : void
    {
        $this->filter = new DirectoryFilter;
    }

    public function testIsDirectoryIsTrue()
    {
        self::assertTrue($this->filter->accept($this->getSplFileInfo()));
    }

    public function testIsDirectoryIsFalse()
    {
        self::assertTrue($this->filter->accept($this->getSplFileInfo()));
    }

    private function getSplFileInfo($isDir = true)
    {
        return new class($isDir) implements SplFileInfo {
            public function __construct($isDir = true)
            {
                $this->isDir = $isDir;
            }

            public function isDir()
            {
                return $this->isDir;
            }
        };
    }
}