
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


ZEPHIR_INIT_CLASS(Zeplara_Routing_CompiledRoute) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Routing, CompiledRoute, zeplara, routing_compiledroute, zeplara_routing_compiledroute_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var Regex
	 */
	zend_declare_property_null(zeplara_routing_compiledroute_ce, SL("host"), ZEND_ACC_PROTECTED);

	/**
	 * @var Regex
	 */
	zend_declare_property_null(zeplara_routing_compiledroute_ce, SL("path"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_routing_compiledroute_ce, 1, zeplara_contracts_routing_compiledroute_ce);
	return SUCCESS;

}

/** 
 * @param Regex host
 * @param Regex path
 */
PHP_METHOD(Zeplara_Routing_CompiledRoute, __construct) {

	zval *host, host_sub, *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host_sub);
	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &host, &path);



	zephir_update_property_zval(this_ptr, ZEND_STRL("host"), host);
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), path);

}

/**
 * @return Regex
 */
PHP_METHOD(Zeplara_Routing_CompiledRoute, getHost) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "host");

}

/**
 * @return Regex
 */
PHP_METHOD(Zeplara_Routing_CompiledRoute, getPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "path");

}

