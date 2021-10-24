
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Cookie_Queue) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Cookie, Queue, zeplara, interfaces_cookie_queue, zeplara_interfaces_cookie_queue_method_entry);

	return SUCCESS;

}

/**
 * @param string key
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Queue, has);

/**
 * @param string key
 * @return Cookie
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Queue, get);

/**
 * @param Cookie cookie
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Queue, set);

/**
 * @param string key
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Queue, put);

/**
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Cookie_Queue, getCookies);

