
extern zend_class_entry *zeplara_interfaces_routing_router_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Routing_Router);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_routing_router_setroutes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, routes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_routing_router_addroute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, route, Zeplara\\Interfaces\\Routing\\Route, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_routing_router_createroute, 0, 0, 3)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, methods, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_routing_router_group, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_routing_router___call, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_routing_router_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Router, getRoutes, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Router, setRoutes, arginfo_zeplara_interfaces_routing_router_setroutes)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Router, addRoute, arginfo_zeplara_interfaces_routing_router_addroute)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Router, createRoute, arginfo_zeplara_interfaces_routing_router_createroute)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Router, group, arginfo_zeplara_interfaces_routing_router_group)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Router, __call, arginfo_zeplara_interfaces_routing_router___call)
	PHP_FE_END
};
