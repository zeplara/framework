
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Routing_RouteCompiler) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Routing, RouteCompiler, zeplara, contracts_routing_routecompiler, zeplara_contracts_routing_routecompiler_method_entry);

	return SUCCESS;

}

/**
 * @param Route route
 * @return CompiledRoute
 * @throws RouteCompilerException
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_RouteCompiler, compile);

