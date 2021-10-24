
extern zend_class_entry *zeplara_interfaces_container_container_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Container_Container);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_container_container_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, resolve, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, resolve)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_container_container_put, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_container_container_make, 0, 0, 1)
	ZEND_ARG_INFO(0, abstrct)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_container_container___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_container_container___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_container_container___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_container_container___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_container_container_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Container_Container, set, arginfo_zeplara_interfaces_container_container_set)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Container_Container, put, arginfo_zeplara_interfaces_container_container_put)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Container_Container, make, arginfo_zeplara_interfaces_container_container_make)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Container_Container, __get, arginfo_zeplara_interfaces_container_container___get)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Container_Container, __isset, arginfo_zeplara_interfaces_container_container___isset)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Container_Container, __set, arginfo_zeplara_interfaces_container_container___set)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Container_Container, __unset, arginfo_zeplara_interfaces_container_container___unset)
	PHP_FE_END
};
