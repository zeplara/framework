
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Application) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces, Application, zeplara, interfaces_application, zeplara_interfaces_application_method_entry);

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(zeplara_interfaces_application_ce, SL("VERSION"), "1.0.0");

	zend_class_implements(zeplara_interfaces_application_ce, 1, zeplara_interfaces_container_container_ce);
	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Application, getBasePath);

