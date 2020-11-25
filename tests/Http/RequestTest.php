<?php

namespace Zeplara\Tests\Http;

use Zeplara\Http\Request;
use Zeplara\Http\UriFactory;
use Zeplara\Http\StreamFactory;
use PHPUnit\Framework\TestCase;

class RequestTest extends TestCase
{
    public function testWithMethod()
    {
        $request = new Request('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        $newRequest = $request->withMethod('POST');

        self::assertNotSame($request->getMethod(), $newRequest->getMethod());
    }
    
    public function testWithUri()
    {
        $request = new Request('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        $newRequest = $request->withUri(UriFactory::create('http://example.com'));

        self::assertNotSame($request->getUri(), $newRequest->getUri());
    }

    public function testWithBody()
    {
        $request = new Request('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        $newRequest = $request->withBody(StreamFactory::create('php://memory'));
        self::assertNotSame($request->getBody(), $newRequest->getBody());
    }

    public function testWithRequestTarget()
    {
        $request = new Request('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        $newRequest = $request->withRequestTarget('/testing');
        self::assertNotSame($request->getRequestTarget(), $newRequest->getRequestTarget());
    }

    public function testGetRequestTarget()
    {
        $request = new Request('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        self::assertSame('/', $request->getRequestTarget());

        $newRequest = $request->withUri(UriFactory::create('http://example.com/api/v1/user?token=abcd&name=abd'));

        self::assertNotSame($request->getRequestTarget(), $newRequest->getRequestTarget());
        self::assertSame('/api/v1/user?token=abcd&name=abd', $newRequest->getRequestTarget());
    }
}