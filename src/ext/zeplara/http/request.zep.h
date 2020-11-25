
extern zend_class_entry *zeplara_http_request_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_Request);

PHP_METHOD(Zeplara_Http_Request, getUri);
PHP_METHOD(Zeplara_Http_Request, getMethod);
PHP_METHOD(Zeplara_Http_Request, __construct);
PHP_METHOD(Zeplara_Http_Request, getRequestTarget);
PHP_METHOD(Zeplara_Http_Request, withRequestTarget);
PHP_METHOD(Zeplara_Http_Request, withMethod);
PHP_METHOD(Zeplara_Http_Request, withUri);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_request_getmethod, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_request_getmethod, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_request___construct, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_OBJ_INFO(0, uri, Psr\\Http\\Message\\UriInterface, 0)
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, protocolVersion, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, protocolVersion)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_request_withrequesttarget, 0, 0, 1)
	ZEND_ARG_INFO(0, requestTarget)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_request_withmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_request_withuri, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, uri, Psr\\Http\\Message\\UriInterface, 0)
	ZEND_ARG_INFO(0, preserveHost)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_request_method_entry) {
	PHP_ME(Zeplara_Http_Request, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Request, getMethod, arginfo_zeplara_http_request_getmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Request, __construct, arginfo_zeplara_http_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Http_Request, getRequestTarget, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Request, withRequestTarget, arginfo_zeplara_http_request_withrequesttarget, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Request, withMethod, arginfo_zeplara_http_request_withmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Request, withUri, arginfo_zeplara_http_request_withuri, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
