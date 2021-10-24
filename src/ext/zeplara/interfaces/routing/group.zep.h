
extern zend_class_entry *zeplara_interfaces_routing_group_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Routing_Group);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_routing_group_load, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, router, Zeplara\\Interfaces\\Routing\\Router, 0)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_routing_group_method_entry) {
	ZEND_FENTRY(load, NULL, arginfo_zeplara_interfaces_routing_group_load, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
