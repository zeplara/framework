
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_File_Finder_AbstractFilter) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Support\\File\\Finder, AbstractFilter, zeplara, support_file_finder_abstractfilter, zeplara_support_file_finder_abstractfilter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * @param SplFileInfo fileInfo
 * @return bool
 */
PHP_METHOD(Zeplara_Support_File_Finder_AbstractFilter, accept) {

}

