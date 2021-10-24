
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/main.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(zeplara_1__closure) {

	ZEPHIR_REGISTER_CLASS(zeplara, 1__closure, zeplara, 1__closure, zeplara_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(zeplara_1__closure_ce, SL("line"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(zeplara_1__closure, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval line, _0, _1, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&line, zeplara_1__closure_ce, SL("line"), PH_NOISY_CC);

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zeplara_file_parser_parserexception_ce);
	ZEPHIR_INIT_VAR(&_3);
	zephir_get_args(&_3);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_CE_STATIC(&_1, zeplara_support_arr_ce, "get", &_2, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 9, &_1, &_5, &line);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "zeplara/File/Parser/EnvParser.zep", 195);
	ZEPHIR_MM_RESTORE();
	return;

}

