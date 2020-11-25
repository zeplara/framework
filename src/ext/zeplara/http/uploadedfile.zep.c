
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_UploadedFile) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Http, UploadedFile, zeplara, http_uploadedfile, zeplara_http_uploadedfile_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(zeplara_http_uploadedfile_ce, SL("moved"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var StreamInterface
	 */
	zend_declare_property_null(zeplara_http_uploadedfile_ce, SL("stream"), ZEND_ACC_PROTECTED);

	/**
	 * @var int|null
	 */
	zend_declare_property_null(zeplara_http_uploadedfile_ce, SL("size"), ZEND_ACC_PROTECTED);

	/**
	 * @var int
	 */
	zend_declare_property_null(zeplara_http_uploadedfile_ce, SL("error"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_http_uploadedfile_ce, SL("clientFilename"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_http_uploadedfile_ce, SL("clientMediaType"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_http_uploadedfile_ce, SL("errors"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_class_implements(zeplara_http_uploadedfile_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\uploadedfileinterface")));
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Http_UploadedFile, getStream) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "stream");

}

/**
 */
PHP_METHOD(Zeplara_Http_UploadedFile, getSize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "size");

}

/**
 */
PHP_METHOD(Zeplara_Http_UploadedFile, getError) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "error");

}

/**
 */
PHP_METHOD(Zeplara_Http_UploadedFile, getClientFilename) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "clientFilename");

}

/**
 */
PHP_METHOD(Zeplara_Http_UploadedFile, getClientMediaType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "clientMediaType");

}

/**
 * @param StreamInterface stream
 * @param string clientFilename
 * @param string clientMediaType
 * @param int size
 * @param int error
 */
PHP_METHOD(Zeplara_Http_UploadedFile, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long error, ZEPHIR_LAST_CALL_STATUS;
	zval clientFilename, clientMediaType;
	zval *stream, stream_sub, *clientFilename_param = NULL, *clientMediaType_param = NULL, *size = NULL, size_sub, *error_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&size_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&clientFilename);
	ZVAL_UNDEF(&clientMediaType);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &stream, &clientFilename_param, &clientMediaType_param, &size, &error_param);

	if (UNEXPECTED(Z_TYPE_P(clientFilename_param) != IS_STRING && Z_TYPE_P(clientFilename_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clientFilename' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clientFilename_param) == IS_STRING)) {
		zephir_get_strval(&clientFilename, clientFilename_param);
	} else {
		ZEPHIR_INIT_VAR(&clientFilename);
		ZVAL_EMPTY_STRING(&clientFilename);
	}
	if (UNEXPECTED(Z_TYPE_P(clientMediaType_param) != IS_STRING && Z_TYPE_P(clientMediaType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clientMediaType' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(clientMediaType_param) == IS_STRING)) {
		zephir_get_strval(&clientMediaType, clientMediaType_param);
	} else {
		ZEPHIR_INIT_VAR(&clientMediaType);
		ZVAL_EMPTY_STRING(&clientMediaType);
	}
	ZEPHIR_SEPARATE_PARAM(size);
	if (!error_param) {
		error = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(error_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'error' must be of the type int"));
		RETURN_MM_NULL();
	}
	error = Z_LVAL_P(error_param);
	}


	zephir_read_static_property_ce(&_0, zeplara_http_uploadedfile_ce, SL("errors"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_long(&_0, error))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The error uploaded file is invalid.", "zeplara/Http/UploadedFile.zep", 65);
		return;
	}
	if (!(Z_TYPE_P(size) == IS_LONG)) {
		if (Z_TYPE_P(size) != IS_NULL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The size must be null or int.", "zeplara/Http/UploadedFile.zep", 70);
			return;
		} else {
			ZEPHIR_CALL_METHOD(size, stream, "getsize", NULL, 0);
			zephir_check_call_status();
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("stream"), stream);
	zephir_update_property_zval(this_ptr, ZEND_STRL("size"), size);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, error);
	zephir_update_property_zval(this_ptr, ZEND_STRL("error"), &_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("clientFilename"), &clientFilename);
	zephir_update_property_zval(this_ptr, ZEND_STRL("clientMediaType"), &clientMediaType);
	ZEPHIR_MM_RESTORE();

}

/**
 * @var string targetPath
 */
PHP_METHOD(Zeplara_Http_UploadedFile, moveTo) {

	zend_bool _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *targetPath, targetPath_sub, __$true, __$false, handle, size, _0, _5, _7, _9, _10, _11, _12, _13, _1$$3, _2$$3, _3$$3, _4$$3, _8$$6, _14$$9, _15$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("error"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_0, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_RuntimeException);
		zephir_read_static_property_ce(&_2$$3, zeplara_http_uploadedfile_ce, SL("errors"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_4$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("error"), PH_NOISY_CC);
		zephir_array_fetch(&_3$$3, &_2$$3, &_4$$3, PH_NOISY | PH_READONLY, "zeplara/Http/UploadedFile.zep", 91);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "zeplara/Http/UploadedFile.zep", 91);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("moved"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_5)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The file has been moved.", "zeplara/Http/UploadedFile.zep", 95);
		return;
	}
	_6 = Z_TYPE_P(targetPath) != IS_STRING;
	if (!(_6)) {
		_6 = ZEPHIR_IS_STRING_IDENTICAL(targetPath, "");
	}
	if (_6) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The target path should be string type.", "zeplara/Http/UploadedFile.zep", 99);
		return;
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("size"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_7)) {
		zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("size"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&size, &_8$$6);
	} else {
		ZEPHIR_INIT_NVAR(&size);
		ZVAL_LONG(&size, 1048576);
	}
	ZEPHIR_CALL_FUNCTION(NULL, "error_clear_last", NULL, 47);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_INIT_NVAR(&_9);
	zephir_create_closure_ex(&_9, NULL, zeplara_1__closure_ce, SL("__invoke"));
	ZVAL_LONG(&_10, 2);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 48, &_9, &_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "wb+");
	ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 90, targetPath, &_11);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 54);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&handle)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The target path is not writable.", "zeplara/Http/UploadedFile.zep", 118);
		return;
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("stream"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_10, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_12, this_ptr, ZEND_STRL("stream"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_13, &_12, "eof", NULL, 0);
		zephir_check_call_status();
		if (!(!(zephir_is_true(&_13)))) {
			break;
		}
		zephir_read_property(&_14$$9, this_ptr, ZEND_STRL("stream"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_15$$9, &_14$$9, "read", NULL, 0, &size);
		zephir_check_call_status();
		zephir_fwrite(NULL, &handle, &_15$$9);
	}
	zephir_fclose(&handle);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("moved"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("moved"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Zeplara_Http_UploadedFile, isMoved) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "moved");

}

void zephir_init_static_properties_Zeplara_Http_UploadedFile(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 8, 0);
	add_index_stringl(&_0, 0, SL("There is no error, the file uploaded with success."));
	add_index_stringl(&_0, 1, SL("The uploaded file exceeds the size directive in php.ini."));
	add_index_stringl(&_0, 2, SL("The uploaded file exceeds the size directive that was specified in the HTML form."));
	add_index_stringl(&_0, 3, SL("The uploaded file was only partially uploaded."));
	add_index_stringl(&_0, 4, SL("No file was uploaded."));
	add_index_stringl(&_0, 6, SL("Missing a temporary folder."));
	add_index_stringl(&_0, 7, SL("Failed to write file to disk."));
	add_index_stringl(&_0, 8, SL("A PHP extension stopped the file upload."));
	zephir_update_static_property_ce(zeplara_http_uploadedfile_ce, ZEND_STRL("errors"), &_0);
	ZEPHIR_MM_RESTORE();

}

