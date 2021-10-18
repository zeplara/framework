
extern zend_class_entry *zeplara_support_facades_abstractfacade_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_Facades_AbstractFacade);

PHP_METHOD(Zeplara_Support_Facades_AbstractFacade, __construct);
PHP_METHOD(Zeplara_Support_Facades_AbstractFacade, setContainer);
PHP_METHOD(Zeplara_Support_Facades_AbstractFacade, __callStatic);
PHP_METHOD(Zeplara_Support_Facades_AbstractFacade, getAccessor);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_facades_abstractfacade_setcontainer, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Zeplara\\Contracts\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_facades_abstractfacade___callstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, paramters, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_facades_abstractfacade_method_entry) {
	PHP_ME(Zeplara_Support_Facades_AbstractFacade, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Support_Facades_AbstractFacade, setContainer, arginfo_zeplara_support_facades_abstractfacade_setcontainer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Facades_AbstractFacade, __callStatic, arginfo_zeplara_support_facades_abstractfacade___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Facades_AbstractFacade, getAccessor, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
