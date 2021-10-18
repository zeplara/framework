
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_File_SplFileInfo) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\File, SplFileInfo, zeplara, contracts_file_splfileinfo, NULL);

	return SUCCESS;

}

