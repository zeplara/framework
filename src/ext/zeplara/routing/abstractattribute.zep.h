
extern zend_class_entry *zeplara_routing_abstractattribute_ce;

ZEPHIR_INIT_CLASS(Zeplara_Routing_AbstractAttribute);

PHP_METHOD(Zeplara_Routing_AbstractAttribute, getAttributes);
PHP_METHOD(Zeplara_Routing_AbstractAttribute, setAttributes);
PHP_METHOD(Zeplara_Routing_AbstractAttribute, __call);
PHP_METHOD(Zeplara_Routing_AbstractAttribute, methodExists);
PHP_METHOD(Zeplara_Routing_AbstractAttribute, throwBadMethodCallException);
zend_object *zephir_init_properties_Zeplara_Routing_AbstractAttribute(zend_class_entry *class_type TSRMLS_DC);
void zephir_init_static_properties_Zeplara_Routing_AbstractAttribute(TSRMLS_D);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_abstractattribute_getattributes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_abstractattribute_getattributes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_abstractattribute_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_abstractattribute___call, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_abstractattribute_methodexists, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_abstractattribute_throwbadmethodcallexception, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_routing_abstractattribute_method_entry) {
	PHP_ME(Zeplara_Routing_AbstractAttribute, getAttributes, arginfo_zeplara_routing_abstractattribute_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_AbstractAttribute, setAttributes, arginfo_zeplara_routing_abstractattribute_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_AbstractAttribute, __call, arginfo_zeplara_routing_abstractattribute___call, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_AbstractAttribute, methodExists, arginfo_zeplara_routing_abstractattribute_methodexists, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Routing_AbstractAttribute, throwBadMethodCallException, arginfo_zeplara_routing_abstractattribute_throwbadmethodcallexception, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
