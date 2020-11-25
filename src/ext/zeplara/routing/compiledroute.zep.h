
extern zend_class_entry *zeplara_routing_compiledroute_ce;

ZEPHIR_INIT_CLASS(Zeplara_Routing_CompiledRoute);

PHP_METHOD(Zeplara_Routing_CompiledRoute, __construct);
PHP_METHOD(Zeplara_Routing_CompiledRoute, getHost);
PHP_METHOD(Zeplara_Routing_CompiledRoute, getPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_compiledroute___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, host, Zeplara\\Routing\\Regex, 0)
	ZEND_ARG_OBJ_INFO(0, path, Zeplara\\Routing\\Regex, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_routing_compiledroute_method_entry) {
	PHP_ME(Zeplara_Routing_CompiledRoute, __construct, arginfo_zeplara_routing_compiledroute___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Routing_CompiledRoute, getHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_CompiledRoute, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
