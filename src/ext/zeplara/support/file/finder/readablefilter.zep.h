
extern zend_class_entry *zeplara_support_file_finder_readablefilter_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_File_Finder_ReadableFilter);

PHP_METHOD(Zeplara_Support_File_Finder_ReadableFilter, accept);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_file_finder_readablefilter_accept, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_file_finder_readablefilter_accept, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, fileInfo, Zeplara\\Support\\File\\SplFileInfo, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_file_finder_readablefilter_method_entry) {
	PHP_ME(Zeplara_Support_File_Finder_ReadableFilter, accept, arginfo_zeplara_support_file_finder_readablefilter_accept, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
