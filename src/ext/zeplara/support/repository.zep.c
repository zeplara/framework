
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_Repository) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Support, Repository, zeplara, support_repository, zeplara_support_repository_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_support_repository_ce, SL("items"), ZEND_ACC_PROTECTED);

	zeplara_support_repository_ce->create_object = zephir_init_properties_Zeplara_Support_Repository;
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Support_Repository, getItems) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "items");

}

/**
 */
PHP_METHOD(Zeplara_Support_Repository, setItems) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *items_param = NULL;
	zval items;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&items);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &items_param);

	zephir_get_arrval(&items, items_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("items"), &items);
	RETURN_THIS();

}

/**
 * @param key
 * @return bool
 */
PHP_METHOD(Zeplara_Support_Repository, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key, key_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	zephir_read_property(&_1, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_CE_STATIC(zeplara_support_arr_ce, "has", &_0, 0, &_1, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param key
 * @param null defaultValue
 * @return mixed
 */
PHP_METHOD(Zeplara_Support_Repository, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key, key_sub, *defaultValue = NULL, defaultValue_sub, __$null, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_1, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_CE_STATIC(zeplara_support_arr_ce, "get", &_0, 0, &_1, key, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param key
 * @param value
 * @return void
 */
PHP_METHOD(Zeplara_Support_Repository, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *key, key_sub, *value, value_sub, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	zephir_read_property(&_2, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_0, zeplara_support_arr_ce, "set", &_1, 0, &_2, key, value);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("items"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param key
 * @return void
 */
PHP_METHOD(Zeplara_Support_Repository, put) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *key, key_sub, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	zephir_read_property(&_2, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_0, zeplara_support_arr_ce, "put", &_1, 0, &_2, key);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("items"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param offset
 * @return bool
 */
PHP_METHOD(Zeplara_Support_Repository, offsetExists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param offset
 * @return mixed
 */
PHP_METHOD(Zeplara_Support_Repository, offsetGet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param offset
 * @param value
 * @return void
 */
PHP_METHOD(Zeplara_Support_Repository, offsetSet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, offset, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param offset
 * @return void
 */
PHP_METHOD(Zeplara_Support_Repository, offsetUnset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "put", NULL, 0, offset);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string key
 * @return mixed
 */
PHP_METHOD(Zeplara_Support_Repository, __get) {

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
PHP_METHOD(Zeplara_Support_Repository, __isset) {

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
PHP_METHOD(Zeplara_Support_Repository, __set) {

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
PHP_METHOD(Zeplara_Support_Repository, __unset) {

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

zend_object *zephir_init_properties_Zeplara_Support_Repository(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("items"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

