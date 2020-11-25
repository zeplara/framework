
extern zend_class_entry *zeplara_support_file_parser_envparser_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_File_Parser_EnvParser);

PHP_METHOD(Zeplara_Support_File_Parser_EnvParser, parse);
PHP_METHOD(Zeplara_Support_File_Parser_EnvParser, compileArrayValue);
PHP_METHOD(Zeplara_Support_File_Parser_EnvParser, compileStringValue);
PHP_METHOD(Zeplara_Support_File_Parser_EnvParser, compileBooleanValue);
PHP_METHOD(Zeplara_Support_File_Parser_EnvParser, compileNullValue);
PHP_METHOD(Zeplara_Support_File_Parser_EnvParser, compileIntegerOrFloatValue);
PHP_METHOD(Zeplara_Support_File_Parser_EnvParser, compileVariableValue);
PHP_METHOD(Zeplara_Support_File_Parser_EnvParser, throwParserExceptionUIMV);
PHP_METHOD(Zeplara_Support_File_Parser_EnvParser, compileValue);
PHP_METHOD(Zeplara_Support_File_Parser_EnvParser, clearComments);
PHP_METHOD(Zeplara_Support_File_Parser_EnvParser, findLineByPos);
void zephir_init_static_properties_Zeplara_Support_File_Parser_EnvParser(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_envparser_parse, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, contents, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, contents)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_envparser_compilearrayvalue, 0, 0, 3)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_envparser_compilestringvalue, 0, 0, 3)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_envparser_compilebooleanvalue, 0, 0, 3)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_envparser_compilenullvalue, 0, 0, 3)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_envparser_compileintegerorfloatvalue, 0, 0, 3)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_envparser_compilevariablevalue, 0, 0, 3)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_envparser_throwparserexceptionuimv, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_envparser_compilevalue, 0, 0, 3)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_envparser_clearcomments, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_envparser_findlinebypos, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, pos)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_file_parser_envparser_method_entry) {
	PHP_ME(Zeplara_Support_File_Parser_EnvParser, parse, arginfo_zeplara_support_file_parser_envparser_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_EnvParser, compileArrayValue, arginfo_zeplara_support_file_parser_envparser_compilearrayvalue, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_EnvParser, compileStringValue, arginfo_zeplara_support_file_parser_envparser_compilestringvalue, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_EnvParser, compileBooleanValue, arginfo_zeplara_support_file_parser_envparser_compilebooleanvalue, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_EnvParser, compileNullValue, arginfo_zeplara_support_file_parser_envparser_compilenullvalue, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_EnvParser, compileIntegerOrFloatValue, arginfo_zeplara_support_file_parser_envparser_compileintegerorfloatvalue, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_EnvParser, compileVariableValue, arginfo_zeplara_support_file_parser_envparser_compilevariablevalue, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_EnvParser, throwParserExceptionUIMV, arginfo_zeplara_support_file_parser_envparser_throwparserexceptionuimv, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_EnvParser, compileValue, arginfo_zeplara_support_file_parser_envparser_compilevalue, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_EnvParser, clearComments, arginfo_zeplara_support_file_parser_envparser_clearcomments, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Parser_EnvParser, findLineByPos, arginfo_zeplara_support_file_parser_envparser_findlinebypos, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
