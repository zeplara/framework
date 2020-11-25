
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Session_Manager) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Session, Manager, zeplara, contracts_session_manager, zeplara_contracts_session_manager_method_entry);

	zend_class_implements(zeplara_contracts_session_manager_ce, 1, zeplara_contracts_repository_ce);
	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Session_Manager, getId);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Session_Manager, getName);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Session_Manager, getPrefix);

/**
 * @return \SessionHandlerInterface
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Session_Manager, getHandler);

/**
 * @param id
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Session_Manager, setId);

/**
 * @param prefix
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Session_Manager, setPrefix);

/**
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Session_Manager, isStarted);

/**
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Session_Manager, start);

/**
 * @param bool destroy
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Session_Manager, regenerate);

/**
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Session_Manager, save);

