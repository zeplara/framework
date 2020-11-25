
extern zend_class_entry *zeplara_session_filesessionhandler_ce;

ZEPHIR_INIT_CLASS(Zeplara_Session_FileSessionHandler);

PHP_METHOD(Zeplara_Session_FileSessionHandler, __construct);
PHP_METHOD(Zeplara_Session_FileSessionHandler, close);
PHP_METHOD(Zeplara_Session_FileSessionHandler, destroy);
PHP_METHOD(Zeplara_Session_FileSessionHandler, gc);
PHP_METHOD(Zeplara_Session_FileSessionHandler, open);
PHP_METHOD(Zeplara_Session_FileSessionHandler, read);
PHP_METHOD(Zeplara_Session_FileSessionHandler, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_filesessionhandler___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_filesessionhandler_destroy, 0, 0, 1)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_filesessionhandler_gc, 0, 0, 1)
	ZEND_ARG_INFO(0, maxlifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_filesessionhandler_open, 0, 0, 2)
	ZEND_ARG_INFO(0, save_path)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_filesessionhandler_read, 0, 0, 1)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_filesessionhandler_write, 0, 0, 2)
	ZEND_ARG_INFO(0, session_id)
	ZEND_ARG_INFO(0, session_data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_session_filesessionhandler_method_entry) {
	PHP_ME(Zeplara_Session_FileSessionHandler, __construct, arginfo_zeplara_session_filesessionhandler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Session_FileSessionHandler, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_FileSessionHandler, destroy, arginfo_zeplara_session_filesessionhandler_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_FileSessionHandler, gc, arginfo_zeplara_session_filesessionhandler_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_FileSessionHandler, open, arginfo_zeplara_session_filesessionhandler_open, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_FileSessionHandler, read, arginfo_zeplara_session_filesessionhandler_read, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_FileSessionHandler, write, arginfo_zeplara_session_filesessionhandler_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
