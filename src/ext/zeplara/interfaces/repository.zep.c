
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Repository) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces, Repository, zeplara, interfaces_repository, zeplara_interfaces_repository_method_entry);

	zend_class_implements(zeplara_interfaces_repository_ce, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Repository, getItems);

/**
 * @param array items
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Repository, setItems);

/**
 * @param key
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Repository, has);

/**
 * @param key
 * @param null defaultValue
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Repository, get);

/**
 * @param key
 * @param value
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Repository, set);

/**
 * @param key
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Repository, put);

/**
 * @param string key
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Repository, __get);

/**
 * @param string key
 * @return bool
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Repository, __isset);

/**
 * @param string key
 * @param value
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Repository, __set);

/**
 * @param string key
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Repository, __unset);

