
extern zend_class_entry *zeplara_support_file_finder_filterfactory_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_File_Finder_FilterFactory);

PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, __construct);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, file);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, files);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, ignoreDotFile);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, ignoreDotFiles);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, extension);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, extensions);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, directory);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, directories);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, dir);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, dirs);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, executable);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, link);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, links);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, readable);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, writable);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, callback);
PHP_METHOD(Zeplara_Support_File_Finder_FilterFactory, date);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filterfactory_extension, 0, 0, 1)
	ZEND_ARG_INFO(0, extensions)
	ZEND_ARG_INFO(0, state)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filterfactory_extensions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, extensions, 0)
	ZEND_ARG_INFO(0, state)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filterfactory_callback, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_file_finder_filterfactory_date, 0, 0, 1)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_INFO(0, operator)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_file_finder_filterfactory_method_entry) {
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, file, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, files, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, ignoreDotFile, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, ignoreDotFiles, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, extension, arginfo_zeplara_support_file_finder_filterfactory_extension, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, extensions, arginfo_zeplara_support_file_finder_filterfactory_extensions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, directory, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, directories, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, dir, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, dirs, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, executable, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, link, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, links, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, readable, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, writable, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, callback, arginfo_zeplara_support_file_finder_filterfactory_callback, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_File_Finder_FilterFactory, date, arginfo_zeplara_support_file_finder_filterfactory_date, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
