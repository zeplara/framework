
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
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Config_IniLoader) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Config, IniLoader, zeplara, config_iniloader, zeplara_config_iniloader_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_config_iniloader_ce, 1, zeplara_contracts_config_loader_ce);
	return SUCCESS;

}

/**
 * @param string file
 * @return array
 * @throws LoaderException
 */
PHP_METHOD(Zeplara_Config_IniLoader, load) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file, file_sub, _0$$3, _1$$3, _2$$3, _3$$3, e, _4, _5$$5, _6$$5, _7$$5, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);



	if ((zephir_file_exists(file) == SUCCESS) == 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, zeplara_config_loaderexception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "File [%s] does not exist.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 2, &_2$$3, file);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 11, &_3$$3, file);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "zeplara/Config/IniLoader.zep", 16);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		ZEPHIR_RETURN_CALL_FUNCTION("parse_ini_file", NULL, 12, file);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_OBJ(&_4, EG(exception));
		Z_ADDREF_P(&_4);
		if (zephir_is_instance_of(&_4, SL("Throwable"))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_4);
			ZEPHIR_INIT_VAR(&_5$$5);
			object_init_ex(&_5$$5, zeplara_config_loaderexception_ce);
			ZEPHIR_CALL_METHOD(&_6$$5, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$5, &e, "getfile", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$5, &e, "getline", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 11, &_6$$5, &_7$$5, &_8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$5, "zeplara/Config/IniLoader.zep", 24);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}

}

