
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Config_Loader) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Config, Loader, zeplara, contracts_config_loader, zeplara_contracts_config_loader_method_entry);

	return SUCCESS;

}

/**
 * @param string file
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Config_Loader, load);

