<?php

namespace Zeplara\Tests\Routing;

use PHPUnit\Framework\TestCase;
use Zeplara\Routing\Route;
use Zeplara\Routing\Router;

class RouterTest extends TestCase
{
    public function testAddRoute()
    {
        $router = new Router;

        $router->addRoute($route = new Route('/', function () {
        
        }, ['GET']));

        self::assertSame([$route], $router->getRoutes());
    }

    public function testRegisterRoute()
    {
        $router = new Router;

        $route = $router->name('home')
                ->get('/', function () {
        
                })->middleware('auth')
                ->middleware('auth1');

        self::assertSame([$route], $router->getRoutes());
        self::assertSame('home', $route->name());
        self::assertSame(['auth', 'auth1'], $route->middleware());
    }

    public function testGroupRoute()
    {
        $router = new Router;

        $router->prefix('/api')->middleware('api')->group(function ($router) {
            $router->get('/user', function () {
            
            });
            $router->get('/users', function () {
            
            });
        });

        self::assertCount(2, $router->getRoutes());
        self::assertSame(['api'], $router->getRoutes()[0]->middleware());
        self::assertSame(['api'], $router->getRoutes()[1]->middleware());
    }

    public function testNestedGroupRoute()
    {
        $router = new Router;

        $router->prefix('/api')->middleware('api')->group(function ($router) {
            $router->get('/user', function () {
            
            });
            $router->get('/users', function () {
            
            });

            $router->middleware('auth')->prefix('/posts')->group(function ($router) {
                $router->get('/', function () {
                
                });
                $router->get('/{id}', function () {
                
                });
            });
        });

        self::assertCount(4, $router->getRoutes());
        self::assertSame(['api', 'auth'], $router->getRoutes()[2]->middleware());
        self::assertSame(['api', 'auth'], $router->getRoutes()[3]->middleware());
        self::assertSame('/api/posts', $router->getRoutes()[2]->getPattern());
        self::assertSame('/api/posts/{id}', $router->getRoutes()[3]->getPattern());
    }
}