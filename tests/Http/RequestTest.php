<?php

namespace Zeplara\Tests\Http;

use Zeplara\Http\Request;
use Zeplara\Http\UriFactory;
use Zeplara\Http\StreamFactory;
use PHPUnit\Framework\TestCase;

class RequestTest extends TestCase
{
    public function testMethod()
    {
        $request = new Request('GET', UriFactory::create(), StreamFactory::create('php://tmp'));

        static::assertEquals('GET', $request->getMethod());

        $newRequest = $request->withMethod('POST');
        
        static::assertNotEquals($newRequest->getMethod(), $request->getMethod());
        static::assertEquals('POST', $newRequest->getMethod());
    }
}