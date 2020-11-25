
extern zend_class_entry *zeplara_config_loaderexception_ce;

ZEPHIR_INIT_CLASS(Zeplara_Config_LoaderException);

PHP_METHOD(Zeplara_Config_LoaderException, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_config_loaderexception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_INFO(0, lineno)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_config_loaderexception_method_entry) {
	PHP_ME(Zeplara_Config_LoaderException, __construct, arginfo_zeplara_config_loaderexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
