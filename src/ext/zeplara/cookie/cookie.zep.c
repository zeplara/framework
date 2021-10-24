
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/time.h"


ZEPHIR_INIT_CLASS(Zeplara_Cookie_Cookie) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Cookie, Cookie, zeplara, cookie_cookie, zeplara_cookie_cookie_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_cookie_cookie_ce, SL("name"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_cookie_cookie_ce, SL("value"), ZEND_ACC_PROTECTED);

	/**
	 * @var int
	 */
	zend_declare_property_null(zeplara_cookie_cookie_ce, SL("expiration"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_cookie_cookie_ce, SL("path"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_cookie_cookie_ce, SL("domain"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_null(zeplara_cookie_cookie_ce, SL("secure"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_null(zeplara_cookie_cookie_ce, SL("httpOnly"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_cookie_cookie_ce, SL("sameSite"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_cookie_cookie_ce, 1, zeplara_interfaces_cookie_cookie_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Cookie_Cookie, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 */
PHP_METHOD(Zeplara_Cookie_Cookie, getValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "value");

}

/**
 */
PHP_METHOD(Zeplara_Cookie_Cookie, getExpiration) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "expiration");

}

/**
 */
PHP_METHOD(Zeplara_Cookie_Cookie, getPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "path");

}

/**
 */
PHP_METHOD(Zeplara_Cookie_Cookie, getDomain) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "domain");

}

/**
 */
PHP_METHOD(Zeplara_Cookie_Cookie, getSameSite) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sameSite");

}

/**
 * Cookie constructor.
 *
 * @param name
 * @param string value
 * @param int expiration
 * @param string path
 * @param string domain
 * @param bool secure
 * @param bool httpOnly
 * @param string sameSite
 */
PHP_METHOD(Zeplara_Cookie_Cookie, __construct) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, value_sub, *expiration = NULL, expiration_sub, *path = NULL, path_sub, *domain = NULL, domain_sub, *secure = NULL, secure_sub, *httpOnly = NULL, httpOnly_sub, *sameSite = NULL, sameSite_sub, __$false, __$true, _1, _2, _3, _4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&expiration_sub);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&domain_sub);
	ZVAL_UNDEF(&secure_sub);
	ZVAL_UNDEF(&httpOnly_sub);
	ZVAL_UNDEF(&sameSite_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 7, &name_param, &value, &expiration, &path, &domain, &secure, &httpOnly, &sameSite);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!value) {
		value = &value_sub;
		ZEPHIR_INIT_VAR(value);
		ZVAL_STRING(value, "");
	}
	if (!expiration) {
		expiration = &expiration_sub;
		ZEPHIR_INIT_VAR(expiration);
		ZVAL_LONG(expiration, 0);
	}
	if (!path) {
		path = &path_sub;
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/");
	}
	if (!domain) {
		domain = &domain_sub;
		ZEPHIR_INIT_VAR(domain);
		ZVAL_STRING(domain, "");
	}
	if (!secure) {
		secure = &secure_sub;
		secure = &__$false;
	}
	if (!httpOnly) {
		httpOnly = &httpOnly_sub;
		httpOnly = &__$true;
	}
	if (!sameSite) {
		sameSite = &sameSite_sub;
		ZEPHIR_INIT_VAR(sameSite);
		ZVAL_STRING(sameSite, "Lax");
	}


	_0 = ZEPHIR_IS_STRING_IDENTICAL(&name, "");
	if (!(_0)) {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "/[=,; \\t\\r\\n\\013\\014]/");
		ZEPHIR_INIT_VAR(&_3);
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "/[=,; \\t\\r\\n\\013\\014]/");
		zephir_preg_match(&_3, &_4, &name, &_1, 0, 0 , 0 );
		_0 = zephir_is_true(&_3);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The name is invalid.", "zeplara/Cookie/Cookie.zep", 67);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", NULL, 34, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setexpiration", NULL, 35, expiration);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpath", NULL, 36, path);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdomain", NULL, 37, domain);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsecure", NULL, 38, secure);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sethttponly", NULL, 39, httpOnly);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsamesite", NULL, 40, sameSite);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Zeplara_Cookie_Cookie, isSecure) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("secure"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_TRUE_IDENTICAL(&_0));

}

/**
 * @return bool
 */
PHP_METHOD(Zeplara_Cookie_Cookie, isHttpOnly) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("httpOnly"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_TRUE_IDENTICAL(&_0));

}

/**
 * @param string|null value
 * @return void
 */
PHP_METHOD(Zeplara_Cookie_Cookie, setValue) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value = NULL, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_INIT_NVAR(value);
		ZVAL_STRING(value, "");
	}
	if (Z_TYPE_P(value) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The value must be an string type.", "zeplara/Cookie/Cookie.zep", 108);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), value);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param DateTimeInterface|int|string expiration
 * @return void
 */
PHP_METHOD(Zeplara_Cookie_Cookie, setExpiration) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expiration = NULL, expiration_sub, _4, _1$$3, _2$$3, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expiration_sub);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expiration);

	ZEPHIR_SEPARATE_PARAM(expiration);


	_0 = Z_TYPE_P(expiration) == IS_OBJECT;
	if (_0) {
		_0 = zephir_is_instance_of(expiration, SL("DateTimeInterface"));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "U");
		ZEPHIR_CALL_METHOD(&_1$$3, expiration, "format", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(expiration, &_1$$3);
	} else if (zephir_is_numeric(expiration) == 0) {
		ZEPHIR_CALL_FUNCTION(&_3$$4, "strtotime", NULL, 41, expiration);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(expiration, &_3$$4);
		if (ZEPHIR_IS_FALSE_IDENTICAL(expiration)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The expiration time is invalid type.", "zeplara/Cookie/Cookie.zep", 125);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_4);
	if (ZEPHIR_GT_LONG(expiration, 0)) {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_LONG(&_4, zephir_get_intval(expiration));
	} else {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_LONG(&_4, 0);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("expiration"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string path
 * @return void
 */
PHP_METHOD(Zeplara_Cookie_Cookie, setPath) {

	zval _1;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path = NULL, path_sub, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);

	ZEPHIR_SEPARATE_PARAM(path);


	_0 = ZEPHIR_IS_STRING_IDENTICAL(path, "");
	if (!(_0)) {
		_0 = Z_TYPE_P(path) == IS_NULL;
	}
	if (_0) {
		ZEPHIR_INIT_NVAR(path);
		ZVAL_STRING(path, "/");
	}
	if (Z_TYPE_P(path) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The path must be an string type.", "zeplara/Cookie/Cookie.zep", 142);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	zephir_array_fast_append(&_1, this_ptr);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "rawUrlEncodeFilter");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/(?:[^a-zA-Z0-9_\\-\\.~:@&=\\+\\,\\/;%]+|%(?![A-Fa-f0-9]{2}))/");
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace_callback", NULL, 42, &_2, &_1, path);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string domain
 * @return void
 */
PHP_METHOD(Zeplara_Cookie_Cookie, setDomain) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *domain = NULL, domain_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domain);

	ZEPHIR_SEPARATE_PARAM(domain);


	if (Z_TYPE_P(domain) == IS_NULL) {
		ZEPHIR_INIT_NVAR(domain);
		ZVAL_STRING(domain, "");
	}
	if (Z_TYPE_P(domain) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The domain must be an string type.", "zeplara/Cookie/Cookie.zep", 161);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("domain"), domain);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param bool secure
 * @return void
 */
PHP_METHOD(Zeplara_Cookie_Cookie, setSecure) {

	zval *secure, secure_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&secure_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &secure);



	if (((Z_TYPE_P(secure) == IS_TRUE || Z_TYPE_P(secure) == IS_FALSE) != 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "The secure must be an boolean type.", "zeplara/Cookie/Cookie.zep", 174);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("secure"), secure);

}

/**
 * @param bool httpOnly
 * @return void
 */
PHP_METHOD(Zeplara_Cookie_Cookie, setHttpOnly) {

	zval *httpOnly, httpOnly_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&httpOnly_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &httpOnly);



	if (((Z_TYPE_P(httpOnly) == IS_TRUE || Z_TYPE_P(httpOnly) == IS_FALSE) != 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "The httpOnly must be an boolean type.", "zeplara/Cookie/Cookie.zep", 187);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("httpOnly"), httpOnly);

}

/**
 * @param string sameSite
 * @return void
 */
PHP_METHOD(Zeplara_Cookie_Cookie, setSameSite) {

	zval _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *sameSite = NULL, sameSite_sub, _0$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sameSite_sub);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sameSite);

	ZEPHIR_SEPARATE_PARAM(sameSite);


	if (ZEPHIR_IS_STRING_IDENTICAL(sameSite, "")) {
		ZEPHIR_INIT_NVAR(sameSite);
		ZVAL_NULL(sameSite);
	}
	if (Z_TYPE_P(sameSite) != IS_NULL) {
		ZEPHIR_CALL_CE_STATIC(&_0$$4, zeplara_support_str_ce, "capitalize", &_1, 0, sameSite);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(sameSite, &_0$$4);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 3, 0);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "None");
		zephir_array_fast_append(&_2$$4, &_3$$4);
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "Lax");
		zephir_array_fast_append(&_2$$4, &_3$$4);
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "Strict");
		zephir_array_fast_append(&_2$$4, &_3$$4);
		if (zephir_fast_in_array(sameSite, &_2$$4) == 0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The samesite is invalid.", "zeplara/Cookie/Cookie.zep", 206);
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("sameSite"), sameSite);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Zeplara_Cookie_Cookie, __toString) {

	zval format, _0, _1, _2, _20, _23, _26, _27, _28, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _9$$3, maxAge$$4, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _21$$6, _22$$6, _24$$7, _25$$7, _29$$10, _30$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&maxAge$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_30$$10);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "urlencode", NULL, 43, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&format);
	ZEPHIR_CONCAT_VS(&format, &_1, "=");
	zephir_read_property(&_2, this_ptr, ZEND_STRL("value"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_2, "")) {
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_time(&_4$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "D, d-M-Y H:i:s T");
		ZVAL_LONG(&_6$$3, (zephir_get_numberval(&_4$$3) - 31536001));
		ZEPHIR_CALL_FUNCTION(&_7$$3, "gmdate", &_8, 44, &_5$$3, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "deleted; Expires=%s; Max-Age=0");
		ZEPHIR_CALL_FUNCTION(&_9$$3, "sprintf", NULL, 2, &_5$$3, &_7$$3);
		zephir_check_call_status();
		zephir_concat_self(&format, &_9$$3);
	} else {
		zephir_read_property(&_10$$4, this_ptr, ZEND_STRL("expiration"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$4);
		zephir_time(&_11$$4);
		ZEPHIR_INIT_VAR(&maxAge$$4);
		zephir_sub_function(&maxAge$$4, &_10$$4, &_11$$4);
		ZEPHIR_INIT_VAR(&_12$$4);
		if (ZEPHIR_GT_LONG(&maxAge$$4, 0)) {
			ZEPHIR_CPY_WRT(&_12$$4, &maxAge$$4);
		} else {
			ZEPHIR_INIT_NVAR(&_12$$4);
			ZVAL_LONG(&_12$$4, 0);
		}
		ZEPHIR_CPY_WRT(&maxAge$$4, &_12$$4);
		zephir_read_property(&_10$$4, this_ptr, ZEND_STRL("value"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_13$$4, "rawurlencode", NULL, 45, &_10$$4);
		zephir_check_call_status();
		zephir_concat_self(&format, &_13$$4);
		zephir_read_property(&_14$$4, this_ptr, ZEND_STRL("expiration"), PH_NOISY_CC | PH_READONLY);
		if (!ZEPHIR_IS_LONG_IDENTICAL(&_14$$4, 0)) {
			zephir_read_property(&_16$$5, this_ptr, ZEND_STRL("expiration"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_17$$5);
			ZVAL_STRING(&_17$$5, "D, d-M-Y H:i:s T");
			ZEPHIR_CALL_FUNCTION(&_18$$5, "gmdate", &_8, 44, &_17$$5, &_16$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_17$$5);
			ZVAL_STRING(&_17$$5, "; Expires=%s; Max-Age=%s");
			ZEPHIR_CALL_FUNCTION(&_19$$5, "sprintf", NULL, 2, &_17$$5, &_18$$5, &maxAge$$4);
			zephir_check_call_status();
			zephir_concat_self(&format, &_19$$5);
		}
	}
	zephir_read_property(&_20, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_20, "")) {
		zephir_read_property(&_21$$6, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_22$$6);
		ZEPHIR_CONCAT_SV(&_22$$6, "; Path=", &_21$$6);
		zephir_concat_self(&format, &_22$$6);
	}
	zephir_read_property(&_23, this_ptr, ZEND_STRL("domain"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_23, "")) {
		zephir_read_property(&_24$$7, this_ptr, ZEND_STRL("domain"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_25$$7);
		ZEPHIR_CONCAT_SV(&_25$$7, "; Domain=", &_24$$7);
		zephir_concat_self(&format, &_25$$7);
	}
	zephir_read_property(&_26, this_ptr, ZEND_STRL("secure"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_26)) {
		zephir_concat_self_str(&format, SL("; Secure"));
	}
	zephir_read_property(&_27, this_ptr, ZEND_STRL("httpOnly"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_27)) {
		zephir_concat_self_str(&format, SL("; HttpOnly"));
	}
	zephir_read_property(&_28, this_ptr, ZEND_STRL("sameSite"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_28)) {
		zephir_read_property(&_29$$10, this_ptr, ZEND_STRL("sameSite"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_30$$10);
		ZEPHIR_CONCAT_SV(&_30$$10, "; SameSite=", &_29$$10);
		zephir_concat_self(&format, &_30$$10);
	}
	RETURN_CCTOR(&format);

}

/**
 * @param array matches
 * @return string
 */
PHP_METHOD(Zeplara_Cookie_Cookie, rawUrlEncodeFilter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *matches, matches_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matches_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches);



	zephir_array_fetch_long(&_0, matches, 0, PH_NOISY | PH_READONLY, "zeplara/Cookie/Cookie.zep", 260);
	ZEPHIR_RETURN_CALL_FUNCTION("rawurlencode", NULL, 45, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

