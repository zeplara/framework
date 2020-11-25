
extern zend_class_entry *zeplara_http_requestfactory_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_RequestFactory);

PHP_METHOD(Zeplara_Http_RequestFactory, createRequest);
PHP_METHOD(Zeplara_Http_RequestFactory, create);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zeplara_http_requestfactory_createrequest, 0, 2, Psr\\Http\\Message\\RequestInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_requestfactory_createrequest, 0, 2, IS_OBJECT, "Psr\\Http\\Message\\RequestInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_requestfactory_create, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, protocolVersion, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, protocolVersion)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_requestfactory_method_entry) {
	PHP_ME(Zeplara_Http_RequestFactory, createRequest, arginfo_zeplara_http_requestfactory_createrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_RequestFactory, create, arginfo_zeplara_http_requestfactory_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
