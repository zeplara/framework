<?php

namespace Zeplara\Tests\Routing;

use Zeplara\Support\Arr;
use Zeplara\Support\Str;
use Zeplara\Routing\Route;
use PHPUnit\Framework\TestCase;
use Zeplara\Routing\RouteCompiler;
use Zeplara\Routing\RouteCompilerException;

class RouteCompilerTest extends TestCase
{
    public function testHost()
    {
        $route = new Route('/', function () {
        
        }, ['GET']);

        $lists = [
            [
                'pattern' => 'example.com',
                'matching' => [
                    'expected' => 'example.com',
                    'unexpected' => 'sub.example.com'
                ],
                'regex' => 'example\.com',
            ],

            [
                'pattern' => '{sub}.example.com',
                'matching' => [
                    'expected' => 'sub.example.com',
                    'unexpected' => 'example.com'
                ],
                'regex' => '(?P<sub>[^\.]++)\.example\.com'
            ],

            [
                'pattern' => '{sub?}.example.com',
                'matching' => [
                    'expected' => [
                        'example.com',
                        'sub.example.com'
                    ],
                    'unexpected' => 'sub.sub.example.com'
                ],
                'regex' => '(?:(?P<sub>[^\.]++)\.)?example\.com'
            ],

            [
                'pattern' => '{sub?}...example.com',
                'matching' => [
                    'expected' => [
                        'example.com',
                        'sub...example.com'
                    ],
                    'unexpected' => [
                        '...example.com',
                        'sub.example.com'
                    ]
                ],
                'regex' => '(?:(?P<sub>[^\.]++)\.\.\.)?example\.com'
            ],

            [
                'pattern' => '{sub1?}.{sub2?}.example.com',
                'matching' => [
                    'expected' => [
                        'example.com',
                        'sub1.example.com',
                        'sub2.example.com',
                        'sub1.sub2.example.com'
                    ],
                    'unexpected' => 'sub1.sub2.sub3.example.com'
                ],
                'regex' => '(?:(?P<sub1>[^\.]++)\.)?(?:(?P<sub2>[^\.]++)\.)?example\.com'
            ],

            [
                'pattern' => 'sub.{sub1?}.example.com',
                'matching' => [
                    'expected' => [
                        'sub.example.com',
                        'sub.sub1.example.com'
                    ],
                    'unexpected' => [
                        'example.com',
                        'sub..example.com',
                        'sub.sub1.sub2.example.com',
                    ]
                ],
                'regex' => 'sub\.(?:(?P<sub1>[^\.]++)\.)?example\.com',
            ],

            [
                'pattern' => 'prefix-{sub1?}.example.com',
                'matching' => [
                    'expected' => [
                        'prefix-example.com',
                        'prefix-sub1.example.com'
                    ],
                    'unexpected' => [
                        'example.com',
                        'sub..example.com',
                        'sub.sub1.sub2.example.com',
                    ]
                ],
                'regex' => 'prefix\-(?:(?P<sub1>[^\.]++)\.)?example\.com',
            ],

            [
                'pattern' => 'sub.{sub1?}.{sub2?}.example.com',
                'matching' => [
                    'expected' => [
                        'sub.example.com',
                        'sub.sub1.sub2.example.com'
                    ],
                    'unexpected' => [
                        'example.com',
                        'sub..example.com',
                        'sub.sub1.sub2.sub3.example.com',
                    ]
                ],
                'regex' => 'sub\.(?:(?P<sub1>[^\.]++)\.)?(?:(?P<sub2>[^\.]++)\.)?example\.com',
            ],

            [
                'pattern' => 'sub.{sub1?}.sub2.{sub3?}.example.com',
                'matching' => [
                    'expected' => [
                        'sub.sub2.example.com',
                        'sub.sub1.sub2.example.com',
                        'sub.sub2.sub3.example.com',
                        'sub.sub1.sub2.sub3.example.com'
                    ],
                    'unexpected' => [
                        'example.com',
                        'sub..sub2.example.com',
                        'sub.sub1.sub2.sub3.sub4.example.com',
                    ]
                ],
                'regex' => 'sub\.(?:(?P<sub1>[^\.]++)\.)?sub2\.(?:(?P<sub3>[^\.]++)\.)?example\.com',
            ],

             [
                'pattern' => '{sub1}.sub2.{sub3?}.example.com',
                'matching' => [
                    'expected' => [
                        'sub1.sub2.sub3.example.com',
                        'sub1.sub2.example.com',
                    ],
                    'unexpected' => [
                        'example.com',
                        'sub2.example.com',
                    ]
                ],
                'regex' => '(?P<sub1>[^\.]++)\.sub2\.(?:(?P<sub3>[^\.]++)\.)?example\.com'
            ],

            [
                'pattern' => '{sub1?}.sub2.{sub3?}.example.com',
                'matching' => [
                    'expected' => [
                        'sub1.sub2.sub3.example.com',
                        'sub1.sub2.example.com',
                        'sub2.sub3.example.com',
                        'sub2.example.com'
                    ],
                    'unexpected' => [
                        'example.com',
                        '.sub2.example.com',
                        'sub.sub1.sub2.sub3.sub4.example.com',
                    ]
                ],
                'regex' => '(?:(?P<sub1>[^\.]++)\.)?sub2\.(?:(?P<sub3>[^\.]++)\.)?example\.com'
            ],

            [
                'pattern' => '{sub1?}{sub2?}.example.com',
                'expected' => [
                    'example.com',
                    'sub1sub2.example.com',
                    'sub1.example.com',
                    'sub2.example.com'
                ],
                'unexpected' => [
                    '.example.com',
                    'sub1.sub2.example.com'
                ],
                'regex' => '(?P<sub1>[^\.]+)?(?:(?P<sub2>[^\.]++)\.)?example\.com'
            ],

            [
                'pattern' => 'sub.{sub1?}.sub2.{sub3?}.sub4.{sub5?}.example.com',
                'matching' => [
                     'expected' => [
                        'sub.sub1.sub2.sub3.sub4.sub5.example.com',
                        'sub.sub1.sub2.sub4.example.com',
                        'sub.sub1.sub2.sub4.sub5.example.com',
                        'sub.sub1.sub2.sub3.sub4.sub5.example.com',
                    ],
                    'unexpected' => 'sub..sub2..sub4..example.com',
                ],
                'regex' => 'sub\.(?:(?P<sub1>[^\.]++)\.)?sub2\.(?:(?P<sub3>[^\.]++)\.)?sub4\.(?:(?P<sub5>[^\.]++)\.)?example\.com'
            ],

            [
                'pattern' => 'sub.{sub1?}.{sub2?}.sub3.{sub4?}.example.com',
                'matching' => [
                    'expected' => [
                        'sub.sub1.sub2.sub3.sub4.example.com',
                        'sub.sub3.example.com'
                    ],
                    'unexpected' => 'sub..sub3..example.com'
                ],
                'regex' => 'sub\.(?:(?P<sub1>[^\.]++)\.)?(?:(?P<sub2>[^\.]++)\.)?sub3\.(?:(?P<sub4>[^\.]++)\.)?example\.com'
            ],

            [
                'pattern' => '{sub1?}.{sub2?}.sub3.{sub4?}.{sub5?}.example.com',
                'matching' => [
                    'expected' => [
                        'sub1.sub2.sub3.sub4.sub5.example.com',
                        'sub1.sub3.example.com',
                        'sub1.sub2.sub3.example.com',
                        'sub1.sub2.sub3.sub4.example.com',
                        'sub3.example.com'
                    ],
                    'unexpected' => [
                        'sub3example.com',
                        'sub1.sub2.sub3example.com'
                    ]
                ],
                'regex' => '(?:(?P<sub1>[^\.]++)\.)?(?:(?P<sub2>[^\.]++)\.)?sub3\.(?:(?P<sub4>[^\.]++)\.)?(?:(?P<sub5>[^\.]++)\.)?example\.com'
            ],

            [
                'pattern' => 'sub{sub1?}.example.com',
                'matching' => [
                    'expected' => [
                        'subsub1.example.com',
                        'sub.example.com'
                    ],
                    'unexpected' => [
                        'sub.sub1.example.com',
                        'subexample.com'
                    ]
                ],
                'regex' => 'sub(?P<sub1>[^\.]++)?\.example\.com'
            ],

            [
                'pattern' => 'sub{sub1?}{sub2?}{sub3?}{sub4?}.example.com',
                'matching' => [
                    'expected' => [
                        'subsub1sub2sub3sub4.example.com',
                        'subsub1.example.com',
                        'subsub1sub2.example.com',
                        'subsub1sub2sub3.example.com',
                        'subsub4.example.com',
                        'sub.example.com'
                    ],
                    'unexpected' => [
                        'subexample.com',
                        'subsub1example.com',
                        'subsub1sub2example.com',
                        'subsub1sub2sub3example.com'
                    ]
                ],
                'regex' => 'sub(?P<sub1>[^\.]+)?(?P<sub2>[^\.]+)?(?P<sub3>[^\.]+)?(?P<sub4>[^\.]++)?\.example\.com'
            ],

            [
                'pattern' => 'sub{sub1?}{sub2?}sub3{sub4?}{sub5?}.example.com',
                'matching' => [
                    'expected' => [
                        'subsub1sub2sub3sub4sub5.example.com',
                        'subsub1sub3.example.com',
                        'subsub1sub2sub3.example.com',
                        'subsub1sub2sub3sub4.example.com',
                        'subsub3.example.com'
                    ],
                    'unexpected' => [
                        'subsub3example.com',
                        'subsub1sub3example.com',
                        'subsub1sub2sub3example.com',
                        'subsub1sub2sub3sub4example.com'
                    ]
                ],
                'regex' => 'sub(?P<sub1>[^\.]+)?(?P<sub2>[^\.]+)?sub3(?P<sub4>[^\.]+)?(?P<sub5>[^\.]++)?\.example\.com'
            ],

            [
                'pattern' => 'sub{sub1?}{sub2?}{sub3?}sub4{sub5?}{sub6?}{sub7?}{sub8?}.example.com',
                'matching' => [
                    'expected' => [
                        'subsub1sub2sub3sub4sub5sub6sub7sub8.example.com',
                        'subsub1sub4.example.com',
                        'subsub1sub2sub4.example.com',
                        'subsub1sub2sub3sub4.example.com',
                        'subsub1sub2sub3sub4sub5.example.com',
                        'subsub1sub2sub3sub4sub5sub6.example.com',
                        'subsub1sub2sub3sub4sub5sub6sub7.example.com',
                        'subsub4.example.com'
                    ],
                    'unexpected' => [
                        'subsub4example.com',
                        'subsub1sub4example.com',
                        'subsub1sub2sub4example.com',
                        'subsub1sub2sub3sub4example.com',
                        'subsub1sub2sub3sub4sub5example.com',
                        'subsub1sub2sub3sub4sub5sub6example.com',
                        'subsub1sub2sub3sub4sub5sub6esub7xample.com'

                    ]
                ],
                'regex' => 'sub(?P<sub1>[^\.]+)?(?P<sub2>[^\.]+)?(?P<sub3>[^\.]+)?sub4(?P<sub5>[^\.]+)?(?P<sub6>[^\.]+)?(?P<sub7>[^\.]+)?(?P<sub8>[^\.]++)?\.example\.com'
            ],

            [
                'pattern' => 'sub{sub1?}{sub2?}{sub3?}{sub4?}.sub5.{sub6?}{sub7?}{sub8?}{sub9?}.example.com',
                'matching' => [
                    'expected' => [
                        'subsub1sub2sub3sub4.sub5.sub6sub7sub8sub9.example.com',
                        'subsub1.sub5.example.com',
                        'subsub1sub2.sub5.example.com',
                        'subsub1sub2sub3.sub5.example.com',
                        'subsub1sub2sub3sub4.sub5.example.com',
                        'subsub1sub2sub3sub4.sub5.sub6example.com',
                        'subsub1sub2sub3sub4.sub5.sub6sub7example.com',
                        'subsub1sub2sub3sub4.sub5.sub6sub7sub8example.com',
                        'sub.sub5.example.com'
                    ],
                    'unexpected' => [
                        'sub.sub5..example.com',
                        'subsub5.example.com',
                        'subsub5..example.com'
                    ]
                ],
                'regex' => 'sub(?P<sub1>[^\.]+)?(?P<sub2>[^\.]+)?(?P<sub3>[^\.]+)?(?P<sub4>[^\.]++)?\.sub5\.(?P<sub6>[^\.]+)?(?P<sub7>[^\.]+)?(?P<sub8>[^\.]+)?(?:(?P<sub9>[^\.]++)\.)?example\.com'
            ],

            [
                'pattern' => 'sub.{sub1?}{sub2?}{sub3?}{sub4?}sub5.{sub6?}{sub7?}{sub8?}{sub9?}.example.com',
                'matching' => [
                    'expected' => [
                        'sub.sub1sub2sub3sub4sub5.sub6sub7sub8sub9.example.com',
                        'sub.sub1sub5.example.com',
                        'sub.sub1sub2sub5.example.com',
                        'sub.sub1sub2sub3sub5.example.com',
                        'sub.sub1sub2sub3sub4sub5.example.com',
                        'sub.sub1sub2sub3sub4sub5.sub6example.com',
                        'sub.sub1sub2sub3sub4sub5.sub6sub7example.com',
                        'sub.sub1sub2sub3sub4sub5.sub6sub7sub8example.com',
                        'sub.sub5.example.com'
                    ],
                    'unexpected' => 'sub.sub5..example.com'
                ],
                'regex' => 'sub\.(?P<sub1>[^\.]+)?(?P<sub2>[^\.]+)?(?P<sub3>[^\.]+)?(?P<sub4>[^\.]+)?sub5\.(?P<sub6>[^\.]+)?(?P<sub7>[^\.]+)?(?P<sub8>[^\.]+)?(?:(?P<sub9>[^\.]++)\.)?example\.com'
            ],

            [
                'pattern' => '{sub1?}.{sub2?}.sub3{sub4?}.{sub5?}.example.com',
                'matching' => [
                    'expected' => [
                        'sub1.sub2.sub3sub4.sub5.example.com',
                        'sub1.sub3.example.com',
                        'sub1.sub2.sub3.example.com',
                        'sub1.sub2.sub3sub4.example.com',
                        'sub3.example.com'
                    ],
                    'unexpected' => [
                        'sub3example.com',
                        'sub1.sub2.sub3example.com',
                        'sub2.sub3example.com'
                    ]
                ],
                'regex' => '(?:(?P<sub1>[^\.]++)\.)?(?:(?P<sub2>[^\.]++)\.)?sub3(?:(?P<sub4>[^\.]++)\.)?(?P<sub5>[^\.]++)?\.example\.com'
            ],

            [
                'pattern' => 'sub.{sub1?}.{sub2?}.{sub3?}.{sub4?}.sub5.{sub6?}.{sub7?}.{sub8?}.{sub9?}.example.com',
                'matching' => [
                    'expected' => [
                        'sub.sub1.sub2.sub3.sub4.sub5.sub6.sub7.sub8.sub9.example.com'
                    ],
                    'unexpected' => 'sub..sub5..example.com'
                ]
            ],

            [
                'pattern' => 'sub{sub1?}.{sub2?}.{sub3?}.{sub4?}.sub5.{sub6?}.{sub7?}.{sub8?}.{sub9?}.example.com',
                'expected' => [
                    'sub.sub5.example.com',
                    'subsub1.sub2.sub3.sub4.sub5.sub6.sub7.sub8.sub9.example.com'
                ],
                'unexpected' => [
                    'subsub5.example.com',
                    'subsub5..example.com'
                ]
            ],

            [
                'pattern' => 'sub{sub1?}.{sub2?}.{sub3?}.{sub4?}sub5.{sub6?}.{sub7?}.{sub8?}.{sub9?}.example.com',
                'expected' => [
                    'subsub5.example.com',
                    'subsub1.sub2.sub3.sub4sub5.sub6.sub7.sub8.sub9.example.com'
                ],
                'unexpected' => 'subsub5..example.com'
               
            ],

             [
                'pattern' => 'sub{sub1?}.{sub2?}.{sub3?}.{sub4?}.sub5{sub6?}.{sub7?}.{sub8?}.{sub9?}.example.com',
                'expected' => [
                    'subsub5.example.com',
                    'subsub1.sub2.sub3.sub4sub5sub6.sub7.sub8.sub9.example.com'
                ],
                'unexpected' => 'sub.sub5example.com'
               
            ],
        ];

        foreach ($lists as $list) {
            $route->host($list['pattern']);
            $compiled = RouteCompiler::compile($route);
            foreach (Arr::wrap($list['matching']['expected'] ?? []) as $expected) {
                static::assertMatchesRegularExpression($compiled->getHost()->getRegex(), $expected);
            }
            foreach (Arr::wrap($list['matching']['unexpected'] ?? []) as $unExpected) {
                static::assertDoesNotMatchRegularExpression($compiled->getHost()->getRegex(), $unExpected);
            }
            if (isset($list['regex'])) {
                static::assertEquals(sprintf("{^%s$}sDui", $list['regex']), $compiled->getHost()->getRegex());
            }
        }
    }

    public function testPath()
    {
        $lists = [
            [
                'pattern' => '/',
                'matching' => [
                    'expected' => '/',
                    'unexpected' => ''
                ],
                'regex' => '/'
            ],
            
            [
                'pattern' => '/hello-world',
                'matching' => [
                    'expected' => '/hello-world'
                ],
                'regex' => '/hello\-world'
            ],

            [
                'pattern' => '/post/{id}',
                'matching' => [
                    'expected' => '/post/id',
                    'unexpected' => '/post'
                ],
                'regex' => '/post/(?P<id>[^/]++)'
            ],

            [
                'pattern' => '/post/{id?}',
                'matching' => [
                    'expected' => [
                        '/post/id',
                        '/post'
                    ],
                    'unexpected' => '/post/'
                ],
                'regex' => '/post(?:/(?P<id>[^/]++))?'
            ],

            [
                'pattern' => '/post/{id}/{slug}',
                'matching' => [
                    'expected' => '/post/id/slug',
                ],
                'regex' => '/post/(?P<id>[^/]++)/(?P<slug>[^/]++)'
            ],

            [
                'pattern' => '/post/{id}/{slug?}',
                'matching' => [
                    'expected' => [
                        '/post/id/slug',
                        '/post/id'
                    ],
                    'unexpected' => '/post/id/'
                ],
                'regex' => '/post/(?P<id>[^/]++)(?:/(?P<slug>[^/]++))?'
            ],

            [
                'pattern' => '/post/{id}/{slug?}/archive',
                'matching' => [
                    'expected' => [
                        '/post/id/slug/archive',
                        '/post/id/archive'
                    ],
                    'unexpected' => '/post/idarchive'
                ],
                'regex' => '/post/(?P<id>[^/]++)/(?:(?P<slug>[^/]++)/)?archive'
            ],

             [
                'pattern' => '/post/{id?}/{slug?}/archive',
                'matching' => [
                    'expected' => [
                        '/post/id/slug/archive',
                        '/post/id/archive',
                        '/post/archive',
                    ],
                    'unexpected' => [
                        '/post/idarchive',
                        'postarchice'
                    ]
                ],
                'regex' => '/post/(?:(?P<id>[^/]++)/)?(?:(?P<slug>[^/]++)/)?archive'
            ],

            [
                'pattern' => '/post{id?}{slug?}{day?}-{month?}-2020{category?}/archive',
                'matching' => [
                    'expected' => [
                        '/postidslug-22-03-2020news/archive',
                        '/postid-2020/archive',
                        '/postidslug-2020/archive',
                        '/postidslug22-2020/archive',
                        '/postidslug22-06-2020/archive',
                        '/post-2020news/archive',
                        '/post-2020/archive'
                    ],
                    'unexpected' => [
                        '/post2020archive',
                        '/post-2020archive',
                        '/postidslug22-03-2020archive'
                    ]
                ],
                'regex' => '/post(?P<id>[^/]+)?(?P<slug>[^/]+)?(?:(?P<day>[^/\-]++)\-)?(?P<month>[^/\-]++)?\-2020(?P<category>[^/]++)?/archive'
            ]
        ];

        foreach ($lists as $list) {
            $route = new Route($list['pattern'], function () {
        
            }, ['GET']);
            $compiled = RouteCompiler::compile($route);
            foreach (Arr::wrap($list['matching']['expected'] ?? []) as $expected) {
                static::assertMatchesRegularExpression($compiled->getPath()->getRegex(), $expected);
            }
            foreach (Arr::wrap($list['matching']['unexpected'] ?? []) as $unExpected) {
                static::assertDoesNotMatchRegularExpression($compiled->getPath()->getRegex(), $unExpected);
            }
            if (isset($list['regex'])) {
                static::assertEquals(sprintf("{^%s$}sDu", $list['regex']), $compiled->getPath()->getRegex());
            }
        }
    }

    public function testRequirement()
    {
        $route = new Route('/post/{id}',function () {
        
        },  ['GET']);

        $route->where('id', '1|2');
        $compiled = RouteCompiler::compile($route);
        static::assertEquals('{^/post/(?P<id>1|2)$}sDu',$compiled->getPath()->getRegex());
        
        $route->where('id', '^1|2');
        $compiled = RouteCompiler::compile($route);
        static::assertEquals('{^/post/(?P<id>1|2)$}sDu',$compiled->getPath()->getRegex());

        $route->where('id', '1|2$');
        $compiled = RouteCompiler::compile($route);
        static::assertEquals('{^/post/(?P<id>1|2)$}sDu',$compiled->getPath()->getRegex());

        $route->where('id', '^1|2$');
        $compiled = RouteCompiler::compile($route);
        static::assertEquals('{^/post/(?P<id>1|2)$}sDu',$compiled->getPath()->getRegex());
        
        $route->where('id', '(1|2)');
        $compiled = RouteCompiler::compile($route);
        static::assertEquals('{^/post/(?P<id>(?:1|2))$}sDu',$compiled->getPath()->getRegex());

        $route->where('id', '((1|2))');
        $compiled = RouteCompiler::compile($route);
        static::assertEquals('{^/post/(?P<id>(?:(?:1|2)))$}sDu',$compiled->getPath()->getRegex());

        $route->where('id', '(?:(1|2))');
        $compiled = RouteCompiler::compile($route);
        static::assertEquals('{^/post/(?P<id>(?:(?:1|2)))$}sDu',$compiled->getPath()->getRegex());

        $route->where('id', '(?:(?:1|2))');
        $compiled = RouteCompiler::compile($route);
        static::assertEquals('{^/post/(?P<id>(?:(?:1|2)))$}sDu',$compiled->getPath()->getRegex());
    }

    public function testInvalidLengthVariable()
    {
        $route = new Route(sprintf(
            '/{%s}', $var = Str::random(35)
        ), function () {

        }, ['GET']);

        $this->expectException(RouteCompilerException::class);
        $this->expectExceptionMessage(sprintf(
            "Variable \"%s\" is too long. maximum is %s characters.", $var, RouteCompiler::MAX_VARIABLE_LEN
        ));
        RouteCompiler::compile($route);
    }

    public function testInvalidPositionalRequiredPattern()
    {
        $route = new Route('/{test?}/{test}', function () {
            
        }, ['GET']);

        $this->expectException(RouteCompilerException::class);
        $this->expectExceptionMessage('Cannot set optional pattern "{test?}" when the next pattern "{test}" is required.');
        RouteCompiler::compile($route);
    }

    public function testInvalidVariableStartWithDigits()
    {
        $route = new Route('/{1test}', function () {

        }, ['GET']);

        $this->expectException(RouteCompilerException::class);
        $this->expectExceptionMessage("Variable \"1test\" cannot start with digit.");
        RouteCompiler::compile($route);
    }

    public function testDuplicateVariable()
    {
        $route = new Route('/{test}/{test}', function () {

        }, ['GET']);

        $this->expectException(RouteCompilerException::class);
        $this->expectExceptionMessage("Variable \"test\" must be unique.");
        RouteCompiler::compile($route);
    }
}
