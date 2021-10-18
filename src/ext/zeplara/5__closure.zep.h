
extern zend_class_entry *zeplara_5__closure_ce;

ZEPHIR_INIT_CLASS(zeplara_5__closure);

PHP_METHOD(zeplara_5__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_5__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, matches)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_5__closure_method_entry) {
	PHP_ME(zeplara_5__closure, __invoke, arginfo_zeplara_5__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
