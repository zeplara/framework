
extern zend_class_entry *zeplara_support_file_finder_filefinder_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_File_Finder_FileFinder);

PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, getPath);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, getDepth);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, setDepth);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, getFilters);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, setFilters);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, __construct);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, addFilter);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, getIterator);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, __call);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, instance);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, create);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, make);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, loadPath);
PHP_METHOD(Zeplara_Support_File_Finder_FileFinder, normalizePath);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_getpath, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_getpath, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_setdepth, 0, 0, 1)
	ZEND_ARG_INFO(0, depth)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_getfilters, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_getfilters, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_setfilters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filefinder___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, depth)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_addfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filefinder___call, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_instance, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, depth)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_create, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, depth)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_make, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, depth)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_loadpath, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, depth)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filefinder_normalizepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_file_finder_filefinder_method_entry) {
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, getPath, arginfo_zeplara_support_file_finder_filefinder_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, getDepth, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, setDepth, arginfo_zeplara_support_file_finder_filefinder_setdepth, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, getFilters, arginfo_zeplara_support_file_finder_filefinder_getfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, setFilters, arginfo_zeplara_support_file_finder_filefinder_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, __construct, arginfo_zeplara_support_file_finder_filefinder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, addFilter, arginfo_zeplara_support_file_finder_filefinder_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, __call, arginfo_zeplara_support_file_finder_filefinder___call, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, instance, arginfo_zeplara_support_file_finder_filefinder_instance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, create, arginfo_zeplara_support_file_finder_filefinder_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, make, arginfo_zeplara_support_file_finder_filefinder_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, loadPath, arginfo_zeplara_support_file_finder_filefinder_loadpath, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Support_File_Finder_FileFinder, normalizePath, arginfo_zeplara_support_file_finder_filefinder_normalizepath, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
