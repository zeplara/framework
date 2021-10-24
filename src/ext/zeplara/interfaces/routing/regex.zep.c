
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Routing_Regex) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Routing, Regex, zeplara, interfaces_routing_regex, zeplara_interfaces_routing_regex_method_entry);

	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Routing_Regex, getRegex);

/**
 * @param string value
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Routing_Regex, match);

/**
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Routing_Regex, getVariables);

