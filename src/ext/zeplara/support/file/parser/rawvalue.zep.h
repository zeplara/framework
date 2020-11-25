
extern zend_class_entry *zeplara_support_file_parser_rawvalue_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_File_Parser_RawValue);

PHP_METHOD(Zeplara_Support_File_Parser_RawValue, getValue);
PHP_METHOD(Zeplara_Support_File_Parser_RawValue, getLines);
PHP_METHOD(Zeplara_Support_File_Parser_RawValue, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_parser_rawvalue___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_file_parser_rawvalue_method_entry) {
	PHP_ME(Zeplara_Support_File_Parser_RawValue, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Parser_RawValue, getLines, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Parser_RawValue, __construct, arginfo_zeplara_support_file_parser_rawvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
