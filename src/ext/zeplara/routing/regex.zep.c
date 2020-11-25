
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Zeplara_Routing_Regex) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Routing, Regex, zeplara, routing_regex, zeplara_routing_regex_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_routing_regex_ce, SL("regex"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_routing_regex_ce, SL("variables"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_routing_regex_ce, 1, zeplara_contracts_routing_regex_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Routing_Regex, getRegex) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "regex");

}

/**
 */
PHP_METHOD(Zeplara_Routing_Regex, getVariables) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "variables");

}

/**
 * @param string regex
 * @param array variables
 */
PHP_METHOD(Zeplara_Routing_Regex, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval variables;
	zval *regex_param = NULL, *variables_param = NULL;
	zval regex;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&variables);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &regex_param, &variables_param);

	if (UNEXPECTED(Z_TYPE_P(regex_param) != IS_STRING && Z_TYPE_P(regex_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'regex' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(regex_param) == IS_STRING)) {
		zephir_get_strval(&regex, regex_param);
	} else {
		ZEPHIR_INIT_VAR(&regex);
		ZVAL_EMPTY_STRING(&regex);
	}
	if (!variables_param) {
		ZEPHIR_INIT_VAR(&variables);
		array_init(&variables);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&variables, variables_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("regex"), &regex);
	zephir_update_property_zval(this_ptr, ZEND_STRL("variables"), &variables);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @return array
 */
PHP_METHOD(Zeplara_Routing_Regex, match) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value, value_sub, matches, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("regex"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_preg_match(&_1, &_0, value, &matches, 0, 0 , 0 );
	RETURN_CCTOR(&matches);

}

