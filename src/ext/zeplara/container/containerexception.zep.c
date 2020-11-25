
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
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Zeplara_Container_ContainerException) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Container, ContainerException, zeplara, container_containerexception, spl_ce_RuntimeException, NULL, 0);

	zend_class_implements(zeplara_container_containerexception_ce, 1, zephir_get_internal_ce(SL("psr\\container\\containerexceptioninterface")));
	return SUCCESS;

}

