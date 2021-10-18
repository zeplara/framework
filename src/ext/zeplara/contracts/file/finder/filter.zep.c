
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_File_Finder_Filter) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\File\\Finder, Filter, zeplara, contracts_file_finder_filter, zeplara_contracts_file_finder_filter_method_entry);

	return SUCCESS;

}

/**
 * @param SplFileInfo fileInfo
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_File_Finder_Filter, accept);

