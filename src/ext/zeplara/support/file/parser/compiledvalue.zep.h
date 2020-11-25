
extern zend_class_entry *zeplara_support_file_parser_compiledvalue_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_File_Parser_CompiledValue);

PHP_METHOD(Zeplara_Support_File_Parser_CompiledValue, getValue);
PHP_METHOD(Zeplara_Support_File_Parser_CompiledValue, getRawValue);
PHP_METHOD(Zeplara_Support_File_Parser_CompiledValue, __construct);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_file_parser_compiledvalue_getrawvalue, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_file_parser_compiledvalue_getrawvalue, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_compiledvalue___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, rawValue, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, rawValue)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_file_parser_compiledvalue_method_entry) {
	PHP_ME(Zeplara_Support_File_Parser_CompiledValue, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Parser_CompiledValue, getRawValue, arginfo_zeplara_support_file_parser_compiledvalue_getrawvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Parser_CompiledValue, __construct, arginfo_zeplara_support_file_parser_compiledvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
