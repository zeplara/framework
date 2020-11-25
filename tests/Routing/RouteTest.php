<?php

namespace Zeplara\Tests\Routing;

use Zeplara\Routing\Route;
use BadMethodCallException;
use PHPUnit\Framework\TestCase;
use Zeplara\Routing\CompiledRoute;

class RouteTest extends TestCase
{
    public function testBasic()
    {
        $route = new Route('/', function () {
        
        }, ['GET']);

        self::assertSame('/', $route->getPattern());
        self::assertIsArray($route->getMethods());
        self::assertSame(['GET'], $route->getMethods());
    }

    public function testAttributesOnConstructor()
    {
        $route = new Route('/', function () {
        
        }, ['GET'], [
            'name' => 'home',
            'middleware' => ['auth'] 
        ]);

        self::assertSame('home', $route->name());
        self::assertIsArray($route->middleware());
        self::assertSame(['auth'], $route->middleware());
    }

    public function testAttributesWithChainMethod()
    {
        $route = new Route('/', function () {
        
        }, ['GET']);

        $route->middleware('auth')->name('home');

        self::assertSame('home', $route->name());
        self::assertIsArray($route->middleware());
        self::assertSame(['auth'], $route->middleware());
    }

    public function testInvalidAttributeOnConstructor()
    {
        $this->expectException(BadMethodCallException::class);

        $route = new Route('/', function () {
        
        }, ['GET'], [
            'name' => 'home',
            'custom_attribute' => 'value' 
        ]);
    }

    public function testInvalidAttributeWithChainMethod()
    {
        $this->expectException(BadMethodCallException::class);
        $route = new Route('/', function () {
        
        }, ['GET']);

        $route->customAttributes('value');
    }

    public function testCompile()
    {
        $route = new Route('/', function () {
        
        }, ['GET']);

        self::assertInstanceOf(CompiledRoute::class, $route->compile());
    }
}