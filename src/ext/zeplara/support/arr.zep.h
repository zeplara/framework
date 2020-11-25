
extern zend_class_entry *zeplara_support_arr_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_Arr);

PHP_METHOD(Zeplara_Support_Arr, __construct);
PHP_METHOD(Zeplara_Support_Arr, wrap);
PHP_METHOD(Zeplara_Support_Arr, flatten);
PHP_METHOD(Zeplara_Support_Arr, get);
PHP_METHOD(Zeplara_Support_Arr, has);
PHP_METHOD(Zeplara_Support_Arr, put);
PHP_METHOD(Zeplara_Support_Arr, set);
PHP_METHOD(Zeplara_Support_Arr, first);
PHP_METHOD(Zeplara_Support_Arr, last);
PHP_METHOD(Zeplara_Support_Arr, createSegmentsOfKey);
PHP_METHOD(Zeplara_Support_Arr, implodeSegmentsOfKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_arr_wrap, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_arr_flatten, 0, 0, 1)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, depth)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_arr_get, 0, 0, 2)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_arr_has, 0, 0, 2)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_arr_put, 0, 0, 2)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_arr_set, 0, 0, 3)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_arr_first, 0, 0, 1)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_arr_last, 0, 0, 1)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_arr_createsegmentsofkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_arr_implodesegmentsofkey, 0, 0, 1)
	ZEND_ARG_INFO(0, segments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_arr_method_entry) {
	PHP_ME(Zeplara_Support_Arr, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Support_Arr, wrap, arginfo_zeplara_support_arr_wrap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Arr, flatten, arginfo_zeplara_support_arr_flatten, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Arr, get, arginfo_zeplara_support_arr_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Arr, has, arginfo_zeplara_support_arr_has, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Arr, put, arginfo_zeplara_support_arr_put, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Arr, set, arginfo_zeplara_support_arr_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Arr, first, arginfo_zeplara_support_arr_first, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Arr, last, arginfo_zeplara_support_arr_last, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Arr, createSegmentsOfKey, arginfo_zeplara_support_arr_createsegmentsofkey, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Arr, implodeSegmentsOfKey, arginfo_zeplara_support_arr_implodesegmentsofkey, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
