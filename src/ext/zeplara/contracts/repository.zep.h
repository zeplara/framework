
extern zend_class_entry *zeplara_contracts_repository_ce;

ZEPHIR_INIT_CLASS(Zeplara_Contracts_Repository);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_repository_setitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, items, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_repository_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_repository_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_repository_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_repository_put, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_repository___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_repository___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_repository___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_contracts_repository___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_contracts_repository_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Contracts_Repository, getItems, NULL)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Repository, setItems, arginfo_zeplara_contracts_repository_setitems)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Repository, has, arginfo_zeplara_contracts_repository_has)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Repository, get, arginfo_zeplara_contracts_repository_get)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Repository, set, arginfo_zeplara_contracts_repository_set)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Repository, put, arginfo_zeplara_contracts_repository_put)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Repository, __get, arginfo_zeplara_contracts_repository___get)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Repository, __isset, arginfo_zeplara_contracts_repository___isset)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Repository, __set, arginfo_zeplara_contracts_repository___set)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Repository, __unset, arginfo_zeplara_contracts_repository___unset)
	PHP_FE_END
};
