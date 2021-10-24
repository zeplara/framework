
extern zend_class_entry *zeplara_interfaces_file_finder_finder_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_File_Finder_Finder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_file_finder_finder_setdepth, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, depth)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_file_finder_finder_setfilters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_file_finder_finder_addfilter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, filter, Zeplara\\Interfaces\\File\\Finder\\Filter, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_file_finder_finder_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_File_Finder_Finder, getPath, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_File_Finder_Finder, getDepth, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_File_Finder_Finder, getFilters, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_File_Finder_Finder, setDepth, arginfo_zeplara_interfaces_file_finder_finder_setdepth)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_File_Finder_Finder, setFilters, arginfo_zeplara_interfaces_file_finder_finder_setfilters)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_File_Finder_Finder, addFilter, arginfo_zeplara_interfaces_file_finder_finder_addfilter)
	PHP_FE_END
};
