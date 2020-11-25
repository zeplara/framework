
extern zend_class_entry *zeplara_contracts_config_loader_ce;

ZEPHIR_INIT_CLASS(Zeplara_Contracts_Config_Loader);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_config_loader_load, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_contracts_config_loader_method_entry) {
	ZEND_FENTRY(load, NULL, arginfo_zeplara_contracts_config_loader_load, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
