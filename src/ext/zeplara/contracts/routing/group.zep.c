
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Routing_Group) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Routing, Group, zeplara, contracts_routing_group, zeplara_contracts_routing_group_method_entry);

	zend_class_implements(zeplara_contracts_routing_group_ce, 1, zeplara_contracts_routing_attribute_ce);
	return SUCCESS;

}

/**
 * @param Router router
 * @param mixed handler
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Routing_Group, load);

