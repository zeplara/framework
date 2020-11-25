
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_Uri) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Http, Uri, zeplara, http_uri, zeplara_http_uri_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_http_uri_ce, SL("scheme"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_http_uri_ce, SL("host"), ZEND_ACC_PROTECTED);

	/**
	 * @var int|null
	 */
	zend_declare_property_null(zeplara_http_uri_ce, SL("port"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_http_uri_ce, SL("userInfo"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_http_uri_ce, SL("path"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_http_uri_ce, SL("query"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_http_uri_ce, SL("fragment"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_http_uri_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\uriinterface")));
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Http_Uri, getScheme) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "scheme");

}

/**
 */
PHP_METHOD(Zeplara_Http_Uri, getHost) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "host");

}

/**
 */
PHP_METHOD(Zeplara_Http_Uri, getPort) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "port");

}

/**
 */
PHP_METHOD(Zeplara_Http_Uri, getUserInfo) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "userInfo");

}

/**
 */
PHP_METHOD(Zeplara_Http_Uri, getPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "path");

}

/**
 */
PHP_METHOD(Zeplara_Http_Uri, getQuery) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "query");

}

/**
 */
PHP_METHOD(Zeplara_Http_Uri, getFragment) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "fragment");

}

/**
 * @param scheme
 * @param host
 * @param null port
 * @param string path
 * @param string query
 * @param string fragment
 * @param string user
 * @param string password
 */
PHP_METHOD(Zeplara_Http_Uri, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *scheme = NULL, scheme_sub, *host = NULL, host_sub, *port = NULL, port_sub, *path = NULL, path_sub, *query = NULL, query_sub, *fragment = NULL, fragment_sub, *user = NULL, user_sub, *password = NULL, password_sub, __$null, _0, _1, _2, _3, _4, _6, _7, _9$$3, _10$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme_sub);
	ZVAL_UNDEF(&host_sub);
	ZVAL_UNDEF(&port_sub);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&query_sub);
	ZVAL_UNDEF(&fragment_sub);
	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&password_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 8, &scheme, &host, &port, &path, &query, &fragment, &user, &password);

	if (!scheme) {
		scheme = &scheme_sub;
		ZEPHIR_INIT_VAR(scheme);
		ZVAL_STRING(scheme, "");
	}
	if (!host) {
		host = &host_sub;
		ZEPHIR_INIT_VAR(host);
		ZVAL_STRING(host, "");
	}
	if (!port) {
		port = &port_sub;
		port = &__$null;
	}
	if (!path) {
		path = &path_sub;
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/");
	}
	if (!query) {
		query = &query_sub;
		ZEPHIR_INIT_VAR(query);
		ZVAL_STRING(query, "");
	}
	if (!fragment) {
		fragment = &fragment_sub;
		ZEPHIR_INIT_VAR(fragment);
		ZVAL_STRING(fragment, "");
	}
	if (!user) {
		user = &user_sub;
		ZEPHIR_INIT_VAR(user);
		ZVAL_STRING(user, "");
	}
	if (!password) {
		password = &password_sub;
		ZEPHIR_INIT_VAR(password);
		ZVAL_STRING(password, "");
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterscheme", NULL, 95, scheme);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("scheme"), &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "filterhost", NULL, 96, host);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("host"), &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "filterport", NULL, 97, port);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("port"), &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "filterpath", NULL, 98, path);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &_3);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "filterqueryorfragment", &_5, 99, query);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("query"), &_4);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "filterqueryorfragment", &_5, 99, fragment);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("fragment"), &_6);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "filteruserinfo", &_8, 100, user);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("userInfo"), &_7);
	if (zephir_is_true(password)) {
		ZEPHIR_CALL_METHOD(&_9$$3, this_ptr, "filteruserinfo", &_8, 100, password);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$3);
		ZEPHIR_CONCAT_SV(&_10$$3, ":", &_9$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("userInfo"), &_10$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Zeplara_Http_Uri, getAuthority) {

	zval authority, _0, _3, _1$$3, _2$$3, _4$$4, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&authority);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&authority);
	zephir_read_property(&authority, this_ptr, ZEND_STRL("host"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("userInfo"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("userInfo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VSV(&_2$$3, &_1$$3, "@", &authority);
		ZEPHIR_CPY_WRT(&authority, &_2$$3);
	}
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("port"), PH_NOISY_CC);
	if (Z_TYPE_P(&_3) != IS_NULL) {
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SV(&_5$$4, ":", &_4$$4);
		zephir_concat_self(&authority, &_5$$4);
	}
	RETURN_CCTOR(&authority);

}

/**
 * @param string scheme
 * @return static
 */
PHP_METHOD(Zeplara_Http_Uri, withScheme) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *scheme, scheme_sub, clone, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme_sub);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, &clone, "filterscheme", NULL, 0, scheme);
	zephir_check_call_status();
	zephir_update_property_zval(&clone, ZEND_STRL("scheme"), &_0);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &clone, "filterport", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(&clone, ZEND_STRL("port"), &_1);
	RETURN_CCTOR(&clone);

}

/**
 * @param string user
 * @param null password
 * @return static
 */
PHP_METHOD(Zeplara_Http_Uri, withUserInfo) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, *password = NULL, password_sub, __$null, clone, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&password_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &password);

	if (!password) {
		password = &password_sub;
		password = &__$null;
	}


	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, &clone, "filteruserinfo", NULL, 0, user);
	zephir_check_call_status();
	zephir_update_property_zval(&clone, ZEND_STRL("userInfo"), &_0);
	if (Z_TYPE_P(password) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1$$3, &clone, "filteruserinfo", NULL, 0, password);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, ":", &_1$$3);
		zephir_update_property_zval(&clone, ZEND_STRL("userInfo"), &_2$$3);
	}
	RETURN_CCTOR(&clone);

}

/**
 * @param string host
 * @return static
 */
PHP_METHOD(Zeplara_Http_Uri, withHost) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *host, host_sub, clone, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host_sub);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &host);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, &clone, "filterhost", NULL, 0, host);
	zephir_check_call_status();
	zephir_update_property_zval(&clone, ZEND_STRL("host"), &_0);
	RETURN_CCTOR(&clone);

}

/**
 * @param int|null port
 * @return static
 */
PHP_METHOD(Zeplara_Http_Uri, withPort) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *port, port_sub, clone, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&port_sub);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, &clone, "filterport", NULL, 0, port);
	zephir_check_call_status();
	zephir_update_property_zval(&clone, ZEND_STRL("port"), &_0);
	RETURN_CCTOR(&clone);

}

/**
 * @param string path
 * @return static
 */
PHP_METHOD(Zeplara_Http_Uri, withPath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, clone, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, &clone, "filterpath", NULL, 0, path);
	zephir_check_call_status();
	zephir_update_property_zval(&clone, ZEND_STRL("path"), &_0);
	RETURN_CCTOR(&clone);

}

/**
 * @param string query
 * @return static
 */
PHP_METHOD(Zeplara_Http_Uri, withQuery) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query, query_sub, clone, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query_sub);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, &clone, "filterqueryorfragment", NULL, 0, query);
	zephir_check_call_status();
	zephir_update_property_zval(&clone, ZEND_STRL("query"), &_0);
	RETURN_CCTOR(&clone);

}

/**
 * @param string fragment
 * @return static
 */
PHP_METHOD(Zeplara_Http_Uri, withFragment) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fragment, fragment_sub, clone, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fragment_sub);
	ZVAL_UNDEF(&clone);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fragment);



	ZEPHIR_INIT_VAR(&clone);
	if (zephir_clone(&clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, &clone, "filterqueryorfragment", NULL, 0, fragment);
	zephir_check_call_status();
	zephir_update_property_zval(&clone, ZEND_STRL("fragment"), &_0);
	RETURN_CCTOR(&clone);

}

/**
 * @return string
 */
PHP_METHOD(Zeplara_Http_Uri, __toString) {

	zend_bool _3;
	zval uri, authority, _0, _4, _6, _7, _10, _1$$3, _2$$3, _5$$4, _8$$5, _9$$5, _11$$6, _12$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&authority);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&uri);
	ZVAL_STRING(&uri, "");
	ZEPHIR_CALL_METHOD(&authority, this_ptr, "getauthority", NULL, 101);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("scheme"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_0, "")) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("scheme"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VS(&_2$$3, &_1$$3, ":");
		zephir_concat_self(&uri, &_2$$3);
	}
	_3 = zephir_is_true(&authority);
	if (!(_3)) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("scheme"), PH_NOISY_CC | PH_READONLY);
		_3 = ZEPHIR_IS_STRING(&_4, "file");
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SV(&_5$$4, "//", &authority);
		zephir_concat_self(&uri, &_5$$4);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	zephir_concat_self(&uri, &_6);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("query"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_7)) {
		zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("query"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZEPHIR_CONCAT_SV(&_9$$5, "?", &_8$$5);
		zephir_concat_self(&uri, &_9$$5);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("fragment"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_10)) {
		zephir_read_property(&_11$$6, this_ptr, ZEND_STRL("fragment"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_12$$6);
		ZEPHIR_CONCAT_SV(&_12$$6, "#", &_11$$6);
		zephir_concat_self(&uri, &_12$$6);
	}
	RETURN_CCTOR(&uri);

}

/**
 * @param scheme
 * @return string
 */
PHP_METHOD(Zeplara_Http_Uri, filterScheme) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *scheme = NULL, scheme_sub, _0, sepIdx$$4, _1$$4, _2$$5, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&sepIdx$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme);

	ZEPHIR_SEPARATE_PARAM(scheme);


	if (Z_TYPE_P(scheme) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The scheme or fragment must be an string.", "zeplara/Http/Uri.zep", 225);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, scheme, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_CPY_WRT(scheme, &_0);
	if (!ZEPHIR_IS_STRING_IDENTICAL(scheme, "")) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_fast_strtolower(&_1$$4, scheme);
		ZEPHIR_CPY_WRT(scheme, &_1$$4);
		ZEPHIR_INIT_NVAR(&_1$$4);
		ZVAL_STRING(&_1$$4, ":");
		ZEPHIR_INIT_VAR(&sepIdx$$4);
		zephir_fast_strpos(&sepIdx$$4, scheme, &_1$$4, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&sepIdx$$4)) {
			ZVAL_LONG(&_2$$5, 0);
			ZEPHIR_INIT_VAR(&_3$$5);
			zephir_substr(&_3$$5, scheme, 0 , zephir_get_intval(&sepIdx$$4), 0);
			ZEPHIR_CPY_WRT(scheme, &_3$$5);
		}
	}
	RETVAL_ZVAL(scheme, 1, 0);
	RETURN_MM();

}

/**
 * @param host
 * @return string
 */
PHP_METHOD(Zeplara_Http_Uri, filterHost) {

	zval *host, host_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &host);



	if (Z_TYPE_P(host) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "The host is invalid type.", "zeplara/Http/Uri.zep", 250);
		return;
	}
	zephir_fast_strtolower(return_value, host);
	return;

}

/**
 * @param int|null port
 * @return int|null
 */
PHP_METHOD(Zeplara_Http_Uri, filterPort) {

	zend_bool _1, _2, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _5$$5;
	zval *port = NULL, port_sub, _0, defaultPortByScheme$$5, _3$$5, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&port_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&defaultPortByScheme$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port);

	ZEPHIR_SEPARATE_PARAM(port);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("scheme"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "")) {
		ZEPHIR_INIT_NVAR(port);
		ZVAL_NULL(port);
	}
	if (Z_TYPE_P(port) == IS_NULL) {
		RETVAL_ZVAL(port, 1, 0);
		RETURN_MM();
	}
	_1 = zephir_is_numeric(port);
	if (_1) {
		_1 = ZEPHIR_GE_LONG(port, 1);
	}
	_2 = _1;
	if (_2) {
		_2 = ZEPHIR_LE_LONG(port, 65535);
	}
	if (_2) {
		zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("scheme"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "tcp");
		ZEPHIR_CALL_FUNCTION(&defaultPortByScheme$$5, "getservbyname", NULL, 102, &_3$$5, &_4$$5);
		zephir_check_call_status();
		_5$$5 = zephir_get_intval(port);
		ZEPHIR_INIT_NVAR(port);
		ZVAL_LONG(port, _5$$5);
		_6$$5 = ZEPHIR_IS_FALSE_IDENTICAL(&defaultPortByScheme$$5);
		if (!(_6$$5)) {
			_6$$5 = ZEPHIR_IS_IDENTICAL(port, &defaultPortByScheme$$5);
		}
		if (_6$$5) {
			ZEPHIR_INIT_NVAR(port);
			ZVAL_NULL(port);
		}
		RETVAL_ZVAL(port, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The port value must be an integer between 1 and 65535.", "zeplara/Http/Uri.zep", 283);
	return;

}

/**
 * @param path
 * @return string|string[]|null
 */
PHP_METHOD(Zeplara_Http_Uri, filterPath) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	if (Z_TYPE_P(path) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The path must be an string.", "zeplara/Http/Uri.zep", 293);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "rawUrlEncodeFilter");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_trim(&_1, path, &_2, ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "/", &_1);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/(?:[^a-zA-Z0-9_\\-\\.~:@&=\\+\\$,\\/;%]+|%(?![A-Fa-f0-9]{2}))/");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace_callback", NULL, 41, &_4, &_0, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param value
 * @return string|string[]|null
 */
PHP_METHOD(Zeplara_Http_Uri, filterQueryOrFragment) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The query or fragment must be an string.", "zeplara/Http/Uri.zep", 310);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "rawUrlEncodeFilter");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/(?:[^a-zA-Z0-9_\\-\\.~!\\$&\"\\(\\)\\*\\+,;=%:@\\/\?]+|%(?![A-Fa-f0-9]{2}))/");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace_callback", NULL, 41, &_1, &_0, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param userInfo
 * @return string|string[]|null
 */
PHP_METHOD(Zeplara_Http_Uri, filterUserInfo) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *userInfo, userInfo_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&userInfo_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &userInfo);



	if (Z_TYPE_P(userInfo) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The user info must be an string.", "zeplara/Http/Uri.zep", 327);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "rawUrlEncodeFilter");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/(?:[^a-zA-Z0-9_\\-\\.~!\\$&\"\\(\\)\\*\\+,;=]+|%(?![A-Fa-f0-9]{2}))/u");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace_callback", NULL, 41, &_1, &_0, userInfo);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param array matches
 * @return string
 */
PHP_METHOD(Zeplara_Http_Uri, rawUrlEncodeFilter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *matches_param = NULL, _0;
	zval matches;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches_param);

	ZEPHIR_OBS_COPY_OR_DUP(&matches, matches_param);


	zephir_array_fetch_long(&_0, &matches, 0, PH_NOISY | PH_READONLY, "zeplara/Http/Uri.zep", 342);
	ZEPHIR_RETURN_CALL_FUNCTION("rawurlencode", NULL, 44, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

