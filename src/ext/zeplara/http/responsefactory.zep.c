
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_ResponseFactory) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Http, ResponseFactory, zeplara, http_responsefactory, zeplara_http_responsefactory_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_http_responsefactory_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\responsefactoryinterface")));
	return SUCCESS;

}

/**
 * @param int code
 * @param string reasonPhrase
 * @return ResponseInterface
 */
PHP_METHOD(Zeplara_Http_ResponseFactory, createResponse) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval reasonPhrase;
	zval *code_param = NULL, *reasonPhrase_param = NULL, _0;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&reasonPhrase);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &code_param, &reasonPhrase_param);

	if (!code_param) {
		code = 200;
	} else {
	if (UNEXPECTED(Z_TYPE_P(code_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'code' must be of the type int"));
		RETURN_MM_NULL();
	}
	code = Z_LVAL_P(code_param);
	}
	if (!reasonPhrase_param) {
		ZEPHIR_INIT_VAR(&reasonPhrase);
		ZVAL_STRING(&reasonPhrase, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(reasonPhrase_param) != IS_STRING && Z_TYPE_P(reasonPhrase_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'reasonPhrase' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(reasonPhrase_param) == IS_STRING)) {
		zephir_get_strval(&reasonPhrase, reasonPhrase_param);
	} else {
		ZEPHIR_INIT_VAR(&reasonPhrase);
		ZVAL_EMPTY_STRING(&reasonPhrase);
	}
	}


	ZVAL_LONG(&_0, code);
	ZEPHIR_RETURN_CALL_SELF("create", NULL, 0, &_0, &reasonPhrase);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param int code
 * @param string reasonPhrase
 * @param StreamInterface body
 * @param array headers
 * @param string protocolVersion
 * @return ResponseInterface
 */
PHP_METHOD(Zeplara_Http_ResponseFactory, create) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zval headers;
	zval reasonPhrase, protocolVersion;
	zval *code_param = NULL, *reasonPhrase_param = NULL, *body = NULL, body_sub, *headers_param = NULL, *protocolVersion_param = NULL, __$null, _1$$3, _2$$3, _3;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&reasonPhrase);
	ZVAL_UNDEF(&protocolVersion);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &code_param, &reasonPhrase_param, &body, &headers_param, &protocolVersion_param);

	if (!code_param) {
		code = 200;
	} else {
	if (UNEXPECTED(Z_TYPE_P(code_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'code' must be of the type int"));
		RETURN_MM_NULL();
	}
	code = Z_LVAL_P(code_param);
	}
	if (!reasonPhrase_param) {
		ZEPHIR_INIT_VAR(&reasonPhrase);
		ZVAL_STRING(&reasonPhrase, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(reasonPhrase_param) != IS_STRING && Z_TYPE_P(reasonPhrase_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'reasonPhrase' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(reasonPhrase_param) == IS_STRING)) {
		zephir_get_strval(&reasonPhrase, reasonPhrase_param);
	} else {
		ZEPHIR_INIT_VAR(&reasonPhrase);
		ZVAL_EMPTY_STRING(&reasonPhrase);
	}
	}
	if (!body) {
		body = &body_sub;
		ZEPHIR_CPY_WRT(body, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(body);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&headers, headers_param);
	}
	if (!protocolVersion_param) {
		ZEPHIR_INIT_VAR(&protocolVersion);
		ZVAL_STRING(&protocolVersion, "1.1");
	} else {
	if (UNEXPECTED(Z_TYPE_P(protocolVersion_param) != IS_STRING && Z_TYPE_P(protocolVersion_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'protocolVersion' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(protocolVersion_param) == IS_STRING)) {
		zephir_get_strval(&protocolVersion, protocolVersion_param);
	} else {
		ZEPHIR_INIT_VAR(&protocolVersion);
		ZVAL_EMPTY_STRING(&protocolVersion);
	}
	}


	if (Z_TYPE_P(body) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "php://temp");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "wb+");
		ZEPHIR_CALL_CE_STATIC(body, zeplara_http_streamfactory_ce, "create", &_0, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
	}
	object_init_ex(return_value, zeplara_http_response_ce);
	ZVAL_LONG(&_3, code);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 70, body, &_3, &reasonPhrase, &headers, &protocolVersion);
	zephir_check_call_status();
	RETURN_MM();

}

