
extern zend_class_entry *zeplara_routing_group_ce;

ZEPHIR_INIT_CLASS(Zeplara_Routing_Group);

PHP_METHOD(Zeplara_Routing_Group, load);
PHP_METHOD(Zeplara_Routing_Group, getSchemeAttribute);
PHP_METHOD(Zeplara_Routing_Group, setSchemeAttribute);
PHP_METHOD(Zeplara_Routing_Group, initSchemeAttribute);
PHP_METHOD(Zeplara_Routing_Group, initHostAttribute);
PHP_METHOD(Zeplara_Routing_Group, getHostAttribute);
PHP_METHOD(Zeplara_Routing_Group, setHostAttribute);
PHP_METHOD(Zeplara_Routing_Group, initPrefixAttribute);
PHP_METHOD(Zeplara_Routing_Group, getPrefixAttribute);
PHP_METHOD(Zeplara_Routing_Group, setPrefixAttribute);
PHP_METHOD(Zeplara_Routing_Group, initNamespaceAttribute);
PHP_METHOD(Zeplara_Routing_Group, getNamespaceAttribute);
PHP_METHOD(Zeplara_Routing_Group, setNamespaceAttribute);
PHP_METHOD(Zeplara_Routing_Group, getRequirementsAttribute);
PHP_METHOD(Zeplara_Routing_Group, setRequirementsAttribute);
PHP_METHOD(Zeplara_Routing_Group, initRequirementsAttribute);
PHP_METHOD(Zeplara_Routing_Group, setWhereAttribute);
PHP_METHOD(Zeplara_Routing_Group, initMiddlewareAttribute);
PHP_METHOD(Zeplara_Routing_Group, getMiddlewareAttribute);
PHP_METHOD(Zeplara_Routing_Group, setMiddlewareAttribute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_load, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, router, Zeplara\\Interfaces\\Routing\\Router, 0)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_setschemeattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_initschemeattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_inithostattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_sethostattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_initprefixattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_setprefixattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_initnamespaceattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_setnamespaceattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_setrequirementsattribute, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, requirements, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_initrequirementsattribute, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, requirements, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_setwhereattribute, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_group_initmiddlewareattribute, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, middleware, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_routing_group_method_entry) {
	PHP_ME(Zeplara_Routing_Group, load, arginfo_zeplara_routing_group_load, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Routing_Group, getSchemeAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, setSchemeAttribute, arginfo_zeplara_routing_group_setschemeattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, initSchemeAttribute, arginfo_zeplara_routing_group_initschemeattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, initHostAttribute, arginfo_zeplara_routing_group_inithostattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, getHostAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, setHostAttribute, arginfo_zeplara_routing_group_sethostattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, initPrefixAttribute, arginfo_zeplara_routing_group_initprefixattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, getPrefixAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, setPrefixAttribute, arginfo_zeplara_routing_group_setprefixattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, initNamespaceAttribute, arginfo_zeplara_routing_group_initnamespaceattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, getNamespaceAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, setNamespaceAttribute, arginfo_zeplara_routing_group_setnamespaceattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, getRequirementsAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, setRequirementsAttribute, arginfo_zeplara_routing_group_setrequirementsattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, initRequirementsAttribute, arginfo_zeplara_routing_group_initrequirementsattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, setWhereAttribute, arginfo_zeplara_routing_group_setwhereattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, initMiddlewareAttribute, arginfo_zeplara_routing_group_initmiddlewareattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, getMiddlewareAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Routing_Group, setMiddlewareAttribute, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
