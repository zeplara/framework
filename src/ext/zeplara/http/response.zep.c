
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_Response) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Http, Response, zeplara, http_response, zeplara_http_abstractmessage_ce, zeplara_http_response_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var int
	 */
	zend_declare_property_null(zeplara_http_response_ce, SL("statusCode"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_http_response_ce, SL("reasonPhrase"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_http_response_ce, SL("phrases"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_class_implements(zeplara_http_response_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\responseinterface")));
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Http_Response, getStatusCode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "statusCode");

}

/**
 */
PHP_METHOD(Zeplara_Http_Response, getReasonPhrase) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "reasonPhrase");

}

/**
 * Response constructor.
 *
 * @param StreamInterface body
 * @param int statusCode
 * @param string reasonPhrase
 * @param array headers
 * @param string protocolVersion
 */
PHP_METHOD(Zeplara_Http_Response, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval headers;
	zval reasonPhrase, protocolVersion;
	zend_long statusCode, ZEPHIR_LAST_CALL_STATUS;
	zval *body, body_sub, *statusCode_param = NULL, *reasonPhrase_param = NULL, *headers_param = NULL, *protocolVersion_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&reasonPhrase);
	ZVAL_UNDEF(&protocolVersion);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &body, &statusCode_param, &reasonPhrase_param, &headers_param, &protocolVersion_param);

	if (!statusCode_param) {
		statusCode = 200;
	} else {
	if (UNEXPECTED(Z_TYPE_P(statusCode_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statusCode' must be of the type int"));
		RETURN_MM_NULL();
	}
	statusCode = Z_LVAL_P(statusCode_param);
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
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&headers, headers_param);
	}
	if (!protocolVersion_param) {
		ZEPHIR_INIT_VAR(&protocolVersion);
		ZVAL_STRING(&protocolVersion, "1.0");
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


	ZVAL_LONG(&_0, statusCode);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertstatuscode", NULL, 67, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, statusCode);
	zephir_update_property_zval(this_ptr, ZEND_STRL("statusCode"), &_0);
	ZVAL_LONG(&_0, statusCode);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "filterreasonphrase", NULL, 68, &_0, &reasonPhrase);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("reasonPhrase"), &_1);
	ZEPHIR_CALL_PARENT(NULL, zeplara_http_response_ce, getThis(), "__construct", &_2, 0, body, &headers, &protocolVersion);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param statusCode
 * @param string reasonPhrase
 * @return static
 */
PHP_METHOD(Zeplara_Http_Response, withStatus) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statusCode, statusCode_sub, *reasonPhrase = NULL, reasonPhrase_sub, clone, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statusCode_sub);
	ZVAL_UNDEF(&reasonPhrase_sub);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statusCode, &reasonPhrase);

	if (!reasonPhrase) {
		reasonPhrase = &reasonPhrase_sub;
		ZEPHIR_INIT_VAR(reasonPhrase);
		ZVAL_STRING(reasonPhrase, "");
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertstatuscode", NULL, 67, statusCode);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&clone, ZEND_STRL("statusCode"), statusCode);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterreasonphrase", NULL, 68, statusCode, reasonPhrase);
	zephir_check_call_status();
	zephir_update_property_zval(&clone, ZEND_STRL("reasonPhrase"), &_0);
	RETURN_CCTOR(&clone);

}

/**
 * @param statusCode
 * @return void
 */
PHP_METHOD(Zeplara_Http_Response, assertStatusCode) {

	zend_bool _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statusCode, statusCode_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statusCode_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statusCode);



	ZVAL_LONG(&_0, 257);
	ZEPHIR_CALL_FUNCTION(&_1, "filter_var", NULL, 69, statusCode, &_0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	if (!(_2)) {
		_2 = ZEPHIR_LT_LONG(statusCode, 100);
	}
	_3 = _2;
	if (!(_3)) {
		_3 = ZEPHIR_GE_LONG(statusCode, 600);
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The status code must be integer value between 100 and 600.", "zeplara/Http/Response.zep", 131);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param int statusCode
 * @param string reasonPhrase
 */
PHP_METHOD(Zeplara_Http_Response, filterReasonPhrase) {

	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval reasonPhrase;
	zval *statusCode_param = NULL, *reasonPhrase_param = NULL, _0, _1, _3, _4$$3, _5$$3;
	zend_long statusCode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&reasonPhrase);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statusCode_param, &reasonPhrase_param);

	if (UNEXPECTED(Z_TYPE_P(statusCode_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statusCode' must be of the type int"));
		RETURN_MM_NULL();
	}
	statusCode = Z_LVAL_P(statusCode_param);
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


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, " ");
	zephir_fast_trim(&_0, &reasonPhrase, &_1, ZEPHIR_TRIM_BOTH);
	_2 = ZEPHIR_IS_STRING_IDENTICAL(&_0, "");
	if (_2) {
		zephir_read_static_property_ce(&_3, zeplara_http_response_ce, SL("phrases"), PH_NOISY_CC | PH_READONLY);
		_2 = zephir_array_isset_long(&_3, statusCode);
	}
	if (_2) {
		zephir_read_static_property_ce(&_4$$3, zeplara_http_response_ce, SL("phrases"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_5$$3, &_4$$3, statusCode, PH_NOISY | PH_READONLY, "zeplara/Http/Response.zep", 142);
		RETURN_CTOR(&_5$$3);
	}
	RETURN_CTOR(&reasonPhrase);

}

void zephir_init_static_properties_Zeplara_Http_Response(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 58, 0);
	add_index_stringl(&_0, 100, SL("Continue"));
	add_index_stringl(&_0, 101, SL("Switching Protocols"));
	add_index_stringl(&_0, 102, SL("Processing"));
	add_index_stringl(&_0, 200, SL("OK"));
	add_index_stringl(&_0, 201, SL("Created"));
	add_index_stringl(&_0, 202, SL("Accepted"));
	add_index_stringl(&_0, 203, SL("Non-Authoritative Information"));
	add_index_stringl(&_0, 204, SL("No Content"));
	add_index_stringl(&_0, 205, SL("Reset Content"));
	add_index_stringl(&_0, 206, SL("Partial Content"));
	add_index_stringl(&_0, 207, SL("Multi-status"));
	add_index_stringl(&_0, 208, SL("Already Reported"));
	add_index_stringl(&_0, 300, SL("Multiple Choices"));
	add_index_stringl(&_0, 301, SL("Moved Permanently"));
	add_index_stringl(&_0, 302, SL("Found"));
	add_index_stringl(&_0, 303, SL("See Other"));
	add_index_stringl(&_0, 304, SL("Not Modified"));
	add_index_stringl(&_0, 305, SL("Use Proxy"));
	add_index_stringl(&_0, 306, SL("Switch Proxy"));
	add_index_stringl(&_0, 307, SL("Temporary Redirect"));
	add_index_stringl(&_0, 400, SL("Bad Request"));
	add_index_stringl(&_0, 401, SL("Unauthorized"));
	add_index_stringl(&_0, 402, SL("Payment Required"));
	add_index_stringl(&_0, 403, SL("Forbidden"));
	add_index_stringl(&_0, 404, SL("Not Found"));
	add_index_stringl(&_0, 405, SL("Method Not Allowed"));
	add_index_stringl(&_0, 406, SL("Not Acceptable"));
	add_index_stringl(&_0, 407, SL("Proxy Authentication Required"));
	add_index_stringl(&_0, 408, SL("Request Time-out"));
	add_index_stringl(&_0, 409, SL("Conflict"));
	add_index_stringl(&_0, 410, SL("Gone"));
	add_index_stringl(&_0, 411, SL("Length Required"));
	add_index_stringl(&_0, 412, SL("Precondition Failed"));
	add_index_stringl(&_0, 413, SL("Request Entity Too Large"));
	add_index_stringl(&_0, 414, SL("Request-URI Too Large"));
	add_index_stringl(&_0, 415, SL("Unsupported Media Type"));
	add_index_stringl(&_0, 416, SL("Requested range not satisfiable"));
	add_index_stringl(&_0, 417, SL("Expectation Failed"));
	add_index_stringl(&_0, 418, SL("I'm a teapot"));
	add_index_stringl(&_0, 422, SL("Unprocessable Entity"));
	add_index_stringl(&_0, 423, SL("Locked"));
	add_index_stringl(&_0, 424, SL("Failed Dependency"));
	add_index_stringl(&_0, 425, SL("Unordered Collection"));
	add_index_stringl(&_0, 426, SL("Upgrade Required"));
	add_index_stringl(&_0, 428, SL("Precondition Required"));
	add_index_stringl(&_0, 429, SL("Too Many Requests"));
	add_index_stringl(&_0, 431, SL("Request Header Fields Too Large"));
	add_index_stringl(&_0, 451, SL("Unavailable For Legal Reasons"));
	add_index_stringl(&_0, 500, SL("Internal Server Error"));
	add_index_stringl(&_0, 501, SL("Not Implemented"));
	add_index_stringl(&_0, 502, SL("Bad Gateway"));
	add_index_stringl(&_0, 503, SL("Service Unavailable"));
	add_index_stringl(&_0, 504, SL("Gateway Time-out"));
	add_index_stringl(&_0, 505, SL("HTTP Version not supported"));
	add_index_stringl(&_0, 506, SL("Variant Also Negotiates"));
	add_index_stringl(&_0, 507, SL("Insufficient Storage"));
	add_index_stringl(&_0, 508, SL("Loop Detected"));
	add_index_stringl(&_0, 511, SL("Network Authentication Required"));
	zephir_update_static_property_ce(zeplara_http_response_ce, ZEND_STRL("phrases"), &_0);
	ZEPHIR_MM_RESTORE();

}

