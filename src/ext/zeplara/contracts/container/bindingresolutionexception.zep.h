
extern zend_class_entry *zeplara_contracts_container_bindingresolutionexception_ce;

ZEPHIR_INIT_CLASS(Zeplara_Contracts_Container_BindingResolutionException);

ZEPHIR_INIT_FUNCS(zeplara_contracts_container_bindingresolutionexception_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Contracts_Container_BindingResolutionException, getReflector, NULL)
	PHP_ABSTRACT_ME(Zeplara_Contracts_Container_BindingResolutionException, getParameter, NULL)
	PHP_FE_END
};
