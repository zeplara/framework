
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
#include "kernel/time.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Zeplara_Cookie_Factory) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Cookie, Factory, zeplara, cookie_factory, zeplara_cookie_factory_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Zeplara_Cookie_Factory, __construct) {

	zval *this_ptr = getThis();



}

/**
 * @param name
 * @param string value
 * @param int expiration
 * @param string path
 * @param string domain
 * @param bool secure
 * @param bool httpOnly
 * @param null sameSite
 * @return Cookie
 */
PHP_METHOD(Zeplara_Cookie_Factory, make) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value = NULL, value_sub, *expiration = NULL, expiration_sub, *path = NULL, path_sub, *domain = NULL, domain_sub, *secure = NULL, secure_sub, *httpOnly = NULL, httpOnly_sub, *sameSite = NULL, sameSite_sub, __$false, __$true, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&expiration_sub);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&domain_sub);
	ZVAL_UNDEF(&secure_sub);
	ZVAL_UNDEF(&httpOnly_sub);
	ZVAL_UNDEF(&sameSite_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 7, &name, &value, &expiration, &path, &domain, &secure, &httpOnly, &sameSite);

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
		sameSite = &__$null;
	}


	object_init_ex(return_value, zeplara_cookie_cookie_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 46, name, value, expiration, path, domain, secure, httpOnly, sameSite);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param name
 * @param string value
 * @param string path
 * @param string domain
 * @param bool secure
 * @param bool httpOnly
 * @param null sameSite
 * @return Cookie
 */
PHP_METHOD(Zeplara_Cookie_Factory, forever) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value = NULL, value_sub, *path = NULL, path_sub, *domain = NULL, domain_sub, *secure = NULL, secure_sub, *httpOnly = NULL, httpOnly_sub, *sameSite = NULL, sameSite_sub, __$false, __$true, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&domain_sub);
	ZVAL_UNDEF(&secure_sub);
	ZVAL_UNDEF(&httpOnly_sub);
	ZVAL_UNDEF(&sameSite_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &name, &value, &path, &domain, &secure, &httpOnly, &sameSite);

	if (!value) {
		value = &value_sub;
		ZEPHIR_INIT_VAR(value);
		ZVAL_STRING(value, "");
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
		sameSite = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) + 315360000));
	ZEPHIR_RETURN_CALL_SELF("make", NULL, 0, name, value, &_1, path, domain, secure, httpOnly, sameSite);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param name
 * @param string path
 * @param string domain
 * @param bool secure
 * @param bool httpOnly
 * @param null sameSite
 * @return Cookie
 */
PHP_METHOD(Zeplara_Cookie_Factory, forget) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *path = NULL, path_sub, *domain = NULL, domain_sub, *secure = NULL, secure_sub, *httpOnly = NULL, httpOnly_sub, *sameSite = NULL, sameSite_sub, __$false, __$true, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&domain_sub);
	ZVAL_UNDEF(&secure_sub);
	ZVAL_UNDEF(&httpOnly_sub);
	ZVAL_UNDEF(&sameSite_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &name, &path, &domain, &secure, &httpOnly, &sameSite);

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
		sameSite = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZVAL_LONG(&_2, (zephir_get_numberval(&_0) - 3600));
	ZEPHIR_RETURN_CALL_SELF("make", NULL, 0, name, &_1, &_2, path, domain, secure, httpOnly, sameSite);
	zephir_check_call_status();
	RETURN_MM();

}

