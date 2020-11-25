
extern zend_class_entry *zeplara_support_file_parser_abstractparser_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_File_Parser_AbstractParser);

PHP_METHOD(Zeplara_Support_File_Parser_AbstractParser, __construct);
PHP_METHOD(Zeplara_Support_File_Parser_AbstractParser, parse);
PHP_METHOD(Zeplara_Support_File_Parser_AbstractParser, parseFile);
PHP_METHOD(Zeplara_Support_File_Parser_AbstractParser, throwParserException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_abstractparser_parse, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, contents, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, contents)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_abstractparser_parsefile, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, file)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_abstractparser_throwparserexception, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_file_parser_abstractparser_method_entry) {
	PHP_ME(Zeplara_Support_File_Parser_AbstractParser, __construct, NULL, ZEND_ACC_FINAL|ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Support_File_Parser_AbstractParser, parse, arginfo_zeplara_support_file_parser_abstractparser_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_AbstractParser, parseFile, arginfo_zeplara_support_file_parser_abstractparser_parsefile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_AbstractParser, throwParserException, arginfo_zeplara_support_file_parser_abstractparser_throwparserexception, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
