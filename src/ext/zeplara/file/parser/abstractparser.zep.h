
extern zend_class_entry *zeplara_file_parser_abstractparser_ce;

ZEPHIR_INIT_CLASS(Zeplara_File_Parser_AbstractParser);

PHP_METHOD(Zeplara_File_Parser_AbstractParser, parseFile);
PHP_METHOD(Zeplara_File_Parser_AbstractParser, throwParserException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_parser_abstractparser_parsefile, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, file)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_parser_abstractparser_throwparserexception, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_file_parser_abstractparser_method_entry) {
	PHP_ME(Zeplara_File_Parser_AbstractParser, parseFile, arginfo_zeplara_file_parser_abstractparser_parsefile, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Parser_AbstractParser, throwParserException, arginfo_zeplara_file_parser_abstractparser_throwparserexception, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
