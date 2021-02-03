
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
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_ServerRequest) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Http, ServerRequest, zeplara, http_serverrequest, zeplara_http_request_ce, zeplara_http_serverrequest_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_http_serverrequest_ce, SL("serverParams"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_http_serverrequest_ce, SL("cookieParams"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_http_serverrequest_ce, SL("queryParams"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_http_serverrequest_ce, SL("uploadedFiles"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_http_serverrequest_ce, SL("parsedBody"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_http_serverrequest_ce, SL("attributes"), ZEND_ACC_PROTECTED);

	zeplara_http_serverrequest_ce->create_object = zephir_init_properties_Zeplara_Http_ServerRequest;

	zend_class_implements(zeplara_http_serverrequest_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\serverrequestinterface")));
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Http_ServerRequest, getServerParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "serverParams");

}

/**
 */
PHP_METHOD(Zeplara_Http_ServerRequest, getCookieParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cookieParams");

}

/**
 */
PHP_METHOD(Zeplara_Http_ServerRequest, getQueryParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "queryParams");

}

/**
 */
PHP_METHOD(Zeplara_Http_ServerRequest, getUploadedFiles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "uploadedFiles");

}

/**
 */
PHP_METHOD(Zeplara_Http_ServerRequest, getParsedBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "parsedBody");

}

/**
 */
PHP_METHOD(Zeplara_Http_ServerRequest, getAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "attributes");

}

/**
 * @param string method
 * @param UriInterface uri
 * @param StreamInterface body
 * @param array serverParams
 * @param array parsedBody
 * @param array queryParams
 * @param array cookieParams
 * @param array uploadedFiles
 * @param array headers
 * @param string protocolVersion
 */
PHP_METHOD(Zeplara_Http_ServerRequest, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serverParams, parsedBody, queryParams, cookieParams, uploadedFiles, headers;
	zval *method_param = NULL, *uri, uri_sub, *body, body_sub, *serverParams_param = NULL, *parsedBody_param = NULL, *queryParams_param = NULL, *cookieParams_param = NULL, *uploadedFiles_param = NULL, *headers_param = NULL, *protocolVersion_param = NULL;
	zval method, protocolVersion;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&protocolVersion);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&serverParams);
	ZVAL_UNDEF(&parsedBody);
	ZVAL_UNDEF(&queryParams);
	ZVAL_UNDEF(&cookieParams);
	ZVAL_UNDEF(&uploadedFiles);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 7, &method_param, &uri, &body, &serverParams_param, &parsedBody_param, &queryParams_param, &cookieParams_param, &uploadedFiles_param, &headers_param, &protocolVersion_param);

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
	if (!serverParams_param) {
		ZEPHIR_INIT_VAR(&serverParams);
		array_init(&serverParams);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&serverParams, serverParams_param);
	}
	if (!parsedBody_param) {
		ZEPHIR_INIT_VAR(&parsedBody);
		array_init(&parsedBody);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&parsedBody, parsedBody_param);
	}
	if (!queryParams_param) {
		ZEPHIR_INIT_VAR(&queryParams);
		array_init(&queryParams);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&queryParams, queryParams_param);
	}
	if (!cookieParams_param) {
		ZEPHIR_INIT_VAR(&cookieParams);
		array_init(&cookieParams);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&cookieParams, cookieParams_param);
	}
	if (!uploadedFiles_param) {
		ZEPHIR_INIT_VAR(&uploadedFiles);
		array_init(&uploadedFiles);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&uploadedFiles, uploadedFiles_param);
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertuploadedfiles", NULL, 71, &uploadedFiles);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("serverParams"), &serverParams);
	zephir_update_property_zval(this_ptr, ZEND_STRL("parsedBody"), &parsedBody);
	zephir_update_property_zval(this_ptr, ZEND_STRL("queryParams"), &queryParams);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cookieParams"), &cookieParams);
	zephir_update_property_zval(this_ptr, ZEND_STRL("uploadedFiles"), &uploadedFiles);
	ZEPHIR_CALL_PARENT(NULL, zeplara_http_serverrequest_ce, getThis(), "__construct", &_0, 0, &method, uri, body, &headers, &protocolVersion);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param array cookies
 * @return static
 */
PHP_METHOD(Zeplara_Http_ServerRequest, withCookieParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *cookies_param = NULL, clone;
	zval cookies;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&clone);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cookies_param);

	ZEPHIR_OBS_COPY_OR_DUP(&cookies, cookies_param);


	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&clone, ZEND_STRL("cookieParams"), &cookies);
	RETURN_CCTOR(&clone);

}

/**
 * @param array query
 * @return static
 */
PHP_METHOD(Zeplara_Http_ServerRequest, withQueryParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *query_param = NULL, clone;
	zval query;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&clone);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);

	ZEPHIR_OBS_COPY_OR_DUP(&query, query_param);


	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&clone, ZEND_STRL("queryParams"), &query);
	RETURN_CCTOR(&clone);

}

/**
 * @param array files
 * @return static
 */
PHP_METHOD(Zeplara_Http_ServerRequest, withUploadedFiles) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *files_param = NULL, clone;
	zval files;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&clone);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &files_param);

	ZEPHIR_OBS_COPY_OR_DUP(&files, files_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertuploadedfiles", NULL, 71, &files);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&clone, ZEND_STRL("uploadedFiles"), &files);
	RETURN_CCTOR(&clone);

}

/**
 * @param array parsedBody
 * @return static
 */
PHP_METHOD(Zeplara_Http_ServerRequest, withParsedBody) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *parsedBody, parsedBody_sub, clone;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parsedBody_sub);
	ZVAL_UNDEF(&clone);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parsedBody);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&clone, ZEND_STRL("parsedBody"), parsedBody);
	RETURN_CCTOR(&clone);

}

/**
 * @param name
 * @param null defaultValue
 * @return static
 */
PHP_METHOD(Zeplara_Http_ServerRequest, getAttribute) {

	zval *name, name_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	zephir_fetch_params_without_memory_grow(1, 1, &name, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, name))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_2, &_1, name, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequest.zep", 139);
	RETURN_CTORW(&_2);

}

/**
 * @param name
 * @param value
 * @return static
 */
PHP_METHOD(Zeplara_Http_ServerRequest, withAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name, name_sub, *value, value_sub, clone;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&clone);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_array(&clone, SL("attributes"), name, value);
	RETURN_CCTOR(&clone);

}

/**
 * @param name
 * @return static
 */
PHP_METHOD(Zeplara_Http_ServerRequest, withoutAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name, name_sub, clone, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &clone, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, name, PH_SEPARATE);
	RETURN_CCTOR(&clone);

}

/**
 * @var array uploadedFiles
 * @return void
 */
PHP_METHOD(Zeplara_Http_ServerRequest, assertUploadedFiles) {

	zend_bool _4$$3, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *uploadedFiles = NULL, uploadedFiles_sub, uploadedFile, _0, *_2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uploadedFiles_sub);
	ZVAL_UNDEF(&uploadedFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uploadedFiles);

	ZEPHIR_SEPARATE_PARAM(uploadedFiles);


	ZEPHIR_CALL_CE_STATIC(&_0, zeplara_support_arr_ce, "flatten", &_1, 0, uploadedFiles);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(uploadedFiles, &_0);
	zephir_is_iterable(uploadedFiles, 0, "zeplara/Http/ServerRequest.zep", 185);
	if (Z_TYPE_P(uploadedFiles) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(uploadedFiles), _2)
		{
			ZEPHIR_INIT_NVAR(&uploadedFile);
			ZVAL_COPY(&uploadedFile, _2);
			_4$$3 = Z_TYPE_P(&uploadedFile) != IS_OBJECT;
			if (!(_4$$3)) {
				_4$$3 = (zephir_instance_of_ev(&uploadedFile, zeplara_http_uploadedfile_ce)) == 0;
			}
			if (_4$$3) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The uploadedFiles values should be instance of \\Zeplara\\Http\\UploadedFile::class", "zeplara/Http/ServerRequest.zep", 182);
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, uploadedFiles, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, uploadedFiles, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&uploadedFile, uploadedFiles, "current", NULL, 0);
			zephir_check_call_status();
				_5$$5 = Z_TYPE_P(&uploadedFile) != IS_OBJECT;
				if (!(_5$$5)) {
					_5$$5 = (zephir_instance_of_ev(&uploadedFile, zeplara_http_uploadedfile_ce)) == 0;
				}
				if (_5$$5) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The uploadedFiles values should be instance of \\Zeplara\\Http\\UploadedFile::class", "zeplara/Http/ServerRequest.zep", 182);
					return;
				}
			ZEPHIR_CALL_METHOD(NULL, uploadedFiles, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&uploadedFile);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Zeplara_Http_ServerRequest(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

