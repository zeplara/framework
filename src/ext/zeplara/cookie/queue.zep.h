
extern zend_class_entry *zeplara_cookie_queue_ce;

ZEPHIR_INIT_CLASS(Zeplara_Cookie_Queue);

PHP_METHOD(Zeplara_Cookie_Queue, getCookies);
PHP_METHOD(Zeplara_Cookie_Queue, has);
PHP_METHOD(Zeplara_Cookie_Queue, get);
PHP_METHOD(Zeplara_Cookie_Queue, set);
PHP_METHOD(Zeplara_Cookie_Queue, put);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_queue_getcookies, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_queue_getcookies, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_queue_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_queue_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_queue_set, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cookie, Zeplara\\Contracts\\Cookie\\Cookie, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_queue_put, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_cookie_queue_method_entry) {
	PHP_ME(Zeplara_Cookie_Queue, getCookies, arginfo_zeplara_cookie_queue_getcookies, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Queue, has, arginfo_zeplara_cookie_queue_has, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Queue, get, arginfo_zeplara_cookie_queue_get, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Queue, set, arginfo_zeplara_cookie_queue_set, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Queue, put, arginfo_zeplara_cookie_queue_put, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
