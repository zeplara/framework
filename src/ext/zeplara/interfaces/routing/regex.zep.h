
extern zend_class_entry *zeplara_interfaces_routing_regex_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Routing_Regex);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_routing_regex_match, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_routing_regex_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Regex, getRegex, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Regex, match, arginfo_zeplara_interfaces_routing_regex_match)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Regex, getVariables, NULL)
	PHP_FE_END
};
