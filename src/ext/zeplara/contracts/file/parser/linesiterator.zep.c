
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_File_Parser_LinesIterator) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\File\\Parser, LinesIterator, zeplara, contracts_file_parser_linesiterator, NULL);

	zend_class_implements(zeplara_contracts_file_parser_linesiterator_ce, 1, zend_ce_iterator);
	return SUCCESS;

}
