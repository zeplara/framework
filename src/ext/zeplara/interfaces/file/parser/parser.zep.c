
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_File_Parser_Parser) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\File\\Parser, Parser, zeplara, interfaces_file_parser_parser, zeplara_interfaces_file_parser_parser_method_entry);

	return SUCCESS;

}

/**
 * @param string contents
 * @return mixed
 * @throws ParserException
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_File_Parser_Parser, parse);

/**
 * @param string file
 * @return mixed
 * @throws \InvalidArgumentException|ParserException
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_File_Parser_Parser, parseFile);

