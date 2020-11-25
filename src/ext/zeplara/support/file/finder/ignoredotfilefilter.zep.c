
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_File_Finder_IgnoreDotFileFilter) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Support\\File\\Finder, IgnoreDotFileFilter, zeplara, support_file_finder_ignoredotfilefilter, zeplara_support_file_finder_abstractfilter_ce, zeplara_support_file_finder_ignoredotfilefilter_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

/**
 * @param SplFileInfo fileInfo
 * @return bool
 */
PHP_METHOD(Zeplara_Support_File_Finder_IgnoreDotFileFilter, accept) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fileInfo, fileInfo_sub, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileInfo_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fileInfo);



	ZEPHIR_CALL_METHOD(&_0, fileInfo, "isfile", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZVAL_LONG(&_1$$3, 8);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "pathinfo", NULL, 169, fileInfo, &_1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(!ZEPHIR_IS_STRING_IDENTICAL(&_2$$3, ""));
	}
	RETURN_MM_BOOL(1);

}

