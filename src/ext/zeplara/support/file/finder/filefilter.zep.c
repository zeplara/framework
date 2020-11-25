
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_File_Finder_FileFilter) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Support\\File\\Finder, FileFilter, zeplara, support_file_finder_filefilter, zeplara_support_file_finder_abstractfilter_ce, zeplara_support_file_finder_filefilter_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

/**
 * @param SplFileInfo fileInfo
 * @return bool
 */
PHP_METHOD(Zeplara_Support_File_Finder_FileFilter, accept) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fileInfo, fileInfo_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileInfo_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fileInfo);



	ZEPHIR_RETURN_CALL_METHOD(fileInfo, "isfile", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

