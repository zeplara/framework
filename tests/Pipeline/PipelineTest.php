<?php

namespace Zeplara\Tests\Pipeline;

use Zeplara\Pipeline\Pipeline;
use PHPUnit\Framework\TestCase;
use Zeplara\Container\Container;

class PipelineTest extends TestCase
{
    public function testPipe()
    {
        $pipeline = new Pipeline(new Container, [
            function ($firstName, $lastName, $next) {
                return $next('Ilham', $lastName);
            }
        ]);

        self::assertSame('Ilham Doe', $pipeline->send(function ($firstName, $lastName) {
            return $firstName.' '.$lastName;
        }, ['Jhon', 'Doe']));
    }

    public function testSkipPipe()
    {
        $pipeline = new Pipeline(new Container, [
            function ($firstName, $lastName, $next) {
            }
        ]);

        self::assertNull($pipeline->send(function ($firstName, $lastName) {
            return $firstName.' '.$lastName;
        }, ['Jhon', 'Doe']));
    }

    public function testAddPipe()
    {
        $pipeline = new Pipeline(new Container);

        $pipeline->addPipe(function ($name, $next) {
            return $next('Ilham');
        });

        self::assertSame('Ilham', $pipeline->send(function ($name) {
            return $name;
        }, ['Jhon Doe']));
    }

    public function testPipeWithFunctionName()
    {
        $pipeline = new Pipeline(new Container, [
            '\Zeplara\Tests\Pipeline\functionPipe'
        ]);

        self::assertSame('after', $pipeline->send(function ($name) {
            return $name;
        }, ['before']));


        $pipeline = new Pipeline(new Container);

        $pipeline->addPipe('\Zeplara\Tests\Pipeline\functionPipe');

        self::assertSame('after', $pipeline->send(function ($name) {
            return $name;
        }, ['before']));
    }

    public function testPipeWithClass()
    {
        $pipeline = new Pipeline(new Container, [
            ClassPipe::class
        ]);

        self::assertSame('after', $pipeline->send(function ($name) {
            return $name;
        }, ['before']));


        $pipeline = new Pipeline(new Container);

        $pipeline->addPipe(ClassPipe::class);

        self::assertSame('after', $pipeline->send(function ($name) {
            return $name;
        }, ['before']));
    }
}

function functionPipe($state, $next)
{
    return $next('after');
}

class ClassPipe
{
    public function __invoke($state, $next)
    {
        return $next('after');
    }
}