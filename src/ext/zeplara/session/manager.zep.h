
extern zend_class_entry *zeplara_session_manager_ce;

ZEPHIR_INIT_CLASS(Zeplara_Session_Manager);

PHP_METHOD(Zeplara_Session_Manager, getId);
PHP_METHOD(Zeplara_Session_Manager, getName);
PHP_METHOD(Zeplara_Session_Manager, getPrefix);
PHP_METHOD(Zeplara_Session_Manager, getHandler);
PHP_METHOD(Zeplara_Session_Manager, __construct);
PHP_METHOD(Zeplara_Session_Manager, setId);
PHP_METHOD(Zeplara_Session_Manager, setPrefix);
PHP_METHOD(Zeplara_Session_Manager, isStarted);
PHP_METHOD(Zeplara_Session_Manager, start);
PHP_METHOD(Zeplara_Session_Manager, regenerate);
PHP_METHOD(Zeplara_Session_Manager, save);
PHP_METHOD(Zeplara_Session_Manager, generateSessionId);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_session_manager_getid, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_session_manager_getid, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_session_manager_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_session_manager_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_session_manager_getprefix, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_session_manager_getprefix, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_manager___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, handler, SessionHandlerInterface, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_manager_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_manager_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_manager_regenerate, 0, 0, 0)
	ZEND_ARG_INFO(0, destroy)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_session_manager_method_entry) {
	PHP_ME(Zeplara_Session_Manager, getId, arginfo_zeplara_session_manager_getid, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Manager, getName, arginfo_zeplara_session_manager_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Manager, getPrefix, arginfo_zeplara_session_manager_getprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Manager, getHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Manager, __construct, arginfo_zeplara_session_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Session_Manager, setId, arginfo_zeplara_session_manager_setid, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Manager, setPrefix, arginfo_zeplara_session_manager_setprefix, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Manager, isStarted, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Manager, start, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Manager, regenerate, arginfo_zeplara_session_manager_regenerate, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Manager, save, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Manager, generateSessionId, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
