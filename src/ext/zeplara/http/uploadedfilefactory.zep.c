
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_UploadedFileFactory) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Http, UploadedFileFactory, zeplara, http_uploadedfilefactory, zeplara_http_uploadedfilefactory_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_class_implements(zeplara_http_uploadedfilefactory_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\uploadedfilefactoryinterface")));
	return SUCCESS;

}

/**
 * @param StreamInterface stream
 * @param int size
 * @param int error
 * @param string clientFilename
 * @param string clientMediaType
 * @return UploadedFileInterface
 */
PHP_METHOD(Zeplara_Http_UploadedFileFactory, createUploadedFile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval clientFilename, clientFileMediaType;
	zend_long size, error, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *size_param = NULL, *error_param = NULL, *clientFilename_param = NULL, *clientFileMediaType_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&clientFilename);
	ZVAL_UNDEF(&clientFileMediaType);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &stream, &size_param, &error_param, &clientFilename_param, &clientFileMediaType_param);

	if (!size_param) {
		size = 0;
	} else {
		size = zephir_get_intval(size_param);
	}
	if (!error_param) {
		error = 0;
	} else {
		error = zephir_get_intval(error_param);
	}
	if (!clientFilename_param) {
		ZEPHIR_INIT_VAR(&clientFilename);
		ZVAL_STRING(&clientFilename, "");
	} else {
		zephir_get_strval(&clientFilename, clientFilename_param);
	}
	if (!clientFileMediaType_param) {
		ZEPHIR_INIT_VAR(&clientFileMediaType);
		ZVAL_STRING(&clientFileMediaType, "");
	} else {
		zephir_get_strval(&clientFileMediaType, clientFileMediaType_param);
	}


	ZVAL_LONG(&_0, size);
	ZVAL_LONG(&_1, error);
	ZEPHIR_RETURN_CALL_SELF("create", NULL, 0, stream, &clientFilename, &clientFileMediaType, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param StreamInterface stream
 * @param int size
 * @param int error
 * @param string clientFilename
 * @param string clientMediaType
 * @return UploadedFileInterface
 */
PHP_METHOD(Zeplara_Http_UploadedFileFactory, create) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval clientFilename, clientFileMediaType;
	zend_long size, error, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *size_param = NULL, *error_param = NULL, *clientFilename_param = NULL, *clientFileMediaType_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&clientFilename);
	ZVAL_UNDEF(&clientFileMediaType);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &stream, &size_param, &error_param, &clientFilename_param, &clientFileMediaType_param);

	if (!size_param) {
		size = 0;
	} else {
		size = zephir_get_intval(size_param);
	}
	if (!error_param) {
		error = 0;
	} else {
		error = zephir_get_intval(error_param);
	}
	if (!clientFilename_param) {
		ZEPHIR_INIT_VAR(&clientFilename);
		ZVAL_STRING(&clientFilename, "");
	} else {
		zephir_get_strval(&clientFilename, clientFilename_param);
	}
	if (!clientFileMediaType_param) {
		ZEPHIR_INIT_VAR(&clientFileMediaType);
		ZVAL_STRING(&clientFileMediaType, "");
	} else {
		zephir_get_strval(&clientFileMediaType, clientFileMediaType_param);
	}


	object_init_ex(return_value, zeplara_http_uploadedfile_ce);
	ZVAL_LONG(&_0, size);
	ZVAL_LONG(&_1, error);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 127, stream, &clientFilename, &clientFileMediaType, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

