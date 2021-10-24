
extern zend_class_entry *zeplara_interfaces_application_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Application);

ZEPHIR_INIT_FUNCS(zeplara_interfaces_application_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Application, getBasePath, NULL)
	PHP_FE_END
};
