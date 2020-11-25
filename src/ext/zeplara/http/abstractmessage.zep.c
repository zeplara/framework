
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
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_AbstractMessage) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Http, AbstractMessage, zeplara, http_abstractmessage, zeplara_http_abstractmessage_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var StreamInterface
	 */
	zend_declare_property_null(zeplara_http_abstractmessage_ce, SL("body"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_http_abstractmessage_ce, SL("headers"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_http_abstractmessage_ce, SL("protocolVersion"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_http_abstractmessage_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\messageinterface")));
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

/**
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

/**
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, getProtocolVersion) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "protocolVersion");

}

/**
 * @param StreamInterface body
 * @param array headers
 * @param string protocolVersion
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, __construct) {

	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval protocolVersion;
	zval headers;
	zval *body, body_sub, *headers_param = NULL, *protocolVersion_param = NULL, key, value, _0, *_1, _2, _5$$3, _7$$3, _9$$4, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&protocolVersion);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &body, &headers_param, &protocolVersion_param);

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertprotocolversion", NULL, 1, &protocolVersion);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("body"), body);
	zephir_update_property_zval(this_ptr, ZEND_STRL("protocolVersion"), &protocolVersion);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &_0);
	zephir_is_iterable(&headers, 0, "zeplara/Http/AbstractMessage.zep", 49);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_CALL_CE_STATIC(&_5$$3, zeplara_support_arr_ce, "wrap", &_6, 0, &value);
			zephir_check_call_status();
			ZEPHIR_CALL_CE_STATIC(&_7$$3, zeplara_support_str_ce, "kebab", &_8, 0, &key);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("headers"), &_7$$3, &_5$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&_9$$4, zeplara_support_arr_ce, "wrap", &_6, 0, &value);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&_10$$4, zeplara_support_str_ce, "kebab", &_8, 0, &key);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("headers"), &_10$$4, &_9$$4);
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param StreamInterface body
 * @return static
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, withBody) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *body, body_sub, clone;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&clone);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&clone, ZEND_STRL("body"), body);
	RETURN_CCTOR(&clone);

}

/**
 * @param string name
 * @return bool
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, hasHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *name, name_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_1, zeplara_support_str_ce, "kebab", &_2, 0, name);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * @param string name
 * @return array
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, getHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL;
	zval *name, name_sub, headers, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_OBS_VAR(&headers);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_1, zeplara_support_str_ce, "kebab", &_2, 0, name);
	zephir_check_call_status();
	if (zephir_array_isset_fetch(&headers, &_0, &_1, 0)) {
		ZEPHIR_RETURN_CALL_CE_STATIC(zeplara_support_arr_ce, "wrap", &_3, 0, &headers);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * @param string name
 * @return string
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, getHeaderLine) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *name, name_sub, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getheader", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, zeplara_support_arr_ce, "flatten", &_1, 0, &_2);
	zephir_check_call_status();
	zephir_fast_join_str(return_value, SL(", "), &_0);
	RETURN_MM();

}

/**
 * @param string name
 * @param value
 * @return static
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, withHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval *name = NULL, name_sub, *value, value_sub, clone, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);

	ZEPHIR_SEPARATE_PARAM(name);


	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_CE_STATIC(&_0, zeplara_support_str_ce, "kebab", &_1, 0, name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(name, &_0);
	ZEPHIR_CALL_CE_STATIC(&_0, zeplara_support_arr_ce, "wrap", &_2, 0, value);
	zephir_check_call_status();
	zephir_update_property_array(&clone, SL("headers"), name, &_0);
	RETURN_CCTOR(&clone);

}

/**
 * @param string name
 * @param value
 * @return static
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, withAddedHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getheader", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_2, zeplara_support_arr_ce, "wrap", &_3, 0, value);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &_2);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "withheader", NULL, 0, name, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string name
 * @return static
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, withoutHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *name, name_sub, clone, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &clone, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_1, zeplara_support_str_ce, "kebab", &_2, 0, name);
	zephir_check_call_status();
	zephir_array_unset(&_0, &_1, PH_SEPARATE);
	RETURN_CCTOR(&clone);

}

/**
 * @param string version
 * @return static
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, withProtocolVersion) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *version, version_sub, clone;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);
	ZVAL_UNDEF(&clone);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertprotocolversion", NULL, 1, version);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&clone, ZEND_STRL("protocolVersion"), version);
	RETURN_CCTOR(&clone);

}

/**
 * @param version
 * @return void
 */
PHP_METHOD(Zeplara_Http_AbstractMessage, assertProtocolVersion) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *version, version_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version);



	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "1.0");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "1.1");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "2.0");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "2");
	zephir_array_fast_append(&_0, &_1);
	if (!(zephir_fast_in_array(version, &_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The protocol version is invalid.", "zeplara/Http/AbstractMessage.zep", 160);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

