
extern zend_class_entry *zeplara_pipeline_pipeline_ce;

ZEPHIR_INIT_CLASS(Zeplara_Pipeline_Pipeline);

PHP_METHOD(Zeplara_Pipeline_Pipeline, getContainer);
PHP_METHOD(Zeplara_Pipeline_Pipeline, getPipes);
PHP_METHOD(Zeplara_Pipeline_Pipeline, setPipes);
PHP_METHOD(Zeplara_Pipeline_Pipeline, __construct);
PHP_METHOD(Zeplara_Pipeline_Pipeline, addPipe);
PHP_METHOD(Zeplara_Pipeline_Pipeline, send);
PHP_METHOD(Zeplara_Pipeline_Pipeline, reduceCallback);
zend_object *zephir_init_properties_Zeplara_Pipeline_Pipeline(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_pipeline_pipeline_getpipes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_pipeline_pipeline_getpipes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_pipeline_pipeline_setpipes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, pipes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_pipeline_pipeline___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Zeplara\\Interfaces\\Container\\Container, 0)
	ZEND_ARG_ARRAY_INFO(0, pipes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_pipeline_pipeline_addpipe, 0, 0, 1)
	ZEND_ARG_INFO(0, pipe)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_pipeline_pipeline_send, 0, 0, 1)
	ZEND_ARG_INFO(0, destination)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_pipeline_pipeline_reducecallback, 0, 0, 2)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, pipe)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_pipeline_pipeline_method_entry) {
	PHP_ME(Zeplara_Pipeline_Pipeline, getContainer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Pipeline_Pipeline, getPipes, arginfo_zeplara_pipeline_pipeline_getpipes, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Pipeline_Pipeline, setPipes, arginfo_zeplara_pipeline_pipeline_setpipes, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Pipeline_Pipeline, __construct, arginfo_zeplara_pipeline_pipeline___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Pipeline_Pipeline, addPipe, arginfo_zeplara_pipeline_pipeline_addpipe, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Pipeline_Pipeline, send, arginfo_zeplara_pipeline_pipeline_send, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Pipeline_Pipeline, reduceCallback, arginfo_zeplara_pipeline_pipeline_reducecallback, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
