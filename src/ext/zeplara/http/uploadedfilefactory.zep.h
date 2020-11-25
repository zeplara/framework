
extern zend_class_entry *zeplara_http_uploadedfilefactory_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_UploadedFileFactory);

PHP_METHOD(Zeplara_Http_UploadedFileFactory, createUploadedFile);
PHP_METHOD(Zeplara_Http_UploadedFileFactory, create);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zeplara_http_uploadedfilefactory_createuploadedfile, 0, 1, Psr\\Http\\Message\\UploadedFileInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uploadedfilefactory_createuploadedfile, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\UploadedFileInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, stream, Psr\\Http\\Message\\StreamInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, size)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, error, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, error)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, clientFilename, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, clientFilename)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, clientFileMediaType, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, clientFileMediaType)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zeplara_http_uploadedfilefactory_create, 0, 1, Psr\\Http\\Message\\UploadedFileInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uploadedfilefactory_create, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\UploadedFileInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, stream, Psr\\Http\\Message\\StreamInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, size)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, error, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, error)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, clientFilename, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, clientFilename)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, clientFileMediaType, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, clientFileMediaType)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_uploadedfilefactory_method_entry) {
	PHP_ME(Zeplara_Http_UploadedFileFactory, createUploadedFile, arginfo_zeplara_http_uploadedfilefactory_createuploadedfile, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_UploadedFileFactory, create, arginfo_zeplara_http_uploadedfilefactory_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
