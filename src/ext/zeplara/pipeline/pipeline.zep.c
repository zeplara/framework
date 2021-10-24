
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Zeplara_Pipeline_Pipeline) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Pipeline, Pipeline, zeplara, pipeline_pipeline, zeplara_pipeline_pipeline_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var Container
	 */
	zend_declare_property_null(zeplara_pipeline_pipeline_ce, SL("container"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_pipeline_pipeline_ce, SL("pipes"), ZEND_ACC_PROTECTED);

	zeplara_pipeline_pipeline_ce->create_object = zephir_init_properties_Zeplara_Pipeline_Pipeline;

	zend_class_implements(zeplara_pipeline_pipeline_ce, 1, zeplara_interfaces_pipeline_pipeline_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Pipeline_Pipeline, getContainer) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 */
PHP_METHOD(Zeplara_Pipeline_Pipeline, getPipes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "pipes");

}

/**
 */
PHP_METHOD(Zeplara_Pipeline_Pipeline, setPipes) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *pipes_param = NULL;
	zval pipes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pipes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pipes_param);

	zephir_get_arrval(&pipes, pipes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("pipes"), &pipes);
	RETURN_THIS();

}

/**
 * Pipeline constructor.
 *
 * @param Container container
 * @param array pipes
 */
PHP_METHOD(Zeplara_Pipeline_Pipeline, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pipes;
	zval *container, container_sub, *pipes_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&pipes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &container, &pipes_param);

	if (!pipes_param) {
		ZEPHIR_INIT_VAR(&pipes);
		array_init(&pipes);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&pipes, pipes_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpipes", NULL, 138, &pipes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param pipe
 * @return void
 */
PHP_METHOD(Zeplara_Pipeline_Pipeline, addPipe) {

	zval *pipe, pipe_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pipe_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &pipe);



	zephir_update_property_array_append(this_ptr, SL("pipes"), pipe);

}

/**
 * @param callable destination
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Zeplara_Pipeline_Pipeline, send) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _2;
	zval *destination, destination_sub, *arguments_param = NULL, _0, _1, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &destination, &arguments_param);

	if (UNEXPECTED(zephir_is_callable(destination) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'destination' must be of the type callable"));
		RETURN_MM_NULL();
	}
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("pipes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "array_reverse", NULL, 139, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "reduceCallback");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_FUNCTION(&_4, "array_reduce", NULL, 140, &_1, &_2, destination);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_5, zeplara_support_arr_ce, "wrap", &_6, 0, &arguments);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param callable handler
 * @param pipe
 * @return Carry
 */
PHP_METHOD(Zeplara_Pipeline_Pipeline, reduceCallback) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler, handler_sub, *pipe = NULL, pipe_sub, _0$$3, _1$$3, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&pipe_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &handler, &pipe);

	if (UNEXPECTED(zephir_is_callable(handler) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be of the type callable"));
		RETURN_MM_NULL();
	}
	ZEPHIR_SEPARATE_PARAM(pipe);


	if (zephir_is_callable(pipe) == 0) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$3, &_0$$3, "make", NULL, 0, pipe);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(pipe, &_1$$3);
	}
	object_init_ex(return_value, zeplara_pipeline_carry_ce);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 141, &_2, handler, pipe);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Zeplara_Pipeline_Pipeline(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("pipes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("pipes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

