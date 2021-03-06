
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Routing_Registrar) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Routing, Registrar, zeplara, contracts_routing_registrar, zeplara_contracts_routing_registrar_method_entry);

	zend_class_implements(zeplara_contracts_routing_registrar_ce, 1, zeplara_contracts_routing_attribute_ce);
	return SUCCESS;

}

/**
 * @return Router
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Registrar, getRouter);

/**
 * @param handler
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Registrar, group);

/**
 * @param string pattern
 * @param callback
 * @param array methods
 * @param array attributes
 * @return Route
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Registrar, register);

