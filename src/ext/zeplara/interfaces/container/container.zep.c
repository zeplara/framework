
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Container_Container) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Container, Container, zeplara, interfaces_container_container, zeplara_interfaces_container_container_method_entry);

	zend_class_implements(zeplara_interfaces_container_container_ce, 1, zephir_get_internal_ce(SL("psr\\container\\containerinterface")));
	zend_class_implements(zeplara_interfaces_container_container_ce, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * @param key
 * @param value
 * @param bool resolve
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Container_Container, set);

/**
 * @param key
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Container_Container, put);

/**
 * @param abstrct
 * @param array arguments
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Container_Container, make);

/**
 * @param string key
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Container_Container, __get);

/**
 * @param string key
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Container_Container, __isset);

/**
 * @param string key
 * @param value
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Container_Container, __set);

/**
 * @param string key
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Container_Container, __unset);

