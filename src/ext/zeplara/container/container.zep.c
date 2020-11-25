
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Zeplara_Container_Container) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Container, Container, zeplara, container_container, zeplara_container_container_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_container_container_ce, SL("bindings"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_container_container_ce, SL("aliasBindings"), ZEND_ACC_PRIVATE);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_container_container_ce, SL("bindingAliases"), ZEND_ACC_PRIVATE);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_container_container_ce, SL("bindingsResolved"), ZEND_ACC_PRIVATE);

	zeplara_container_container_ce->create_object = zephir_init_properties_Zeplara_Container_Container;

	zend_class_implements(zeplara_container_container_ce, 1, zeplara_contracts_container_container_ce);
	return SUCCESS;

}

/**
 * @param key
 * @return mixed
 */
PHP_METHOD(Zeplara_Container_Container, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, _0, _5, _8, _9, _1$$3, _2$$3, _3$$3, _4$$3, _6$$4, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvekey", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, &_0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zeplara_container_containerexception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Binding [%s] does not exists.");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 2, &_3$$3, key);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "zeplara/Container/Container.zep", 38);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("bindingsResolved"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_5, key)) {
		zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("bindingsResolved"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_7$$4, &_6$$4, key, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 42);
		RETURN_CTOR(&_7$$4);
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_9, &_8, key, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 45);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolvebinding", NULL, 0, key, &_9);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param key
 * @return bool 
 */
PHP_METHOD(Zeplara_Container_Container, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolvekey", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * @param key
 * @param value
 * @param bool resolve
 * @return void
 */
PHP_METHOD(Zeplara_Container_Container, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool resolve, _0$$3, _7$$4, _9$$4;
	zval *key, key_sub, *value = NULL, value_sub, *resolve_param = NULL, _1$$3, _3$$4, _4$$4, _5$$4, _6$$4, _8$$4, _10$$4, _11$$4, _12$$5, _13$$5, _14$$5, _15$$5, _17$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_17$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key, &value, &resolve_param);

	ZEPHIR_SEPARATE_PARAM(value);
	if (!resolve_param) {
		resolve = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(resolve_param) != IS_TRUE && Z_TYPE_P(resolve_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'resolve' must be of the type bool"));
		RETURN_MM_NULL();
	}
	resolve = (Z_TYPE_P(resolve_param) == IS_TRUE);
	}


	if (resolve == 0) {
		_0$$3 = Z_TYPE_P(value) == IS_STRING;
		if (_0$$3) {
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "has", &_2, 0, value);
			zephir_check_call_status();
			_0$$3 = zephir_is_true(&_1$$3);
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_4$$4, value)) {
				zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_3$$4);
				zephir_array_fetch(&_3$$4, &_5$$4, value, PH_NOISY, "zeplara/Container/Container.zep", 67);
			} else {
				ZEPHIR_CPY_WRT(&_3$$4, value);
			}
			ZEPHIR_CPY_WRT(value, &_3$$4);
			ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "has", &_2, 0, key);
			zephir_check_call_status();
			_7$$4 = zephir_is_true(&_6$$4);
			if (_7$$4) {
				zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
				_9$$4 = zephir_array_isset(&_8$$4, key) == 0;
				if (!(_9$$4)) {
					zephir_read_property(&_10$$4, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_11$$4, &_10$$4, key, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 69);
					_9$$4 = !ZEPHIR_IS_IDENTICAL(&_11$$4, value);
				}
				_7$$4 = _9$$4;
			}
			if (_7$$4) {
				ZEPHIR_INIT_VAR(&_12$$5);
				object_init_ex(&_12$$5, zeplara_container_containerexception_ce);
				ZEPHIR_INIT_VAR(&_14$$5);
				ZVAL_STRING(&_14$$5, "Cannot make alias [%s] when that alias already exists as root binding or as alias.");
				ZEPHIR_CALL_FUNCTION(&_15$$5, "sprintf", NULL, 2, &_14$$5, key);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_12$$5, "__construct", NULL, 8, &_15$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_12$$5, "zeplara/Container/Container.zep", 70);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "put", &_16, 0, key);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("aliasBindings"), key, value);
			zephir_update_property_array_multi(this_ptr, SL("bindingAliases"), key, SL("za"), 2, value);
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "put", &_16, 0, key);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("bindings"), key, value);
		}
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "put", &_16, 0, key);
		zephir_check_call_status();
		if (zephir_is_callable(value)) {
			ZEPHIR_INIT_VAR(&_17$$8);
			ZEPHIR_CALL_USER_FUNC(&_17$$8, value);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, &_17$$8);
		}
		zephir_update_property_array(this_ptr, SL("bindings"), key, value);
		zephir_update_property_array(this_ptr, SL("bindingsResolved"), key, value);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param key
 * @return void
 */
PHP_METHOD(Zeplara_Container_Container, put) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$4, _12$$4, _13$$4, alias$$5, _14$$5, _15$$5, *_16$$5, _17$$5, _20$$5, _18$$6, _19$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&alias$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, key)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("bindingAliases"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_4$$3);
		zephir_array_fetch(&_4$$3, &_3$$3, key, PH_NOISY, "zeplara/Container/Container.zep", 101);
		zephir_array_fetch(&_2$$3, &_1$$3, &_4$$3, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 101);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("bindingAliases"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_8$$3);
		zephir_array_fetch(&_8$$3, &_7$$3, key, PH_NOISY, "zeplara/Container/Container.zep", 101);
		zephir_array_fetch(&_6$$3, &_5$$3, &_8$$3, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 101);
		ZEPHIR_CALL_FUNCTION(&_9$$3, "array_search", NULL, 21, key, &_6$$3);
		zephir_check_call_status();
		zephir_array_unset(&_2$$3, &_9$$3, PH_SEPARATE);
		zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_10$$3, key, PH_SEPARATE);
	} else {
		zephir_read_property(&_11$$4, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_11$$4, key, PH_SEPARATE);
		zephir_read_property(&_12$$4, this_ptr, ZEND_STRL("bindingsResolved"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_12$$4, key, PH_SEPARATE);
		zephir_read_property(&_13$$4, this_ptr, ZEND_STRL("bindingAliases"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_13$$4, key)) {
			zephir_read_property(&_14$$5, this_ptr, ZEND_STRL("bindingAliases"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_15$$5, &_14$$5, key, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 109);
			zephir_is_iterable(&_15$$5, 0, "zeplara/Container/Container.zep", 113);
			if (Z_TYPE_P(&_15$$5) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_15$$5), _16$$5)
				{
					ZEPHIR_INIT_NVAR(&alias$$5);
					ZVAL_COPY(&alias$$5, _16$$5);
					zephir_read_property(&_18$$6, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_18$$6, &alias$$5, PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_15$$5, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_17$$5, &_15$$5, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_17$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&alias$$5, &_15$$5, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property(&_19$$7, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
						zephir_array_unset(&_19$$7, &alias$$5, PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &_15$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&alias$$5);
			zephir_read_property(&_20$$5, this_ptr, ZEND_STRL("bindingAliases"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_20$$5, key, PH_SEPARATE);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param $abstract
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Zeplara_Container_Container, make) {

	zend_class_entry *_25$$17;
	zend_bool _11$$10, _17$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _12$$11;
	zval *abstract = NULL, abstract_sub, *arguments_param = NULL, reflection, constructor, _26, _0$$3, _2$$3, _3$$3, _4$$3, _6$$3, _7$$3, _5$$5, _8$$7, _9$$7, _10$$9, _13$$11, _14$$13, _15$$13, _16$$13, _18$$13, _19$$14, _20$$14, _21$$15, _22$$16, _24$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&abstract_sub);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&constructor);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_12$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &abstract, &arguments_param);

	ZEPHIR_SEPARATE_PARAM(abstract);
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);
	}


	if (Z_TYPE_P(abstract) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "resolvekey", &_1, 0, abstract);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(abstract, &_0$$3);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "resolvekey", &_1, 0, abstract);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "has", NULL, 0, &_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_0$$3)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, abstract);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, ".");
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_fast_strpos(&_4$$3, abstract, &_3$$3, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_4$$3)) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_fast_explode_str(&_5$$5, SL("."), abstract, 2 );
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "make", NULL, 22, &_5$$5, &arguments);
			zephir_check_call_status();
			RETURN_MM();
		}

		/* try_start_1: */

			ZEPHIR_INIT_VAR(&reflection);
			object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 23, abstract);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_6$$3);
			ZVAL_OBJ(&_6$$3, EG(exception));
			Z_ADDREF_P(&_6$$3);
			ZEPHIR_INIT_VAR(&_7$$3);
			if (zephir_instance_of_ev(&_6$$3, zephir_get_internal_ce(SL("reflectionexception")))) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&_7$$3, &_6$$3);

				/* try_start_2: */

					ZEPHIR_INIT_NVAR(&reflection);
					object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
					ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 24, abstract);
					zephir_check_call_status_or_jump(try_end_2);

				try_end_2:

				if (EG(exception)) {
					ZEPHIR_INIT_VAR(&_8$$7);
					ZVAL_OBJ(&_8$$7, EG(exception));
					Z_ADDREF_P(&_8$$7);
					ZEPHIR_INIT_VAR(&_9$$7);
					if (zephir_instance_of_ev(&_8$$7, zephir_get_internal_ce(SL("reflectionexception")))) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(&_9$$7, &_8$$7);
						ZEPHIR_INIT_VAR(&_10$$9);
						object_init_ex(&_10$$9, zeplara_container_invalidabstractexception_ce);
						ZEPHIR_CALL_METHOD(NULL, &_10$$9, "__construct", NULL, 25, abstract);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$9, "zeplara/Container/Container.zep", 143);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
	} else if (zephir_is_callable(abstract)) {
		_11$$10 = Z_TYPE_P(abstract) == IS_OBJECT;
		if (_11$$10) {
			_11$$10 = (zephir_instance_of_ev(abstract, zend_ce_closure)) == 0;
		}
		if (_11$$10) {
			ZEPHIR_INIT_VAR(&_12$$11);
			zephir_create_array(&_12$$11, 2, 0);
			zephir_array_fast_append(&_12$$11, abstract);
			ZEPHIR_INIT_VAR(&_13$$11);
			ZVAL_STRING(&_13$$11, "__invoke");
			zephir_array_fast_append(&_12$$11, &_13$$11);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "make", NULL, 22, &_12$$11, &arguments);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_NVAR(&reflection);
		if (Z_TYPE_P(abstract) != IS_ARRAY) {
			object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
			ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 24, abstract);
			zephir_check_call_status();
		} else {
			object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionmethod")));
			zephir_array_fetch_long(&_14$$13, abstract, 0, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 154);
			zephir_array_fetch_long(&_15$$13, abstract, 1, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 154);
			ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 26, &_14$$13, &_15$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16$$13, &reflection, "isstatic", NULL, 27);
			zephir_check_call_status();
			_17$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&_16$$13);
			if (_17$$13) {
				ZEPHIR_OBS_VAR(&_18$$13);
				zephir_array_fetch_long(&_18$$13, abstract, 0, PH_NOISY, "zeplara/Container/Container.zep", 155);
				_17$$13 = Z_TYPE_P(&_18$$13) == IS_STRING;
			}
			if (_17$$13) {
				zephir_array_fetch_long(&_20$$14, abstract, 0, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 156);
				ZEPHIR_CALL_METHOD(&_19$$14, this_ptr, "make", NULL, 22, &_20$$14);
				zephir_check_call_status();
				zephir_array_update_long(abstract, 0, &_19$$14, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
			}
		}
	} else {
		ZEPHIR_INIT_VAR(&_21$$15);
		object_init_ex(&_21$$15, zeplara_container_invalidabstractexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_21$$15, "__construct", NULL, 25, abstract);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_21$$15, "zeplara/Container/Container.zep", 160);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if ((zephir_instance_of_ev(&reflection, zephir_get_internal_ce(SL("reflectionclass")))) == 0) {
		ZEPHIR_CALL_METHOD(&_22$$16, this_ptr, "parsearguments", &_23, 0, &reflection, &arguments);
		zephir_check_call_status();
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, abstract, &_22$$16);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&constructor, &reflection, "getconstructor", NULL, 28);
	zephir_check_call_status();
	if (Z_TYPE_P(&constructor) == IS_NULL) {
		zephir_fetch_safe_class(&_24$$17, abstract);
		_25$$17 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_24$$17), Z_STRLEN_P(&_24$$17), ZEND_FETCH_CLASS_AUTO);
		if(!_25$$17) {
			RETURN_MM_NULL();
		}
		object_init_ex(return_value, _25$$17);
		if (zephir_has_constructor(return_value)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_26, this_ptr, "parsearguments", &_23, 0, &constructor, &arguments);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&reflection, "newinstanceargs", NULL, 29, &_26);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string key
 * @return mixed
 */
PHP_METHOD(Zeplara_Container_Container, offsetGet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string key
 * @return bool
 */
PHP_METHOD(Zeplara_Container_Container, offsetExists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string key
 * @param value
 * @return void
 */
PHP_METHOD(Zeplara_Container_Container, offsetSet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string key
 * @return void
 */
PHP_METHOD(Zeplara_Container_Container, offsetUnset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "put", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string key
 * @return mixed
 */
PHP_METHOD(Zeplara_Container_Container, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string key
 * @return bool
 */
PHP_METHOD(Zeplara_Container_Container, __isset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string key
 * @param value
 * @return void
 */
PHP_METHOD(Zeplara_Container_Container, __set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string key
 * @return void
 */
PHP_METHOD(Zeplara_Container_Container, __unset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "put", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param reflector
 * @param array arguments
 */
PHP_METHOD(Zeplara_Container_Container, parseArguments) {

	zend_bool _8$$5, _10$$5, _19$$11, _21$$11, _25$$14, _27$$14, _39$$21, _41$$21, _49$$27, _51$$27, _55$$30, _57$$30;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL, *_33 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval arguments;
	zval *reflector, reflector_sub, *arguments_param = NULL, __$null, e, i, params, parameters, parameter, refClass, *_0, _1, _4$$3, _5$$3, _6$$4, _7$$4, _9$$5, _11$$5, _12$$5, _13$$6, _14$$8, _15$$8, _17$$7, _18$$9, _20$$11, _22$$11, _23$$12, _24$$13, _26$$14, _28$$14, _29$$15, _30$$16, _31$$17, _34$$17, _32$$18, _35$$19, _36$$19, _37$$20, _38$$20, _40$$21, _42$$21, _43$$21, _44$$22, _45$$24, _46$$24, _47$$23, _48$$25, _50$$27, _52$$27, _53$$28, _54$$29, _56$$30, _58$$30, _59$$31, _60$$32, _61$$33, _63$$33, _62$$34;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflector_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&refClass);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_35$$19);
	ZVAL_UNDEF(&_36$$19);
	ZVAL_UNDEF(&_37$$20);
	ZVAL_UNDEF(&_38$$20);
	ZVAL_UNDEF(&_40$$21);
	ZVAL_UNDEF(&_42$$21);
	ZVAL_UNDEF(&_43$$21);
	ZVAL_UNDEF(&_44$$22);
	ZVAL_UNDEF(&_45$$24);
	ZVAL_UNDEF(&_46$$24);
	ZVAL_UNDEF(&_47$$23);
	ZVAL_UNDEF(&_48$$25);
	ZVAL_UNDEF(&_50$$27);
	ZVAL_UNDEF(&_52$$27);
	ZVAL_UNDEF(&_53$$28);
	ZVAL_UNDEF(&_54$$29);
	ZVAL_UNDEF(&_56$$30);
	ZVAL_UNDEF(&_58$$30);
	ZVAL_UNDEF(&_59$$31);
	ZVAL_UNDEF(&_60$$32);
	ZVAL_UNDEF(&_61$$33);
	ZVAL_UNDEF(&_63$$33);
	ZVAL_UNDEF(&_62$$34);
	ZVAL_UNDEF(&arguments);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &reflector, &arguments_param);

	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);
	}


	index = 0;
	ZEPHIR_CALL_METHOD(&params, reflector, "getparameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&parameters);
	array_init(&parameters);
	zephir_is_iterable(&params, 0, "zeplara/Container/Container.zep", 307);
	if (Z_TYPE_P(&params) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&params), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&i);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&i, _3);
			} else {
				ZVAL_LONG(&i, _2);
			}
			ZEPHIR_INIT_NVAR(&parameter);
			ZVAL_COPY(&parameter, _0);
			ZEPHIR_CALL_METHOD(&refClass, &parameter, "getclass", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_4$$3, &parameter, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_5$$3, index);
			if (zephir_array_isset(&arguments, &_4$$3)) {
				ZEPHIR_OBS_NVAR(&_7$$4);
				zephir_read_property(&_7$$4, &parameter, ZEND_STRL("name"), PH_NOISY_CC);
				zephir_array_fetch(&_6$$4, &arguments, &_7$$4, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 267);
				zephir_array_update_zval(&parameters, &i, &_6$$4, PH_COPY | PH_SEPARATE);
			} else if (Z_TYPE_P(&refClass) != IS_NULL) {
				_8$$5 = zephir_array_isset_long(&arguments, index);
				if (_8$$5) {
					ZEPHIR_OBS_NVAR(&_9$$5);
					zephir_array_fetch_long(&_9$$5, &arguments, index, PH_NOISY, "zeplara/Container/Container.zep", 269);
					_8$$5 = Z_TYPE_P(&_9$$5) == IS_OBJECT;
				}
				_10$$5 = _8$$5;
				if (_10$$5) {
					ZEPHIR_OBS_NVAR(&_11$$5);
					zephir_array_fetch_long(&_11$$5, &arguments, index, PH_NOISY, "zeplara/Container/Container.zep", 269);
					ZEPHIR_OBS_NVAR(&_12$$5);
					zephir_read_property(&_12$$5, &refClass, ZEND_STRL("name"), PH_NOISY_CC);
					_10$$5 = zephir_is_instance_of(&_11$$5, Z_STRVAL_P(&_12$$5), Z_STRLEN_P(&_12$$5));
				}
				if (_10$$5) {
					zephir_array_fetch_long(&_13$$6, &arguments, index, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 270);
					zephir_array_update_zval(&parameters, &i, &_13$$6, PH_COPY | PH_SEPARATE);
					index++;
				} else {

					/* try_start_1: */

						zephir_read_property(&_15$$8, &refClass, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(&_14$$8, this_ptr, "make", &_16, 0, &_15$$8);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_array_update_zval(&parameters, &i, &_14$$8, PH_COPY | PH_SEPARATE);

					try_end_1:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_17$$7);
						ZVAL_OBJ(&_17$$7, EG(exception));
						Z_ADDREF_P(&_17$$7);
						if (zephir_instance_of_ev(&_17$$7, zeplara_container_bindingresolutionexception_ce)) {
							zend_clear_exception(TSRMLS_C);
							ZEPHIR_CPY_WRT(&e, &_17$$7);
							ZEPHIR_CALL_METHOD(&_18$$9, &parameter, "isdefaultvalueavailable", NULL, 0);
							zephir_check_call_status();
							if (ZEPHIR_IS_FALSE_IDENTICAL(&_18$$9)) {
								zephir_throw_exception_debug(&e, "zeplara/Container/Container.zep", 277);
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&parameters, &i, &__$null, PH_COPY | PH_SEPARATE);
						}
					}
				}
			} else if (zephir_array_key_exists(&arguments, &_5$$3)) {
				_19$$11 = zephir_array_isset_long(&params, (zephir_get_numberval(&i) + 1));
				if (_19$$11) {
					ZEPHIR_CALL_METHOD(&_20$$11, &parameter, "isdefaultvalueavailable", NULL, 0);
					zephir_check_call_status();
					_21$$11 = zephir_is_true(&_20$$11);
					if (_21$$11) {
						ZEPHIR_CALL_METHOD(&_22$$11, &parameter, "isoptional", NULL, 0);
						zephir_check_call_status();
						_21$$11 = ZEPHIR_IS_FALSE_IDENTICAL(&_22$$11);
					}
					_19$$11 = _21$$11;
				}
				if (_19$$11) {
					ZEPHIR_CALL_METHOD(&_23$$12, &parameter, "getdefaultvalue", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&parameters, &i, &_23$$12, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch_long(&_24$$13, &arguments, index, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 288);
					zephir_array_update_zval(&parameters, &i, &_24$$13, PH_COPY | PH_SEPARATE);
					index++;
				}
			} else if (zephir_array_key_exists(&arguments, &i)) {
				_25$$14 = zephir_array_isset_long(&params, (zephir_get_numberval(&i) + 1));
				if (_25$$14) {
					ZEPHIR_CALL_METHOD(&_26$$14, &parameter, "isdefaultvalueavailable", NULL, 0);
					zephir_check_call_status();
					_27$$14 = zephir_is_true(&_26$$14);
					if (_27$$14) {
						ZEPHIR_CALL_METHOD(&_28$$14, &parameter, "isoptional", NULL, 0);
						zephir_check_call_status();
						_27$$14 = ZEPHIR_IS_FALSE_IDENTICAL(&_28$$14);
					}
					_25$$14 = _27$$14;
				}
				if (_25$$14) {
					ZEPHIR_CALL_METHOD(&_29$$15, &parameter, "getdefaultvalue", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&parameters, &i, &_29$$15, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch(&_30$$16, &arguments, &i, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 295);
					zephir_array_update_zval(&parameters, &i, &_30$$16, PH_COPY | PH_SEPARATE);
					index = (zephir_get_numberval(&i) + 1);
				}
			} else {
				ZEPHIR_CALL_METHOD(&_31$$17, &parameter, "isdefaultvalueavailable", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_31$$17)) {
					ZEPHIR_INIT_NVAR(&_32$$18);
					object_init_ex(&_32$$18, zeplara_container_bindingresolutionexception_ce);
					ZEPHIR_CALL_METHOD(NULL, &_32$$18, "__construct", &_33, 30, reflector, &parameter);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_32$$18, "zeplara/Container/Container.zep", 300);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_34$$17, &parameter, "getdefaultvalue", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&parameters, &i, &_34$$17, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &params, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &params, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&i, &params, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&parameter, &params, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&refClass, &parameter, "getclass", NULL, 0);
				zephir_check_call_status();
				zephir_read_property(&_35$$19, &parameter, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_36$$19, index);
				if (zephir_array_isset(&arguments, &_35$$19)) {
					ZEPHIR_OBS_NVAR(&_38$$20);
					zephir_read_property(&_38$$20, &parameter, ZEND_STRL("name"), PH_NOISY_CC);
					zephir_array_fetch(&_37$$20, &arguments, &_38$$20, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 267);
					zephir_array_update_zval(&parameters, &i, &_37$$20, PH_COPY | PH_SEPARATE);
				} else if (Z_TYPE_P(&refClass) != IS_NULL) {
					_39$$21 = zephir_array_isset_long(&arguments, index);
					if (_39$$21) {
						ZEPHIR_OBS_NVAR(&_40$$21);
						zephir_array_fetch_long(&_40$$21, &arguments, index, PH_NOISY, "zeplara/Container/Container.zep", 269);
						_39$$21 = Z_TYPE_P(&_40$$21) == IS_OBJECT;
					}
					_41$$21 = _39$$21;
					if (_41$$21) {
						ZEPHIR_OBS_NVAR(&_42$$21);
						zephir_array_fetch_long(&_42$$21, &arguments, index, PH_NOISY, "zeplara/Container/Container.zep", 269);
						ZEPHIR_OBS_NVAR(&_43$$21);
						zephir_read_property(&_43$$21, &refClass, ZEND_STRL("name"), PH_NOISY_CC);
						_41$$21 = zephir_is_instance_of(&_42$$21, Z_STRVAL_P(&_43$$21), Z_STRLEN_P(&_43$$21));
					}
					if (_41$$21) {
						zephir_array_fetch_long(&_44$$22, &arguments, index, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 270);
						zephir_array_update_zval(&parameters, &i, &_44$$22, PH_COPY | PH_SEPARATE);
						index++;
					} else {

						/* try_start_2: */

							zephir_read_property(&_46$$24, &refClass, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_METHOD(&_45$$24, this_ptr, "make", &_16, 22, &_46$$24);
							zephir_check_call_status_or_jump(try_end_2);
							zephir_array_update_zval(&parameters, &i, &_45$$24, PH_COPY | PH_SEPARATE);

						try_end_2:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_47$$23);
							ZVAL_OBJ(&_47$$23, EG(exception));
							Z_ADDREF_P(&_47$$23);
							if (zephir_instance_of_ev(&_47$$23, zeplara_container_bindingresolutionexception_ce)) {
								zend_clear_exception(TSRMLS_C);
								ZEPHIR_CPY_WRT(&e, &_47$$23);
								ZEPHIR_CALL_METHOD(&_48$$25, &parameter, "isdefaultvalueavailable", NULL, 0);
								zephir_check_call_status();
								if (ZEPHIR_IS_FALSE_IDENTICAL(&_48$$25)) {
									zephir_throw_exception_debug(&e, "zeplara/Container/Container.zep", 277);
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&parameters, &i, &__$null, PH_COPY | PH_SEPARATE);
							}
						}
					}
				} else if (zephir_array_key_exists(&arguments, &_36$$19)) {
					_49$$27 = zephir_array_isset_long(&params, (zephir_get_numberval(&i) + 1));
					if (_49$$27) {
						ZEPHIR_CALL_METHOD(&_50$$27, &parameter, "isdefaultvalueavailable", NULL, 0);
						zephir_check_call_status();
						_51$$27 = zephir_is_true(&_50$$27);
						if (_51$$27) {
							ZEPHIR_CALL_METHOD(&_52$$27, &parameter, "isoptional", NULL, 0);
							zephir_check_call_status();
							_51$$27 = ZEPHIR_IS_FALSE_IDENTICAL(&_52$$27);
						}
						_49$$27 = _51$$27;
					}
					if (_49$$27) {
						ZEPHIR_CALL_METHOD(&_53$$28, &parameter, "getdefaultvalue", NULL, 0);
						zephir_check_call_status();
						zephir_array_update_zval(&parameters, &i, &_53$$28, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_fetch_long(&_54$$29, &arguments, index, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 288);
						zephir_array_update_zval(&parameters, &i, &_54$$29, PH_COPY | PH_SEPARATE);
						index++;
					}
				} else if (zephir_array_key_exists(&arguments, &i)) {
					_55$$30 = zephir_array_isset_long(&params, (zephir_get_numberval(&i) + 1));
					if (_55$$30) {
						ZEPHIR_CALL_METHOD(&_56$$30, &parameter, "isdefaultvalueavailable", NULL, 0);
						zephir_check_call_status();
						_57$$30 = zephir_is_true(&_56$$30);
						if (_57$$30) {
							ZEPHIR_CALL_METHOD(&_58$$30, &parameter, "isoptional", NULL, 0);
							zephir_check_call_status();
							_57$$30 = ZEPHIR_IS_FALSE_IDENTICAL(&_58$$30);
						}
						_55$$30 = _57$$30;
					}
					if (_55$$30) {
						ZEPHIR_CALL_METHOD(&_59$$31, &parameter, "getdefaultvalue", NULL, 0);
						zephir_check_call_status();
						zephir_array_update_zval(&parameters, &i, &_59$$31, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_fetch(&_60$$32, &arguments, &i, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 295);
						zephir_array_update_zval(&parameters, &i, &_60$$32, PH_COPY | PH_SEPARATE);
						index = (zephir_get_numberval(&i) + 1);
					}
				} else {
					ZEPHIR_CALL_METHOD(&_61$$33, &parameter, "isdefaultvalueavailable", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_61$$33)) {
						ZEPHIR_INIT_NVAR(&_62$$34);
						object_init_ex(&_62$$34, zeplara_container_bindingresolutionexception_ce);
						ZEPHIR_CALL_METHOD(NULL, &_62$$34, "__construct", &_33, 30, reflector, &parameter);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_62$$34, "zeplara/Container/Container.zep", 300);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_63$$33, &parameter, "getdefaultvalue", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&parameters, &i, &_63$$33, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &params, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&parameter);
	ZEPHIR_INIT_NVAR(&i);
	if (zephir_is_true(&parameters)) {
		RETURN_CCTOR(&parameters);
	}
	RETURN_CTOR(&arguments);

}

/**
 * @param key
 * @param binding
 * @return mixed
 * @throws ReflectionException
 */
PHP_METHOD(Zeplara_Container_Container, resolveBinding) {

	zend_bool _0, _10$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *binding, binding_sub, _17, _18, _19, _1$$3, _2$$3, _3$$3, _4$$5, _5$$5, _7$$5, _8$$5, _9$$4, _11$$4, _12$$4, _13$$6, _14$$6, _15$$6, _16$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&binding_sub);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &binding);



	_0 = Z_TYPE_P(binding) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(binding, zend_ce_closure);
	}
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "call_user_func", NULL, 31, binding, this_ptr);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("bindingsResolved"), key, &_1$$3);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("bindingsResolved"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, key, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 324);
		RETURN_CTOR(&_3$$3);
	}
	if (Z_TYPE_P(binding) == IS_STRING) {
		if (ZEPHIR_IS_IDENTICAL(key, binding)) {
			zephir_read_property(&_4$$5, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_4$$5, key, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "make", &_6, 0, binding);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("bindingsResolved"), key, &_5$$5);
			zephir_update_property_array(this_ptr, SL("bindings"), key, binding);
			zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("bindingsResolved"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_8$$5, &_7$$5, key, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 333);
			RETURN_CTOR(&_8$$5);
		}
		zephir_read_property(&_9$$4, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
		_10$$4 = zephir_array_isset(&_9$$4, binding);
		if (_10$$4) {
			zephir_read_property(&_11$$4, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_12$$4, &_11$$4, binding, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 336);
			_10$$4 = ZEPHIR_IS_IDENTICAL(&_12$$4, key);
		}
		if (_10$$4) {
			zephir_read_property(&_13$$6, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_13$$6, binding, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "make", &_6, 22, binding);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("bindingsResolved"), key, &_14$$6);
			zephir_update_property_array(this_ptr, SL("aliasBindings"), binding, key);
			zephir_read_property(&_15$$6, this_ptr, ZEND_STRL("bindingsResolved"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_16$$6, &_15$$6, key, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 340);
			RETURN_CTOR(&_16$$6);
		}
	}
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "make", &_6, 22, binding);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("bindingsResolved"), key, &_17);
	zephir_read_property(&_18, this_ptr, ZEND_STRL("bindingsResolved"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_19, &_18, key, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 346);
	RETURN_CTOR(&_19);

}

/**
 * @param key
 * @return string
 */
PHP_METHOD(Zeplara_Container_Container, resolveKey) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, key) == 0;
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3, &_2, key, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 355);
		_1 = ZEPHIR_IS_IDENTICAL(key, &_3);
	}
	if (_1) {
		RETVAL_ZVAL(key, 1, 0);
		RETURN_MM();
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, key, PH_NOISY | PH_READONLY, "zeplara/Container/Container.zep", 359);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolvekey", NULL, 32, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Zeplara_Container_Container(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("bindingsResolved"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindingsResolved"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("bindingAliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindingAliases"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("aliasBindings"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("aliasBindings"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("bindings"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindings"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

