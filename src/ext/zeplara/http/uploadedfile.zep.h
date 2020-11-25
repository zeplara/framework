
extern zend_class_entry *zeplara_http_uploadedfile_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_UploadedFile);

PHP_METHOD(Zeplara_Http_UploadedFile, getStream);
PHP_METHOD(Zeplara_Http_UploadedFile, getSize);
PHP_METHOD(Zeplara_Http_UploadedFile, getError);
PHP_METHOD(Zeplara_Http_UploadedFile, getClientFilename);
PHP_METHOD(Zeplara_Http_UploadedFile, getClientMediaType);
PHP_METHOD(Zeplara_Http_UploadedFile, __construct);
PHP_METHOD(Zeplara_Http_UploadedFile, moveTo);
PHP_METHOD(Zeplara_Http_UploadedFile, isMoved);
void zephir_init_static_properties_Zeplara_Http_UploadedFile(TSRMLS_D);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uploadedfile_getsize, 0, 0, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uploadedfile_getsize, 0, 0, IS_LONG, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uploadedfile_geterror, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uploadedfile_geterror, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uploadedfile_getclientfilename, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uploadedfile_getclientfilename, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uploadedfile_getclientmediatype, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uploadedfile_getclientmediatype, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uploadedfile___construct, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, stream, Psr\\Http\\Message\\StreamInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, clientFilename, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, clientFilename)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, clientMediaType, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, clientMediaType)
#endif
	ZEND_ARG_INFO(0, size)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, error, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, error)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uploadedfile_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_uploadedfile_method_entry) {
	PHP_ME(Zeplara_Http_UploadedFile, getStream, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_UploadedFile, getSize, arginfo_zeplara_http_uploadedfile_getsize, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_UploadedFile, getError, arginfo_zeplara_http_uploadedfile_geterror, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_UploadedFile, getClientFilename, arginfo_zeplara_http_uploadedfile_getclientfilename, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_UploadedFile, getClientMediaType, arginfo_zeplara_http_uploadedfile_getclientmediatype, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_UploadedFile, __construct, arginfo_zeplara_http_uploadedfile___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Http_UploadedFile, moveTo, arginfo_zeplara_http_uploadedfile_moveto, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_UploadedFile, isMoved, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
