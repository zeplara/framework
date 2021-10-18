
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


ZEPHIR_INIT_CLASS(Zeplara_Routing_RouteCompilerException) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Routing, RouteCompilerException, zeplara, routing_routecompilerexception, zend_exception_get_default(TSRMLS_C), NULL, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_routing_routecompilerexception_ce, 1, zeplara_contracts_routing_routecompilerexception_ce);
	return SUCCESS;

}

