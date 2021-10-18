
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Zeplara_Container_InvalidAbstractException) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Container, InvalidAbstractException, zeplara, container_invalidabstractexception, spl_ce_InvalidArgumentException, zeplara_container_invalidabstractexception_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(zeplara_container_invalidabstractexception_ce, SL("abstract"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_container_invalidabstractexception_ce, 1, zeplara_contracts_container_invalidabstractexception_ce);
	return SUCCESS;

}

/**
 * @param $abstract
 */
PHP_METHOD(Zeplara_Container_InvalidAbstractException, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *abstract, abstract_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&abstract_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &abstract);



	zephir_update_property_zval(this_ptr, ZEND_STRL("abstract"), abstract);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Abstract is not provided.");
	ZEPHIR_CALL_PARENT(NULL, zeplara_container_invalidabstractexception_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return mixed
 */
PHP_METHOD(Zeplara_Container_InvalidAbstractException, getAbstract) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "abstract");

}

