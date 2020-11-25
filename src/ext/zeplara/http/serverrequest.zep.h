
extern zend_class_entry *zeplara_http_serverrequest_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_ServerRequest);

PHP_METHOD(Zeplara_Http_ServerRequest, getServerParams);
PHP_METHOD(Zeplara_Http_ServerRequest, getCookieParams);
PHP_METHOD(Zeplara_Http_ServerRequest, getQueryParams);
PHP_METHOD(Zeplara_Http_ServerRequest, getUploadedFiles);
PHP_METHOD(Zeplara_Http_ServerRequest, getParsedBody);
PHP_METHOD(Zeplara_Http_ServerRequest, getAttributes);
PHP_METHOD(Zeplara_Http_ServerRequest, __construct);
PHP_METHOD(Zeplara_Http_ServerRequest, withCookieParams);
PHP_METHOD(Zeplara_Http_ServerRequest, withQueryParams);
PHP_METHOD(Zeplara_Http_ServerRequest, withUploadedFiles);
PHP_METHOD(Zeplara_Http_ServerRequest, withParsedBody);
PHP_METHOD(Zeplara_Http_ServerRequest, getAttribute);
PHP_METHOD(Zeplara_Http_ServerRequest, withAttribute);
PHP_METHOD(Zeplara_Http_ServerRequest, withoutAttribute);
PHP_METHOD(Zeplara_Http_ServerRequest, assertUploadedFiles);
zend_object *zephir_init_properties_Zeplara_Http_ServerRequest(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getserverparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getserverparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getcookieparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getcookieparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getqueryparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getqueryparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getuploadedfiles, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getuploadedfiles, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getparsedbody, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getparsedbody, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getattributes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_serverrequest_getattributes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_serverrequest___construct, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_OBJ_INFO(0, uri, Psr\\Http\\Message\\UriInterface, 0)
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_serverrequest_withcookieparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cookies, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_serverrequest_withqueryparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, query, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_serverrequest_withuploadedfiles, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, files, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_serverrequest_withparsedbody, 0, 0, 1)
	ZEND_ARG_INFO(0, parsedBody)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_serverrequest_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_serverrequest_withattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_serverrequest_withoutattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_serverrequest_assertuploadedfiles, 0, 0, 1)
	ZEND_ARG_INFO(0, uploadedFiles)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_serverrequest_method_entry) {
	PHP_ME(Zeplara_Http_ServerRequest, getServerParams, arginfo_zeplara_http_serverrequest_getserverparams, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, getCookieParams, arginfo_zeplara_http_serverrequest_getcookieparams, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, getQueryParams, arginfo_zeplara_http_serverrequest_getqueryparams, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, getUploadedFiles, arginfo_zeplara_http_serverrequest_getuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, getParsedBody, arginfo_zeplara_http_serverrequest_getparsedbody, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, getAttributes, arginfo_zeplara_http_serverrequest_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, __construct, arginfo_zeplara_http_serverrequest___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Http_ServerRequest, withCookieParams, arginfo_zeplara_http_serverrequest_withcookieparams, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, withQueryParams, arginfo_zeplara_http_serverrequest_withqueryparams, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, withUploadedFiles, arginfo_zeplara_http_serverrequest_withuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, withParsedBody, arginfo_zeplara_http_serverrequest_withparsedbody, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, getAttribute, arginfo_zeplara_http_serverrequest_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, withAttribute, arginfo_zeplara_http_serverrequest_withattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, withoutAttribute, arginfo_zeplara_http_serverrequest_withoutattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_ServerRequest, assertUploadedFiles, arginfo_zeplara_http_serverrequest_assertuploadedfiles, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
