
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Zeplara_File_Finder_CallbackFilter) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\File\\Finder, CallbackFilter, zeplara, file_finder_callbackfilter, zeplara_file_finder_callbackfilter_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var callable
	 */
	zend_declare_property_null(zeplara_file_finder_callbackfilter_ce, SL("callback"), ZEND_ACC_PRIVATE);

	zend_class_implements(zeplara_file_finder_callbackfilter_ce, 1, zeplara_interfaces_file_finder_filter_ce);
	return SUCCESS;

}

/**
 * @param callable callback
 */
PHP_METHOD(Zeplara_File_Finder_CallbackFilter, __construct) {

	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &callback);

	if (UNEXPECTED(zephir_is_callable(callback) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'callback' must be of the type callable"));
		RETURN_NULL();
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("callback"), callback);

}

/**
 * @return bool
 */
PHP_METHOD(Zeplara_File_Finder_CallbackFilter, accept) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fileInfo, fileInfo_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileInfo_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fileInfo);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 32, &_0, fileInfo);
	zephir_check_call_status();
	RETURN_MM();

}

