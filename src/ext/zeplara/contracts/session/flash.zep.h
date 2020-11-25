
extern zend_class_entry *zeplara_contracts_session_flash_ce;

ZEPHIR_INIT_CLASS(Zeplara_Contracts_Session_Flash);

ZEPHIR_INIT_FUNCS(zeplara_contracts_session_flash_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Contracts_Session_Flash, getName, NULL)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Session_Flash, getManager, NULL)
	PHP_FE_END
};
