
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Application) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts, Application, zeplara, contracts_application, zeplara_contracts_application_method_entry);

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(zeplara_contracts_application_ce, SL("VERSION"), "1.0.0");

	zend_class_implements(zeplara_contracts_application_ce, 1, zeplara_contracts_container_container_ce);
	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Application, getBasePath);

