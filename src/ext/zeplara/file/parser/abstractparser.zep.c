
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
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Zeplara_File_Parser_AbstractParser) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\File\\Parser, AbstractParser, zeplara, file_parser_abstractparser, zeplara_file_parser_abstractparser_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(zeplara_file_parser_abstractparser_ce, 1, zeplara_interfaces_file_parser_parser_ce);
	return SUCCESS;

}

/**
 * @param string file
 * @return mixed
 * @throws InvalidArgumentException|ParserException
 */
PHP_METHOD(Zeplara_File_Parser_AbstractParser, parseFile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, _0$$3, _1$$3, _2$$3, _3$$3, e, _5, _4$$4, _6$$5, _7$$5;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_EMPTY_STRING(&file);
	}


	if ((zephir_file_exists(&file) == SUCCESS) == 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "File %s does not exists.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 2, &_2$$3, &file);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "zeplara/File/Parser/AbstractParser.zep", 17);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_file_get_contents(&_4$$4, &file);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parse", NULL, 0, &_4$$4);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_OBJ(&_5, EG(exception));
		Z_ADDREF_P(&_5);
		if (zephir_instance_of_ev(&_5, zeplara_file_parser_parserexception_ce)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_5);
			ZEPHIR_CALL_METHOD(&_6$$5, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$5, &e, "getline", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexception", NULL, 0, &_6$$5, &file, &_7$$5);
			zephir_check_call_status();
		}
	}

}

/**
 * @param string message
 * @param string file
 * @param int line
 * @throws ParserException
 */
PHP_METHOD(Zeplara_File_Parser_AbstractParser, throwParserException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, *file = NULL, file_sub, *line = NULL, line_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &message, &file, &line);

	if (!file) {
		file = &file_sub;
		ZEPHIR_INIT_VAR(file);
		ZVAL_STRING(file, "");
	}
	if (!line) {
		line = &line_sub;
		ZEPHIR_INIT_VAR(line);
		ZVAL_LONG(line, 0);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zeplara_file_parser_parserexception_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 9, message, file, line);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "zeplara/File/Parser/AbstractParser.zep", 37);
	ZEPHIR_MM_RESTORE();
	return;

}

