
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
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Config_YamlLoader) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Config, YamlLoader, zeplara, config_yamlloader, zeplara_config_yamlloader_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_config_yamlloader_ce, 1, zeplara_interfaces_config_loader_ce);
	return SUCCESS;

}

PHP_METHOD(Zeplara_Config_YamlLoader, load) {

	zval *file, file_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &file);




}

