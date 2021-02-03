
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(zeplara_3__closure) {

	ZEPHIR_REGISTER_CLASS(zeplara, 3__closure, zeplara, 3__closure, zeplara_3__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(zeplara_3__closure, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *matches, matches_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matches_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches);



	zephir_array_fetch_long(&_0, matches, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 115);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "(?:%s)");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 2, &_1, &_0);
	zephir_check_call_status();
	RETURN_CCTOR(&_2);

}

