
extern zend_class_entry *zeplara_file_finder_directoryfilter_ce;

ZEPHIR_INIT_CLASS(Zeplara_File_Finder_DirectoryFilter);

PHP_METHOD(Zeplara_File_Finder_DirectoryFilter, accept);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_file_finder_directoryfilter_accept, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_file_finder_directoryfilter_accept, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, fileInfo, Zeplara\\Contracts\\File\\SplFileInfo, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_file_finder_directoryfilter_method_entry) {
	PHP_ME(Zeplara_File_Finder_DirectoryFilter, accept, arginfo_zeplara_file_finder_directoryfilter_accept, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
