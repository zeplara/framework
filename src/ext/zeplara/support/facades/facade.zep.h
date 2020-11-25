
extern zend_class_entry *zeplara_support_facades_facade_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_Facades_Facade);

PHP_METHOD(Zeplara_Support_Facades_Facade, __construct);
PHP_METHOD(Zeplara_Support_Facades_Facade, getAccessor);

ZEPHIR_INIT_FUNCS(zeplara_support_facades_facade_method_entry) {
	PHP_ME(Zeplara_Support_Facades_Facade, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Support_Facades_Facade, getAccessor, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
