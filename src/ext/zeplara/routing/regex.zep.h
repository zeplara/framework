
extern zend_class_entry *zeplara_routing_regex_ce;

ZEPHIR_INIT_CLASS(Zeplara_Routing_Regex);

PHP_METHOD(Zeplara_Routing_Regex, getRegex);
PHP_METHOD(Zeplara_Routing_Regex, getVariables);
PHP_METHOD(Zeplara_Routing_Regex, __construct);
PHP_METHOD(Zeplara_Routing_Regex, match);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_regex_getregex, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_regex_getregex, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_regex_getvariables, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_routing_regex_getvariables, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_regex___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, regex, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, regex)
#endif
	ZEND_ARG_ARRAY_INFO(0, variables, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_routing_regex_match, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_routing_regex_method_entry) {
	PHP_ME(Zeplara_Routing_Regex, getRegex, arginfo_zeplara_routing_regex_getregex, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Regex, getVariables, arginfo_zeplara_routing_regex_getvariables, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Routing_Regex, __construct, arginfo_zeplara_routing_regex___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Routing_Regex, match, arginfo_zeplara_routing_regex_match, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
