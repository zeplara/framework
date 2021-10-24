
extern zend_class_entry *zeplara_session_flash_ce;

ZEPHIR_INIT_CLASS(Zeplara_Session_Flash);

PHP_METHOD(Zeplara_Session_Flash, getName);
PHP_METHOD(Zeplara_Session_Flash, getManager);
PHP_METHOD(Zeplara_Session_Flash, __construct);
PHP_METHOD(Zeplara_Session_Flash, set);
PHP_METHOD(Zeplara_Session_Flash, resolveKey);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_session_flash_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_session_flash_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_flash___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, manager, Zeplara\\Interfaces\\Session\\Manager, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_flash_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_session_flash_resolvekey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_session_flash_method_entry) {
	PHP_ME(Zeplara_Session_Flash, getName, arginfo_zeplara_session_flash_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Flash, getManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Flash, __construct, arginfo_zeplara_session_flash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Session_Flash, set, arginfo_zeplara_session_flash_set, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Session_Flash, resolveKey, arginfo_zeplara_session_flash_resolvekey, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
