
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_File_Parser_CompiledValue) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\File\\Parser, CompiledValue, zeplara, interfaces_file_parser_compiledvalue, zeplara_interfaces_file_parser_compiledvalue_method_entry);

	return SUCCESS;

}

/**
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_File_Parser_CompiledValue, getValue);

/**
 * @return RawValue
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_File_Parser_CompiledValue, getRawValue);

