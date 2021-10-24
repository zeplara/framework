
extern zend_class_entry *zeplara_interfaces_session_manager_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Session_Manager);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_session_manager_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_session_manager_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_session_manager_regenerate, 0, 0, 0)
	ZEND_ARG_INFO(0, destroy)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_session_manager_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Session_Manager, getId, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Session_Manager, getName, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Session_Manager, getPrefix, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Session_Manager, getHandler, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Session_Manager, setId, arginfo_zeplara_interfaces_session_manager_setid)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Session_Manager, setPrefix, arginfo_zeplara_interfaces_session_manager_setprefix)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Session_Manager, isStarted, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Session_Manager, start, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Session_Manager, regenerate, arginfo_zeplara_interfaces_session_manager_regenerate)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Session_Manager, save, NULL)
	PHP_FE_END
};
