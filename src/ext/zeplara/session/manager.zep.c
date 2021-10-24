
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
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Zeplara_Session_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Session, Manager, zeplara, session_manager, zeplara_support_abstractrepository_ce, zeplara_session_manager_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_session_manager_ce, SL("id"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_session_manager_ce, SL("name"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_session_manager_ce, SL("prefix"), ZEND_ACC_PROTECTED);

	/**
	 * @var SessionHandlerInterface
	 */
	zend_declare_property_null(zeplara_session_manager_ce, SL("handler"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(zeplara_session_manager_ce, SL("started"), 0, ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_session_manager_ce, 1, zeplara_interfaces_session_manager_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Session_Manager, getId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "id");

}

/**
 */
PHP_METHOD(Zeplara_Session_Manager, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 */
PHP_METHOD(Zeplara_Session_Manager, getPrefix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "prefix");

}

/**
 */
PHP_METHOD(Zeplara_Session_Manager, getHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handler");

}

/**
 * Manager constructor.
 *
 * @param SessionHandlerInterface handler
 * @param name
 * @param string prefix
 * @param string id
 */
PHP_METHOD(Zeplara_Session_Manager, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler, handler_sub, *name, name_sub, *prefix = NULL, prefix_sub, *id = NULL, id_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&prefix_sub);
	ZVAL_UNDEF(&id_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &handler, &name, &prefix, &id);

	if (!prefix) {
		prefix = &prefix_sub;
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "");
	}
	if (!id) {
		id = &id_sub;
		ZEPHIR_INIT_VAR(id);
		ZVAL_STRING(id, "");
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), name);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprefix", NULL, 174, prefix);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setid", NULL, 175, id);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param id
 * @return void
 */
PHP_METHOD(Zeplara_Session_Manager, setId) {

	zend_bool _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_INIT_VAR(&_0);
	_1 = Z_TYPE_P(id) == IS_STRING;
	if (_1) {
		ZEPHIR_CALL_FUNCTION(&_2, "ctype_alnum", NULL, 176, id);
		zephir_check_call_status();
		_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	}
	_3 = _1;
	if (_3) {
		_3 = zephir_fast_strlen_ev(id) == 40;
	}
	if (_3) {
		ZEPHIR_CPY_WRT(&_0, id);
	} else {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "generatesessionid", NULL, 177);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("id"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string prefix
 * @return void
 */
PHP_METHOD(Zeplara_Session_Manager, setPrefix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prefix, prefix_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\/");
	zephir_fast_trim(&_0, prefix, &_1, ZEPHIR_TRIM_BOTH);
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Zeplara_Session_Manager, isStarted) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "started");

}

/**
 * @return void
 */
PHP_METHOD(Zeplara_Session_Manager, start) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, data, _1, _2, _3, _4, _5$$4, _6$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Cannot start the session already started.", "zeplara/Session/Manager.zep", 81);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_2, &_3);
	ZEPHIR_CALL_METHOD(&data, &_1, "read", NULL, 0, &_4);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING_IDENTICAL(&data, "")) {
		ZEPHIR_CALL_FUNCTION(NULL, "error_clear_last", NULL, 48);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_INIT_NVAR(&_5$$4);
		zephir_create_closure_ex(&_5$$4, NULL, zeplara_9__closure_ce, SL("__invoke"));
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 49, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_6$$4, "unserialize", NULL, 60, &data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&data, &_6$$4);
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setitems", NULL, 0, &data);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 55);
		zephir_check_call_status();
	}
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param bool destroy
 * @return bool
 */
PHP_METHOD(Zeplara_Session_Manager, regenerate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destroy = NULL, destroy_sub, __$false, _0, _5, _1$$4, _2$$4, _3$$4, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destroy_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &destroy);

	if (!destroy) {
		destroy = &destroy_sub;
		destroy = &__$false;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Cannot regenerate the session id before start the session.", "zeplara/Session/Manager.zep", 114);
		return;
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(destroy)) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_VV(&_4$$4, &_2$$4, &_3$$4);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "destroy", NULL, 0, &_4$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "generatesessionid", NULL, 177);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setid", NULL, 175, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return void
 */
PHP_METHOD(Zeplara_Session_Manager, save) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _1, _2, _3, _4, _5, _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Cannot save the session before start the session.", "zeplara/Session/Manager.zep", 130);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_2, &_3);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_6, "serialize", NULL, 51, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "write", NULL, 0, &_4, &_6);
	zephir_check_call_status();
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Zeplara_Session_Manager, generateSessionId) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 40);
	ZEPHIR_RETURN_CALL_CE_STATIC(zeplara_support_str_ce, "random", &_0, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

