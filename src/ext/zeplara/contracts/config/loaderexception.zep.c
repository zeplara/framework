
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Config_LoaderException) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Config, LoaderException, zeplara, contracts_config_loaderexception, NULL);

	zend_class_implements(zeplara_contracts_config_loaderexception_ce, 1, zephir_get_internal_ce(SL("throwable")));
	return SUCCESS;

}

