
extern zend_class_entry *zeplara_file_parser_compiledvalue_ce;

ZEPHIR_INIT_CLASS(Zeplara_File_Parser_CompiledValue);

PHP_METHOD(Zeplara_File_Parser_CompiledValue, getValue);
PHP_METHOD(Zeplara_File_Parser_CompiledValue, getRawValue);
PHP_METHOD(Zeplara_File_Parser_CompiledValue, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_parser_compiledvalue___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, rawValue, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, rawValue)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_file_parser_compiledvalue_method_entry) {
	PHP_ME(Zeplara_File_Parser_CompiledValue, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Parser_CompiledValue, getRawValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Parser_CompiledValue, __construct, arginfo_zeplara_file_parser_compiledvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
