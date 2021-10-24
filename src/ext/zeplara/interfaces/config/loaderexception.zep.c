
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Config_LoaderException) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Config, LoaderException, zeplara, interfaces_config_loaderexception, NULL);

	zend_class_implements(zeplara_interfaces_config_loaderexception_ce, 1, zephir_get_internal_ce(SL("throwable")));
	return SUCCESS;

}

