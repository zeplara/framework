
extern zend_class_entry *zeplara_http_responsefactory_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_ResponseFactory);

PHP_METHOD(Zeplara_Http_ResponseFactory, createResponse);
PHP_METHOD(Zeplara_Http_ResponseFactory, create);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zeplara_http_responsefactory_createresponse, 0, 0, Psr\\Http\\Message\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_responsefactory_createresponse, 0, 0, IS_OBJECT, "Psr\\Http\\Message\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, reasonPhrase, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, reasonPhrase)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_responsefactory_create, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, reasonPhrase, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, reasonPhrase)
#endif
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, protocolVersion, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, protocolVersion)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_responsefactory_method_entry) {
	PHP_ME(Zeplara_Http_ResponseFactory, createResponse, arginfo_zeplara_http_responsefactory_createresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ResponseFactory, create, arginfo_zeplara_http_responsefactory_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
