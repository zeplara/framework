
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_RequestFactory) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Http, RequestFactory, zeplara, http_requestfactory, zeplara_http_requestfactory_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_http_requestfactory_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\requestfactoryinterface")));
	return SUCCESS;

}

/**
 * @param string method
 * @param string|UriInterface uri
 * @return RequestInterface
 */
PHP_METHOD(Zeplara_Http_RequestFactory, createRequest) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *uri, uri_sub;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &uri);

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


	ZEPHIR_RETURN_CALL_SELF("create", NULL, 0, &method, uri);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string method
 * @param string|UriInterface uri
 * @param StreamInterface body
 * @param array headers
 * @param string protocolVersion
 * @return RequestInterface
 */
PHP_METHOD(Zeplara_Http_RequestFactory, create) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval headers;
	zval *method_param = NULL, *uri = NULL, uri_sub, *body = NULL, body_sub, *headers_param = NULL, *protocolVersion_param = NULL, __$null, _0$$3, _3$$4, _4$$4;
	zval method, protocolVersion;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&protocolVersion);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&body_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &method_param, &uri, &body, &headers_param, &protocolVersion_param);

	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "GET");
	} else {
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
	}
	if (!uri) {
		uri = &uri_sub;
		ZEPHIR_CPY_WRT(uri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
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


	if ((zephir_is_instance_of(uri, SL("Psr\\Http\\Message\\UriInterface"))) == 0) {
		ZEPHIR_CALL_CE_STATIC(&_0$$3, zeplara_http_urifactory_ce, "create", &_1, 0, uri);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(uri, &_0$$3);
	}
	if (Z_TYPE_P(body) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "php://temp");
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "wb+");
		ZEPHIR_CALL_CE_STATIC(body, zeplara_http_streamfactory_ce, "create", &_2, 0, &_3$$4, &_4$$4);
		zephir_check_call_status();
	}
	object_init_ex(return_value, zeplara_http_request_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 66, &method, uri, body, &headers, &protocolVersion);
	zephir_check_call_status();
	RETURN_MM();

}

