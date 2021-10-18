
extern zend_class_entry *zeplara_file_parser_yamlparser_ce;

ZEPHIR_INIT_CLASS(Zeplara_File_Parser_YamlParser);

PHP_METHOD(Zeplara_File_Parser_YamlParser, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_parser_yamlparser_parse, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, contents, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, contents)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_file_parser_yamlparser_method_entry) {
	PHP_ME(Zeplara_File_Parser_YamlParser, parse, arginfo_zeplara_file_parser_yamlparser_parse, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
