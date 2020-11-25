
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
#include "ext/spl/spl_directory.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_File_SplFileInfo) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Support\\File, SplFileInfo, zeplara, support_file_splfileinfo, spl_ce_SplFileInfo, NULL, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

