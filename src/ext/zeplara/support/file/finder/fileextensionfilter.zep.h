
extern zend_class_entry *zeplara_support_file_finder_fileextensionfilter_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_File_Finder_FileExtensionFilter);

PHP_METHOD(Zeplara_Support_File_Finder_FileExtensionFilter, __construct);
PHP_METHOD(Zeplara_Support_File_Finder_FileExtensionFilter, accept);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_fileextensionfilter___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, extensions, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, state, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, state)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_file_finder_fileextensionfilter_accept, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_file_finder_fileextensionfilter_accept, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, fileInfo, Zeplara\\Support\\File\\SplFileInfo, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_file_finder_fileextensionfilter_method_entry) {
	PHP_ME(Zeplara_Support_File_Finder_FileExtensionFilter, __construct, arginfo_zeplara_support_file_finder_fileextensionfilter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Support_File_Finder_FileExtensionFilter, accept, arginfo_zeplara_support_file_finder_fileextensionfilter_accept, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
