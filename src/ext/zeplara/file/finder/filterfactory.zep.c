
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Zeplara_File_Finder_FilterFactory) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\File\\Finder, FilterFactory, zeplara, file_finder_filterfactory, zeplara_file_finder_filterfactory_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, __construct) {

	zval *this_ptr = getThis();



}

/**
 * @return FileFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, file) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zeplara_file_finder_filefilter_ce);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * @return FileFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, files) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_SELF("file", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return IgnoreDotFileFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, ignoreDotFile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zeplara_file_finder_ignoredotfilefilter_ce);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * @return IgnoreDotFileFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, ignoreDotFiles) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_SELF("ignoredotfile", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param mixed extensions
 * @param int state
 * @return FileExtensionFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, extension) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *extensions, extensions_sub, *state = NULL, state_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extensions_sub);
	ZVAL_UNDEF(&state_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &extensions, &state);

	if (!state) {
		state = &state_sub;
		ZEPHIR_INIT_VAR(state);
		ZVAL_LONG(state, 1);
	}


	object_init_ex(return_value, zeplara_file_finder_fileextensionfilter_ce);
	ZEPHIR_CALL_CE_STATIC(&_0, zeplara_support_arr_ce, "wrap", &_1, 0, extensions);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 68, &_0, state);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param array extensions
 * @param int state
 * @return FileExtensionFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, extensions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *extensions_param = NULL, *state = NULL, state_sub;
	zval extensions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&state_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &extensions_param, &state);

	ZEPHIR_OBS_COPY_OR_DUP(&extensions, extensions_param);
	if (!state) {
		state = &state_sub;
		ZEPHIR_INIT_VAR(state);
		ZVAL_LONG(state, 1);
	}


	ZEPHIR_RETURN_CALL_SELF("extension", NULL, 0, &extensions, state);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return DirectoryFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, directory) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zeplara_file_finder_directoryfilter_ce);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * @return DirectoryFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, directories) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_SELF("directory", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return DirectoryFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, dir) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_SELF("directory", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return DirectoryFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, dirs) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_SELF("directory", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return ExecutableFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, executable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zeplara_file_finder_executablefilter_ce);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * @return LinkFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, link) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zeplara_file_finder_linkfilter_ce);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * @return LinkFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, links) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_SELF("link", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return ReadableFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, readable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zeplara_file_finder_readablefilter_ce);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * @return WritableFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, writable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zeplara_file_finder_writablefilter_ce);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * @param callable callback
 * @return CallbackFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, callback) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);

	if (UNEXPECTED(zephir_is_callable(callback) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'callback' must be of the type callable"));
		RETURN_MM_NULL();
	}


	object_init_ex(return_value, zeplara_file_finder_callbackfilter_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 69, callback);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param mixed time
 * @param string operator
 * @return DateFilter
 */
PHP_METHOD(Zeplara_File_Finder_FilterFactory, date) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *time, time_sub, *operator, operator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&time_sub);
	ZVAL_UNDEF(&operator_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &time, &operator);



	object_init_ex(return_value, zeplara_file_finder_datefilter_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 70, time, operator);
	zephir_check_call_status();
	RETURN_MM();

}

