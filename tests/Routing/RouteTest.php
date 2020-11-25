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

        self::assertEquals('/', $route->getPattern());
        self::assertIsArray($route->getMethods());
        self::assertEquals(['GET'], $route->getMethods());
    }

    public function testAttributesOnConstructor()
    {
        $route = new Route('/', function () {
        
        }, ['GET'], [
            'name' => 'home',
            'middleware' => ['auth'] 
        ]);

        self::assertEquals('home', $route->name());
        self::assertIsArray($route->middleware());
        self::assertEquals(['auth'], $route->middleware());
    }

    public function testAttributesWithChainMethod()
    {
        $route = new Route('/', function () {
        
        }, ['GET']);

        $route->middleware('auth')->name('home');

        self::assertEquals('home', $route->name());
        self::assertIsArray($route->middleware());
        self::assertEquals(['auth'], $route->middleware());
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