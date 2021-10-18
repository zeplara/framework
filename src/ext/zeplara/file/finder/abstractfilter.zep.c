
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_File_Finder_AbstractFilter) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\File\\Finder, AbstractFilter, zeplara, file_finder_abstractfilter, zeplara_file_finder_abstractfilter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * @param SplFileInfo fileInfo
 * @return bool
 */
PHP_METHOD(Zeplara_File_Finder_AbstractFilter, accept) {

}

