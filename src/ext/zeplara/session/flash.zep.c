
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Zeplara_Session_Flash) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Session, Flash, zeplara, session_flash, zeplara_support_repository_ce, zeplara_session_flash_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_session_flash_ce, SL("name"), ZEND_ACC_PROTECTED);

	/**
	 * @var Manager
	 */
	zend_declare_property_null(zeplara_session_flash_ce, SL("manager"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Session_Flash, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 */
PHP_METHOD(Zeplara_Session_Flash, getManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "manager");

}

/**
 * @param Manager manager
 * @param string name
 */
PHP_METHOD(Zeplara_Session_Flash, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *manager, manager_sub, *name, name_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &manager, &name);



	ZEPHIR_CALL_METHOD(&_0, manager, "isstarted", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The session is not started.", "zeplara/Session/Flash.zep", 26);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&_1, manager, "get", NULL, 0, name, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setitems", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, manager, "put", NULL, 0, name);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("manager"), manager);
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), name);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string key
 * @param value
 * @return void
 */
PHP_METHOD(Zeplara_Session_Flash, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key, key_sub, *value, value_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	ZEPHIR_CALL_PARENT(NULL, zeplara_session_flash_ce, getThis(), "set", &_0, 0, key, value);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "resolvekey", NULL, 145, key);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_2, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string key
 * @return string
 */
PHP_METHOD(Zeplara_Session_Flash, resolveKey) {

	zval *key, key_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &key);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VSV(return_value, &_0, ".", key);
	return;

}

