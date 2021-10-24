
extern zend_class_entry *zeplara_interfaces_routing_compiledroute_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Routing_CompiledRoute);

ZEPHIR_INIT_FUNCS(zeplara_interfaces_routing_compiledroute_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_CompiledRoute, getHost, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_CompiledRoute, getPath, NULL)
	PHP_FE_END
};
