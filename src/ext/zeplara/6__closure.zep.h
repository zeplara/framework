
extern zend_class_entry *zeplara_6__closure_ce;

ZEPHIR_INIT_CLASS(zeplara_6__closure);

PHP_METHOD(zeplara_6__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_6__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, matches)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_6__closure_method_entry) {
	PHP_ME(zeplara_6__closure, __invoke, arginfo_zeplara_6__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
