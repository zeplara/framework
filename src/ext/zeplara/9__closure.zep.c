
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(zeplara_9__closure) {

	ZEPHIR_REGISTER_CLASS(zeplara, 9__closure, zeplara, 9__closure, zeplara_9__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(zeplara_9__closure_ce, SL("values"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(zeplara_9__closure, __invoke) {

	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval values, *matches, matches_sub, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&matches_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&values, zeplara_9__closure_ce, SL("values"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &matches);



	zephir_array_fetch_long(&_2, matches, 1, PH_NOISY | PH_READONLY, "zeplara/Support/File/Parser/EnvParser.zep", 203);
	zephir_array_fetch_long(&_3, matches, 0, PH_NOISY | PH_READONLY, "zeplara/Support/File/Parser/EnvParser.zep", 203);
	ZEPHIR_CALL_CE_STATIC(&_0, zeplara_support_arr_ce, "get", &_1, 0, &values, &_2, &_3);
	zephir_check_call_status();
	zephir_get_strval(&_4, &_0);
	RETURN_CTOR(&_4);

}

