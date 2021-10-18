
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_File_Parser_RawValue) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\File\\Parser, RawValue, zeplara, contracts_file_parser_rawvalue, zeplara_contracts_file_parser_rawvalue_method_entry);

	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_File_Parser_RawValue, getValue);

/**
 * @return LinesIterator
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_File_Parser_RawValue, getLines);

