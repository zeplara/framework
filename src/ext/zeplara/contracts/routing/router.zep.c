
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Routing_Router) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Routing, Router, zeplara, contracts_routing_router, zeplara_contracts_routing_router_method_entry);

	return SUCCESS;

}

/**
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Router, getRoutes);

/**
 * @param array routes
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Router, setRoutes);

/**
 * @param Route route
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Router, addRoute);

/**
 * @param string pattern
 * @param callback
 * @param array methods
 * @param array attributes
 * @return Route
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Router, createRoute);

/**
 * @param handler
 * @param array attributes
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Router, group);

/**
 * @param string name
 * @param array arguments
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Router, __call);

