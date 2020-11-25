<?php

namespace Zeplara\Tests\Container;

use PHPUnit\Framework\TestCase;
use Zeplara\Container\Container;
use Zeplara\Container\ContainerException;
use Zeplara\Container\InvalidAbstractException;

class ContainerTest extends TestCase
{
    public function testBasicBindingResolution()
    {
        $container = new Container;

        $container->set(ContractA::class, A::class);

        static::assertInstanceOf(ContractA::class, $container->get(ContractA::class));
        static::assertInstanceOf(A::class, $container->get(ContractA::class));
    }

    public function testClosureBindingsResolution()
    {
        $container = new Container;

        $container->set('test', function () {
            return 'blah';
        });

        static::assertEquals('blah', $container->get('test'));

        $container->set('ContractAString', function () {
            return ContractA::class;
        });

        static::assertIsString($container->get('ContractAString'));

        $container->set(ContractA::class, function () {
            $a = new  A;

            $a->name = 'ilham';

            return $a;
        });

        $a = new A;

        $a->name = 'ilham';

        static::assertInstanceOf(ContractA::class, $container->get(ContractA::class));
        static::assertInstanceOf(A::class, $container->get(ContractA::class));
        static::assertEquals($container->get(ContractA::class)->name, $a->name);
    }

    public function testResolvedBindingsResolution()
    {
        $a = new A;

        $a->name = 'ilham';

        $container = new Container;

        $container->set(ContractA::class, $a, true);

        static::assertInstanceOf(ContractA::class, $container->get(ContractA::class));
        static::assertInstanceOf(A::class, $container->get(ContractA::class));
        static::assertEquals($a->name, $container->get(ContractA::class)->name);

        $container->set('name', $a->name, true);

        static::assertEquals($a->name, $container->get('name'));
        
        $container->set('name1', function () use ($a) {
            return $a->name;
        }, true);

        static::assertEquals($a->name, $container->get('name1'));

        $container->set('ContractAString', function () {
            return ContractA::class;
        }, true);

        static::assertIsString($container->get('ContractAString'));
    }

    public function testAliasBindingsResolution()
    {
        $a = new A;
        $a->name = 'ilham';
        $container = new Container;

        $container->set(ContractA::class, $a, true);
        $container->set(A::class, ContractA::class);
        $container->set('AClass', A::class);
        $container->set('AClass', 'AClass');

        static::assertEquals($a->name, $container->get(ContractA::class)->name);
        static::assertEquals($a->name, $container->get(A::class)->name);
        static::assertEquals($a->name, $container->get('AClass')->name);

        $container->put(A::class);

        static::assertFalse($container->has(A::class));
        static::assertTrue($container->has(ContractA::class));
        static::assertTrue($container->has('AClass'));

        $container->put('AClass');
        static::assertTrue($container->has(ContractA::class));
        static::assertFalse($container->has('AClass'));
        static::assertFalse($container->has(A::class));

        $container->put(ContractA::class);
        static::assertFalse($container->has(ContractA::class));
        static::assertFalse($container->has('AClass'));
        static::assertFalse($container->has(A::class));

        $container->set(ContractA::class, $a, true);
        $container->set(A::class, ContractA::class);
        $container->set('AClass', A::class);

        $container->put(ContractA::class);
        static::assertFalse($container->has(ContractA::class));
        static::assertFalse($container->has('AClass'));
        static::assertFalse($container->has(A::class));
    }

    public function testAliasErrorWhenKeyExistsAsRootBindingResolution()
    {
        $this->expectException(ContainerException::class);

        $container = new Container;

        $container->set('name', 'ilham', true);
        $container->set('nama', 'name');
        $container->set('address', 'cibiru');
        $container->set('name', 'address');
    }

    public function testAliasErrorWhenKeyExistsAsAliasBindingResolution()
    {
        $this->expectException(ContainerException::class);

        $container = new Container;

        $container->set('name', 'ilham', true);
        $container->set('nama', 'name');
        $container->set('address', 'cibiru');
        $container->set('nama', 'address');
    }

    public function testBasicDependencyInjection()
    {
        $container = new Container;
        $a = new A;
        $a->name = 'ilham';
        $container->set(ContractA::class, $a, true);
        
        static::assertInstanceOf(ContractA::class, $container->make(ContractAInjection::class)->a);
        static::assertInstanceOf(A::class, $container->make(ContractAInjection::class)->a);
        static::assertInstanceOf(A::class, $container->make(ContractAInjection::class)->aSame);
        static::assertEquals($a->name, $container->make(ContractAInjection::class)->a->name);
        static::assertNull($container->make(ContractAInjection::class)->aSame->name);

        static::assertInstanceOf(ContractAInjectionInjection::class, $container->make(ContractAInjectionInjection::class));
        static::assertInstanceOf(ContractAInjection::class, $container->make(ContractAInjectionInjection::class)->contractAInjection);
        static::assertInstanceOf(ContractA::class, $container->make(ContractAInjectionInjection::class)->contractAInjection->a);
        static::assertInstanceOf(A::class, $container->make(ContractAInjectionInjection::class)->contractAInjection->a);
        static::assertEquals($a->name, $container->make(ContractAInjectionInjection::class)->contractAInjection->a->name);
        
        $container->set(A::class, ContractA::class);

        static::assertInstanceOf(ContractA::class, $container->make(ContractAInjection::class)->a);
        static::assertInstanceOf(A::class, $container->make(ContractAInjection::class)->a);
        static::assertInstanceOf(A::class, $container->make(ContractAInjection::class)->aSame);
        static::assertEquals($a->name, $container->make(ContractAInjection::class)->a->name);
        static::assertNotNull($container->make(ContractAInjection::class)->aSame->name);

        static::assertInstanceOf(ContractAInjectionInjection::class, $container->make(ContractAInjectionInjection::class));
        static::assertInstanceOf(ContractAInjection::class, $container->make(ContractAInjectionInjection::class)->contractAInjection);
        static::assertInstanceOf(ContractA::class, $container->make(ContractAInjectionInjection::class)->contractAInjection->a);
        static::assertInstanceOf(A::class, $container->make(ContractAInjectionInjection::class)->contractAInjection->a);
        static::assertEquals($a->name, $container->make(ContractAInjectionInjection::class)->contractAInjection->a->name);
    }

    public function testArgumentsDependencyInjection()
    {
        $container = new Container;

        $a = new A;
        $a->name = 'ilham';

        $container->set(ContractA::class, $a, true);
        $container->set(A::class, ContractA::class);
        
        $obj = $container->make(ContractAInjectionArguments::class, ['blah']);

        static::assertInstanceOf(ContractA::class, $obj->a);
        static::assertInstanceOf(A::class, $obj->a);
        static::assertEquals('blah', $obj->param1);

        $args = $container->make(__NAMESPACE__.'\\ContractAInjectionArguments.advancedParams', [
            'param2',
            'param5',
            'param6'
        ]);

        static::assertCount(7, $args);
        static::assertNull($args[0]);
        static::assertEquals('param2', $args[1]);
        static::assertEquals('param3', $args[2]);
        static::assertEquals('param4', $args[3]);
        static::assertEquals('param5', $args[4]);
        static::assertEquals('param6', $args[5]);
        static::assertNull($args[6]);

        $args = $container->make(__NAMESPACE__.'\\ContractAInjectionArguments.advancedParamsWithRegistered', [
            'param2',
            'param5',
            'param6'
        ]);

        static::assertCount(7, $args);
        static::assertInstanceOf(ContractA::class, $args[0]);
        static::assertEquals('param2', $args[1]);
        static::assertEquals('param3', $args[2]);
        static::assertEquals('param4', $args[3]);
        static::assertEquals('param5', $args[4]);
        static::assertEquals('param6', $args[5]);
        static::assertNull($args[6]);

        $args = $container->make(__NAMESPACE__.'\\ContractAInjectionArguments.advancedParamsWithNullObject', [
            'param2',
            'param5',
            'param6'
        ]);

        static::assertCount(7, $args);
        static::assertNull($args[0]);
        static::assertEquals('param2', $args[1]);
        static::assertEquals('param3', $args[2]);
        static::assertEquals('param4', $args[3]);
        static::assertEquals('param5', $args[4]);
        static::assertEquals('param6', $args[5]);
        static::assertNull($args[6]);

        $args = $container->make(__NAMESPACE__.'\\ContractAInjectionArguments.advancedParamsWithNullObject', [
            new NullObjectParam('ilham'),
            'param2',
            'param5',
            'param6'
        ]);

        static::assertCount(7, $args);
        static::assertNotNull($args[0]);
        static::assertInstanceOf(NullObjectParam::class, $args[0]);
        static::assertEquals('param2', $args[1]);
        static::assertEquals('param3', $args[2]);
        static::assertEquals('param4', $args[3]);
        static::assertEquals('param5', $args[4]);
        static::assertEquals('param6', $args[5]);
        static::assertNull($args[6]);
    }

    public function testCallFunction()
    {
        $container = new Container;

        static::assertTrue($container->make(__NAMESPACE__.'\\callFunction'));
    }

    public function testCallMethod()
    {
        $container = new Container;

        static::assertTrue($container->make(__NAMESPACE__.'\\CallClassMethod.call'));
        static::assertTrue($container->make([__NAMESPACE__.'\\CallClassMethod', 'call']));

        static::assertTrue($container->make(__NAMESPACE__.'\\CallClassMethod.callStatic'));
        static::assertTrue($container->make([__NAMESPACE__.'\\CallClassMethod', 'callStatic']));

        static::assertTrue($container->make(new CallClassMethod));
    }

    public function testInvalidAbstractString()
    {
        $this->expectException(InvalidAbstractException::class);

        $container = new Container;

        $container->make('InvalidAbstract');
    }

    public function testInvalidAbstractArray()
    {
        $this->expectException(InvalidAbstractException::class);
        
        $container = new Container;

        $container->make([new A, 'invalidMethod']);
    }

    public function testInvalidAbstractObject()
    {
        $this->expectException(InvalidAbstractException::class);
        
        $container = new Container;

        $container->make(new A);
    }
}

interface ContractA
{

}

class A implements ContractA
{
    public $name;
}

class ContractAInjection 
{
    public $a;
    public $aSame;

    public function __construct(ContractA $a, A $aSame)
    {
        $this->a = $a;
        $this->aSame = $aSame;
    }
}

class ContractAInjectionInjection
{
    public $contractAInjection;

    public function __construct(ContractAInjection $contractAInjection)
    {
        $this->contractAInjection = $contractAInjection;
    }
}

class NullObjectParam
{
    public function __construct($name)
    {
        
    }
}

class ContractAInjectionArguments
{
    public $a;
    public $param1;

    public function __construct(ContractA $a, $param1)
    {
        $this->a = $a;
        $this->param1 = $param1;
    }

    public static function advancedParams($param1 = null, $param2, $param3 = 'param3', $param4 = 'param4', $param5, $param6, $param7 = null)
    {
        return func_get_args();
    }

    public static function advancedParamsWithRegistered(ContractA $param1 = null, $param2, $param3 = 'param3', $param4 = 'param4', $param5, $param6, $param7 = null)
    {
        return func_get_args();
    }

    public static function advancedParamsWithNullObject(NullObjectParam $param1 = null, $param2, $param3 = 'param3', $param4 = 'param4', $param5, $param6, $param7 = null)
    {
        return func_get_args();
    }
}

class CallClassMethod
{
    public function call()
    {
        return true;
    }

    public static function callStatic()
    {
        return true;
    }

    public function __invoke()
    {
        return true;
    }
}

function callFunction()
{
    return true;
}