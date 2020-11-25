
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_File_Parser_CompiledValue) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Support\\File\\Parser, CompiledValue, zeplara, support_file_parser_compiledvalue, zeplara_support_file_parser_compiledvalue_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(zeplara_support_file_parser_compiledvalue_ce, SL("value"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_support_file_parser_compiledvalue_ce, SL("rawValue"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Support_File_Parser_CompiledValue, getValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "value");

}

/**
 */
PHP_METHOD(Zeplara_Support_File_Parser_CompiledValue, getRawValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "rawValue");

}

/**
 * @param value
 * @param string rawValue
 */
PHP_METHOD(Zeplara_Support_File_Parser_CompiledValue, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval rawValue;
	zval *value, value_sub, *rawValue_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&rawValue);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &rawValue_param);

	if (UNEXPECTED(Z_TYPE_P(rawValue_param) != IS_STRING && Z_TYPE_P(rawValue_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'rawValue' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(rawValue_param) == IS_STRING)) {
		zephir_get_strval(&rawValue, rawValue_param);
	} else {
		ZEPHIR_INIT_VAR(&rawValue);
		ZVAL_EMPTY_STRING(&rawValue);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), value);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zeplara_support_file_parser_rawvalue_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 175, &rawValue);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("rawValue"), &_0);
	ZEPHIR_MM_RESTORE();

}

