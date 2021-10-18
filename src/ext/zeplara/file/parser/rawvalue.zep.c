
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Zeplara_File_Parser_RawValue) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\File\\Parser, RawValue, zeplara, file_parser_rawvalue, zeplara_file_parser_rawvalue_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @param string value
	 */
	zend_declare_property_null(zeplara_file_parser_rawvalue_ce, SL("value"), ZEND_ACC_PROTECTED);

	/**
	 * @var LinesIterator
	 */
	zend_declare_property_null(zeplara_file_parser_rawvalue_ce, SL("lines"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_file_parser_rawvalue_ce, 1, zeplara_contracts_file_parser_rawvalue_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_File_Parser_RawValue, getValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "value");

}

/**
 */
PHP_METHOD(Zeplara_File_Parser_RawValue, getLines) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "lines");

}

/**
 * @param string value
 */
PHP_METHOD(Zeplara_File_Parser_RawValue, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, _0;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	if (UNEXPECTED(Z_TYPE_P(value_param) != IS_STRING && Z_TYPE_P(value_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(value_param) == IS_STRING)) {
		zephir_get_strval(&value, value_param);
	} else {
		ZEPHIR_INIT_VAR(&value);
		ZVAL_EMPTY_STRING(&value);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), &value);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zeplara_file_parser_linesiterator_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 87, &value);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("lines"), &_0);
	ZEPHIR_MM_RESTORE();

}

