
extern zend_class_entry *zeplara_contracts_application_ce;

ZEPHIR_INIT_CLASS(Zeplara_Contracts_Application);

ZEPHIR_INIT_FUNCS(zeplara_contracts_application_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Contracts_Application, getBasePath, NULL)
	PHP_FE_END
};
