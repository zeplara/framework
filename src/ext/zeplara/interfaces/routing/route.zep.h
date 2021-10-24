
extern zend_class_entry *zeplara_interfaces_routing_route_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Routing_Route);

ZEPHIR_INIT_FUNCS(zeplara_interfaces_routing_route_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Route, getPattern, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Route, getMethods, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Route, getCallback, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Route, compile, NULL)
	PHP_FE_END
};
