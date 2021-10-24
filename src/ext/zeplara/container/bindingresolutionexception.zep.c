
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Zeplara_Container_BindingResolutionException) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Container, BindingResolutionException, zeplara, container_bindingresolutionexception, zeplara_container_containerexception_ce, zeplara_container_bindingresolutionexception_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var Reflector
	 */
	zend_declare_property_null(zeplara_container_bindingresolutionexception_ce, SL("reflector"), ZEND_ACC_PROTECTED);

	/**
	 * @var ReflectionParameter
	 */
	zend_declare_property_null(zeplara_container_bindingresolutionexception_ce, SL("parameter"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_container_bindingresolutionexception_ce, 1, zeplara_interfaces_container_bindingresolutionexception_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Container_BindingResolutionException, getReflector) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "reflector");

}

/**
 */
PHP_METHOD(Zeplara_Container_BindingResolutionException, getParameter) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "parameter");

}

/**
 * @param Reflection reflector
 * @param ReflectionParameter parameter
 */
PHP_METHOD(Zeplara_Container_BindingResolutionException, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *reflector, reflector_sub, *parameter, parameter_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflector_sub);
	ZVAL_UNDEF(&parameter_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &reflector, &parameter);



	zephir_update_property_zval(this_ptr, ZEND_STRL("reflector"), reflector);
	zephir_update_property_zval(this_ptr, ZEND_STRL("parameter"), parameter);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSV(&_0, parameter, " ", reflector);
	ZEPHIR_CALL_PARENT(NULL, zeplara_container_bindingresolutionexception_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

