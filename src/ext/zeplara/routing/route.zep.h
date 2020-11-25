
extern zend_class_entry *zeplara_routing_route_ce;

ZEPHIR_INIT_CLASS(Zeplara_Routing_Route);

PHP_METHOD(Zeplara_Routing_Route, getPattern);
PHP_METHOD(Zeplara_Routing_Route, getMethods);
PHP_METHOD(Zeplara_Routing_Route, getCallback);
PHP_METHOD(Zeplara_Routing_Route, __construct);
PHP_METHOD(Zeplara_Routing_Route, compile);
PHP_METHOD(Zeplara_Routing_Route, getSchemeAttribute);
PHP_METHOD(Zeplara_Routing_Route, setSchemeAttribute);
PHP_METHOD(Zeplara_Routing_Route, initSchemeAttribute);
PHP_METHOD(Zeplara_Routing_Route, getHostAttribute);
PHP_METHOD(Zeplara_Routing_Route, setHostAttribute);
PHP_METHOD(Zeplara_Routing_Route, initHostAttribute);
PHP_METHOD(Zeplara_Routing_Route, getRequirementsAttribute);
PHP_METHOD(Zeplara_Routing_Route, setRequirementsAttribute);
PHP_METHOD(Zeplara_Routing_Route, initRequirementsAttribute);
PHP_METHOD(Zeplara_Routing_Route, setWhereAttribute);
PHP_METHOD(Zeplara_Routing_Route, getMiddlewareAttribute);
PHP_METHOD(Zeplara_Routing_Route, setMiddlewareAttribute);
PHP_METHOD(Zeplara_Routing_Route, initMiddlewareAttribute);
PHP_METHOD(Zeplara_Routing_Route, getNameAttribute);
PHP_METHOD(Zeplara_Routing_Route, setNameAttribute);
PHP_METHOD(Zeplara_Routing_Route, initNameAttribute);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_route_getpattern, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_route_getpattern, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_route_getmethods, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_route_getmethods, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_route___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, methods, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_route_setschemeattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_route_initschemeattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_route_sethostattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_route_inithostattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_route_setrequirementsattribute, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, requirements, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_route_initrequirementsattribute, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, requirements, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_route_setwhereattribute, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_route_initmiddlewareattribute, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, middleware, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_route_setnameattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_route_initnameattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_routing_route_method_entry) {
	PHP_ME(Zeplara_Routing_Route, getPattern, arginfo_zeplara_routing_route_getpattern, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Route, getMethods, arginfo_zeplara_routing_route_getmethods, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Route, getCallback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Route, __construct, arginfo_zeplara_routing_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Routing_Route, compile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Route, getSchemeAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, setSchemeAttribute, arginfo_zeplara_routing_route_setschemeattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, initSchemeAttribute, arginfo_zeplara_routing_route_initschemeattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, getHostAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, setHostAttribute, arginfo_zeplara_routing_route_sethostattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, initHostAttribute, arginfo_zeplara_routing_route_inithostattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, getRequirementsAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, setRequirementsAttribute, arginfo_zeplara_routing_route_setrequirementsattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, initRequirementsAttribute, arginfo_zeplara_routing_route_initrequirementsattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, setWhereAttribute, arginfo_zeplara_routing_route_setwhereattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, getMiddlewareAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, setMiddlewareAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, initMiddlewareAttribute, arginfo_zeplara_routing_route_initmiddlewareattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, getNameAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, setNameAttribute, arginfo_zeplara_routing_route_setnameattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Route, initNameAttribute, arginfo_zeplara_routing_route_initnameattribute, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
