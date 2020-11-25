
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_Request) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Http, Request, zeplara, http_request, zeplara_http_abstractmessage_ce, zeplara_http_request_method_entry, 0);

	/**
	 * @var UriInterface 
	 */
	zend_declare_property_null(zeplara_http_request_ce, SL("uri"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_http_request_ce, SL("method"), ZEND_ACC_PROTECTED);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(zeplara_http_request_ce, SL("requestTarget"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_http_request_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\requestinterface")));
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Http_Request, getUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "uri");

}

/**
 */
PHP_METHOD(Zeplara_Http_Request, getMethod) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "method");

}

/**
 */
PHP_METHOD(Zeplara_Http_Request, getRequestTarget) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "requestTarget");

}

/**
 * @param string method
 * @param UriInterface uri
 * @param StreamInterface body
 * @param array headers
 * @param string protocolVersion
 */
PHP_METHOD(Zeplara_Http_Request, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval headers;
	zval *method_param = NULL, *uri, uri_sub, *body, body_sub, *headers_param = NULL, *protocolVersion_param = NULL;
	zval method, protocolVersion;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&protocolVersion);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &method_param, &uri, &body, &headers_param, &protocolVersion_param);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
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


	zephir_update_property_zval(this_ptr, ZEND_STRL("method"), &method);
	zephir_update_property_zval(this_ptr, ZEND_STRL("uri"), uri);
	ZEPHIR_CALL_PARENT(NULL, zeplara_http_request_ce, getThis(), "__construct", &_0, 0, body, &headers, &protocolVersion);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param requestTarget
 * @return static
 */
PHP_METHOD(Zeplara_Http_Request, withRequestTarget) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *requestTarget, requestTarget_sub, clone;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestTarget_sub);
	ZVAL_UNDEF(&clone);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &requestTarget);



	if (Z_TYPE_P(requestTarget) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The requestTarget should be string type.", "zeplara/Http/Request.zep", 52);
		return;
	}
	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&clone, ZEND_STRL("requestTarget"), requestTarget);
	RETURN_CCTOR(&clone);

}

/**
 * @param string method
 * @return static
 */
PHP_METHOD(Zeplara_Http_Request, withMethod) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *method, method_sub, clone;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&clone);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&clone, ZEND_STRL("method"), method);
	RETURN_CCTOR(&clone);

}

/**
 * @param UriInterface uri
 * @param bool preserveHost
 * @return static
 */
PHP_METHOD(Zeplara_Http_Request, withUri) {

	zend_bool _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri, uri_sub, *preserveHost = NULL, preserveHost_sub, __$false, clone, host, port$$3, _2$$3, _3$$3, _0$$4, _4$$5, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&preserveHost_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&port$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri, &preserveHost);

	if (!preserveHost) {
		preserveHost = &preserveHost_sub;
		preserveHost = &__$false;
	}


	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&clone, ZEND_STRL("uri"), uri);
	ZEPHIR_CALL_METHOD(&host, uri, "gethost", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING_IDENTICAL(&host, "")) {
		ZEPHIR_CALL_METHOD(&port$$3, uri, "getport", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&port$$3) != IS_NULL) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_CONCAT_SV(&_0$$4, ":", &port$$3);
			zephir_concat_self(&host, &_0$$4);
		}
		_1$$3 = ZEPHIR_IS_FALSE_IDENTICAL(preserveHost);
		if (!(_1$$3)) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "host");
			ZEPHIR_CALL_METHOD(&_2$$3, &clone, "hasheader", NULL, 0, &_3$$3);
			zephir_check_call_status();
			_1$$3 = ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3);
		}
		if (_1$$3) {
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "host");
			ZEPHIR_CALL_METHOD(&_4$$5, &clone, "withheader", NULL, 0, &_5$$5, &host);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&clone, &_4$$5);
		}
	}
	RETURN_CCTOR(&clone);

}

