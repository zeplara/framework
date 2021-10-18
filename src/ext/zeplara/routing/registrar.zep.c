
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/main.h"


/**
 * @method Registrar|string scheme(string $value = null)
 * @method Registrar|string host(string $value = null)
 * @method Registrar|string prefix(string $value = null)
 * @method Registrar|string namespace(string $value = null)
 * @method Registrar|array requirements(array $requirements)
 * @method Registrar where(string $key, $value)
 * @method Registrar|array middleware(...$args)
 * @method Registrar|string name(string $name = null)
 */
ZEPHIR_INIT_CLASS(Zeplara_Routing_Registrar) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Routing, Registrar, zeplara, routing_registrar, zeplara_routing_abstractattribute_ce, zeplara_routing_registrar_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var Router
	 */
	zend_declare_property_null(zeplara_routing_registrar_ce, SL("router"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_routing_registrar_ce, 1, zeplara_contracts_routing_registrar_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Routing_Registrar, getRouter) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "router");

}

/**
 * @param Router router
 */
PHP_METHOD(Zeplara_Routing_Registrar, __construct) {

	zval *router, router_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&router_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &router);



	zephir_update_property_zval(this_ptr, ZEND_STRL("router"), router);

}

/**
 * @param string pattern
 * @param callback
 * @param array attributes
 * @return Route
 */
PHP_METHOD(Zeplara_Routing_Registrar, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0;
	zval *pattern, pattern_sub, *callback, callback_sub, *attributes_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &pattern, &callback, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GET");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "HEAD");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "register", NULL, 151, pattern, callback, &_0, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string pattern
 * @param callback
 * @param array attributes
 * @return Route
 */
PHP_METHOD(Zeplara_Routing_Registrar, post) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0;
	zval *pattern, pattern_sub, *callback, callback_sub, *attributes_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &pattern, &callback, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "POST");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "register", NULL, 151, pattern, callback, &_0, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string pattern
 * @param callback
 * @param array attributes
 * @return Route
 */
PHP_METHOD(Zeplara_Routing_Registrar, put) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0;
	zval *pattern, pattern_sub, *callback, callback_sub, *attributes_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &pattern, &callback, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "PUT");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "register", NULL, 151, pattern, callback, &_0, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string pattern
 * @param callback
 * @param array attributes
 * @return Route
 */
PHP_METHOD(Zeplara_Routing_Registrar, delete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0;
	zval *pattern, pattern_sub, *callback, callback_sub, *attributes_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &pattern, &callback, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "DELETE");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "register", NULL, 151, pattern, callback, &_0, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string pattern
 * @param callback
 * @param array attributes
 * @return Route
 */
PHP_METHOD(Zeplara_Routing_Registrar, patch) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0;
	zval *pattern, pattern_sub, *callback, callback_sub, *attributes_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &pattern, &callback, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "PATCH");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "register", NULL, 151, pattern, callback, &_0, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string pattern
 * @param callback
 * @param array attributes
 * @return Route
 */
PHP_METHOD(Zeplara_Routing_Registrar, options) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0;
	zval *pattern, pattern_sub, *callback, callback_sub, *attributes_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &pattern, &callback, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "OPTIONS");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "register", NULL, 151, pattern, callback, &_0, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string pattern
 * @param callback
 * @param array attributes
 * @return Route
 */
PHP_METHOD(Zeplara_Routing_Registrar, any) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _0;
	zval *pattern, pattern_sub, *callback, callback_sub, *attributes_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &pattern, &callback, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 7, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HEAD");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "GET");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "POST");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "PUT");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "DELETE");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "PATCH");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "OPTIONS");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "register", NULL, 151, pattern, callback, &_0, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param handler
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Registrar, group) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler, handler_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &handler);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "group", NULL, 0, handler, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string pattern
 * @param callback
 * @param array methods
 * @param array attributes
 * @return Route
 */
PHP_METHOD(Zeplara_Routing_Registrar, register) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval methods, attributes;
	zval *pattern, pattern_sub, *callback, callback_sub, *methods_param = NULL, *attributes_param = NULL, route, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &pattern, &callback, &methods_param, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&methods, methods_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_1, &_2, &attributes);
	ZEPHIR_CALL_METHOD(&route, &_0, "createroute", NULL, 0, pattern, callback, &methods, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "addroute", NULL, 0, &route);
	zephir_check_call_status();
	RETURN_CCTOR(&route);

}

/**
 * @param string value
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Registrar, setSchemeAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value_param = NULL, sepIdx, _0, _1, _4, _2$$3, _3$$3;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&sepIdx);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

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


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &value);
	zephir_get_strval(&value, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ":");
	ZEPHIR_INIT_VAR(&sepIdx);
	zephir_fast_strpos(&sepIdx, &value, &_1, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&sepIdx)) {
		ZVAL_LONG(&_2$$3, 0);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_substr(&_3$$3, &value, 0 , zephir_get_intval(&sepIdx), 0);
		zephir_get_strval(&value, &_3$$3);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "scheme");
	zephir_update_property_array(this_ptr, SL("attributes"), &_4, &value);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Registrar, setHostAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "host");
	zephir_update_property_array(this_ptr, SL("attributes"), &_0, &value);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Registrar, setPrefixAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *value_param = NULL, _0, _1, _2, _4, _5, _6, _7, _8, _9, _10, _11;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);

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


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "prefix");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "");
	ZEPHIR_CALL_CE_STATIC(&_2, zeplara_support_arr_ce, "get", &_3, 0, &_4, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "/");
	zephir_fast_trim(&_1, &_2, &_5, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_NVAR(&_6);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "/");
	zephir_fast_trim(&_6, &value, &_7, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_VSV(&_8, &_1, "/", &_6);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "/");
	zephir_fast_trim(&_0, &_8, &_9, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SV(&_10, "/", &_0);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "prefix");
	zephir_update_property_array(this_ptr, SL("attributes"), &_11, &_10);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Registrar, setNamespaceAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *value_param = NULL, _0, _1, _2, _4, _5, _6, _7, _8, _9, _10, _11;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);

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


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "namespace");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "");
	ZEPHIR_CALL_CE_STATIC(&_2, zeplara_support_arr_ce, "get", &_3, 0, &_4, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "\\");
	zephir_fast_trim(&_1, &_2, &_5, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_NVAR(&_6);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "\\");
	zephir_fast_trim(&_6, &value, &_7, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_VSV(&_8, &_1, "\\", &_6);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "\\");
	zephir_fast_trim(&_0, &_8, &_9, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SV(&_10, "\\", &_0);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "namespace");
	zephir_update_property_array(this_ptr, SL("attributes"), &_11, &_10);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param array value
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Registrar, setRequirementsAttribute) {

	zend_string *_6;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *requirements_param = NULL, key, value, _0, *_3, _4, _1$$3, _2$$3;
	zval requirements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requirements);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &requirements_param);

	ZEPHIR_OBS_COPY_OR_DUP(&requirements, requirements_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string(&_0, SL("requirements")))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "requirements");
		zephir_update_property_array(this_ptr, SL("attributes"), &_2$$3, &_1$$3);
	}
	zephir_is_iterable(&requirements, 0, "zeplara/Routing/Registrar.zep", 199);
	if (Z_TYPE_P(&requirements) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&requirements), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&key, _6);
			} else {
				ZVAL_LONG(&key, _5);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			if (zephir_is_numeric(&key)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The requirements key should be string type.", "zeplara/Routing/Registrar.zep", 194);
				return;
			}
			zephir_update_property_array_multi(this_ptr, SL("attributes"), &value, SL("sz"), 3, SL("requirements"), &key);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &requirements, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &requirements, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &requirements, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &requirements, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_is_numeric(&key)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The requirements key should be string type.", "zeplara/Routing/Registrar.zep", 194);
					return;
				}
				zephir_update_property_array_multi(this_ptr, SL("attributes"), &value, SL("sz"), 3, SL("requirements"), &key);
			ZEPHIR_CALL_METHOD(NULL, &requirements, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string key
 * @param value
 */
PHP_METHOD(Zeplara_Routing_Registrar, setWhereAttribute) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	zephir_array_update_zval(&_0, &key, value, PH_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrequirementsattribute", NULL, 152, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Registrar, setMiddlewareAttribute) {

	zval _0, _1, _3, _4, _5, _6, _7, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "middleware");
	ZEPHIR_CALL_CE_STATIC(&_1, zeplara_support_arr_ce, "get", &_2, 0, &_3, &_5, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	zephir_get_args(&_5);
	zephir_fast_array_merge(&_0, &_1, &_5);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_CALL_FUNCTION(&_7, "array_unique", NULL, 150, &_0, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "middleware");
	zephir_update_property_array(this_ptr, SL("attributes"), &_8, &_7);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Registrar, setNameAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "name");
	zephir_update_property_array(this_ptr, SL("attributes"), &_0, &value);
	ZEPHIR_MM_RESTORE();

}

