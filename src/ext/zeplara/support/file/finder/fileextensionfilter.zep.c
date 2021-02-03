
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_File_Finder_FileExtensionFilter) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Support\\File\\Finder, FileExtensionFilter, zeplara, support_file_finder_fileextensionfilter, zeplara_support_file_finder_abstractfilter_ce, zeplara_support_file_finder_fileextensionfilter_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_support_file_finder_fileextensionfilter_ce, SL("extensions"), ZEND_ACC_PRIVATE);

	/**
	 * @var int
	 */
	zend_declare_property_null(zeplara_support_file_finder_fileextensionfilter_ce, SL("state"), ZEND_ACC_PRIVATE);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(zeplara_support_file_finder_fileextensionfilter_ce, SL("EXPECTED"), 1);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(zeplara_support_file_finder_fileextensionfilter_ce, SL("NOT_EXPECTED"), 0);

	return SUCCESS;

}

/**
 * @param array extensions
 * @param int state
 */
PHP_METHOD(Zeplara_Support_File_Finder_FileExtensionFilter, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long state;
	zval *extensions_param = NULL, *state_param = NULL, _1, _2, _3;
	zval extensions, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &extensions_param, &state_param);

	ZEPHIR_OBS_COPY_OR_DUP(&extensions, extensions_param);
	if (!state_param) {
		state = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(state_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'state' must be of the type int"));
		RETURN_MM_NULL();
	}
	state = Z_LVAL_P(state_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 1);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_array_fast_append(&_0, &_1);
	ZVAL_LONG(&_2, state);
	if (zephir_fast_in_array(&_2, &_0) == 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The state is invalid.", "zeplara/Support/File/Finder/FileExtensionFilter.zep", 33);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("extensions"), &extensions);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(&_3, state);
	zephir_update_property_zval(this_ptr, ZEND_STRL("state"), &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param SplFileInfo fileInfo
 * @return bool
 */
PHP_METHOD(Zeplara_Support_File_Finder_FileExtensionFilter, accept) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fileInfo, fileInfo_sub, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileInfo_sub);
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
	ZVAL_UNDEF(&_11$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fileInfo);



	ZEPHIR_CALL_METHOD(&_0, fileInfo, "isfile", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("state"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_LONG_IDENTICAL(&_2$$3, 0)) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZEPHIR_CALL_METHOD(&_4$$3, fileInfo, "getextension", NULL, 0);
			zephir_check_call_status();
			zephir_fast_strtolower(&_3$$3, &_4$$3);
			zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_6$$3);
			ZVAL_STRING(&_6$$3, "strtolower");
			ZEPHIR_CALL_FUNCTION(&_7$$3, "array_map", NULL, 151, &_6$$3, &_5$$3);
			zephir_check_call_status();
			ZVAL_BOOL(&_1$$3, zephir_fast_in_array(&_3$$3, &_7$$3) == 0);
		} else {
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_CALL_METHOD(&_8$$3, fileInfo, "getextension", NULL, 0);
			zephir_check_call_status();
			zephir_fast_strtolower(&_6$$3, &_8$$3);
			zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_10$$3);
			ZVAL_STRING(&_10$$3, "strtolower");
			ZEPHIR_CALL_FUNCTION(&_11$$3, "array_map", NULL, 151, &_10$$3, &_9$$3);
			zephir_check_call_status();
			ZVAL_BOOL(&_1$$3, zephir_fast_in_array(&_6$$3, &_11$$3));
		}
		RETURN_CCTOR(&_1$$3);
	}
	RETURN_MM_BOOL(1);

}

