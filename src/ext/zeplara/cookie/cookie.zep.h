
extern zend_class_entry *zeplara_cookie_cookie_ce;

ZEPHIR_INIT_CLASS(Zeplara_Cookie_Cookie);

PHP_METHOD(Zeplara_Cookie_Cookie, getName);
PHP_METHOD(Zeplara_Cookie_Cookie, getValue);
PHP_METHOD(Zeplara_Cookie_Cookie, getExpiration);
PHP_METHOD(Zeplara_Cookie_Cookie, getPath);
PHP_METHOD(Zeplara_Cookie_Cookie, getDomain);
PHP_METHOD(Zeplara_Cookie_Cookie, getSameSite);
PHP_METHOD(Zeplara_Cookie_Cookie, __construct);
PHP_METHOD(Zeplara_Cookie_Cookie, isSecure);
PHP_METHOD(Zeplara_Cookie_Cookie, isHttpOnly);
PHP_METHOD(Zeplara_Cookie_Cookie, setValue);
PHP_METHOD(Zeplara_Cookie_Cookie, setExpiration);
PHP_METHOD(Zeplara_Cookie_Cookie, setPath);
PHP_METHOD(Zeplara_Cookie_Cookie, setDomain);
PHP_METHOD(Zeplara_Cookie_Cookie, setSecure);
PHP_METHOD(Zeplara_Cookie_Cookie, setHttpOnly);
PHP_METHOD(Zeplara_Cookie_Cookie, setSameSite);
PHP_METHOD(Zeplara_Cookie_Cookie, __toString);
PHP_METHOD(Zeplara_Cookie_Cookie, rawUrlEncodeFilter);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getvalue, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getvalue, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getexpiration, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getexpiration, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getpath, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getpath, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getdomain, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getdomain, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getsamesite, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_cookie_cookie_getsamesite, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_cookie___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expiration)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, httpOnly)
	ZEND_ARG_INFO(0, sameSite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_cookie_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_cookie_setexpiration, 0, 0, 1)
	ZEND_ARG_INFO(0, expiration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_cookie_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_cookie_setdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_cookie_setsecure, 0, 0, 1)
	ZEND_ARG_INFO(0, secure)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_cookie_sethttponly, 0, 0, 1)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_cookie_setsamesite, 0, 0, 1)
	ZEND_ARG_INFO(0, sameSite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_cookie_cookie_rawurlencodefilter, 0, 0, 1)
	ZEND_ARG_INFO(0, matches)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_cookie_cookie_method_entry) {
	PHP_ME(Zeplara_Cookie_Cookie, getName, arginfo_zeplara_cookie_cookie_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, getValue, arginfo_zeplara_cookie_cookie_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, getExpiration, arginfo_zeplara_cookie_cookie_getexpiration, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, getPath, arginfo_zeplara_cookie_cookie_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, getDomain, arginfo_zeplara_cookie_cookie_getdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, getSameSite, arginfo_zeplara_cookie_cookie_getsamesite, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, __construct, arginfo_zeplara_cookie_cookie___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Cookie_Cookie, isSecure, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, isHttpOnly, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, setValue, arginfo_zeplara_cookie_cookie_setvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, setExpiration, arginfo_zeplara_cookie_cookie_setexpiration, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, setPath, arginfo_zeplara_cookie_cookie_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, setDomain, arginfo_zeplara_cookie_cookie_setdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, setSecure, arginfo_zeplara_cookie_cookie_setsecure, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, setHttpOnly, arginfo_zeplara_cookie_cookie_sethttponly, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, setSameSite, arginfo_zeplara_cookie_cookie_setsamesite, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Cookie_Cookie, rawUrlEncodeFilter, arginfo_zeplara_cookie_cookie_rawurlencodefilter, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
