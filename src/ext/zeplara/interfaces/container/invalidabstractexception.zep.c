
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Container_InvalidAbstractException) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Container, InvalidAbstractException, zeplara, interfaces_container_invalidabstractexception, zeplara_interfaces_container_invalidabstractexception_method_entry);

	zend_class_implements(zeplara_interfaces_container_invalidabstractexception_ce, 1, zephir_get_internal_ce(SL("throwable")));
	return SUCCESS;

}

/**
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Container_InvalidAbstractException, getAbstract);

