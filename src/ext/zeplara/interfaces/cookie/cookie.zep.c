
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Cookie_Cookie) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Cookie, Cookie, zeplara, interfaces_cookie_cookie, zeplara_interfaces_cookie_cookie_method_entry);

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(zeplara_interfaces_cookie_cookie_ce, SL("SAMESITE_NONE"), "None");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(zeplara_interfaces_cookie_cookie_ce, SL("SAMESITE_LAX"), "Lax");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(zeplara_interfaces_cookie_cookie_ce, SL("SAMESITE_STRICT"), "Strict");

	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, getName);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, getValue);

/**
 * @return int
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, getExpiration);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, getPath);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, getDomain);

/**
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, isSecure);

/**
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, isHttpOnly);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, getSameSite);

/**
 * @param string|null value
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, setValue);

/**
 * @param \DateTimeInterface|int|string expiration
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, setExpiration);

/**
 * @param string path
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, setPath);

/**
 * @param string domain
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, setDomain);

/**
 * @param bool secure
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, setSecure);

/**
 * @param bool httpOnly
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, setHttpOnly);

/**
 * @param string sameSite
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, setSameSite);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Cookie, __toString);

