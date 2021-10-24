
extern zend_class_entry *zeplara_interfaces_cookie_cookie_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Cookie_Cookie);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_cookie_cookie_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_cookie_cookie_setexpiration, 0, 0, 1)
	ZEND_ARG_INFO(0, expiration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_cookie_cookie_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_cookie_cookie_setdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_cookie_cookie_setsecure, 0, 0, 1)
	ZEND_ARG_INFO(0, secure)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_cookie_cookie_sethttponly, 0, 0, 1)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_cookie_cookie_setsamesite, 0, 0, 1)
	ZEND_ARG_INFO(0, sameSite)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_cookie_cookie_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, getName, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, getValue, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, getExpiration, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, getPath, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, getDomain, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, isSecure, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, isHttpOnly, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, getSameSite, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, setValue, arginfo_zeplara_interfaces_cookie_cookie_setvalue)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, setExpiration, arginfo_zeplara_interfaces_cookie_cookie_setexpiration)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, setPath, arginfo_zeplara_interfaces_cookie_cookie_setpath)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, setDomain, arginfo_zeplara_interfaces_cookie_cookie_setdomain)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, setSecure, arginfo_zeplara_interfaces_cookie_cookie_setsecure)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, setHttpOnly, arginfo_zeplara_interfaces_cookie_cookie_sethttponly)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, setSameSite, arginfo_zeplara_interfaces_cookie_cookie_setsamesite)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Cookie_Cookie, __toString, NULL)
	PHP_FE_END
};
