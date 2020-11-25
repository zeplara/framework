
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Routing_CompiledRoute) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Routing, CompiledRoute, zeplara, contracts_routing_compiledroute, zeplara_contracts_routing_compiledroute_method_entry);

	return SUCCESS;

}

/**
 * @return Regex
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_CompiledRoute, getHost);

/**
 * @return Regex
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_CompiledRoute, getPath);

