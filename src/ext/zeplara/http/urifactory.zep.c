
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
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_UriFactory) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Http, UriFactory, zeplara, http_urifactory, zeplara_http_urifactory_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_http_urifactory_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\urifactoryinterface")));
	return SUCCESS;

}

/**
 * @param string uri
 * @return UriInterface
 */
PHP_METHOD(Zeplara_Http_UriFactory, createUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}
	}


	ZEPHIR_RETURN_CALL_SELF("create", NULL, 0, &uri);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string|array|null uri
 * @return UriInterface
 */
PHP_METHOD(Zeplara_Http_UriFactory, create) {

	zend_bool _0$$3, _13$$3, _19$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, uri_sub, _SERVER, __$null, scheme, host, port, path, query, fragment, user, pass, _1$$3, _12$$3, _18$$3, _2$$4, parsed$$5, _3$$5, _4$$5, _5$$5, _6$$5, _8$$6, _9$$7, _10$$8, _11$$9, _14$$10, parsed$$11, _15$$11, _16$$11, _17$$12, _20$$13, _21$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&fragment);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&pass);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&parsed$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&parsed$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$14);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = &uri_sub;
		ZEPHIR_CPY_WRT(uri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}


	ZEPHIR_INIT_VAR(&scheme);
	ZVAL_STRING(&scheme, "http");
	ZEPHIR_INIT_VAR(&host);
	ZVAL_STRING(&host, "localhost");
	ZEPHIR_INIT_VAR(&port);
	ZVAL_NULL(&port);
	ZEPHIR_INIT_VAR(&path);
	ZVAL_STRING(&path, "/");
	ZEPHIR_INIT_VAR(&query);
	ZVAL_STRING(&query, "");
	ZEPHIR_INIT_VAR(&fragment);
	ZVAL_STRING(&fragment, "");
	ZEPHIR_INIT_VAR(&user);
	ZVAL_STRING(&user, "");
	ZEPHIR_INIT_VAR(&pass);
	ZVAL_STRING(&pass, "");
	if (Z_TYPE_P(uri) == IS_NULL) {
		ZEPHIR_INIT_NVAR(uri);
		array_init(uri);
		zephir_array_update_string(uri, SL("scheme"), &scheme, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(uri, SL("host"), &host, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(uri, SL("port"), &port, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(uri, SL("path"), &path, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(uri, SL("query"), &query, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(uri, SL("user"), &user, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(uri, SL("pass"), &pass, PH_COPY | PH_SEPARATE);
		_0$$3 = zephir_array_isset_string(&_SERVER, SL("HTTPS"));
		if (_0$$3) {
			zephir_array_fetch_string(&_1$$3, &_SERVER, SL("HTTPS"), PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 45);
			_0$$3 = !ZEPHIR_IS_STRING(&_1$$3, "off");
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "https");
			zephir_array_update_string(uri, SL("scheme"), &_2$$4, PH_COPY | PH_SEPARATE);
		}
		if (zephir_array_isset_string(&_SERVER, SL("HTTP_HOST"))) {
			zephir_array_fetch_string(&_4$$5, &_SERVER, SL("HTTP_HOST"), PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 52);
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "%s://%s");
			ZEPHIR_CALL_FUNCTION(&_6$$5, "sprintf", NULL, 2, &_5$$5, &scheme, &_4$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&parsed$$5, "parse_url", &_7, 136, &_6$$5);
			zephir_check_call_status();
			if (zephir_array_isset_string(&parsed$$5, SL("host"))) {
				zephir_array_fetch_string(&_8$$6, &parsed$$5, SL("host"), PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 55);
				zephir_array_update_string(uri, SL("host"), &_8$$6, PH_COPY | PH_SEPARATE);
			}
			if (zephir_array_isset_string(&parsed$$5, SL("port"))) {
				zephir_array_fetch_string(&_9$$7, &parsed$$5, SL("port"), PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 59);
				zephir_array_update_string(uri, SL("port"), &_9$$7, PH_COPY | PH_SEPARATE);
			}
		} else if (zephir_array_isset_string(&_SERVER, SL("SERVER_NAME"))) {
			zephir_array_fetch_string(&_10$$8, &_SERVER, SL("SERVER_NAME"), PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 62);
			zephir_array_update_string(uri, SL("host"), &_10$$8, PH_COPY | PH_SEPARATE);
		} else if (zephir_array_isset_string(&_SERVER, SL("SERVER_ADDR"))) {
			zephir_array_fetch_string(&_11$$9, &_SERVER, SL("SERVER_ADDR"), PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 64);
			zephir_array_update_string(uri, SL("host"), &_11$$9, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_VAR(&_12$$3);
		zephir_array_fetch_string(&_12$$3, uri, SL("port"), PH_NOISY, "zeplara/Http/UriFactory.zep", 67);
		_13$$3 = Z_TYPE_P(&_12$$3) == IS_NULL;
		if (_13$$3) {
			_13$$3 = zephir_array_isset_string(&_SERVER, SL("SERVER_PORT"));
		}
		if (_13$$3) {
			zephir_array_fetch_string(&_14$$10, &_SERVER, SL("SERVER_PORT"), PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 68);
			zephir_array_update_string(uri, SL("port"), &_14$$10, PH_COPY | PH_SEPARATE);
		}
		if (zephir_array_isset_string(&_SERVER, SL("REQUEST_URI"))) {
			zephir_array_fetch_string(&_15$$11, &_SERVER, SL("REQUEST_URI"), PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 74);
			ZEPHIR_INIT_VAR(&parsed$$11);
			zephir_fast_explode_str(&parsed$$11, SL("?"), &_15$$11, 2 );
			zephir_array_fetch_long(&_16$$11, &parsed$$11, 0, PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 75);
			zephir_array_update_string(uri, SL("path"), &_16$$11, PH_COPY | PH_SEPARATE);
			if (zephir_array_isset_long(&parsed$$11, 1)) {
				zephir_array_fetch_long(&_17$$12, &parsed$$11, 1, PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 78);
				zephir_array_update_string(uri, SL("query"), &_17$$12, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_array_fetch_string(&_18$$3, uri, SL("query"), PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 82);
		_19$$3 = ZEPHIR_IS_STRING_IDENTICAL(&_18$$3, "");
		if (_19$$3) {
			_19$$3 = zephir_array_isset_string(&_SERVER, SL("QUERY_STRING"));
		}
		if (_19$$3) {
			zephir_array_fetch_string(&_20$$13, &_SERVER, SL("QUERY_STRING"), PH_NOISY | PH_READONLY, "zeplara/Http/UriFactory.zep", 83);
			zephir_array_update_string(uri, SL("query"), &_20$$13, PH_COPY | PH_SEPARATE);
		}
	}
	if (Z_TYPE_P(uri) == IS_STRING) {
		ZEPHIR_CALL_FUNCTION(&_21$$14, "parse_url", &_7, 136, uri);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(uri, &_21$$14);
		if (ZEPHIR_IS_FALSE_IDENTICAL(uri)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The url is invalid.", "zeplara/Http/UriFactory.zep", 91);
			return;
		}
	}
	if (Z_TYPE_P(uri) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The uri should be string or array or null tyoe.", "zeplara/Http/UriFactory.zep", 96);
		return;
	}
	if (zephir_array_isset_string(uri, SL("scheme"))) {
		ZEPHIR_OBS_NVAR(&scheme);
		zephir_array_fetch_string(&scheme, uri, SL("scheme"), PH_NOISY, "zeplara/Http/UriFactory.zep", 100);
	}
	if (zephir_array_isset_string(uri, SL("host"))) {
		ZEPHIR_OBS_NVAR(&host);
		zephir_array_fetch_string(&host, uri, SL("host"), PH_NOISY, "zeplara/Http/UriFactory.zep", 104);
	}
	if (zephir_array_isset_string(uri, SL("port"))) {
		ZEPHIR_OBS_NVAR(&port);
		zephir_array_fetch_string(&port, uri, SL("port"), PH_NOISY, "zeplara/Http/UriFactory.zep", 108);
	}
	if (zephir_array_isset_string(uri, SL("path"))) {
		ZEPHIR_OBS_NVAR(&path);
		zephir_array_fetch_string(&path, uri, SL("path"), PH_NOISY, "zeplara/Http/UriFactory.zep", 112);
	}
	if (zephir_array_isset_string(uri, SL("query"))) {
		ZEPHIR_OBS_NVAR(&query);
		zephir_array_fetch_string(&query, uri, SL("query"), PH_NOISY, "zeplara/Http/UriFactory.zep", 116);
	}
	if (zephir_array_isset_string(uri, SL("fragment"))) {
		ZEPHIR_OBS_NVAR(&fragment);
		zephir_array_fetch_string(&fragment, uri, SL("fragment"), PH_NOISY, "zeplara/Http/UriFactory.zep", 120);
	}
	if (zephir_array_isset_string(uri, SL("user"))) {
		ZEPHIR_OBS_NVAR(&user);
		zephir_array_fetch_string(&user, uri, SL("user"), PH_NOISY, "zeplara/Http/UriFactory.zep", 124);
	}
	if (zephir_array_isset_string(uri, SL("pass"))) {
		ZEPHIR_OBS_NVAR(&pass);
		zephir_array_fetch_string(&pass, uri, SL("pass"), PH_NOISY, "zeplara/Http/UriFactory.zep", 128);
	}
	object_init_ex(return_value, zeplara_http_uri_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 137, &scheme, &host, &port, &path, &query, &fragment, &user, &pass);
	zephir_check_call_status();
	RETURN_MM();

}

