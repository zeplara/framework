
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
#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(zeplara_6__closure) {

	ZEPHIR_REGISTER_CLASS(zeplara, 6__closure, zeplara, 6__closure, zeplara_6__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(zeplara_6__closure, __invoke) {

	zval args, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	zephir_get_args(&args);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zend_exception_get_default(TSRMLS_C));
	zephir_array_fetch_long(&_1, &args, 1, PH_NOISY | PH_READONLY, "zeplara/Support/File/Finder/FileFinder.zep", 145);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 65, &_1);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "zeplara/Support/File/Finder/FileFinder.zep", 145);
	ZEPHIR_MM_RESTORE();
	return;

}

