
extern zend_class_entry *zeplara_support_facades_facade_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_Facades_Facade);

PHP_METHOD(Zeplara_Support_Facades_Facade, __construct);
PHP_METHOD(Zeplara_Support_Facades_Facade, setContainer);
PHP_METHOD(Zeplara_Support_Facades_Facade, __callStatic);
PHP_METHOD(Zeplara_Support_Facades_Facade, getAccessor);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_facades_facade_setcontainer, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Zeplara\\Contracts\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_facades_facade___callstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, paramters, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_facades_facade_method_entry) {
	PHP_ME(Zeplara_Support_Facades_Facade, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Support_Facades_Facade, setContainer, arginfo_zeplara_support_facades_facade_setcontainer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Facades_Facade, __callStatic, arginfo_zeplara_support_facades_facade___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Facades_Facade, getAccessor, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
