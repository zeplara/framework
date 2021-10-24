
extern zend_class_entry *zeplara_interfaces_file_parser_parser_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_File_Parser_Parser);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_file_parser_parser_parse, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, contents, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, contents)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_file_parser_parser_parsefile, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, file)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_file_parser_parser_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_File_Parser_Parser, parse, arginfo_zeplara_interfaces_file_parser_parser_parse)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_File_Parser_Parser, parseFile, arginfo_zeplara_interfaces_file_parser_parser_parsefile)
	PHP_FE_END
};
