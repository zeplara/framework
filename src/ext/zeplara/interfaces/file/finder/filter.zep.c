
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_File_Finder_Filter) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\File\\Finder, Filter, zeplara, interfaces_file_finder_filter, zeplara_interfaces_file_finder_filter_method_entry);

	return SUCCESS;

}

/**
 * @param SplFileInfo fileInfo
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_File_Finder_Filter, accept);

