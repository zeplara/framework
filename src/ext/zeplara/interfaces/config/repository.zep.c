
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Config_Repository) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Config, Repository, zeplara, interfaces_config_repository, NULL);

	zend_class_implements(zeplara_interfaces_config_repository_ce, 1, zeplara_interfaces_repository_ce);
	return SUCCESS;

}

