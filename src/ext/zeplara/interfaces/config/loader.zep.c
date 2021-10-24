
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Config_Loader) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Config, Loader, zeplara, interfaces_config_loader, zeplara_interfaces_config_loader_method_entry);

	return SUCCESS;

}

/**
 * @param string file
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Config_Loader, load);

