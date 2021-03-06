
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Routing_RouteCompilerException) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Routing, RouteCompilerException, zeplara, contracts_routing_routecompilerexception, NULL);

	zend_class_implements(zeplara_contracts_routing_routecompilerexception_ce, 1, zephir_get_internal_ce(SL("throwable")));
	return SUCCESS;

}

