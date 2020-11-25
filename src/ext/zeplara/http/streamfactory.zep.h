
extern zend_class_entry *zeplara_http_streamfactory_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_StreamFactory);

PHP_METHOD(Zeplara_Http_StreamFactory, createStream);
PHP_METHOD(Zeplara_Http_StreamFactory, createStreamFromFile);
PHP_METHOD(Zeplara_Http_StreamFactory, createStreamFromResource);
PHP_METHOD(Zeplara_Http_StreamFactory, create);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zeplara_http_streamfactory_createstream, 0, 0, Psr\\Http\\Message\\StreamInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_streamfactory_createstream, 0, 0, IS_OBJECT, "Psr\\Http\\Message\\StreamInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zeplara_http_streamfactory_createstreamfromfile, 0, 1, Psr\\Http\\Message\\StreamInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_streamfactory_createstreamfromfile, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\StreamInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filename)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zeplara_http_streamfactory_createstreamfromresource, 0, 1, Psr\\Http\\Message\\StreamInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_streamfactory_createstreamfromresource, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\StreamInterface", 0)
#endif
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_streamfactory_create, 0, 0, 1)
	ZEND_ARG_INFO(0, filenameOrResourceOrContent)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_streamfactory_method_entry) {
	PHP_ME(Zeplara_Http_StreamFactory, createStream, arginfo_zeplara_http_streamfactory_createstream, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_StreamFactory, createStreamFromFile, arginfo_zeplara_http_streamfactory_createstreamfromfile, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_StreamFactory, createStreamFromResource, arginfo_zeplara_http_streamfactory_createstreamfromresource, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_StreamFactory, create, arginfo_zeplara_http_streamfactory_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
