
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_Facades_Facade) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Support\\Facades, Facade, zeplara, support_facades_facade, zeplara_support_facades_facade_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Zeplara_Support_Facades_Facade, __construct) {

	zval *this_ptr = getThis();



}

/**
 * @throws RuntimeException
 */
PHP_METHOD(Zeplara_Support_Facades_Facade, getAccessor) {

	zval _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, spl_ce_RuntimeException);
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_called_class(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "%s class does not implement %s method.");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "getAccessor");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 2, &_3, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 8, &_5);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "zeplara/Support/Facades/Facade.zep", 20);
	ZEPHIR_MM_RESTORE();
	return;

}

