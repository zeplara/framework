
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_File_Parser_CompiledValue) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\File\\Parser, CompiledValue, zeplara, contracts_file_parser_compiledvalue, zeplara_contracts_file_parser_compiledvalue_method_entry);

	return SUCCESS;

}

/**
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_File_Parser_CompiledValue, getValue);

/**
 * @return RawValue
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_File_Parser_CompiledValue, getRawValue);

