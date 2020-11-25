
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Repository) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts, Repository, zeplara, contracts_repository, zeplara_contracts_repository_method_entry);

	zend_class_implements(zeplara_contracts_repository_ce, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Repository, getItems);

/**
 * @param array items
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Repository, setItems);

/**
 * @param key
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Repository, has);

/**
 * @param key
 * @param null defaultValue
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Repository, get);

/**
 * @param key
 * @param value
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Repository, set);

/**
 * @param key
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Repository, put);

/**
 * @param string key
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Repository, __get);

/**
 * @param string key
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Repository, __isset);

/**
 * @param string key
 * @param value
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Repository, __set);

/**
 * @param string key
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Repository, __unset);

