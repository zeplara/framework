
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/main.h"
#include "kernel/concat.h"


/**
 * @method Route|string scheme(string $value = null)
 * @method Route|string host(string $value = null)
 * @method Route|array requirements(array $requirements)
 * @method Route where(string $key, $value)
 * @method Route|array middleware(...$args)
 * @method Route|string name(string $name = null)
 */
ZEPHIR_INIT_CLASS(Zeplara_Routing_Route) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Routing, Route, zeplara, routing_route, zeplara_routing_attribute_ce, zeplara_routing_route_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_routing_route_ce, SL("pattern"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_routing_route_ce, SL("methods"), ZEND_ACC_PROTECTED);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(zeplara_routing_route_ce, SL("callback"), ZEND_ACC_PROTECTED);

	/**
	 * @var CompiledRoute|null
	 */
	zend_declare_property_null(zeplara_routing_route_ce, SL("compiled"), ZEND_ACC_PRIVATE);

	zend_class_implements(zeplara_routing_route_ce, 1, zeplara_contracts_routing_route_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Routing_Route, getPattern) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "pattern");

}

/**
 */
PHP_METHOD(Zeplara_Routing_Route, getMethods) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "methods");

}

/**
 */
PHP_METHOD(Zeplara_Routing_Route, getCallback) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "callback");

}

/**
 * @param string pattern
 * @param callback
 * @param array methods
 * @param array attributes
 */
PHP_METHOD(Zeplara_Routing_Route, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval methods, attributes;
	zval *pattern, pattern_sub, *callback, callback_sub, *methods_param = NULL, *attributes_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&callback_sub);
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


	zephir_update_property_zval(this_ptr, ZEND_STRL("pattern"), pattern);
	zephir_update_property_zval(this_ptr, ZEND_STRL("callback"), callback);
	zephir_update_property_zval(this_ptr, ZEND_STRL("methods"), &methods);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setattributes", NULL, 0, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return CompiledRoute
 */
PHP_METHOD(Zeplara_Routing_Route, compile) {

	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("compiled"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_CE_STATIC(&_1$$3, zeplara_routing_routecompiler_ce, "compile", &_2, 0, this_ptr);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("compiled"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "compiled");

}

/**
 * @return string
 */
PHP_METHOD(Zeplara_Routing_Route, getSchemeAttribute) {

	zval _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("scheme"))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("scheme"), PH_NOISY | PH_READONLY, "zeplara/Routing/Route.zep", 66);
		RETURN_CTORW(&_2$$3);
	}
	RETURN_STRING("");

}

/**
 * @param string value
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Route, setSchemeAttribute) {

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
PHP_METHOD(Zeplara_Routing_Route, initSchemeAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setschemeattribute", NULL, 120, &value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Zeplara_Routing_Route, getHostAttribute) {

	zval _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("host"))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("host"), PH_NOISY | PH_READONLY, "zeplara/Routing/Route.zep", 104);
		RETURN_CTORW(&_2$$3);
	}
	RETURN_STRING("");

}

/**
 * @param string value
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Route, setHostAttribute) {

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
PHP_METHOD(Zeplara_Routing_Route, initHostAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sethostattribute", NULL, 121, &value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return array
 */
PHP_METHOD(Zeplara_Routing_Route, getRequirementsAttribute) {

	zval _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("requirements"))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("requirements"), PH_NOISY | PH_READONLY, "zeplara/Routing/Route.zep", 134);
		RETURN_CTORW(&_2$$3);
	}
	array_init(return_value);
	return;

}

/**
 * @param array value
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Route, setRequirementsAttribute) {

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
	zephir_is_iterable(&requirements, 0, "zeplara/Routing/Route.zep", 159);
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
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The requirements key should be string type.", "zeplara/Routing/Route.zep", 154);
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
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The requirements key should be string type.", "zeplara/Routing/Route.zep", 154);
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
 * @param array requirements
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Route, initRequirementsAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *requirements_param = NULL;
	zval requirements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requirements);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &requirements_param);

	ZEPHIR_OBS_COPY_OR_DUP(&requirements, requirements_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrequirementsattribute", NULL, 122, &requirements);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string key
 * @param value
 */
PHP_METHOD(Zeplara_Routing_Route, setWhereAttribute) {

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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrequirementsattribute", NULL, 122, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return array
 */
PHP_METHOD(Zeplara_Routing_Route, getMiddlewareAttribute) {

	zval _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("middleware"))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("middleware"), PH_NOISY | PH_READONLY, "zeplara/Routing/Route.zep", 185);
		RETURN_CTORW(&_2$$3);
	}
	array_init(return_value);
	return;

}

/**
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Route, setMiddlewareAttribute) {

	zval _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmiddlewareattribute", NULL, 123);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_args(&_2);
	zephir_fast_array_merge(&_0, &_1, &_2);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_FUNCTION(&_4, "array_unique", NULL, 117, &_0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "middleware");
	zephir_update_property_array(this_ptr, SL("attributes"), &_5, &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param array middleware
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Route, initMiddlewareAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *middleware_param = NULL, _0, _2;
	zval middleware, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middleware);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &middleware_param);

	ZEPHIR_OBS_COPY_OR_DUP(&middleware, middleware_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	zephir_array_fast_append(&_1, this_ptr);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "setMiddlewareAttribute");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_0, &_1, &middleware);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Zeplara_Routing_Route, getNameAttribute) {

	zval _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("name"))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2$$3, &_1$$3, SL("name"), PH_NOISY | PH_READONLY, "zeplara/Routing/Route.zep", 214);
		RETURN_CTORW(&_2$$3);
	}
	RETURN_STRING("");

}

/**
 * @param string value
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Route, setNameAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, _0, _1, _2;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getnameattribute", NULL, 124);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, &value);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "name");
	zephir_update_property_array(this_ptr, SL("attributes"), &_2, &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Route, initNameAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setnameattribute", NULL, 125, &value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

