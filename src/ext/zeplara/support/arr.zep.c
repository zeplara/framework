
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_Arr) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Support, Arr, zeplara, support_arr, zeplara_support_arr_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Zeplara_Support_Arr, __construct) {

	zval *this_ptr = getThis();



}

/**
 * @param value
 * @return array
 */
PHP_METHOD(Zeplara_Support_Arr, wrap) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value = NULL, value_sub, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	if (Z_TYPE_P(value) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_fast_append(&_0$$3, value);
		ZEPHIR_CPY_WRT(value, &_0$$3);
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * @param values
 * @param depth
 * @return array
 */
PHP_METHOD(Zeplara_Support_Arr, flatten) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values, values_sub, *depth = NULL, depth_sub, results, item, *_0, _1, nestedItem$$3, nestedValues$$3, *_5$$3, _6$$3, _3$$5, nestedItem$$9, nestedValues$$9, *_8$$9, _9$$9, _7$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&depth_sub);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&nestedItem$$3);
	ZVAL_UNDEF(&nestedValues$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&nestedItem$$9);
	ZVAL_UNDEF(&nestedValues$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_7$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values, &depth);

	if (!depth) {
		depth = &depth_sub;
		ZEPHIR_INIT_VAR(depth);
		ZVAL_LONG(depth, 512);
	}


	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	zephir_is_iterable(values, 0, "zeplara/Support/Arr.zep", 57);
	if (Z_TYPE_P(values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(values), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			if (Z_TYPE_P(&item) != IS_ARRAY) {
				zephir_array_append(&results, &item, PH_SEPARATE, "zeplara/Support/Arr.zep", 39);
				continue;
			}
			if (ZEPHIR_GT_LONG(depth, 0)) {
				ZVAL_LONG(&_3$$5, (zephir_get_numberval(depth) - 1));
				ZEPHIR_CALL_SELF(&nestedValues$$3, "flatten", &_2, 0, &item, &_3$$5);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_FUNCTION(&nestedValues$$3, "array_values", &_4, 146, &item);
				zephir_check_call_status();
			}
			zephir_is_iterable(&nestedValues$$3, 0, "zeplara/Support/Arr.zep", 55);
			if (Z_TYPE_P(&nestedValues$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&nestedValues$$3), _5$$3)
				{
					ZEPHIR_INIT_NVAR(&nestedItem$$3);
					ZVAL_COPY(&nestedItem$$3, _5$$3);
					zephir_array_append(&results, &nestedItem$$3, PH_SEPARATE, "zeplara/Support/Arr.zep", 52);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &nestedValues$$3, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_6$$3, &nestedValues$$3, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_6$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&nestedItem$$3, &nestedValues$$3, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_append(&results, &nestedItem$$3, PH_SEPARATE, "zeplara/Support/Arr.zep", 52);
					ZEPHIR_CALL_METHOD(NULL, &nestedValues$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&nestedItem$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, values, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&item) != IS_ARRAY) {
					zephir_array_append(&results, &item, PH_SEPARATE, "zeplara/Support/Arr.zep", 39);
					continue;
				}
				if (ZEPHIR_GT_LONG(depth, 0)) {
					ZVAL_LONG(&_7$$11, (zephir_get_numberval(depth) - 1));
					ZEPHIR_CALL_SELF(&nestedValues$$9, "flatten", &_2, 0, &item, &_7$$11);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_FUNCTION(&nestedValues$$9, "array_values", &_4, 146, &item);
					zephir_check_call_status();
				}
				zephir_is_iterable(&nestedValues$$9, 0, "zeplara/Support/Arr.zep", 55);
				if (Z_TYPE_P(&nestedValues$$9) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&nestedValues$$9), _8$$9)
					{
						ZEPHIR_INIT_NVAR(&nestedItem$$9);
						ZVAL_COPY(&nestedItem$$9, _8$$9);
						zephir_array_append(&results, &nestedItem$$9, PH_SEPARATE, "zeplara/Support/Arr.zep", 52);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &nestedValues$$9, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_9$$9, &nestedValues$$9, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_9$$9)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&nestedItem$$9, &nestedValues$$9, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_append(&results, &nestedItem$$9, PH_SEPARATE, "zeplara/Support/Arr.zep", 52);
						ZEPHIR_CALL_METHOD(NULL, &nestedValues$$9, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&nestedItem$$9);
			ZEPHIR_CALL_METHOD(NULL, values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&results);

}

/**
 * @param array values
 * @param key
 * @param null|mixed defaultValue
 * @return mixed
 */
PHP_METHOD(Zeplara_Support_Arr, get) {

	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_4 = NULL;
	zval *values, values_sub, *key = NULL, key_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0$$3, sgmnts, segments, _5, _6, _7$$6, _8$$6, _9$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&sgmnts);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &values, &key, &defaultValue);

	ZEPHIR_SEPARATE_PARAM(key);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	if (zephir_array_isset(values, key)) {
		zephir_array_fetch(&_0$$3, values, key, PH_NOISY | PH_READONLY, "zeplara/Support/Arr.zep", 69);
		RETURN_CTOR(&_0$$3);
	}
	ZEPHIR_CALL_SELF(&segments, "createsegmentsofkey", &_1, 147, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&sgmnts, &segments);
	while (1) {
		_2 = zephir_array_isset(values, key) == 0;
		if (_2) {
			_2 = zephir_fast_count_int(&sgmnts) > 1;
		}
		if (!(_2)) {
			break;
		}
		ZEPHIR_MAKE_REF(&sgmnts);
		ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_3, 148, &sgmnts);
		ZEPHIR_UNREF(&sgmnts);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(key, "implodesegmentsofkey", &_4, 149, &sgmnts);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_5, zephir_fast_count_int(&sgmnts));
	ZEPHIR_CALL_FUNCTION(&_6, "array_slice", NULL, 150, &segments, &_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&segments, &_6);
	if (zephir_array_isset(values, key)) {
		if (zephir_fast_count_int(&segments)) {
			zephir_array_fetch(&_7$$6, values, key, PH_NOISY | PH_READONLY, "zeplara/Support/Arr.zep", 86);
			ZEPHIR_CALL_SELF(&_8$$6, "implodesegmentsofkey", &_4, 149, &segments);
			zephir_check_call_status();
			ZEPHIR_RETURN_CALL_SELF("get", NULL, 0, &_7$$6, &_8$$6, defaultValue);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_array_fetch(&_9$$5, values, key, PH_NOISY | PH_READONLY, "zeplara/Support/Arr.zep", 89);
		RETURN_CTOR(&_9$$5);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * @param array values
 * @param key
 * @return bool
 */
PHP_METHOD(Zeplara_Support_Arr, has) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_3 = NULL;
	zval *values, values_sub, *key = NULL, key_sub, sgmnts, segments, _4, _5, _6$$6, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&sgmnts);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &values, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	if (zephir_array_isset(values, key)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_SELF(&segments, "createsegmentsofkey", &_0, 147, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&sgmnts, &segments);
	while (1) {
		_1 = zephir_array_isset(values, key) == 0;
		if (_1) {
			_1 = zephir_fast_count_int(&sgmnts) > 1;
		}
		if (!(_1)) {
			break;
		}
		ZEPHIR_MAKE_REF(&sgmnts);
		ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_2, 148, &sgmnts);
		ZEPHIR_UNREF(&sgmnts);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(key, "implodesegmentsofkey", &_3, 149, &sgmnts);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_4, zephir_fast_count_int(&sgmnts));
	ZEPHIR_CALL_FUNCTION(&_5, "array_slice", NULL, 150, &segments, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&segments, &_5);
	if (zephir_array_isset(values, key)) {
		if (zephir_fast_count_int(&segments)) {
			zephir_array_fetch(&_6$$6, values, key, PH_NOISY | PH_READONLY, "zeplara/Support/Arr.zep", 120);
			ZEPHIR_CALL_SELF(&_7$$6, "implodesegmentsofkey", &_3, 149, &segments);
			zephir_check_call_status();
			ZEPHIR_RETURN_CALL_SELF("has", NULL, 0, &_6$$6, &_7$$6);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * @param array values
 * @param key
 * @return array
 */
PHP_METHOD(Zeplara_Support_Arr, put) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_3 = NULL;
	zval *values, values_sub, *key = NULL, key_sub, sgmnts, segments, _4, _5, _6$$5, _7$$5, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&sgmnts);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &values, &key);

	ZEPHIR_SEPARATE_PARAM(values);
	ZEPHIR_SEPARATE_PARAM(key);


	zephir_array_unset(values, key, PH_SEPARATE);
	ZEPHIR_CALL_SELF(&segments, "createsegmentsofkey", &_0, 147, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&sgmnts, &segments);
	while (1) {
		_1 = zephir_array_isset(values, key) == 0;
		if (_1) {
			_1 = zephir_fast_count_int(&sgmnts) > 1;
		}
		if (!(_1)) {
			break;
		}
		ZEPHIR_MAKE_REF(&sgmnts);
		ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_2, 148, &sgmnts);
		ZEPHIR_UNREF(&sgmnts);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(key, "implodesegmentsofkey", &_3, 149, &sgmnts);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_4, zephir_fast_count_int(&sgmnts));
	ZEPHIR_CALL_FUNCTION(&_5, "array_slice", NULL, 150, &segments, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&segments, &_5);
	if (zephir_array_isset(values, key)) {
		if (zephir_fast_count_int(&segments)) {
			zephir_array_fetch(&_7$$5, values, key, PH_NOISY | PH_READONLY, "zeplara/Support/Arr.zep", 152);
			ZEPHIR_CALL_SELF(&_8$$5, "implodesegmentsofkey", &_3, 149, &segments);
			zephir_check_call_status();
			ZEPHIR_CALL_SELF(&_6$$5, "put", NULL, 0, &_7$$5, &_8$$5);
			zephir_check_call_status();
			zephir_array_update_zval(values, key, &_6$$5, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_unset(values, key, PH_SEPARATE);
		}
	}
	RETVAL_ZVAL(values, 1, 0);
	RETURN_MM();

}

/**
 * @param array values
 * @param key
 * @param value
 * @return array
 */
PHP_METHOD(Zeplara_Support_Arr, set) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_3 = NULL;
	zval *values, values_sub, *key = NULL, key_sub, *value, value_sub, sgmnts, segments, _4, _5, _6$$5, _7$$5, _8$$5, _9$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&sgmnts);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &values, &key, &value);

	ZEPHIR_SEPARATE_PARAM(values);
	ZEPHIR_SEPARATE_PARAM(key);


	if (zephir_array_isset(values, key)) {
		zephir_array_update_zval(values, key, value, PH_COPY | PH_SEPARATE);
		RETVAL_ZVAL(values, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_SELF(&segments, "createsegmentsofkey", &_0, 147, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&sgmnts, &segments);
	while (1) {
		_1 = zephir_array_isset(values, key) == 0;
		if (_1) {
			_1 = zephir_fast_count_int(&sgmnts) > 1;
		}
		if (!(_1)) {
			break;
		}
		ZEPHIR_MAKE_REF(&sgmnts);
		ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_2, 148, &sgmnts);
		ZEPHIR_UNREF(&sgmnts);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(key, "implodesegmentsofkey", &_3, 149, &sgmnts);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_4, zephir_fast_count_int(&sgmnts));
	ZEPHIR_CALL_FUNCTION(&_5, "array_slice", NULL, 150, &segments, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&segments, &_5);
	if (zephir_fast_count_int(&segments)) {
		ZEPHIR_INIT_VAR(&_8$$5);
		if (zephir_array_isset(values, key)) {
			ZEPHIR_OBS_NVAR(&_8$$5);
			zephir_array_fetch(&_8$$5, values, key, PH_NOISY, "zeplara/Support/Arr.zep", 188);
		} else {
			ZEPHIR_INIT_NVAR(&_8$$5);
			array_init(&_8$$5);
		}
		ZEPHIR_CALL_SELF(&_7$$5, "wrap", NULL, 0, &_8$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&_9$$5, "implodesegmentsofkey", &_3, 149, &segments);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&_6$$5, "set", NULL, 0, &_7$$5, &_9$$5, value);
		zephir_check_call_status();
		zephir_array_update_zval(values, key, &_6$$5, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_update_zval(values, key, value, PH_COPY | PH_SEPARATE);
	}
	RETVAL_ZVAL(values, 1, 0);
	RETURN_MM();

}

/**
 * @param array values
 * @param null defaultValue
 * @return mixed
 */
PHP_METHOD(Zeplara_Support_Arr, first) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values, values_sub, *defaultValue = NULL, defaultValue_sub, __$null, value, *_0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_is_iterable(values, 0, "zeplara/Support/Arr.zep", 209);
	if (Z_TYPE_P(values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(values), _0)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			RETURN_CCTOR(&value);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, values, "current", NULL, 0);
			zephir_check_call_status();
				RETURN_CCTOR(&value);
			ZEPHIR_CALL_METHOD(NULL, values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * @param array values
 * @param null defaultValue
 * @return mixed
 */
PHP_METHOD(Zeplara_Support_Arr, last) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values, values_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_FUNCTION(&_0, "array_reverse", NULL, 106, values);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("first", NULL, 0, &_0, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param key
 * @return array
 */
PHP_METHOD(Zeplara_Support_Arr, createSegmentsOfKey) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	zephir_get_strval(&_0, key);
	zephir_fast_explode_str(return_value, SL("."), &_0, LONG_MAX);
	RETURN_MM();

}

/**
 * @param array segments
 * @return string
 */
PHP_METHOD(Zeplara_Support_Arr, implodeSegmentsOfKey) {

	zval *segments, segments_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&segments_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &segments);



	zephir_fast_join_str(return_value, SL("."), segments);
	return;

}

