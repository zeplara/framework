
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_File_Parser_YamlParser) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\File\\Parser, YamlParser, zeplara, file_parser_yamlparser, zeplara_file_parser_abstractparser_ce, zeplara_file_parser_yamlparser_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_file_parser_yamlparser_ce, 1, zeplara_contracts_file_parser_parser_ce);
	return SUCCESS;

}

/**
 * @var string contents
 * @return array
 */
PHP_METHOD(Zeplara_File_Parser_YamlParser, parse) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *contents_param = NULL;
	zval contents;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contents);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &contents_param);

	if (UNEXPECTED(Z_TYPE_P(contents_param) != IS_STRING && Z_TYPE_P(contents_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'contents' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(contents_param) == IS_STRING)) {
		zephir_get_strval(&contents, contents_param);
	} else {
		ZEPHIR_INIT_VAR(&contents);
		ZVAL_EMPTY_STRING(&contents);
	}


	object_init_ex(return_value, zeplara_file_parser_linesiterator_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 88, &contents);
	zephir_check_call_status();
	RETURN_MM();

}

