
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
#include "ext/spl/spl_directory.h"


ZEPHIR_INIT_CLASS(Zeplara_File_SplFileInfo) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\File, SplFileInfo, zeplara, file_splfileinfo, spl_ce_SplFileInfo, NULL, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_file_splfileinfo_ce, 1, zeplara_contracts_file_splfileinfo_ce);
	return SUCCESS;

}

