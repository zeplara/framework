<?php

namespace Zeplara\Tests\File\Finder;

use PHPUnit\Framework\TestCase;
use Zeplara\Contracts\File\SplFileInfo;
use Zeplara\File\Finder\WritableFilter;

class WritableFilterTest extends TestCase
{
    public function setUp() : void
    {
        $this->filter = new WritableFilter;
    }

    public function testIsAccepted()
    {
        self::assertTrue($this->filter->accept($this->getSplFileInfo()));
    }

    public function testIsNotAccepted()
    {
        self::assertFalse($this->filter->accept($this->getSplFileInfo(false)));
    }

    private function getSplFileInfo($writable = true)
    {
        return new class($writable) implements SplFileInfo {
            public function __construct($writable = true)
            {
                $this->writable = $writable;
            }

            public function isWritable()
            {
                return $this->writable;
            }
        };
    }
}