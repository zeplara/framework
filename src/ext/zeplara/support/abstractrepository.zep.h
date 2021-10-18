
extern zend_class_entry *zeplara_support_abstractrepository_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_AbstractRepository);

PHP_METHOD(Zeplara_Support_AbstractRepository, getItems);
PHP_METHOD(Zeplara_Support_AbstractRepository, setItems);
PHP_METHOD(Zeplara_Support_AbstractRepository, has);
PHP_METHOD(Zeplara_Support_AbstractRepository, get);
PHP_METHOD(Zeplara_Support_AbstractRepository, set);
PHP_METHOD(Zeplara_Support_AbstractRepository, put);
PHP_METHOD(Zeplara_Support_AbstractRepository, offsetExists);
PHP_METHOD(Zeplara_Support_AbstractRepository, offsetGet);
PHP_METHOD(Zeplara_Support_AbstractRepository, offsetSet);
PHP_METHOD(Zeplara_Support_AbstractRepository, offsetUnset);
PHP_METHOD(Zeplara_Support_AbstractRepository, __get);
PHP_METHOD(Zeplara_Support_AbstractRepository, __isset);
PHP_METHOD(Zeplara_Support_AbstractRepository, __set);
PHP_METHOD(Zeplara_Support_AbstractRepository, __unset);
zend_object *zephir_init_properties_Zeplara_Support_AbstractRepository(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_abstractrepository_getitems, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_abstractrepository_getitems, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository_setitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, items, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository_put, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_abstractrepository___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_abstractrepository_method_entry) {
	PHP_ME(Zeplara_Support_AbstractRepository, getItems, arginfo_zeplara_support_abstractrepository_getitems, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, setItems, arginfo_zeplara_support_abstractrepository_setitems, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, has, arginfo_zeplara_support_abstractrepository_has, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, get, arginfo_zeplara_support_abstractrepository_get, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, set, arginfo_zeplara_support_abstractrepository_set, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, put, arginfo_zeplara_support_abstractrepository_put, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, offsetExists, arginfo_zeplara_support_abstractrepository_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, offsetGet, arginfo_zeplara_support_abstractrepository_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, offsetSet, arginfo_zeplara_support_abstractrepository_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, offsetUnset, arginfo_zeplara_support_abstractrepository_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, __get, arginfo_zeplara_support_abstractrepository___get, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, __isset, arginfo_zeplara_support_abstractrepository___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, __set, arginfo_zeplara_support_abstractrepository___set, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_AbstractRepository, __unset, arginfo_zeplara_support_abstractrepository___unset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
