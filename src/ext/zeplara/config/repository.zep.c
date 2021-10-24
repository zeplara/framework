
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Config_Repository) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Config, Repository, zeplara, config_repository, zeplara_support_abstractrepository_ce, NULL, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_config_repository_ce, 1, zeplara_interfaces_config_repository_ce);
	return SUCCESS;

}

