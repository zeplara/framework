
extern zend_class_entry *zeplara_routing_routecompiler_ce;

ZEPHIR_INIT_CLASS(Zeplara_Routing_RouteCompiler);

PHP_METHOD(Zeplara_Routing_RouteCompiler, compile);
PHP_METHOD(Zeplara_Routing_RouteCompiler, parseRegex);
PHP_METHOD(Zeplara_Routing_RouteCompiler, resolveRequirement);
PHP_METHOD(Zeplara_Routing_RouteCompiler, hasNextStaticPrefixOnNextMatch);
PHP_METHOD(Zeplara_Routing_RouteCompiler, hasStaticPrefixWithoutSeparatorOnPrevMatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_routecompiler_compile, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route, Zeplara\\Contracts\\Routing\\Route, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_routecompiler_parseregex, 0, 0, 3)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, separator)
	ZEND_ARG_INFO(0, flags)
	ZEND_ARG_INFO(0, requirements)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_routecompiler_resolverequirement, 0, 0, 1)
	ZEND_ARG_INFO(0, requirement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_routecompiler_hasnextstaticprefixonnextmatch, 0, 0, 3)
	ZEND_ARG_INFO(0, nextIdx)
	ZEND_ARG_INFO(0, lastIdx)
	ZEND_ARG_INFO(0, matches)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_routecompiler_hasstaticprefixwithoutseparatoronprevmatch, 0, 0, 2)
	ZEND_ARG_INFO(0, prevIdx)
	ZEND_ARG_INFO(0, matches)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_routing_routecompiler_method_entry) {
	PHP_ME(Zeplara_Routing_RouteCompiler, compile, arginfo_zeplara_routing_routecompiler_compile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Routing_RouteCompiler, parseRegex, arginfo_zeplara_routing_routecompiler_parseregex, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Routing_RouteCompiler, resolveRequirement, arginfo_zeplara_routing_routecompiler_resolverequirement, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Routing_RouteCompiler, hasNextStaticPrefixOnNextMatch, arginfo_zeplara_routing_routecompiler_hasnextstaticprefixonnextmatch, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Routing_RouteCompiler, hasStaticPrefixWithoutSeparatorOnPrevMatch, arginfo_zeplara_routing_routecompiler_hasstaticprefixwithoutseparatoronprevmatch, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
