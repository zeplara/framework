
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_File_Parser_ParserException) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Support\\File\\Parser, ParserException, zeplara, support_file_parser_parserexception, zephir_get_internal_ce(SL("errorexception")), zeplara_support_file_parser_parserexception_method_entry, 0);

	return SUCCESS;

}

/**
 * ParserException constructor.
 *
 * @param string message
 * @param string filename
 * @param int lineno
 */
PHP_METHOD(Zeplara_Support_File_Parser_ParserException, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, *filename = NULL, filename_sub, *lineno = NULL, lineno_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&filename_sub);
	ZVAL_UNDEF(&lineno_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &message, &filename, &lineno);

	if (!filename) {
		filename = &filename_sub;
		ZEPHIR_INIT_VAR(filename);
		ZVAL_STRING(filename, "");
	}
	if (!lineno) {
		lineno = &lineno_sub;
		ZEPHIR_INIT_VAR(lineno);
		ZVAL_LONG(lineno, 0);
	}


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_PARENT(NULL, zeplara_support_file_parser_parserexception_ce, getThis(), "__construct", NULL, 0, message, &_0, &_1, filename, lineno);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

