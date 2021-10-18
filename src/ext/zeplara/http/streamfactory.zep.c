
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_StreamFactory) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Http, StreamFactory, zeplara, http_streamfactory, zeplara_http_streamfactory_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_http_streamfactory_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\streamfactoryinterface")));
	return SUCCESS;

}

/**
 * @param string content
 * @return StreamInterface
 */
PHP_METHOD(Zeplara_Http_StreamFactory, createStream) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, stream, _0, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&stream);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &content_param);

	if (!content_param) {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_STRING(&content, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(&content, content_param);
	} else {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_EMPTY_STRING(&content);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://temp");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "wb+");
	ZEPHIR_CALL_METHOD(&stream, this_ptr, "createstreamfromfile", NULL, 122, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &stream, "write", NULL, 0, &content);
	zephir_check_call_status();
	RETURN_CCTOR(&stream);

}

/**
 * @param string filename
 * @param string mode
 * @return StreamInterface
 */
PHP_METHOD(Zeplara_Http_StreamFactory, createStreamFromFile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filename_param = NULL, *mode_param = NULL, handler, _0, _1;
	zval filename, mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filename_param, &mode_param);

	if (UNEXPECTED(Z_TYPE_P(filename_param) != IS_STRING && Z_TYPE_P(filename_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filename' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filename_param) == IS_STRING)) {
		zephir_get_strval(&filename, filename_param);
	} else {
		ZEPHIR_INIT_VAR(&filename);
		ZVAL_EMPTY_STRING(&filename);
	}
	if (!mode_param) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_STRING(&mode, "r");
	} else {
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(&mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_EMPTY_STRING(&mode);
	}
	}


	ZEPHIR_CALL_FUNCTION(NULL, "error_clear_last", NULL, 48);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, zeplara_3__closure_ce, SL("__invoke"));
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 49, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&handler, "fopen", NULL, 123, &filename, &mode);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 55);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&handler)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The file couldn't be opened.", "zeplara/Http/StreamFactory.zep", 43);
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "createstreamfromresource", NULL, 124, &handler);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param resource $resource
 * @return StreamInterface
 */
PHP_METHOD(Zeplara_Http_StreamFactory, createStreamFromResource) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resource, resource_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resource_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);



	object_init_ex(return_value, zeplara_http_stream_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 125, resource);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string|resource filenameOrResourceOrContent
 * @param string|null mode
 * @return StreamInterface
 */
PHP_METHOD(Zeplara_Http_StreamFactory, create) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filenameOrResourceOrContent, filenameOrResourceOrContent_sub, *mode = NULL, mode_sub, __$null, newSelf;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filenameOrResourceOrContent_sub);
	ZVAL_UNDEF(&mode_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&newSelf);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filenameOrResourceOrContent, &mode);

	if (!mode) {
		mode = &mode_sub;
		mode = &__$null;
	}


	ZEPHIR_INIT_VAR(&newSelf);
	object_init_ex(&newSelf, zeplara_http_streamfactory_ce);
	if (zephir_has_constructor(&newSelf)) {
		ZEPHIR_CALL_METHOD(NULL, &newSelf, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(filenameOrResourceOrContent) == IS_RESOURCE) {
		ZEPHIR_RETURN_CALL_METHOD(&newSelf, "createstreamfromresource", NULL, 124, filenameOrResourceOrContent);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(filenameOrResourceOrContent) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The filenameOrResourceOrContent must be string or resource type.", "zeplara/Http/StreamFactory.zep", 74);
		return;
	}
	if (Z_TYPE_P(mode) == IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(&newSelf, "createstream", NULL, 126, filenameOrResourceOrContent);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(&newSelf, "createstreamfromfile", NULL, 122, filenameOrResourceOrContent, mode);
	zephir_check_call_status();
	RETURN_MM();

}

