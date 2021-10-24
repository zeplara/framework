
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_File_SplFileInfo) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\File, SplFileInfo, zeplara, interfaces_file_splfileinfo, NULL);

	return SUCCESS;

}

