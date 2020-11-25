
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Zeplara_Session_FileSessionHandler) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Session, FileSessionHandler, zeplara, session_filesessionhandler, zeplara_session_filesessionhandler_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_session_filesessionhandler_ce, SL("path"), ZEND_ACC_PRIVATE);

	zend_class_implements(zeplara_session_filesessionhandler_ce, 1, zephir_get_internal_ce(SL("sessionhandlerinterface")));
	return SUCCESS;

}

/**
 * FileSessionHandler constructor.
 *
 * @param path
 */
PHP_METHOD(Zeplara_Session_FileSessionHandler, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, _0, _4, _5, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	ZEPHIR_CALL_FUNCTION(&_0, "is_writable", NULL, 138, path);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Directory %s is not writable");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 2, &_2$$3, path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "zeplara/Session/FileSessionHandler.zep", 24);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "\\/");
	zephir_fast_trim(&_4, path, &_5, ZEPHIR_TRIM_RIGHT);
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Zeplara_Session_FileSessionHandler, close) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * @param string session_id
 * @return bool
 */
PHP_METHOD(Zeplara_Session_FileSessionHandler, destroy) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id, session_id_sub, file, _0, _1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_id_sub);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &session_id);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&file);
	ZEPHIR_CONCAT_VSV(&file, &_0, "/", session_id);
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", NULL, 139, &file);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_FUNCTION(NULL, "error_clear_last", NULL, 47);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_create_closure_ex(&_2$$3, NULL, zeplara_3__closure_ce, SL("__invoke"));
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 48, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 140, &file);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 54);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * @param int maxlifetime
 * @return bool
 */
PHP_METHOD(Zeplara_Session_FileSessionHandler, gc) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL;
	zval *maxlifetime, maxlifetime_sub, file, files, _0, _2, _3, _4, _5, _6, *_7, _8, _9$$3, _11$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &maxlifetime);



	zephir_read_property(&_2, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_0, zeplara_support_file_finder_filefinder_ce, "instance", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &_0, "ignoredotfiles", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_3, "files", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_time(&_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_sub_function(&_6, &_5, maxlifetime);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "<=");
	ZEPHIR_CALL_METHOD(&files, &_4, "date", NULL, 0, &_6, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "error_clear_last", NULL, 47);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	ZEPHIR_INIT_NVAR(&_5);
	zephir_create_closure_ex(&_5, NULL, zeplara_4__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 48, &_5);
	zephir_check_call_status();
	zephir_is_iterable(&files, 0, "zeplara/Session/FileSessionHandler.zep", 86);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _7)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _7);
			ZEPHIR_CALL_METHOD(&_9$$3, &file, "getrealpath", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_10, 140, &_9$$3);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &files, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_11$$4, &file, "getrealpath", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_10, 140, &_11$$4);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 54);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * @param string save_path
 * @param string name
 * @return bool
 */
PHP_METHOD(Zeplara_Session_FileSessionHandler, open) {

	zval *save_path, save_path_sub, *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&save_path_sub);
	ZVAL_UNDEF(&name_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &save_path, &name);



	RETURN_BOOL(1);

}

/**
 * @param string session_id
 * @return string
 */
PHP_METHOD(Zeplara_Session_FileSessionHandler, read) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id, session_id_sub, file, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_id_sub);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &session_id);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&file);
	ZEPHIR_CONCAT_VSV(&file, &_0, "/", session_id);
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", NULL, 139, &file);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		RETURN_MM_STRING("");
	}
	zephir_file_get_contents(return_value, &file);
	RETURN_MM();

}

/**
 * @param string session_id
 * @param string session_data
 * @return bool
 */
PHP_METHOD(Zeplara_Session_FileSessionHandler, write) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id, session_id_sub, *session_data, session_data_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_id_sub);
	ZVAL_UNDEF(&session_data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &session_id, &session_data);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &_0, "/", session_id);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_FUNCTION(&_3, "file_put_contents", NULL, 141, &_1, session_data, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_3)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

