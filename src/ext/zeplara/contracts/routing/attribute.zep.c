
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Routing_Attribute) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Routing, Attribute, zeplara, contracts_routing_attribute, zeplara_contracts_routing_attribute_method_entry);

	return SUCCESS;

}

/**
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Attribute, getAttributes);

/**
 * @param array attributes
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Attribute, setAttributes);

/**
 * @param string name
 * @param array arguments
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Attribute, __call);

