
extern zend_class_entry *zeplara_http_uri_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_Uri);

PHP_METHOD(Zeplara_Http_Uri, getScheme);
PHP_METHOD(Zeplara_Http_Uri, getHost);
PHP_METHOD(Zeplara_Http_Uri, getPort);
PHP_METHOD(Zeplara_Http_Uri, getUserInfo);
PHP_METHOD(Zeplara_Http_Uri, getPath);
PHP_METHOD(Zeplara_Http_Uri, getQuery);
PHP_METHOD(Zeplara_Http_Uri, getFragment);
PHP_METHOD(Zeplara_Http_Uri, __construct);
PHP_METHOD(Zeplara_Http_Uri, getAuthority);
PHP_METHOD(Zeplara_Http_Uri, withScheme);
PHP_METHOD(Zeplara_Http_Uri, withUserInfo);
PHP_METHOD(Zeplara_Http_Uri, withHost);
PHP_METHOD(Zeplara_Http_Uri, withPort);
PHP_METHOD(Zeplara_Http_Uri, withPath);
PHP_METHOD(Zeplara_Http_Uri, withQuery);
PHP_METHOD(Zeplara_Http_Uri, withFragment);
PHP_METHOD(Zeplara_Http_Uri, __toString);
PHP_METHOD(Zeplara_Http_Uri, filterScheme);
PHP_METHOD(Zeplara_Http_Uri, filterHost);
PHP_METHOD(Zeplara_Http_Uri, filterPort);
PHP_METHOD(Zeplara_Http_Uri, filterPath);
PHP_METHOD(Zeplara_Http_Uri, filterQueryOrFragment);
PHP_METHOD(Zeplara_Http_Uri, filterUserInfo);
PHP_METHOD(Zeplara_Http_Uri, rawUrlEncodeFilter);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getscheme, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getscheme, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_gethost, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_gethost, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getport, 0, 0, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getport, 0, 0, IS_LONG, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getuserinfo, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getuserinfo, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getpath, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getpath, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getquery, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getquery, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getfragment, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_uri_getfragment, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, scheme)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, fragment)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_withscheme, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_withuserinfo, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_withhost, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_withport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_withpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_withquery, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_withfragment, 0, 0, 1)
	ZEND_ARG_INFO(0, fragment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_filterscheme, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_filterhost, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_filterport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_filterpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_filterqueryorfragment, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_filteruserinfo, 0, 0, 1)
	ZEND_ARG_INFO(0, userInfo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_uri_rawurlencodefilter, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, matches, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_uri_method_entry) {
	PHP_ME(Zeplara_Http_Uri, getScheme, arginfo_zeplara_http_uri_getscheme, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, getHost, arginfo_zeplara_http_uri_gethost, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, getPort, arginfo_zeplara_http_uri_getport, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, getUserInfo, arginfo_zeplara_http_uri_getuserinfo, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, getPath, arginfo_zeplara_http_uri_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, getQuery, arginfo_zeplara_http_uri_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, getFragment, arginfo_zeplara_http_uri_getfragment, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, __construct, arginfo_zeplara_http_uri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Http_Uri, getAuthority, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, withScheme, arginfo_zeplara_http_uri_withscheme, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, withUserInfo, arginfo_zeplara_http_uri_withuserinfo, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, withHost, arginfo_zeplara_http_uri_withhost, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, withPort, arginfo_zeplara_http_uri_withport, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, withPath, arginfo_zeplara_http_uri_withpath, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, withQuery, arginfo_zeplara_http_uri_withquery, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, withFragment, arginfo_zeplara_http_uri_withfragment, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Uri, filterScheme, arginfo_zeplara_http_uri_filterscheme, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Http_Uri, filterHost, arginfo_zeplara_http_uri_filterhost, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Http_Uri, filterPort, arginfo_zeplara_http_uri_filterport, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Http_Uri, filterPath, arginfo_zeplara_http_uri_filterpath, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Http_Uri, filterQueryOrFragment, arginfo_zeplara_http_uri_filterqueryorfragment, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Http_Uri, filterUserInfo, arginfo_zeplara_http_uri_filteruserinfo, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Http_Uri, rawUrlEncodeFilter, arginfo_zeplara_http_uri_rawurlencodefilter, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
