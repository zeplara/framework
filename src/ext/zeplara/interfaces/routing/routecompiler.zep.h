
extern zend_class_entry *zeplara_interfaces_routing_routecompiler_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Routing_RouteCompiler);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_routing_routecompiler_compile, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route, Zeplara\\Interfaces\\Routing\\Route, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_routing_routecompiler_method_entry) {
	ZEND_FENTRY(compile, NULL, arginfo_zeplara_interfaces_routing_routecompiler_compile, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
