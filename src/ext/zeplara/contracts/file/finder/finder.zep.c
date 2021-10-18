
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_File_Finder_Finder) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\File\\Finder, Finder, zeplara, contracts_file_finder_finder, zeplara_contracts_file_finder_finder_method_entry);

	zend_class_implements(zeplara_contracts_file_finder_finder_ce, 1, zend_ce_aggregate);
	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_File_Finder_Finder, getPath);

/**
 * @return int
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_File_Finder_Finder, getDepth);

/**
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_File_Finder_Finder, getFilters);

/**
 * @var int depth
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_File_Finder_Finder, setDepth);

/**
 * @var array filters
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_File_Finder_Finder, setFilters);

/**
 * @param Filter filter
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_File_Finder_Finder, addFilter);

