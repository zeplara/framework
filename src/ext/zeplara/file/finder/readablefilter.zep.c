
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_File_Finder_ReadableFilter) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\File\\Finder, ReadableFilter, zeplara, file_finder_readablefilter, zeplara_file_finder_readablefilter_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_file_finder_readablefilter_ce, 1, zeplara_interfaces_file_finder_filter_ce);
	return SUCCESS;

}

/**
 * @param SplFileInfo fileInfo
 * @return bool
 */
PHP_METHOD(Zeplara_File_Finder_ReadableFilter, accept) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fileInfo, fileInfo_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileInfo_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fileInfo);



	ZEPHIR_RETURN_CALL_METHOD(fileInfo, "isreadable", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

