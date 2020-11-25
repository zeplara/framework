
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Zeplara_Session_CookieSessionHandler) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Session, CookieSessionHandler, zeplara, session_cookiesessionhandler, zeplara_session_cookiesessionhandler_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var Queue
	 */
	zend_declare_property_null(zeplara_session_cookiesessionhandler_ce, SL("queue"), ZEND_ACC_PRIVATE);

	/**
	 * @var ServerRequestInterface
	 */
	zend_declare_property_null(zeplara_session_cookiesessionhandler_ce, SL("request"), ZEND_ACC_PRIVATE);

	zend_class_implements(zeplara_session_cookiesessionhandler_ce, 1, zephir_get_internal_ce(SL("sessionhandlerinterface")));
	return SUCCESS;

}

/**
 * @param Queue queue
 * @param ServerRequestInterface request
 */
PHP_METHOD(Zeplara_Session_CookieSessionHandler, __construct) {

	zval *queue, queue_sub, *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&request_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &queue, &request);



	zephir_update_property_zval(this_ptr, ZEND_STRL("queue"), queue);
	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);

}

/**
 * @return bool
 */
PHP_METHOD(Zeplara_Session_CookieSessionHandler, close) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * @param int maxlifetime
 * @return bool
 */
PHP_METHOD(Zeplara_Session_CookieSessionHandler, gc) {

	zval *maxlifetime, maxlifetime_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &maxlifetime);



	RETURN_BOOL(1);

}

/**
 * @param string save_path
 * @param string name
 * @return bool
 */
PHP_METHOD(Zeplara_Session_CookieSessionHandler, open) {

	zval *save_path, save_path_sub, *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&save_path_sub);
	ZVAL_UNDEF(&name_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &save_path, &name);



	RETURN_BOOL(1);

}

/**
 * @param string session_id
 * @return mixed|string|null
 */
PHP_METHOD(Zeplara_Session_CookieSessionHandler, read) {

	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id, session_id_sub, cookie, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_id_sub);
	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &session_id);



	ZEPHIR_OBS_VAR(&cookie);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getcookieparams", NULL, 0);
	zephir_check_call_status();
	zephir_array_isset_fetch(&cookie, &_1, session_id, 0);
	zephir_get_strval(&_2, &cookie);
	RETURN_CTOR(&_2);

}

/**
 * @param string session_id
 * @param string session_data
 * @return bool
 */
PHP_METHOD(Zeplara_Session_CookieSessionHandler, write) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *session_id, session_id_sub, *session_data, session_data_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_id_sub);
	ZVAL_UNDEF(&session_data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &session_id, &session_data);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("queue"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_1, zeplara_cookie_factory_ce, "make", &_2, 0, session_id, session_data);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * @param string session_id
 * @return bool
 */
PHP_METHOD(Zeplara_Session_CookieSessionHandler, destroy) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *session_id, session_id_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_id_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &session_id);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("queue"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_1, zeplara_cookie_factory_ce, "forget", &_2, 0, session_id);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

