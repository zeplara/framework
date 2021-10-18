
extern zend_class_entry *zeplara_config_yamlloader_ce;

ZEPHIR_INIT_CLASS(Zeplara_Config_YamlLoader);

PHP_METHOD(Zeplara_Config_YamlLoader, load);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_config_yamlloader_load, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_config_yamlloader_method_entry) {
	PHP_ME(Zeplara_Config_YamlLoader, load, arginfo_zeplara_config_yamlloader_load, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
