
extern zend_class_entry *zeplara_http_abstractmessage_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_AbstractMessage);

PHP_METHOD(Zeplara_Http_AbstractMessage, getBody);
PHP_METHOD(Zeplara_Http_AbstractMessage, getHeaders);
PHP_METHOD(Zeplara_Http_AbstractMessage, getProtocolVersion);
PHP_METHOD(Zeplara_Http_AbstractMessage, __construct);
PHP_METHOD(Zeplara_Http_AbstractMessage, withBody);
PHP_METHOD(Zeplara_Http_AbstractMessage, hasHeader);
PHP_METHOD(Zeplara_Http_AbstractMessage, getHeader);
PHP_METHOD(Zeplara_Http_AbstractMessage, getHeaderLine);
PHP_METHOD(Zeplara_Http_AbstractMessage, withHeader);
PHP_METHOD(Zeplara_Http_AbstractMessage, withAddedHeader);
PHP_METHOD(Zeplara_Http_AbstractMessage, withoutHeader);
PHP_METHOD(Zeplara_Http_AbstractMessage, withProtocolVersion);
PHP_METHOD(Zeplara_Http_AbstractMessage, assertProtocolVersion);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_abstractmessage_getheaders, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_abstractmessage_getheaders, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_abstractmessage_getprotocolversion, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_abstractmessage_getprotocolversion, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_abstractmessage___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, protocolVersion, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, protocolVersion)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_abstractmessage_withbody, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_abstractmessage_hasheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_abstractmessage_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_abstractmessage_getheaderline, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_abstractmessage_withheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_abstractmessage_withaddedheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_abstractmessage_withoutheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_abstractmessage_withprotocolversion, 0, 0, 1)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_abstractmessage_assertprotocolversion, 0, 0, 1)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_abstractmessage_method_entry) {
	PHP_ME(Zeplara_Http_AbstractMessage, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_AbstractMessage, getHeaders, arginfo_zeplara_http_abstractmessage_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_AbstractMessage, getProtocolVersion, arginfo_zeplara_http_abstractmessage_getprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_AbstractMessage, __construct, arginfo_zeplara_http_abstractmessage___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Http_AbstractMessage, withBody, arginfo_zeplara_http_abstractmessage_withbody, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_AbstractMessage, hasHeader, arginfo_zeplara_http_abstractmessage_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_AbstractMessage, getHeader, arginfo_zeplara_http_abstractmessage_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_AbstractMessage, getHeaderLine, arginfo_zeplara_http_abstractmessage_getheaderline, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_AbstractMessage, withHeader, arginfo_zeplara_http_abstractmessage_withheader, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_AbstractMessage, withAddedHeader, arginfo_zeplara_http_abstractmessage_withaddedheader, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_AbstractMessage, withoutHeader, arginfo_zeplara_http_abstractmessage_withoutheader, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_AbstractMessage, withProtocolVersion, arginfo_zeplara_http_abstractmessage_withprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_AbstractMessage, assertProtocolVersion, arginfo_zeplara_http_abstractmessage_assertprotocolversion, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
