
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * @method Route get(string $pattern, $callback, array $attributes = [])
 * @method Route post(string $pattern, $callback, array $attributes = [])
 * @method Route put(string $pattern, $callback, array $attributes = [])
 * @method Route delete(string $pattern, $callback, array $attributes = [])
 * @method Route patch(string $pattern, $callback, array $attributes = [])
 * @method Route options(string $pattern, $callback, array $attributes = [])
 * @method Route any(string $pattern, $callback, array $attributes = [])
 * @method Route register(string $pattern, $callback, array $methods, array $attributes = [])
 * @method Registrar|string scheme(string $value = null)
 * @method Registrar|string host(string $value = null)
 * @method Registrar|string prefix(string $value = null)
 * @method Registrar|string namespace(string $value = null)
 * @method Registrar|array requirements(array $requirements)
 * @method Registrar where(string $key, $value)
 * @method Registrar|array middleware(...$args)
 * @method Registrar|string name(string $name = null)
 */
ZEPHIR_INIT_CLASS(Zeplara_Routing_Router) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Routing, Router, zeplara, routing_router, zeplara_routing_router_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_routing_router_ce, SL("routes"), ZEND_ACC_PROTECTED);

	/**
	 * @var Group
	 */
	zend_declare_property_null(zeplara_routing_router_ce, SL("group"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zeplara_routing_router_ce->create_object = zephir_init_properties_Zeplara_Routing_Router;

	zend_class_implements(zeplara_routing_router_ce, 1, zeplara_contracts_routing_router_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Routing_Router, getRoutes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "routes");

}

/**
 * @param array routes
 */
PHP_METHOD(Zeplara_Routing_Router, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routes_param = NULL, _0;
	zval routes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &routes_param);

	if (!routes_param) {
		ZEPHIR_INIT_VAR(&routes);
		array_init(&routes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&routes, routes_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setroutes", NULL, 137, &routes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zeplara_routing_group_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_static_property_ce(zeplara_routing_router_ce, ZEND_STRL("group"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param array routes
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Router, setRoutes) {

	zend_bool _2$$3, _4$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routes_param = NULL, route, *_0, _1;
	zval routes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &routes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&routes, routes_param);


	zephir_is_iterable(&routes, 0, "zeplara/Routing/Router.zep", 62);
	if (Z_TYPE_P(&routes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routes), _0)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _0);
			_2$$3 = Z_TYPE_P(&route) != IS_OBJECT;
			if (!(_2$$3)) {
				_2$$3 = (zephir_instance_of_ev(&route, zeplara_contracts_routing_route_ce)) == 0;
			}
			if (_2$$3) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The value must be instanceof Route.", "zeplara/Routing/Router.zep", 57);
				return;
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addroute", &_3, 138, &route);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &routes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &routes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&route, &routes, "current", NULL, 0);
			zephir_check_call_status();
				_4$$5 = Z_TYPE_P(&route) != IS_OBJECT;
				if (!(_4$$5)) {
					_4$$5 = (zephir_instance_of_ev(&route, zeplara_contracts_routing_route_ce)) == 0;
				}
				if (_4$$5) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The value must be instanceof Route.", "zeplara/Routing/Router.zep", 57);
					return;
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addroute", &_3, 138, &route);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &routes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&route);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param RouteContract route
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Router, addRoute) {

	zval *route, route_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &route);



	zephir_update_property_array_append(this_ptr, SL("routes"), route);

}

/**
 * @param string pattern
 * @param callback
 * @param array methods
 * @param array attributes
 * @return Route
 */
PHP_METHOD(Zeplara_Routing_Router, createRoute) {

	zend_bool _14, _15, _18$$5, _19$$5, _21$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval methods, attributes;
	zval *pattern = NULL, pattern_sub, *callback = NULL, callback_sub, *methods_param = NULL, *attributes_param = NULL, scheme, host, namespace, requirements, middleware, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _16$$4, _17$$4, _20$$5, _22$$6, _23$$6, _24$$6, _25$$6, _26$$6, _27$$6, _28$$6, _29$$7, _30$$7, _31$$7, _32$$7, _33$$7, _34$$7, _35$$7, _36$$7, _37$$7, _38$$10, _39$$10, _40$$10, _41$$10, _42$$13, _43$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&namespace);
	ZVAL_UNDEF(&requirements);
	ZVAL_UNDEF(&middleware);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_36$$7);
	ZVAL_UNDEF(&_37$$7);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_42$$13);
	ZVAL_UNDEF(&_43$$13);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &pattern, &callback, &methods_param, &attributes_param);

	ZEPHIR_SEPARATE_PARAM(pattern);
	ZEPHIR_SEPARATE_PARAM(callback);
	ZEPHIR_OBS_COPY_OR_DUP(&methods, methods_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	zephir_read_static_property_ce(&_0, zeplara_routing_router_ce, SL("group"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&scheme, &_0, "scheme", NULL, 0);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_1, zeplara_routing_router_ce, SL("group"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&host, &_1, "host", NULL, 0);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_2, zeplara_routing_router_ce, SL("group"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&middleware, &_2, "middleware", NULL, 0);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_3, zeplara_routing_router_ce, SL("group"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&namespace, &_3, "namespace", NULL, 0);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_4, zeplara_routing_router_ce, SL("group"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&requirements, &_4, "requirements", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_read_static_property_ce(&_7, zeplara_routing_router_ce, SL("group"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_8, &_7, "prefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "/");
	zephir_fast_trim(&_6, &_8, &_9, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "/");
	zephir_fast_trim(&_10, pattern, &_11, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_VSV(&_12, &_6, "/", &_10);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "/");
	zephir_fast_trim(&_5, &_12, &_13, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_NVAR(pattern);
	ZEPHIR_CONCAT_SV(pattern, "/", &_5);
	_14 = zephir_is_true(&scheme);
	if (_14) {
		_14 = !(zephir_array_isset_string(&attributes, SL("scheme")));
	}
	if (_14) {
		zephir_array_update_string(&attributes, SL("scheme"), &scheme, PH_COPY | PH_SEPARATE);
	}
	_15 = zephir_is_true(&host);
	if (_15) {
		_15 = !(zephir_array_isset_string(&attributes, SL("host")));
	}
	if (_15) {
		zephir_read_static_property_ce(&_16$$4, zeplara_routing_router_ce, SL("group"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_17$$4, &_16$$4, "host", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&attributes, SL("host"), &_17$$4, PH_COPY | PH_SEPARATE);
	}
	if (zephir_is_true(&namespace)) {
		_18$$5 = Z_TYPE_P(callback) == IS_ARRAY;
		if (_18$$5) {
			_18$$5 = zephir_fast_count_int(callback) == 2;
		}
		_19$$5 = _18$$5;
		if (_19$$5) {
			ZEPHIR_OBS_VAR(&_20$$5);
			zephir_array_fetch_long(&_20$$5, callback, 0, PH_NOISY, "zeplara/Routing/Router.zep", 102);
			_19$$5 = Z_TYPE_P(&_20$$5) == IS_STRING;
		}
		_21$$5 = _19$$5;
		if (_21$$5) {
			_21$$5 = zephir_is_callable(callback) == 0;
		}
		if (Z_TYPE_P(callback) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_22$$6);
			ZEPHIR_INIT_VAR(&_23$$6);
			ZEPHIR_INIT_VAR(&_24$$6);
			ZVAL_STRING(&_24$$6, "\\");
			zephir_fast_trim(&_23$$6, &namespace, &_24$$6, ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_VAR(&_25$$6);
			ZEPHIR_INIT_VAR(&_26$$6);
			ZVAL_STRING(&_26$$6, "\\");
			zephir_fast_trim(&_25$$6, callback, &_26$$6, ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_VAR(&_27$$6);
			ZEPHIR_CONCAT_VSV(&_27$$6, &_23$$6, "\\", &_25$$6);
			ZEPHIR_INIT_VAR(&_28$$6);
			ZVAL_STRING(&_28$$6, "\\");
			zephir_fast_trim(&_22$$6, &_27$$6, &_28$$6, ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_NVAR(callback);
			ZEPHIR_CONCAT_SV(callback, "\\", &_22$$6);
		} else if (_21$$5) {
			ZEPHIR_INIT_VAR(&_29$$7);
			ZEPHIR_INIT_VAR(&_30$$7);
			ZEPHIR_INIT_VAR(&_31$$7);
			ZVAL_STRING(&_31$$7, "\\");
			zephir_fast_trim(&_30$$7, &namespace, &_31$$7, ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_VAR(&_32$$7);
			zephir_array_fetch_long(&_33$$7, callback, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/Router.zep", 103);
			ZEPHIR_INIT_VAR(&_34$$7);
			ZVAL_STRING(&_34$$7, "\\");
			zephir_fast_trim(&_32$$7, &_33$$7, &_34$$7, ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_VAR(&_35$$7);
			ZEPHIR_CONCAT_VSV(&_35$$7, &_30$$7, "\\", &_32$$7);
			ZEPHIR_INIT_VAR(&_36$$7);
			ZVAL_STRING(&_36$$7, "\\");
			zephir_fast_trim(&_29$$7, &_35$$7, &_36$$7, ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_VAR(&_37$$7);
			ZEPHIR_CONCAT_SV(&_37$$7, "\\", &_29$$7);
			zephir_array_update_long(callback, 0, &_37$$7, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	if (zephir_is_true(&middleware)) {
		if (!(zephir_array_isset_string(&attributes, SL("middleware")))) {
			zephir_array_update_string(&attributes, SL("middleware"), &middleware, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(&_38$$10);
			zephir_array_fetch_string(&_39$$10, &attributes, SL("middleware"), PH_NOISY | PH_READONLY, "zeplara/Routing/Router.zep", 111);
			zephir_fast_array_merge(&_38$$10, &middleware, &_39$$10);
			ZVAL_LONG(&_40$$10, 0);
			ZEPHIR_CALL_FUNCTION(&_41$$10, "array_unique", NULL, 117, &_38$$10, &_40$$10);
			zephir_check_call_status();
			zephir_array_update_string(&attributes, SL("middleware"), &_41$$10, PH_COPY | PH_SEPARATE);
		}
	}
	if (zephir_is_true(&requirements)) {
		if (!(zephir_array_isset_string(&attributes, SL("requirements")))) {
			zephir_array_update_string(&attributes, SL("requirements"), &requirements, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_VAR(&_42$$13);
			zephir_array_fetch_string(&_43$$13, &attributes, SL("requirements"), PH_NOISY | PH_READONLY, "zeplara/Routing/Router.zep", 119);
			zephir_fast_array_merge(&_42$$13, &requirements, &_43$$13);
			zephir_array_update_string(&attributes, SL("requirements"), &_42$$13, PH_COPY | PH_SEPARATE);
		}
	}
	object_init_ex(return_value, zeplara_routing_route_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 139, pattern, callback, &methods, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param handler
 * @param array attributes
 * @return void
 */
PHP_METHOD(Zeplara_Routing_Router, group) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *handler, handler_sub, *attributes_param = NULL, groupClone, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&groupClone);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &handler, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);
	}


	zephir_read_static_property_ce(&_0, zeplara_routing_router_ce, SL("group"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&groupClone);
	if (zephir_clone(&groupClone, &_0) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_static_property_ce(&_1, zeplara_routing_router_ce, SL("group"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setattributes", NULL, 0, &attributes);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(NULL, zeplara_routing_group_ce, "load", &_2, 0, this_ptr, handler);
	zephir_check_call_status();
	zephir_update_static_property_ce(zeplara_routing_router_ce, ZEND_STRL("group"), &groupClone);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string name
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Zeplara_Routing_Router, __call) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _0;
	zval *name, name_sub, *arguments_param = NULL, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &arguments_param);

	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zeplara_routing_registrar_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 140, this_ptr);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, name);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &arguments);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Zeplara_Routing_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

