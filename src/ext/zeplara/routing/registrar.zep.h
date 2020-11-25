
extern zend_class_entry *zeplara_routing_registrar_ce;

ZEPHIR_INIT_CLASS(Zeplara_Routing_Registrar);

PHP_METHOD(Zeplara_Routing_Registrar, getRouter);
PHP_METHOD(Zeplara_Routing_Registrar, __construct);
PHP_METHOD(Zeplara_Routing_Registrar, get);
PHP_METHOD(Zeplara_Routing_Registrar, post);
PHP_METHOD(Zeplara_Routing_Registrar, put);
PHP_METHOD(Zeplara_Routing_Registrar, delete);
PHP_METHOD(Zeplara_Routing_Registrar, patch);
PHP_METHOD(Zeplara_Routing_Registrar, options);
PHP_METHOD(Zeplara_Routing_Registrar, any);
PHP_METHOD(Zeplara_Routing_Registrar, group);
PHP_METHOD(Zeplara_Routing_Registrar, register);
PHP_METHOD(Zeplara_Routing_Registrar, setSchemeAttribute);
PHP_METHOD(Zeplara_Routing_Registrar, setHostAttribute);
PHP_METHOD(Zeplara_Routing_Registrar, setPrefixAttribute);
PHP_METHOD(Zeplara_Routing_Registrar, setNamespaceAttribute);
PHP_METHOD(Zeplara_Routing_Registrar, setRequirementsAttribute);
PHP_METHOD(Zeplara_Routing_Registrar, setWhereAttribute);
PHP_METHOD(Zeplara_Routing_Registrar, setMiddlewareAttribute);
PHP_METHOD(Zeplara_Routing_Registrar, setNameAttribute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, router, Zeplara\\Routing\\Router, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_get, 0, 0, 2)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_post, 0, 0, 2)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_put, 0, 0, 2)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_delete, 0, 0, 2)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_patch, 0, 0, 2)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_options, 0, 0, 2)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_any, 0, 0, 2)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_group, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_register, 0, 0, 3)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, methods, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_setschemeattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_sethostattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_setprefixattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_setnamespaceattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_setrequirementsattribute, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, requirements, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_setwhereattribute, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_registrar_setnameattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_routing_registrar_method_entry) {
	PHP_ME(Zeplara_Routing_Registrar, getRouter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Registrar, __construct, arginfo_zeplara_routing_registrar___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Routing_Registrar, get, arginfo_zeplara_routing_registrar_get, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Registrar, post, arginfo_zeplara_routing_registrar_post, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Registrar, put, arginfo_zeplara_routing_registrar_put, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Registrar, delete, arginfo_zeplara_routing_registrar_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Registrar, patch, arginfo_zeplara_routing_registrar_patch, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Registrar, options, arginfo_zeplara_routing_registrar_options, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Registrar, any, arginfo_zeplara_routing_registrar_any, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Registrar, group, arginfo_zeplara_routing_registrar_group, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Registrar, register, arginfo_zeplara_routing_registrar_register, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Registrar, setSchemeAttribute, arginfo_zeplara_routing_registrar_setschemeattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Registrar, setHostAttribute, arginfo_zeplara_routing_registrar_sethostattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Registrar, setPrefixAttribute, arginfo_zeplara_routing_registrar_setprefixattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Registrar, setNamespaceAttribute, arginfo_zeplara_routing_registrar_setnamespaceattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Registrar, setRequirementsAttribute, arginfo_zeplara_routing_registrar_setrequirementsattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Registrar, setWhereAttribute, arginfo_zeplara_routing_registrar_setwhereattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Registrar, setMiddlewareAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Registrar, setNameAttribute, arginfo_zeplara_routing_registrar_setnameattribute, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
