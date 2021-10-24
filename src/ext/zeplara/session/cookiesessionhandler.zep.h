
extern zend_class_entry *zeplara_session_cookiesessionhandler_ce;

ZEPHIR_INIT_CLASS(Zeplara_Session_CookieSessionHandler);

PHP_METHOD(Zeplara_Session_CookieSessionHandler, __construct);
PHP_METHOD(Zeplara_Session_CookieSessionHandler, close);
PHP_METHOD(Zeplara_Session_CookieSessionHandler, gc);
PHP_METHOD(Zeplara_Session_CookieSessionHandler, open);
PHP_METHOD(Zeplara_Session_CookieSessionHandler, read);
PHP_METHOD(Zeplara_Session_CookieSessionHandler, write);
PHP_METHOD(Zeplara_Session_CookieSessionHandler, destroy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_cookiesessionhandler___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, queue, Zeplara\\Interfaces\\Cookie\\Queue, 0)
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\ServerRequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_cookiesessionhandler_gc, 0, 0, 1)
	ZEND_ARG_INFO(0, maxlifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_cookiesessionhandler_open, 0, 0, 2)
	ZEND_ARG_INFO(0, save_path)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_cookiesessionhandler_read, 0, 0, 1)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_cookiesessionhandler_write, 0, 0, 2)
	ZEND_ARG_INFO(0, session_id)
	ZEND_ARG_INFO(0, session_data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_cookiesessionhandler_destroy, 0, 0, 1)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_session_cookiesessionhandler_method_entry) {
	PHP_ME(Zeplara_Session_CookieSessionHandler, __construct, arginfo_zeplara_session_cookiesessionhandler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Session_CookieSessionHandler, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_CookieSessionHandler, gc, arginfo_zeplara_session_cookiesessionhandler_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_CookieSessionHandler, open, arginfo_zeplara_session_cookiesessionhandler_open, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_CookieSessionHandler, read, arginfo_zeplara_session_cookiesessionhandler_read, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_CookieSessionHandler, write, arginfo_zeplara_session_cookiesessionhandler_write, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_CookieSessionHandler, destroy, arginfo_zeplara_session_cookiesessionhandler_destroy, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
