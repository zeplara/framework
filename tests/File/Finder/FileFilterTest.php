<?php

namespace Zeplara\Tests\File\Finder;

use PHPUnit\Framework\TestCase;
use Zeplara\File\Finder\FileFilter;
use Zeplara\Interfaces\File\SplFileInfo;

class FileFilterTest extends TestCase
{
    public function setUp() : void
    {
        $this->filter = new FileFilter;
    }

    public function testIsAccepted()
    {
        self::assertTrue($this->filter->accept($this->getSplFileInfo()));
    }

    public function testIsNotAccepted()
    {
        self::assertTrue($this->filter->accept($this->getSplFileInfo()));
    }

    private function getSplFileInfo($isFile = true)
    {
        return new class($isFile) implements SplFileInfo {
            public function __construct($isFile = true)
            {
                $this->isFile = $isFile;
            }

            public function isFile()
            {
                return $this->isFile;
            }
        };
    }
}