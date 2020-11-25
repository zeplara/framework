
extern zend_class_entry *zeplara_pipeline_carry_ce;

ZEPHIR_INIT_CLASS(Zeplara_Pipeline_Carry);

PHP_METHOD(Zeplara_Pipeline_Carry, __construct);
PHP_METHOD(Zeplara_Pipeline_Carry, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_pipeline_carry___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, container, Zeplara\\Contracts\\Container\\Container, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, pipe)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_pipeline_carry_method_entry) {
	PHP_ME(Zeplara_Pipeline_Carry, __construct, arginfo_zeplara_pipeline_carry___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Pipeline_Carry, __invoke, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
