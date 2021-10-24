
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Session_Flash) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Session, Flash, zeplara, interfaces_session_flash, zeplara_interfaces_session_flash_method_entry);

	zend_class_implements(zeplara_interfaces_session_flash_ce, 1, zeplara_interfaces_repository_ce);
	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Session_Flash, getName);

/**
 * @return Manager
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Session_Flash, getManager);

