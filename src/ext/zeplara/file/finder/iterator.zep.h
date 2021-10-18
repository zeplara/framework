
extern zend_class_entry *zeplara_file_finder_iterator_ce;

ZEPHIR_INIT_CLASS(Zeplara_File_Finder_Iterator);

PHP_METHOD(Zeplara_File_Finder_Iterator, getFilters);
PHP_METHOD(Zeplara_File_Finder_Iterator, __construct);
PHP_METHOD(Zeplara_File_Finder_Iterator, accept);
PHP_METHOD(Zeplara_File_Finder_Iterator, isAccepted);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_file_finder_iterator_getfilters, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_file_finder_iterator_getfilters, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_iterator___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, iterator, Iterator, 0)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_file_finder_iterator_isaccepted, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, fileInfo, Zeplara\\File\\Finder\\SplFileInfo, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_file_finder_iterator_method_entry) {
	PHP_ME(Zeplara_File_Finder_Iterator, getFilters, arginfo_zeplara_file_finder_iterator_getfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Finder_Iterator, __construct, arginfo_zeplara_file_finder_iterator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_File_Finder_Iterator, accept, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_File_Finder_Iterator, isAccepted, arginfo_zeplara_file_finder_iterator_isaccepted, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
