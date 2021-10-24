<?php

namespace Zeplara\Tests\File\Finder;

use PHPUnit\Framework\TestCase;
use Zeplara\File\Finder\CallbackFilter;
use Zeplara\Interfaces\File\SplFileInfo;

class CallbackFilterTest extends TestCase
{
    public function testIsAccepted()
    {
        self::assertTrue($this->getCallbackFilterInstance(function () {
            return true;
        })->accept($this->getSplFileInfo()));
    }

    public function testIsNotAccepted()
    {
        self::assertFalse($this->getCallbackFilterInstance(function () {
            return false;
        })->accept($this->getSplFileInfo()));
    }

    private function getCallbackFilterInstance(callable $callback)
    {
        return new CallbackFilter($callback);
    }

    private function getSplFileInfo()
    {
        return new class implements SplFileInfo {
            //
        };
    }
}