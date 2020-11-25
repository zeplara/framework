
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Container_BindingResolutionException) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Container, BindingResolutionException, zeplara, contracts_container_bindingresolutionexception, zeplara_contracts_container_bindingresolutionexception_method_entry);

	return SUCCESS;

}

/**
 * @return Reflector
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Container_BindingResolutionException, getReflector);

/**
 * @return ReflectionParameter
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Container_BindingResolutionException, getParameter);

