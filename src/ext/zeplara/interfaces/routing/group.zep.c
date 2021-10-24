
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Routing_Group) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Routing, Group, zeplara, interfaces_routing_group, zeplara_interfaces_routing_group_method_entry);

	zend_class_implements(zeplara_interfaces_routing_group_ce, 1, zeplara_interfaces_routing_attribute_ce);
	return SUCCESS;

}

/**
 * @param Router router
 * @param mixed handler
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Routing_Group, load);

