
extern zend_class_entry *zeplara_http_serverrequestfactory_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_ServerRequestFactory);

PHP_METHOD(Zeplara_Http_ServerRequestFactory, createServerRequest);
PHP_METHOD(Zeplara_Http_ServerRequestFactory, create);
PHP_METHOD(Zeplara_Http_ServerRequestFactory, parseUploadedFiles);
PHP_METHOD(Zeplara_Http_ServerRequestFactory, getAllHeaders);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zeplara_http_serverrequestfactory_createserverrequest, 0, 2, Psr\\Http\\Message\\ServerRequestInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequestfactory_createserverrequest, 0, 2, IS_OBJECT, "Psr\\Http\\Message\\ServerRequestInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_ARRAY_INFO(0, serverParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_serverrequestfactory_create, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 1)
	ZEND_ARG_ARRAY_INFO(0, serverParams, 0)
	ZEND_ARG_ARRAY_INFO(0, parsedBody, 0)
	ZEND_ARG_ARRAY_INFO(0, queryParams, 0)
	ZEND_ARG_ARRAY_INFO(0, cookieParams, 0)
	ZEND_ARG_ARRAY_INFO(0, uploadedFiles, 0)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, protocolVersion, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, protocolVersion)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_serverrequestfactory_method_entry) {
	PHP_ME(Zeplara_Http_ServerRequestFactory, createServerRequest, arginfo_zeplara_http_serverrequestfactory_createserverrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequestFactory, create, arginfo_zeplara_http_serverrequestfactory_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Http_ServerRequestFactory, parseUploadedFiles, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Http_ServerRequestFactory, getAllHeaders, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
