
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Routing_CompiledRoute) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Routing, CompiledRoute, zeplara, interfaces_routing_compiledroute, zeplara_interfaces_routing_compiledroute_method_entry);

	return SUCCESS;

}

/**
 * @return Regex
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Routing_CompiledRoute, getHost);

/**
 * @return Regex
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Routing_CompiledRoute, getPath);

