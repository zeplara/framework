<?php

namespace Zeplara\Tests\Cookie;

use InvalidArgumentException;
use PHPUnit\Framework\TestCase;
use Zeplara\Cookie\Factory;
use Zeplara\Cookie\Queue;

class QueueTest extends TestCase
{
    public function testQueue()
    {
        $queue = new Queue;

        $queue->set($cookie = Factory::make('cookie_name'));

        self::assertTrue($queue->has('cookie_name'));

        self::assertTrue($queue->has('cookie_name'));
        self::assertSame($cookie, $queue->get('cookie_name'));
    }

    public function testGetNotExists()
    {
        $this->expectException(InvalidArgumentException::class);

        $queue = new Queue;

        $queue->get('cookie_name');
    }
}