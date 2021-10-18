
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_ServerRequestFactory) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Http, ServerRequestFactory, zeplara, http_serverrequestfactory, zeplara_http_serverrequestfactory_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_http_serverrequestfactory_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\serverrequestfactoryinterface")));
	return SUCCESS;

}

/**
 * @param string method
 * @param uri
 * @param array serverParams
 * @return ServerRequestInterface
 */
PHP_METHOD(Zeplara_Http_ServerRequestFactory, createServerRequest) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serverParams;
	zval *method_param = NULL, *uri, uri_sub, *serverParams_param = NULL, _0;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&serverParams);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &method_param, &uri, &serverParams_param);

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


	ZVAL_NULL(&_0);
	ZEPHIR_RETURN_CALL_SELF("create", NULL, 0, &method, uri, &_0, &serverParams);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string method
 * @param uri
 * @param array serverParams
 * @return ServerRequestInterface
 */
PHP_METHOD(Zeplara_Http_ServerRequestFactory, create) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_9 = NULL, *_12 = NULL, *_15 = NULL, *_17 = NULL;
	zval serverParams, parsedBody, queryParams, cookieParams, uploadedFiles, headers, _10$$10, _13$$11;
	zval *method_param = NULL, *uri = NULL, uri_sub, *body = NULL, body_sub, *serverParams_param = NULL, *parsedBody_param = NULL, *queryParams_param = NULL, *cookieParams_param = NULL, *uploadedFiles_param = NULL, *headers_param = NULL, *protocolVersion_param = NULL, _SERVER, _POST, _GET, _COOKIE, __$null, _0$$3, _1$$3, _3$$4, _6$$5, _7$$5, _8$$10, _11$$11, _14, _16, _18, _19;
	zval method, protocolVersion, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&protocolVersion);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&serverParams);
	ZVAL_UNDEF(&parsedBody);
	ZVAL_UNDEF(&queryParams);
	ZVAL_UNDEF(&cookieParams);
	ZVAL_UNDEF(&uploadedFiles);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_13$$11);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 10, &method_param, &uri, &body, &serverParams_param, &parsedBody_param, &queryParams_param, &cookieParams_param, &uploadedFiles_param, &headers_param, &protocolVersion_param);

	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "");
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
		ZVAL_STRING(&protocolVersion, "");
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


	if (ZEPHIR_IS_STRING_IDENTICAL(&method, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_array_isset_string(&_SERVER, SL("REQUEST_METHOD"))) {
			ZEPHIR_OBS_VAR(&_1$$3);
			zephir_array_fetch_string(&_1$$3, &_SERVER, SL("REQUEST_METHOD"), PH_NOISY, "zeplara/Http/ServerRequestFactory.zep", 43);
			zephir_get_strval(&_2$$3, &_1$$3);
			ZEPHIR_CPY_WRT(&_0$$3, &_2$$3);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "GET");
		}
		zephir_get_strval(&method, &_0$$3);
	}
	if ((zephir_is_instance_of(uri, SL("Psr\\Http\\Message\\UriInterface"))) == 0) {
		ZEPHIR_CALL_CE_STATIC(&_3$$4, zeplara_http_urifactory_ce, "create", &_4, 0, uri);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(uri, &_3$$4);
	}
	if (Z_TYPE_P(body) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "php://input");
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "r+");
		ZEPHIR_CALL_CE_STATIC(body, zeplara_http_streamfactory_ce, "create", &_5, 0, &_6$$5, &_7$$5);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(&serverParams)) {
		ZEPHIR_CPY_WRT(&serverParams, &_SERVER);
	}
	if (ZEPHIR_IS_EMPTY(&parsedBody)) {
		ZEPHIR_CPY_WRT(&parsedBody, &_POST);
	}
	if (ZEPHIR_IS_EMPTY(&queryParams)) {
		ZEPHIR_CPY_WRT(&queryParams, &_GET);
	}
	if (ZEPHIR_IS_EMPTY(&cookieParams)) {
		ZEPHIR_CPY_WRT(&cookieParams, &_COOKIE);
	}
	if (ZEPHIR_IS_EMPTY(&uploadedFiles)) {
		ZEPHIR_CALL_SELF(&_8$$10, "parseuploadedfiles", &_9, 104);
		zephir_check_call_status();
		zephir_get_arrval(&_10$$10, &_8$$10);
		ZEPHIR_CPY_WRT(&uploadedFiles, &_10$$10);
	}
	if (ZEPHIR_IS_EMPTY(&headers)) {
		ZEPHIR_CALL_SELF(&_11$$11, "getallheaders", &_12, 105);
		zephir_check_call_status();
		zephir_get_arrval(&_13$$11, &_11$$11);
		ZEPHIR_CPY_WRT(&headers, &_13$$11);
	}
	ZEPHIR_INIT_VAR(&_14);
	if (ZEPHIR_IS_STRING_IDENTICAL(&protocolVersion, "")) {
		ZEPHIR_CALL_SELF(&_16, "parseprotocolversion", &_17, 106);
		zephir_check_call_status();
		ZVAL_LONG(&_18, 1);
		ZEPHIR_INIT_VAR(&_19);
		ZVAL_STRING(&_19, "1.1");
		ZEPHIR_CALL_CE_STATIC(&_14, zeplara_support_arr_ce, "get", &_15, 0, &_16, &_18, &_19);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_14, &protocolVersion);
	}
	zephir_get_strval(&protocolVersion, &_14);
	object_init_ex(return_value, zeplara_http_serverrequest_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 107, &method, uri, body, &serverParams, &parsedBody, &queryParams, &cookieParams, &uploadedFiles, &headers, &protocolVersion);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param array files
 * @return array
 */
PHP_METHOD(Zeplara_Http_ServerRequestFactory, parseUploadedFiles) {

	zend_string *_3, *_9$$4, *_49$$11;
	zend_ulong _2, _8$$4, _48$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _FILES, files, key, value, *_0, _1, _4$$3, k$$4, v$$4, _5$$4, *_6$$4, _7$$4, _10$$6, _11$$5, _13$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5, _21$$5, _22$$5, _23$$5, _24$$8, _25$$7, _26$$7, _27$$7, _28$$7, _29$$7, _30$$7, _31$$7, _32$$7, _33$$7, _34$$7, _35$$7, _36$$9, _37$$9, _38$$9, _39$$9, _40$$9, _41$$9, _42$$9, _43$$9, _44$$10, k$$11, v$$11, _45$$11, *_46$$11, _47$$11, _50$$13, _51$$12, _52$$12, _53$$12, _54$$12, _55$$12, _56$$12, _57$$12, _58$$12, _59$$12, _60$$12, _61$$12, _62$$15, _63$$14, _64$$14, _65$$14, _66$$14, _67$$14, _68$$14, _69$$14, _70$$14, _71$$14, _72$$14, _73$$14, _74$$16, _75$$16, _76$$16, _77$$16, _78$$16, _79$$16, _80$$16, _81$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&k$$4);
	ZVAL_UNDEF(&v$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&k$$11);
	ZVAL_UNDEF(&v$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_47$$11);
	ZVAL_UNDEF(&_50$$13);
	ZVAL_UNDEF(&_51$$12);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_53$$12);
	ZVAL_UNDEF(&_54$$12);
	ZVAL_UNDEF(&_55$$12);
	ZVAL_UNDEF(&_56$$12);
	ZVAL_UNDEF(&_57$$12);
	ZVAL_UNDEF(&_58$$12);
	ZVAL_UNDEF(&_59$$12);
	ZVAL_UNDEF(&_60$$12);
	ZVAL_UNDEF(&_61$$12);
	ZVAL_UNDEF(&_62$$15);
	ZVAL_UNDEF(&_63$$14);
	ZVAL_UNDEF(&_64$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_66$$14);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_68$$14);
	ZVAL_UNDEF(&_69$$14);
	ZVAL_UNDEF(&_70$$14);
	ZVAL_UNDEF(&_71$$14);
	ZVAL_UNDEF(&_72$$14);
	ZVAL_UNDEF(&_73$$14);
	ZVAL_UNDEF(&_74$$16);
	ZVAL_UNDEF(&_75$$16);
	ZVAL_UNDEF(&_76$$16);
	ZVAL_UNDEF(&_77$$16);
	ZVAL_UNDEF(&_78$$16);
	ZVAL_UNDEF(&_79$$16);
	ZVAL_UNDEF(&_80$$16);
	ZVAL_UNDEF(&_81$$16);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));

	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	zephir_is_iterable(&_FILES, 0, "zeplara/Http/ServerRequestFactory.zep", 118);
	if (Z_TYPE_P(&_FILES) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_FILES), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_OBS_NVAR(&_4$$3);
			zephir_array_fetch_string(&_4$$3, &value, SL("error"), PH_NOISY, "zeplara/Http/ServerRequestFactory.zep", 93);
			if (Z_TYPE_P(&_4$$3) == IS_ARRAY) {
				zephir_array_fetch_string(&_5$$4, &value, SL("error"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 95);
				zephir_is_iterable(&_5$$4, 0, "zeplara/Http/ServerRequestFactory.zep", 107);
				if (Z_TYPE_P(&_5$$4) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_5$$4), _8$$4, _9$$4, _6$$4)
					{
						ZEPHIR_INIT_NVAR(&k$$4);
						if (_9$$4 != NULL) { 
							ZVAL_STR_COPY(&k$$4, _9$$4);
						} else {
							ZVAL_LONG(&k$$4, _8$$4);
						}
						ZEPHIR_INIT_NVAR(&v$$4);
						ZVAL_COPY(&v$$4, _6$$4);
						if (!(zephir_array_isset(&files, &key))) {
							ZEPHIR_INIT_NVAR(&_10$$6);
							array_init(&_10$$6);
							zephir_array_update_zval(&files, &key, &_10$$6, PH_COPY | PH_SEPARATE);
						}
						zephir_array_fetch_string(&_15$$5, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 100);
						zephir_array_fetch(&_16$$5, &_15$$5, &k$$4, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 100);
						ZEPHIR_INIT_NVAR(&_17$$5);
						ZVAL_STRING(&_17$$5, "r");
						ZEPHIR_CALL_CE_STATIC(&_13$$5, zeplara_http_streamfactory_ce, "create", &_14, 0, &_16$$5, &_17$$5);
						zephir_check_call_status();
						zephir_array_fetch_string(&_18$$5, &value, SL("size"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 101);
						zephir_array_fetch(&_19$$5, &_18$$5, &k$$4, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 101);
						zephir_array_fetch_string(&_20$$5, &value, SL("name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 103);
						zephir_array_fetch(&_21$$5, &_20$$5, &k$$4, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 103);
						zephir_array_fetch_string(&_22$$5, &value, SL("type"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 104);
						zephir_array_fetch(&_23$$5, &_22$$5, &k$$4, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 105);
						ZEPHIR_CALL_CE_STATIC(&_11$$5, zeplara_http_uploadedfilefactory_ce, "create", &_12, 0, &_13$$5, &_19$$5, &v$$4, &_21$$5, &_23$$5);
						zephir_check_call_status();
						zephir_array_update_multi(&files, &_11$$5, SL("za"), 2, &key);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_5$$4, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_7$$4, &_5$$4, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_7$$4)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&k$$4, &_5$$4, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&v$$4, &_5$$4, "current", NULL, 0);
						zephir_check_call_status();
							if (!(zephir_array_isset(&files, &key))) {
								ZEPHIR_INIT_NVAR(&_24$$8);
								array_init(&_24$$8);
								zephir_array_update_zval(&files, &key, &_24$$8, PH_COPY | PH_SEPARATE);
							}
							zephir_array_fetch_string(&_27$$7, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 100);
							zephir_array_fetch(&_28$$7, &_27$$7, &k$$4, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 100);
							ZEPHIR_INIT_NVAR(&_29$$7);
							ZVAL_STRING(&_29$$7, "r");
							ZEPHIR_CALL_CE_STATIC(&_26$$7, zeplara_http_streamfactory_ce, "create", &_14, 0, &_28$$7, &_29$$7);
							zephir_check_call_status();
							zephir_array_fetch_string(&_30$$7, &value, SL("size"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 101);
							zephir_array_fetch(&_31$$7, &_30$$7, &k$$4, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 101);
							zephir_array_fetch_string(&_32$$7, &value, SL("name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 103);
							zephir_array_fetch(&_33$$7, &_32$$7, &k$$4, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 103);
							zephir_array_fetch_string(&_34$$7, &value, SL("type"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 104);
							zephir_array_fetch(&_35$$7, &_34$$7, &k$$4, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 105);
							ZEPHIR_CALL_CE_STATIC(&_25$$7, zeplara_http_uploadedfilefactory_ce, "create", &_12, 0, &_26$$7, &_31$$7, &v$$4, &_33$$7, &_35$$7);
							zephir_check_call_status();
							zephir_array_update_multi(&files, &_25$$7, SL("za"), 2, &key);
						ZEPHIR_CALL_METHOD(NULL, &_5$$4, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&v$$4);
				ZEPHIR_INIT_NVAR(&k$$4);
			} else {
				zephir_array_fetch_string(&_38$$9, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 109);
				ZEPHIR_INIT_NVAR(&_39$$9);
				ZVAL_STRING(&_39$$9, "r");
				ZEPHIR_CALL_CE_STATIC(&_37$$9, zeplara_http_streamfactory_ce, "create", &_14, 0, &_38$$9, &_39$$9);
				zephir_check_call_status();
				zephir_array_fetch_string(&_40$$9, &value, SL("size"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 110);
				zephir_array_fetch_string(&_41$$9, &value, SL("error"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 111);
				zephir_array_fetch_string(&_42$$9, &value, SL("name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 112);
				zephir_array_fetch_string(&_43$$9, &value, SL("type"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 114);
				ZEPHIR_CALL_CE_STATIC(&_36$$9, zeplara_http_uploadedfilefactory_ce, "create", &_12, 0, &_37$$9, &_40$$9, &_41$$9, &_42$$9, &_43$$9);
				zephir_check_call_status();
				zephir_array_update_zval(&files, &key, &_36$$9, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_FILES, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &_FILES, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_FILES, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_FILES, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_44$$10);
				zephir_array_fetch_string(&_44$$10, &value, SL("error"), PH_NOISY, "zeplara/Http/ServerRequestFactory.zep", 93);
				if (Z_TYPE_P(&_44$$10) == IS_ARRAY) {
					zephir_array_fetch_string(&_45$$11, &value, SL("error"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 95);
					zephir_is_iterable(&_45$$11, 0, "zeplara/Http/ServerRequestFactory.zep", 107);
					if (Z_TYPE_P(&_45$$11) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_45$$11), _48$$11, _49$$11, _46$$11)
						{
							ZEPHIR_INIT_NVAR(&k$$11);
							if (_49$$11 != NULL) { 
								ZVAL_STR_COPY(&k$$11, _49$$11);
							} else {
								ZVAL_LONG(&k$$11, _48$$11);
							}
							ZEPHIR_INIT_NVAR(&v$$11);
							ZVAL_COPY(&v$$11, _46$$11);
							if (!(zephir_array_isset(&files, &key))) {
								ZEPHIR_INIT_NVAR(&_50$$13);
								array_init(&_50$$13);
								zephir_array_update_zval(&files, &key, &_50$$13, PH_COPY | PH_SEPARATE);
							}
							zephir_array_fetch_string(&_53$$12, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 100);
							zephir_array_fetch(&_54$$12, &_53$$12, &k$$11, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 100);
							ZEPHIR_INIT_NVAR(&_55$$12);
							ZVAL_STRING(&_55$$12, "r");
							ZEPHIR_CALL_CE_STATIC(&_52$$12, zeplara_http_streamfactory_ce, "create", &_14, 0, &_54$$12, &_55$$12);
							zephir_check_call_status();
							zephir_array_fetch_string(&_56$$12, &value, SL("size"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 101);
							zephir_array_fetch(&_57$$12, &_56$$12, &k$$11, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 101);
							zephir_array_fetch_string(&_58$$12, &value, SL("name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 103);
							zephir_array_fetch(&_59$$12, &_58$$12, &k$$11, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 103);
							zephir_array_fetch_string(&_60$$12, &value, SL("type"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 104);
							zephir_array_fetch(&_61$$12, &_60$$12, &k$$11, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 105);
							ZEPHIR_CALL_CE_STATIC(&_51$$12, zeplara_http_uploadedfilefactory_ce, "create", &_12, 0, &_52$$12, &_57$$12, &v$$11, &_59$$12, &_61$$12);
							zephir_check_call_status();
							zephir_array_update_multi(&files, &_51$$12, SL("za"), 2, &key);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_45$$11, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_47$$11, &_45$$11, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_47$$11)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&k$$11, &_45$$11, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&v$$11, &_45$$11, "current", NULL, 0);
							zephir_check_call_status();
								if (!(zephir_array_isset(&files, &key))) {
									ZEPHIR_INIT_NVAR(&_62$$15);
									array_init(&_62$$15);
									zephir_array_update_zval(&files, &key, &_62$$15, PH_COPY | PH_SEPARATE);
								}
								zephir_array_fetch_string(&_65$$14, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 100);
								zephir_array_fetch(&_66$$14, &_65$$14, &k$$11, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 100);
								ZEPHIR_INIT_NVAR(&_67$$14);
								ZVAL_STRING(&_67$$14, "r");
								ZEPHIR_CALL_CE_STATIC(&_64$$14, zeplara_http_streamfactory_ce, "create", &_14, 0, &_66$$14, &_67$$14);
								zephir_check_call_status();
								zephir_array_fetch_string(&_68$$14, &value, SL("size"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 101);
								zephir_array_fetch(&_69$$14, &_68$$14, &k$$11, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 101);
								zephir_array_fetch_string(&_70$$14, &value, SL("name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 103);
								zephir_array_fetch(&_71$$14, &_70$$14, &k$$11, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 103);
								zephir_array_fetch_string(&_72$$14, &value, SL("type"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 104);
								zephir_array_fetch(&_73$$14, &_72$$14, &k$$11, PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 105);
								ZEPHIR_CALL_CE_STATIC(&_63$$14, zeplara_http_uploadedfilefactory_ce, "create", &_12, 0, &_64$$14, &_69$$14, &v$$11, &_71$$14, &_73$$14);
								zephir_check_call_status();
								zephir_array_update_multi(&files, &_63$$14, SL("za"), 2, &key);
							ZEPHIR_CALL_METHOD(NULL, &_45$$11, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&v$$11);
					ZEPHIR_INIT_NVAR(&k$$11);
				} else {
					zephir_array_fetch_string(&_76$$16, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 109);
					ZEPHIR_INIT_NVAR(&_77$$16);
					ZVAL_STRING(&_77$$16, "r");
					ZEPHIR_CALL_CE_STATIC(&_75$$16, zeplara_http_streamfactory_ce, "create", &_14, 0, &_76$$16, &_77$$16);
					zephir_check_call_status();
					zephir_array_fetch_string(&_78$$16, &value, SL("size"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 110);
					zephir_array_fetch_string(&_79$$16, &value, SL("error"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 111);
					zephir_array_fetch_string(&_80$$16, &value, SL("name"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 112);
					zephir_array_fetch_string(&_81$$16, &value, SL("type"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 114);
					ZEPHIR_CALL_CE_STATIC(&_74$$16, zeplara_http_uploadedfilefactory_ce, "create", &_12, 0, &_75$$16, &_78$$16, &_79$$16, &_80$$16, &_81$$16);
					zephir_check_call_status();
					zephir_array_update_zval(&files, &key, &_74$$16, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_FILES, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&files);

}

/**
 * @return array
 */
PHP_METHOD(Zeplara_Http_ServerRequestFactory, getAllHeaders) {

	zend_bool _9$$6, _16$$10;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SERVER, key, value, headers, copy_server, *_0, _1, _4$$5, _5$$5, _6$$5, _7$$6, _8$$6, _10$$8, _11$$9, _12$$9, _13$$9, _14$$10, _15$$10, _17$$12, _18$$14, basic_pass$$15, _19$$15, _20$$15, _21$$15, _22$$15, _23$$16;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&copy_server);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&basic_pass$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$16);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	if ((zephir_function_exists_ex(ZEND_STRL("getallheaders")) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("getallheaders", NULL, 108);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(ZEND_STRL("apache_request_headers")) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("apache_request_headers", NULL, 109);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_INIT_VAR(&copy_server);
	zephir_create_array(&copy_server, 3, 0);
	add_assoc_stringl_ex(&copy_server, SL("CONTENT_MD5"), SL("Content-Md5"));
	add_assoc_stringl_ex(&copy_server, SL("CONTENT_TYPE"), SL("Content-Type"));
	add_assoc_stringl_ex(&copy_server, SL("CONTENT_LENGTH"), SL("Content-Length"));
	zephir_is_iterable(&_SERVER, 0, "zeplara/Http/ServerRequestFactory.zep", 153);
	if (Z_TYPE_P(&_SERVER) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_SERVER), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZVAL_LONG(&_4$$5, 0);
			ZVAL_LONG(&_5$$5, 5);
			ZEPHIR_INIT_NVAR(&_6$$5);
			zephir_substr(&_6$$5, &key, 0 , 5 , 0);
			if (ZEPHIR_IS_STRING(&_6$$5, "HTTP_")) {
				ZVAL_LONG(&_7$$6, 5);
				ZEPHIR_INIT_NVAR(&_8$$6);
				zephir_substr(&_8$$6, &key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CPY_WRT(&key, &_8$$6);
				_9$$6 = !(zephir_array_isset(&copy_server, &key));
				if (!(_9$$6)) {
					_9$$6 = !(zephir_array_isset(&_SERVER, &key));
				}
				if (_9$$6) {
					zephir_array_update_zval(&headers, &key, &value, PH_COPY | PH_SEPARATE);
				}
			} else if (zephir_array_isset(&copy_server, &key)) {
				ZEPHIR_OBS_NVAR(&_10$$8);
				zephir_array_fetch(&_10$$8, &copy_server, &key, PH_NOISY, "zeplara/Http/ServerRequestFactory.zep", 149);
				zephir_array_update_zval(&headers, &_10$$8, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_SERVER, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &_SERVER, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_SERVER, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_SERVER, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_11$$9, 0);
				ZVAL_LONG(&_12$$9, 5);
				ZEPHIR_INIT_NVAR(&_13$$9);
				zephir_substr(&_13$$9, &key, 0 , 5 , 0);
				if (ZEPHIR_IS_STRING(&_13$$9, "HTTP_")) {
					ZVAL_LONG(&_14$$10, 5);
					ZEPHIR_INIT_NVAR(&_15$$10);
					zephir_substr(&_15$$10, &key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					ZEPHIR_CPY_WRT(&key, &_15$$10);
					_16$$10 = !(zephir_array_isset(&copy_server, &key));
					if (!(_16$$10)) {
						_16$$10 = !(zephir_array_isset(&_SERVER, &key));
					}
					if (_16$$10) {
						zephir_array_update_zval(&headers, &key, &value, PH_COPY | PH_SEPARATE);
					}
				} else if (zephir_array_isset(&copy_server, &key)) {
					ZEPHIR_OBS_NVAR(&_17$$12);
					zephir_array_fetch(&_17$$12, &copy_server, &key, PH_NOISY, "zeplara/Http/ServerRequestFactory.zep", 149);
					zephir_array_update_zval(&headers, &_17$$12, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_SERVER, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (!(zephir_array_isset_string(&headers, SL("Authorization")))) {
		if (zephir_array_isset_string(&_SERVER, SL("REDIRECT_HTTP_AUTHORIZATION"))) {
			zephir_array_fetch_string(&_18$$14, &_SERVER, SL("REDIRECT_HTTP_AUTHORIZATION"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 155);
			zephir_array_update_string(&headers, SL("Authorization"), &_18$$14, PH_COPY | PH_SEPARATE);
		} else if (zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_USER"))) {
			ZEPHIR_OBS_VAR(&basic_pass$$15);
			zephir_array_isset_string_fetch(&basic_pass$$15, &_SERVER, SL("PHP_AUTH_PW"), 0);
			zephir_array_fetch_string(&_19$$15, &_SERVER, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 159);
			ZEPHIR_INIT_VAR(&_20$$15);
			ZEPHIR_CONCAT_VSV(&_20$$15, &_19$$15, ":", &basic_pass$$15);
			ZEPHIR_CALL_FUNCTION(&_21$$15, "base64_encode", NULL, 54, &_20$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_22$$15);
			ZEPHIR_CONCAT_SV(&_22$$15, "Basic ", &_21$$15);
			zephir_array_update_string(&headers, SL("Authorization"), &_22$$15, PH_COPY | PH_SEPARATE);
		} else if (zephir_array_isset_string(&_SERVER, SL("PHP_AUTH_DIGEST"))) {
			zephir_array_fetch_string(&_23$$16, &_SERVER, SL("PHP_AUTH_DIGEST"), PH_NOISY | PH_READONLY, "zeplara/Http/ServerRequestFactory.zep", 161);
			zephir_array_update_string(&headers, SL("Authorization"), &_23$$16, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(&headers);

}

/**
 * @return array
 */
PHP_METHOD(Zeplara_Http_ServerRequestFactory, parseProtocolVersion) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, matches, _0, _2, _3, _4;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "SERVER_PROTOCOL");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_CALL_CE_STATIC(&_0, zeplara_support_arr_ce, "get", &_1, 0, &_SERVER, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "~^HTTP\\/(\\d\\.\\d)$~i");
	ZEPHIR_INIT_NVAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "~^HTTP\\/(\\d\\.\\d)$~i");
	zephir_preg_match(&_3, &_4, &_0, &matches, 0, 0 , 0 );
	RETURN_CCTOR(&matches);

}

