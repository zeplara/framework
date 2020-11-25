
extern zend_class_entry *zeplara_container_container_ce;

ZEPHIR_INIT_CLASS(Zeplara_Container_Container);

PHP_METHOD(Zeplara_Container_Container, get);
PHP_METHOD(Zeplara_Container_Container, has);
PHP_METHOD(Zeplara_Container_Container, set);
PHP_METHOD(Zeplara_Container_Container, put);
PHP_METHOD(Zeplara_Container_Container, make);
PHP_METHOD(Zeplara_Container_Container, offsetGet);
PHP_METHOD(Zeplara_Container_Container, offsetExists);
PHP_METHOD(Zeplara_Container_Container, offsetSet);
PHP_METHOD(Zeplara_Container_Container, offsetUnset);
PHP_METHOD(Zeplara_Container_Container, __get);
PHP_METHOD(Zeplara_Container_Container, __isset);
PHP_METHOD(Zeplara_Container_Container, __set);
PHP_METHOD(Zeplara_Container_Container, __unset);
PHP_METHOD(Zeplara_Container_Container, parseArguments);
PHP_METHOD(Zeplara_Container_Container, resolveBinding);
PHP_METHOD(Zeplara_Container_Container, resolveKey);
zend_object *zephir_init_properties_Zeplara_Container_Container(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, resolve, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, resolve)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_put, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_make, 0, 0, 1)
	ZEND_ARG_INFO(0, abstract)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_parsearguments, 0, 0, 1)
	ZEND_ARG_INFO(0, reflector)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_resolvebinding, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, binding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_container_resolvekey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_container_container_method_entry) {
	PHP_ME(Zeplara_Container_Container, get, arginfo_zeplara_container_container_get, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, has, arginfo_zeplara_container_container_has, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, set, arginfo_zeplara_container_container_set, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, put, arginfo_zeplara_container_container_put, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, make, arginfo_zeplara_container_container_make, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, offsetGet, arginfo_zeplara_container_container_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, offsetExists, arginfo_zeplara_container_container_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, offsetSet, arginfo_zeplara_container_container_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, offsetUnset, arginfo_zeplara_container_container_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, __get, arginfo_zeplara_container_container___get, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, __isset, arginfo_zeplara_container_container___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, __set, arginfo_zeplara_container_container___set, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, __unset, arginfo_zeplara_container_container___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_Container, parseArguments, arginfo_zeplara_container_container_parsearguments, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Container_Container, resolveBinding, arginfo_zeplara_container_container_resolvebinding, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Container_Container, resolveKey, arginfo_zeplara_container_container_resolvekey, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
