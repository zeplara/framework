
extern zend_class_entry *zeplara_config_xmlloader_ce;

ZEPHIR_INIT_CLASS(Zeplara_Config_XmlLoader);

PHP_METHOD(Zeplara_Config_XmlLoader, load);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_config_xmlloader_load, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_config_xmlloader_method_entry) {
	PHP_ME(Zeplara_Config_XmlLoader, load, arginfo_zeplara_config_xmlloader_load, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
