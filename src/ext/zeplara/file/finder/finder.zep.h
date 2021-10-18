
extern zend_class_entry *zeplara_file_finder_finder_ce;

ZEPHIR_INIT_CLASS(Zeplara_File_Finder_Finder);

PHP_METHOD(Zeplara_File_Finder_Finder, getPath);
PHP_METHOD(Zeplara_File_Finder_Finder, getDepth);
PHP_METHOD(Zeplara_File_Finder_Finder, setDepth);
PHP_METHOD(Zeplara_File_Finder_Finder, getFilters);
PHP_METHOD(Zeplara_File_Finder_Finder, setFilters);
PHP_METHOD(Zeplara_File_Finder_Finder, __construct);
PHP_METHOD(Zeplara_File_Finder_Finder, addFilter);
PHP_METHOD(Zeplara_File_Finder_Finder, getIterator);
PHP_METHOD(Zeplara_File_Finder_Finder, __call);
PHP_METHOD(Zeplara_File_Finder_Finder, instance);
PHP_METHOD(Zeplara_File_Finder_Finder, create);
PHP_METHOD(Zeplara_File_Finder_Finder, make);
PHP_METHOD(Zeplara_File_Finder_Finder, loadPath);
PHP_METHOD(Zeplara_File_Finder_Finder, normalizePath);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_file_finder_finder_getpath, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_file_finder_finder_getpath, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_file_finder_finder_getdepth, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_file_finder_finder_getdepth, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_finder_setdepth, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, depth)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_file_finder_finder_getfilters, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_file_finder_finder_getfilters, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_finder_setfilters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_finder___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, depth)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_finder_addfilter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, filter, Zeplara\\Contracts\\File\\Finder\\Filter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_finder___call, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_finder_instance, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, depth)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_finder_create, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, depth)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_finder_make, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, depth)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_finder_loadpath, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, depth)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_finder_normalizepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_file_finder_finder_method_entry) {
	PHP_ME(Zeplara_File_Finder_Finder, getPath, arginfo_zeplara_file_finder_finder_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Finder_Finder, getDepth, arginfo_zeplara_file_finder_finder_getdepth, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Finder_Finder, setDepth, arginfo_zeplara_file_finder_finder_setdepth, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Finder_Finder, getFilters, arginfo_zeplara_file_finder_finder_getfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Finder_Finder, setFilters, arginfo_zeplara_file_finder_finder_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Finder_Finder, __construct, arginfo_zeplara_file_finder_finder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_File_Finder_Finder, addFilter, arginfo_zeplara_file_finder_finder_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Finder_Finder, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Finder_Finder, __call, arginfo_zeplara_file_finder_finder___call, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Finder_Finder, instance, arginfo_zeplara_file_finder_finder_instance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_File_Finder_Finder, create, arginfo_zeplara_file_finder_finder_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_File_Finder_Finder, make, arginfo_zeplara_file_finder_finder_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_File_Finder_Finder, loadPath, arginfo_zeplara_file_finder_finder_loadpath, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_File_Finder_Finder, normalizePath, arginfo_zeplara_file_finder_finder_normalizepath, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
