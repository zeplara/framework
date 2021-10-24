<?php

namespace Zeplara\Tests\File\Finder;

use PHPUnit\Framework\TestCase;
use Zeplara\File\Finder\LinkFilter;
use Zeplara\Interfaces\File\SplFileInfo;

class LinkFilterTest extends TestCase
{
    public function setUp() : void
    {
        $this->filter = new LinkFilter;
    }

    public function testIsAccepted()
    {
        self::assertTrue($this->filter->accept($this->getSplFileInfo(true)));
    }

    public function testIsNotAccepted()
    {
        self::assertFalse($this->filter->accept($this->getSplFileInfo(false)));
    }

    private function getSplFileInfo($isLink = true)
    {
        return new class($isLink) implements SplFileInfo {
            public function __construct($isLink = true)
            {
                $this->isLink = $isLink;
            }

            public function isLink()
            {
                return $this->isLink;
            }
        };
    }
}