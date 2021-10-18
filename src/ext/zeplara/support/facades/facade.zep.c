
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_Facades_Facade) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Support\\Facades, Facade, zeplara, support_facades_facade, zeplara_support_facades_facade_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(zeplara_support_facades_facade_ce, SL("container"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	return SUCCESS;

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Zeplara_Support_Facades_Facade, __construct) {

	zval *this_ptr = getThis();



}

/**
 * @param Container container
 * @return void
 */
PHP_METHOD(Zeplara_Support_Facades_Facade, setContainer) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &container);



	zephir_update_static_property_ce(zeplara_support_facades_facade_ce, ZEND_STRL("container"), container);

}

PHP_METHOD(Zeplara_Support_Facades_Facade, __callStatic) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval paramters;
	zval *name, name_sub, *paramters_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&paramters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &paramters_param);

	if (!paramters_param) {
		ZEPHIR_INIT_VAR(&paramters);
		array_init(&paramters);
	} else {
		zephir_get_arrval(&paramters, paramters_param);
	}



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
	zephir_throw_exception_debug(&_0, "zeplara/Support/Facades/Facade.zep", 37);
	ZEPHIR_MM_RESTORE();
	return;

}

