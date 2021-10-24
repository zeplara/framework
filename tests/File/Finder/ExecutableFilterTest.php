<?php

namespace Zeplara\Tests\File\Finder;

use PHPUnit\Framework\TestCase;
use Zeplara\Interfaces\File\SplFileInfo;
use Zeplara\File\Finder\ExecutableFilter;

class ExecutableFilterTest extends TestCase
{
    public function setUp() : void
    {
        $this->filter = new ExecutableFilter;
    }

    public function testIsAccepted()
    {
        self::assertTrue($this->filter->accept($this->getSplFileInfo()));
    }

    public function testIsNotAccepted()
    {
        self::assertTrue($this->filter->accept($this->getSplFileInfo()));
    }

    private function getSplFileInfo($isExecutable = true)
    {
        return new class($isExecutable) implements SplFileInfo {
            public function __construct($isExecutable = true)
            {
                $this->isExecutable = $isExecutable;
            }

            public function isExecutable()
            {
                return $this->isExecutable;
            }
        };
    }
}