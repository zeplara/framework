
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Support_File_Parser_YamlParser) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Support\\File\\Parser, YamlParser, zeplara, support_file_parser_yamlparser, zeplara_support_file_parser_abstractparser_ce, zeplara_support_file_parser_yamlparser_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(Zeplara_Support_File_Parser_YamlParser, parse) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *contents_param = NULL, lines;
	zval contents;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&lines);

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


	ZEPHIR_INIT_VAR(&lines);
	object_init_ex(&lines, zeplara_support_file_parser_linesiterator_ce);
	ZEPHIR_CALL_METHOD(NULL, &lines, "__construct", NULL, 173, &contents);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "print_r", NULL, 183, &lines);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

