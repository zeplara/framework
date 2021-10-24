
extern zend_class_entry *zeplara_interfaces_pipeline_pipeline_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Pipeline_Pipeline);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_pipeline_pipeline_setpipes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, pipes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_pipeline_pipeline_addpipe, 0, 0, 1)
	ZEND_ARG_INFO(0, pipe)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_pipeline_pipeline_send, 0, 0, 1)
	ZEND_ARG_INFO(0, destination)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_pipeline_pipeline_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Pipeline_Pipeline, getContainer, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Pipeline_Pipeline, getPipes, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Pipeline_Pipeline, setPipes, arginfo_zeplara_interfaces_pipeline_pipeline_setpipes)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Pipeline_Pipeline, addPipe, arginfo_zeplara_interfaces_pipeline_pipeline_addpipe)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Pipeline_Pipeline, send, arginfo_zeplara_interfaces_pipeline_pipeline_send)
	PHP_FE_END
};
