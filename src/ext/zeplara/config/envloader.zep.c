
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Zeplara_Config_EnvLoader) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Config, EnvLoader, zeplara, config_envloader, zeplara_config_envloader_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_config_envloader_ce, 1, zeplara_contracts_config_loader_ce);
	return SUCCESS;

}

/**
 * @param string file
 * @return array
 * @throws LoaderException
 */
PHP_METHOD(Zeplara_Config_EnvLoader, load) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file, file_sub, e, _1, _0$$3, _2$$4, _3$$4, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);




	/* try_start_1: */

		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, zeplara_file_parser_envparser_ce);
		if (zephir_has_constructor(&_0$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_0$$3, "parsefile", NULL, 10, file);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		if (zephir_instance_of_ev(&_1, zeplara_file_parser_parserexception_ce)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_1);
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, zeplara_config_loaderexception_ce);
			ZEPHIR_CALL_METHOD(&_3$$4, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$4, &e, "getfile", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5$$4, &e, "getline", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 11, &_3$$4, &_4$$4, &_5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "zeplara/Config/EnvLoader.zep", 21);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}

}

