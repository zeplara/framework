
extern zend_class_entry *zeplara_contracts_file_finder_filter_ce;

ZEPHIR_INIT_CLASS(Zeplara_Contracts_File_Finder_Filter);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_contracts_file_finder_filter_accept, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_contracts_file_finder_filter_accept, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, fileInfo, Zeplara\\Contracts\\File\\SplFileInfo, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_contracts_file_finder_filter_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Contracts_File_Finder_Filter, accept, arginfo_zeplara_contracts_file_finder_filter_accept)
	PHP_FE_END
};
