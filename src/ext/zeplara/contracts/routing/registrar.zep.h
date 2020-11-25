
extern zend_class_entry *zeplara_contracts_routing_registrar_ce;

ZEPHIR_INIT_CLASS(Zeplara_Contracts_Routing_Registrar);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_routing_registrar_group, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_routing_registrar_register, 0, 0, 3)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, methods, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_contracts_routing_registrar_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Contracts_Routing_Registrar, getRouter, NULL)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Routing_Registrar, group, arginfo_zeplara_contracts_routing_registrar_group)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Routing_Registrar, register, arginfo_zeplara_contracts_routing_registrar_register)
	PHP_FE_END
};
