
extern zend_class_entry *zeplara_file_parser_parserexception_ce;

ZEPHIR_INIT_CLASS(Zeplara_File_Parser_ParserException);

PHP_METHOD(Zeplara_File_Parser_ParserException, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_parser_parserexception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_INFO(0, lineno)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_file_parser_parserexception_method_entry) {
	PHP_ME(Zeplara_File_Parser_ParserException, __construct, arginfo_zeplara_file_parser_parserexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
