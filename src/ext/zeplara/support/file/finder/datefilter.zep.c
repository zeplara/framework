
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_File_Finder_DateFilter) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Support\\File\\Finder, DateFilter, zeplara, support_file_finder_datefilter, zeplara_support_file_finder_abstractfilter_ce, zeplara_support_file_finder_datefilter_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(zeplara_support_file_finder_datefilter_ce, SL("time"), ZEND_ACC_PRIVATE);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_support_file_finder_datefilter_ce, SL("operator"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * DateFilter constructor.
 *
 * @param time
 * @param null operator
 */
PHP_METHOD(Zeplara_Support_File_Finder_DateFilter, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *time = NULL, time_sub, *operator = NULL, operator_sub, __$null, _0$$3, _1$$5, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&time_sub);
	ZVAL_UNDEF(&operator_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &time, &operator);

	ZEPHIR_SEPARATE_PARAM(time);
	if (!operator) {
		operator = &operator_sub;
		operator = &__$null;
	}


	if (zephir_is_numeric(time) == 0) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "strtotime", NULL, 40, time);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(time, &_0$$3);
		if (ZEPHIR_IS_FALSE_IDENTICAL(time)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The time is invalid type.", "zeplara/Support/File/Finder/DateFilter.zep", 29);
			return;
		}
	}
	if (zephir_is_instance_of(time, SL("DateTimeInterface"))) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "U");
		ZEPHIR_CALL_METHOD(&_1$$5, time, "format", NULL, 0, &_2$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(time, &_1$$5);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("time"), time);
	zephir_update_property_zval(this_ptr, ZEND_STRL("operator"), operator);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param SplFileInfo fileInfo
 * @return bool
 */
PHP_METHOD(Zeplara_Support_File_Finder_DateFilter, accept) {

	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fileInfo, fileInfo_sub, time, _0, _1$$3, _2$$4, _3$$5, _4$$6, _5$$7, _6$$8, _7$$9, _8$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileInfo_sub);
	ZVAL_UNDEF(&time);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fileInfo);



	ZEPHIR_CALL_METHOD(&time, fileInfo, "getmtime", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("operator"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_STRING(&_0, "<")) {
			zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("time"), PH_NOISY_CC | PH_READONLY);
			result = ZEPHIR_LT(&time, &_1$$3);
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, ">")) {
			zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("time"), PH_NOISY_CC | PH_READONLY);
			result = ZEPHIR_GT(&time, &_2$$4);
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "<=")) {
			zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("time"), PH_NOISY_CC | PH_READONLY);
			result = ZEPHIR_LE(&time, &_3$$5);
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, ">=")) {
			zephir_read_property(&_4$$6, this_ptr, ZEND_STRL("time"), PH_NOISY_CC | PH_READONLY);
			result = ZEPHIR_GE(&time, &_4$$6);
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "!=") || ZEPHIR_IS_STRING(&_0, "<>")) {
			zephir_read_property(&_5$$7, this_ptr, ZEND_STRL("time"), PH_NOISY_CC | PH_READONLY);
			result = !ZEPHIR_IS_EQUAL(&time, &_5$$7);
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "!==")) {
			zephir_read_property(&_6$$8, this_ptr, ZEND_STRL("time"), PH_NOISY_CC | PH_READONLY);
			result = !ZEPHIR_IS_IDENTICAL(&time, &_6$$8);
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "==")) {
			zephir_read_property(&_7$$9, this_ptr, ZEND_STRL("time"), PH_NOISY_CC | PH_READONLY);
			result = ZEPHIR_IS_EQUAL(&time, &_7$$9);
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "===")) {
			zephir_read_property(&_8$$10, this_ptr, ZEND_STRL("time"), PH_NOISY_CC | PH_READONLY);
			result = ZEPHIR_IS_IDENTICAL(&time, &_8$$10);
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The operator is invalid.", "zeplara/Support/File/Finder/DateFilter.zep", 78);
		return;
	} while(0);

	RETURN_MM_BOOL(result);

}

