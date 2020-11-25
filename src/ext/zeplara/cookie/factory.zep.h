
extern zend_class_entry *zeplara_cookie_factory_ce;

ZEPHIR_INIT_CLASS(Zeplara_Cookie_Factory);

PHP_METHOD(Zeplara_Cookie_Factory, __construct);
PHP_METHOD(Zeplara_Cookie_Factory, make);
PHP_METHOD(Zeplara_Cookie_Factory, forever);
PHP_METHOD(Zeplara_Cookie_Factory, forget);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_factory_make, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expiration)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, httpOnly)
	ZEND_ARG_INFO(0, sameSite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_factory_forever, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, httpOnly)
	ZEND_ARG_INFO(0, sameSite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_factory_forget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, httpOnly)
	ZEND_ARG_INFO(0, sameSite)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_cookie_factory_method_entry) {
	PHP_ME(Zeplara_Cookie_Factory, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Cookie_Factory, make, arginfo_zeplara_cookie_factory_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Cookie_Factory, forever, arginfo_zeplara_cookie_factory_forever, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Cookie_Factory, forget, arginfo_zeplara_cookie_factory_forget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
