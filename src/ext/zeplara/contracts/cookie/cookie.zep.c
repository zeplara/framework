
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Cookie_Cookie) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Cookie, Cookie, zeplara, contracts_cookie_cookie, zeplara_contracts_cookie_cookie_method_entry);

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(zeplara_contracts_cookie_cookie_ce, SL("SAMESITE_NONE"), "None");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(zeplara_contracts_cookie_cookie_ce, SL("SAMESITE_LAX"), "Lax");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(zeplara_contracts_cookie_cookie_ce, SL("SAMESITE_STRICT"), "Strict");

	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, getName);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, getValue);

/**
 * @return int
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, getExpiration);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, getPath);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, getDomain);

/**
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, isSecure);

/**
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, isHttpOnly);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, getSameSite);

/**
 * @param value
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, setValue);

/**
 * @param DateTimeInterface|int|string| expiration
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, setExpiration);

/**
 * @param path
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, setPath);

/**
 * @param domain
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, setDomain);

/**
 * @param bool secure
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, setSecure);

/**
 * @param bool httpOnly
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, setHttpOnly);

/**
 * @param sameSite
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, setSameSite);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Cookie_Cookie, __toString);

