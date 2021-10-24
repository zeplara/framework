
extern zend_class_entry *zeplara_interfaces_routing_attribute_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Routing_Attribute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_routing_attribute_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_routing_attribute___call, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_routing_attribute_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Attribute, getAttributes, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Attribute, setAttributes, arginfo_zeplara_interfaces_routing_attribute_setattributes)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Routing_Attribute, __call, arginfo_zeplara_interfaces_routing_attribute___call)
	PHP_FE_END
};
