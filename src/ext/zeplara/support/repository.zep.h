
extern zend_class_entry *zeplara_support_repository_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_Repository);

PHP_METHOD(Zeplara_Support_Repository, getItems);
PHP_METHOD(Zeplara_Support_Repository, setItems);
PHP_METHOD(Zeplara_Support_Repository, has);
PHP_METHOD(Zeplara_Support_Repository, get);
PHP_METHOD(Zeplara_Support_Repository, set);
PHP_METHOD(Zeplara_Support_Repository, put);
PHP_METHOD(Zeplara_Support_Repository, offsetExists);
PHP_METHOD(Zeplara_Support_Repository, offsetGet);
PHP_METHOD(Zeplara_Support_Repository, offsetSet);
PHP_METHOD(Zeplara_Support_Repository, offsetUnset);
PHP_METHOD(Zeplara_Support_Repository, __get);
PHP_METHOD(Zeplara_Support_Repository, __isset);
PHP_METHOD(Zeplara_Support_Repository, __set);
PHP_METHOD(Zeplara_Support_Repository, __unset);
zend_object *zephir_init_properties_Zeplara_Support_Repository(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_repository_getitems, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_repository_getitems, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository_setitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, items, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository_put, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_repository___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_repository_method_entry) {
	PHP_ME(Zeplara_Support_Repository, getItems, arginfo_zeplara_support_repository_getitems, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, setItems, arginfo_zeplara_support_repository_setitems, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, has, arginfo_zeplara_support_repository_has, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, get, arginfo_zeplara_support_repository_get, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, set, arginfo_zeplara_support_repository_set, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, put, arginfo_zeplara_support_repository_put, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, offsetExists, arginfo_zeplara_support_repository_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, offsetGet, arginfo_zeplara_support_repository_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, offsetSet, arginfo_zeplara_support_repository_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, offsetUnset, arginfo_zeplara_support_repository_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, __get, arginfo_zeplara_support_repository___get, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, __isset, arginfo_zeplara_support_repository___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, __set, arginfo_zeplara_support_repository___set, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_Repository, __unset, arginfo_zeplara_support_repository___unset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
