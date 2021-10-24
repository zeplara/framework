
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Config_JsonLoader) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Config, JsonLoader, zeplara, config_jsonloader, zeplara_config_jsonloader_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_config_jsonloader_ce, 1, zeplara_interfaces_config_loader_ce);
	return SUCCESS;

}

/**
 * @param string file
 * @return array
 * @throws LoaderException
 */
PHP_METHOD(Zeplara_Config_JsonLoader, load) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file, file_sub, __$false, __$null, __$true, _0$$3, _1$$3, _2$$3, _3$$3, items, _5, _6, _7, _8, _9$$4, _10$$4, _11$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);



	if ((zephir_file_exists(file) == SUCCESS) == 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, zeplara_config_loaderexception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "File [%s] does not exist.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 2, &_2$$3, file);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", &_4, 11, &_3$$3, file);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "zeplara/Config/JsonLoader.zep", 15);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_5, "filesize", NULL, 13, file);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 0);
	ZEPHIR_CALL_FUNCTION(&_7, "file_get_contents", NULL, 14, file, &__$false, &__$null, &_6, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&items);
	zephir_json_decode(&items, &_7, zephir_get_intval(&__$true) );
	ZEPHIR_CALL_FUNCTION(&_8, "json_last_error", NULL, 15);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_8, 0)) {
		ZEPHIR_INIT_VAR(&_9$$4);
		object_init_ex(&_9$$4, zeplara_config_loaderexception_ce);
		ZEPHIR_CALL_FUNCTION(&_10$$4, "json_last_error_msg", NULL, 16);
		zephir_check_call_status();
		ZVAL_LONG(&_11$$4, 0);
		ZEPHIR_CALL_METHOD(NULL, &_9$$4, "__construct", &_4, 11, &_10$$4, file, &_11$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$4, "zeplara/Config/JsonLoader.zep", 23);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&items);

}

