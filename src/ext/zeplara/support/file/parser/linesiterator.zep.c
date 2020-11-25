
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_File_Parser_LinesIterator) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Support\\File\\Parser, LinesIterator, zeplara, support_file_parser_linesiterator, zephir_get_internal_ce(SL("arrayiterator")), zeplara_support_file_parser_linesiterator_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

/**
 * @param string contents
 */
PHP_METHOD(Zeplara_Support_File_Parser_LinesIterator, __construct) {

	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *contents_param = NULL, _0, _1, _3;
	zval contents;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &contents_param);

	if (UNEXPECTED(Z_TYPE_P(contents_param) != IS_STRING && Z_TYPE_P(contents_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'contents' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(contents_param) == IS_STRING)) {
		zephir_get_strval(&contents, contents_param);
	} else {
		ZEPHIR_INIT_VAR(&contents);
		ZVAL_EMPTY_STRING(&contents);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "\r\n");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "\r");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "\n");
	zephir_fast_str_replace(&_1, &_2, &_3, &contents);
	zephir_fast_explode_str(&_0, SL("\n"), &_1, LONG_MAX);
	ZEPHIR_CALL_PARENT(NULL, zeplara_support_file_parser_linesiterator_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

