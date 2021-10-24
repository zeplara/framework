
extern zend_class_entry *zeplara_interfaces_cookie_queue_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Cookie_Queue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_cookie_queue_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_cookie_queue_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_cookie_queue_set, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cookie, Zeplara\\Interfaces\\Cookie\\Cookie, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_cookie_queue_put, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_cookie_queue_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Queue, has, arginfo_zeplara_interfaces_cookie_queue_has)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Queue, get, arginfo_zeplara_interfaces_cookie_queue_get)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Queue, set, arginfo_zeplara_interfaces_cookie_queue_set)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Queue, put, arginfo_zeplara_interfaces_cookie_queue_put)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Queue, getCookies, NULL)
	PHP_FE_END
};
