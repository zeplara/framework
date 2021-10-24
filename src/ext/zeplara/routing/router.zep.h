
extern zend_class_entry *zeplara_routing_router_ce;

ZEPHIR_INIT_CLASS(Zeplara_Routing_Router);

PHP_METHOD(Zeplara_Routing_Router, getRoutes);
PHP_METHOD(Zeplara_Routing_Router, __construct);
PHP_METHOD(Zeplara_Routing_Router, setRoutes);
PHP_METHOD(Zeplara_Routing_Router, addRoute);
PHP_METHOD(Zeplara_Routing_Router, createRoute);
PHP_METHOD(Zeplara_Routing_Router, group);
PHP_METHOD(Zeplara_Routing_Router, __call);
zend_object *zephir_init_properties_Zeplara_Routing_Router(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_router_getroutes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_router_getroutes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_router___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, routes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_router_setroutes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, routes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_router_addroute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route, Zeplara\\Interfaces\\Routing\\Route, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_router_createroute, 0, 0, 3)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, methods, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_router_group, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_router___call, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_routing_router_method_entry) {
	PHP_ME(Zeplara_Routing_Router, getRoutes, arginfo_zeplara_routing_router_getroutes, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Router, __construct, arginfo_zeplara_routing_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Routing_Router, setRoutes, arginfo_zeplara_routing_router_setroutes, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Router, addRoute, arginfo_zeplara_routing_router_addroute, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Router, createRoute, arginfo_zeplara_routing_router_createroute, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Router, group, arginfo_zeplara_routing_router_group, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Router, __call, arginfo_zeplara_routing_router___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
