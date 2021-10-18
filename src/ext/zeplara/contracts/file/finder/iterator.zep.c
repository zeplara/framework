
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_File_Finder_Iterator) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\File\\Finder, Iterator, zeplara, contracts_file_finder_iterator, NULL);

	zend_class_implements(zeplara_contracts_file_finder_iterator_ce, 1, zend_ce_iterator);
	return SUCCESS;

}

