<?php

namespace Zeplara\Tests\Http;

use PHPUnit\Framework\TestCase;
use Zeplara\Http\ServerRequest;
use Zeplara\Http\StreamFactory;
use Zeplara\Http\UploadedFile;
use Zeplara\Http\UploadedFileFactory;
use Zeplara\Http\UriFactory;

class ServerRequestTest extends TestCase
{
    public function testGetServerParams()
    {
        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        self::assertIsArray($request->getServerParams());
        self::assertCount(0, $request->getServerParams());

        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'), ['key' => 'value']);

        self::assertIsArray($request->getServerParams());
        self::assertCount(1, $request->getServerParams());
    }

    public function testGetParsedBody()
    {
        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        self::assertIsArray($request->getParsedBody());
        self::assertCount(0, $request->getParsedBody());

        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'), [], ['key' => 'value']);

        self::assertIsArray($request->getParsedBody());
        self::assertCount(1, $request->getParsedBody());
        self::assertSame(['key' => 'value'], $request->getParsedBody());
    }

    public function testWithParsedBody()
    {
        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        $newRequest = $request->withParsedBody(['key' => 'value']);

        self::assertCount(0, $request->getParsedBody());
        self::assertCount(1, $newRequest->getParsedBody());
        self::assertNotSame($request, $newRequest);
    }

    public function testGetQueryParams()
    {
        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        self::assertIsArray($request->getQueryParams());
        self::assertCount(0, $request->getQueryParams());

        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'), [], [], ['key' => 'value']);

        self::assertIsArray($request->getQueryParams());
        self::assertCount(1, $request->getQueryParams());
    }

    public function testWithQueryParams()
    {
        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        $newRequest = $request->withQueryParams(['key' => 'value']);

        self::assertNotSame($request->getQueryParams(), $newRequest->getQueryParams());
        self::assertEquals(['key' => 'value'], $newRequest->getQueryParams());
    }

    public function testGetCookieParams()
    {
        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        self::assertIsArray($request->getCookieParams());
        self::assertCount(0, $request->getCookieParams());

        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'), [], [], [], ['key' => 'value']);

        self::assertIsArray($request->getCookieParams());
        self::assertCount(1, $request->getCookieParams());
    }

    public function testWithCookieParams()
    {
        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'));

        $newRequest = $request->withCookieParams(['key' => 'value']);

        self::assertIsArray($request->getCookieParams());
        self::assertCount(0, $request->getCookieParams());
        self::assertIsArray($newRequest->getCookieParams());
        self::assertCount(1, $newRequest->getCookieParams());
        self::assertNotSame($request, $newRequest);
    }

    public function testGetUploadedFiles()
    {
        $request = new ServerRequest('GET', UriFactory::create(), StreamFactory::create('php://temp'), [], [], [], [], ['key' => UploadedFileFactory::create(StreamFactory::create('php://temp'), 3000, 0, 'testing')]);
        
        self::assertIsArray($request->getUploadedFiles());
        
        foreach ($request->getUploadedFiles() as $file) {
            self::assertInstanceOf(UploadedFile::class, $file);
        }
    }
}