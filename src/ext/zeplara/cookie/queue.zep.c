
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Zeplara_Cookie_Queue) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Cookie, Queue, zeplara, cookie_queue, zeplara_cookie_queue_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_cookie_queue_ce, SL("cookies"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_cookie_queue_ce, 1, zeplara_contracts_cookie_queue_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Cookie_Queue, getCookies) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cookies");

}

/**
 * @param string key
 * @return bool
 */
PHP_METHOD(Zeplara_Cookie_Queue, has) {

	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &key);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, key));

}

/**
 * @param string key
 * @return Cookie
 */
PHP_METHOD(Zeplara_Cookie_Queue, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0, _5, _6, _1$$3, _2$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, key);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Cookie %s does not exists.");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 2, &_3$$3, key);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "zeplara/Cookie/Queue.zep", 30);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, key, PH_NOISY | PH_READONLY, "zeplara/Cookie/Queue.zep", 33);
	RETURN_CTOR(&_6);

}

/**
 * @param Cookie cookie
 * @return void
 */
PHP_METHOD(Zeplara_Cookie_Queue, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cookie, cookie_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookie_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cookie);



	ZEPHIR_CALL_METHOD(&_0, cookie, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("cookies"), &_0, cookie);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string key
 * @return void
 */
PHP_METHOD(Zeplara_Cookie_Queue, put) {

	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &key);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, key, PH_SEPARATE);

}

