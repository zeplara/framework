
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Routing_Route) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Routing, Route, zeplara, contracts_routing_route, zeplara_contracts_routing_route_method_entry);

	zend_class_implements(zeplara_contracts_routing_route_ce, 1, zeplara_contracts_routing_attribute_ce);
	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Route, getPattern);

/**
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Route, getMethods);

/**
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Route, getCallback);

/**
 * @return CompiledRoute
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Route, compile);

