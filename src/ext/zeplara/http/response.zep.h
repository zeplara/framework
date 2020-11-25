
extern zend_class_entry *zeplara_http_response_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_Response);

PHP_METHOD(Zeplara_Http_Response, getStatusCode);
PHP_METHOD(Zeplara_Http_Response, getReasonPhrase);
PHP_METHOD(Zeplara_Http_Response, __construct);
PHP_METHOD(Zeplara_Http_Response, withStatus);
PHP_METHOD(Zeplara_Http_Response, assertStatusCode);
PHP_METHOD(Zeplara_Http_Response, filterReasonPhrase);
void zephir_init_static_properties_Zeplara_Http_Response(TSRMLS_D);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_response_getstatuscode, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_response_getstatuscode, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_response_getreasonphrase, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_response_getreasonphrase, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_response___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statusCode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, statusCode)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, reasonPhrase, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, reasonPhrase)
#endif
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, protocolVersion, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, protocolVersion)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_response_withstatus, 0, 0, 1)
	ZEND_ARG_INFO(0, statusCode)
	ZEND_ARG_INFO(0, reasonPhrase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_response_assertstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, statusCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_response_filterreasonphrase, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statusCode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, statusCode)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, reasonPhrase, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, reasonPhrase)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_response_method_entry) {
	PHP_ME(Zeplara_Http_Response, getStatusCode, arginfo_zeplara_http_response_getstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Response, getReasonPhrase, arginfo_zeplara_http_response_getreasonphrase, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Response, __construct, arginfo_zeplara_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Http_Response, withStatus, arginfo_zeplara_http_response_withstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Response, assertStatusCode, arginfo_zeplara_http_response_assertstatuscode, ZEND_ACC_PROTECTED)
	PHP_ME(Zeplara_Http_Response, filterReasonPhrase, arginfo_zeplara_http_response_filterreasonphrase, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
