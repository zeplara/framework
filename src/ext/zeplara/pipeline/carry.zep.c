
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Zeplara_Pipeline_Carry) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Pipeline, Carry, zeplara, pipeline_carry, zeplara_pipeline_carry_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var callable
	 */
	zend_declare_property_null(zeplara_pipeline_carry_ce, SL("handler"), ZEND_ACC_PRIVATE);

	/**
	 * @var callable
	 */
	zend_declare_property_null(zeplara_pipeline_carry_ce, SL("pipe"), ZEND_ACC_PRIVATE);

	/**
	 * @var Container 
	 */
	zend_declare_property_null(zeplara_pipeline_carry_ce, SL("container"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * @param Container container
 * @param callable handler
 * @param callable pipe
 */
PHP_METHOD(Zeplara_Pipeline_Carry, __construct) {

	zval *container, container_sub, *handler, handler_sub, *pipe, pipe_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&pipe_sub);

	zephir_fetch_params_without_memory_grow(3, 0, &container, &handler, &pipe);

	if (UNEXPECTED(zephir_is_callable(handler) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be of the type callable"));
		RETURN_NULL();
	}
	if (UNEXPECTED(zephir_is_callable(pipe) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pipe' must be of the type callable"));
		RETURN_NULL();
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	zephir_update_property_zval(this_ptr, ZEND_STRL("pipe"), pipe);

}

/**
 * @return mixed
 */
PHP_METHOD(Zeplara_Pipeline_Carry, __invoke) {

	zval _1;
	zval args, _0, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_get_arrval(&_1, &_0);
	ZEPHIR_CPY_WRT(&args, &_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_array_append(&args, &_2, PH_SEPARATE, "zeplara/Pipeline/Carry.zep", 40);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("pipe"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_3, "make", NULL, 0, &_4, &args);
	zephir_check_call_status();
	RETURN_MM();

}

