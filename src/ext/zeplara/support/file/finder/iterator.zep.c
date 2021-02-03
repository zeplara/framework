
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_File_Finder_Iterator) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Support\\File\\Finder, Iterator, zeplara, support_file_finder_iterator, spl_ce_FilterIterator, zeplara_support_file_finder_iterator_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_support_file_finder_iterator_ce, SL("filters"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Support_File_Finder_Iterator, getFilters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "filters");

}

/**
 * @param IteratorContract iterator
 * @param array filters
 */
PHP_METHOD(Zeplara_Support_File_Finder_Iterator, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filters;
	zval *iterator, iterator_sub, *filters_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&iterator_sub);
	ZVAL_UNDEF(&filters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &iterator, &filters_param);

	ZEPHIR_OBS_COPY_OR_DUP(&filters, filters_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("filters"), &filters);
	ZEPHIR_CALL_PARENT(NULL, zeplara_support_file_finder_iterator_ce, getThis(), "__construct", NULL, 0, iterator);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Zeplara_Support_File_Finder_Iterator, accept) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "current", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "isaccepted", NULL, 169, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param SplFileInfo fileInfo
 * @return bool
 */
PHP_METHOD(Zeplara_Support_File_Finder_Iterator, isAccepted) {

	zend_bool _5$$3, _15$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_11 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fileInfo, fileInfo_sub, filter, _0, *_1, _2, _3$$4, _13$$3, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _14$$8, _21$$7, _16$$9, _17$$9, _18$$9, _19$$9, _20$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileInfo_sub);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fileInfo);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "zeplara/Support/File/Finder/Iterator.zep", 52);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&filter);
			ZVAL_COPY(&filter, _1);
			if (zephir_is_callable(&filter)) {
				ZEPHIR_CALL_CE_STATIC(&_3$$4, zeplara_support_file_finder_filterfactory_ce, "callback", &_4, 0, &filter);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filter, &_3$$4);
			}
			_5$$3 = Z_TYPE_P(&filter) != IS_OBJECT;
			if (!(_5$$3)) {
				_5$$3 = (zephir_instance_of_ev(&filter, zeplara_support_file_finder_abstractfilter_ce)) == 0;
			}
			if (_5$$3) {
				ZEPHIR_INIT_NVAR(&_6$$5);
				object_init_ex(&_6$$5, spl_ce_UnexpectedValueException);
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZVAL_STRING(&_8$$5, "The filter must be instanceof %s\\AbstractFilter");
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_STRING(&_9$$5, "Zeplara\\Support\\File\\Finder");
				ZEPHIR_CALL_FUNCTION(&_10$$5, "sprintf", &_11, 2, &_8$$5, &_9$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_12, 170, &_10$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$5, "zeplara/Support/File/Finder/Iterator.zep", 45);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_13$$3, &filter, "accept", NULL, 0, fileInfo);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_13$$3)) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&filter, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_is_callable(&filter)) {
					ZEPHIR_CALL_CE_STATIC(&_14$$8, zeplara_support_file_finder_filterfactory_ce, "callback", &_4, 0, &filter);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&filter, &_14$$8);
				}
				_15$$7 = Z_TYPE_P(&filter) != IS_OBJECT;
				if (!(_15$$7)) {
					_15$$7 = (zephir_instance_of_ev(&filter, zeplara_support_file_finder_abstractfilter_ce)) == 0;
				}
				if (_15$$7) {
					ZEPHIR_INIT_NVAR(&_16$$9);
					object_init_ex(&_16$$9, spl_ce_UnexpectedValueException);
					ZEPHIR_INIT_NVAR(&_18$$9);
					ZVAL_STRING(&_18$$9, "The filter must be instanceof %s\\AbstractFilter");
					ZEPHIR_INIT_NVAR(&_19$$9);
					ZVAL_STRING(&_19$$9, "Zeplara\\Support\\File\\Finder");
					ZEPHIR_CALL_FUNCTION(&_20$$9, "sprintf", &_11, 2, &_18$$9, &_19$$9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_16$$9, "__construct", &_12, 170, &_20$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_16$$9, "zeplara/Support/File/Finder/Iterator.zep", 45);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_21$$7, &filter, "accept", NULL, 0, fileInfo);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_21$$7)) {
					RETURN_MM_BOOL(0);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&filter);
	RETURN_MM_BOOL(1);

}

