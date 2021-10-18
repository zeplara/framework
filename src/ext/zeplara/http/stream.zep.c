
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Zeplara_Http_Stream) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Http, Stream, zeplara, http_stream, zeplara_http_stream_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var int|null
	 */
	zend_declare_property_null(zeplara_http_stream_ce, SL("size"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_null(zeplara_http_stream_ce, SL("seekable"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_null(zeplara_http_stream_ce, SL("readable"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_null(zeplara_http_stream_ce, SL("writable"), ZEND_ACC_PROTECTED);

	/**
	 * @var $resource
	 */
	zend_declare_property_null(zeplara_http_stream_ce, SL("resource"), ZEND_ACC_PRIVATE);

	zend_class_implements(zeplara_http_stream_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\streaminterface")));
	return SUCCESS;

}

/**
 * Stream constructor.
 *
 * @param resource $resource
 */
PHP_METHOD(Zeplara_Http_Stream, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resource, resource_sub, __$true, __$false, meta, _1, _2, _3, _4, _5, _6, _7, _8, _9, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resource_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&meta);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);

	if (UNEXPECTED(Z_TYPE_P(resource) != IS_RESOURCE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'resource' must be of the type resource"));
		RETURN_MM_NULL();
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("resource"), resource);
	ZEPHIR_CALL_FUNCTION(&meta, "stream_get_meta_data", NULL, 110, resource);
	zephir_check_call_status();
	if (zephir_array_isset_string(&meta, SL("seekable"))) {
		zephir_array_fetch_string(&_0$$3, &meta, SL("seekable"), PH_NOISY | PH_READONLY, "zeplara/Http/Stream.zep", 41);
		zephir_update_property_zval(this_ptr, ZEND_STRL("seekable"), &_0$$3);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_array_fetch_string(&_2, &meta, SL("mode"), PH_NOISY | PH_READONLY, "zeplara/Http/Stream.zep", 44);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/r|a\\+|ab\\+|w\\+|wb\\+|x\\+|xb\\+|c\\+|cb\\+/");
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "/r|a\\+|ab\\+|w\\+|wb\\+|x\\+|xb\\+|c\\+|cb\\+/");
	zephir_preg_match(&_4, &_5, &_2, &_1, 0, 0 , 0 );
	if (zephir_get_boolval(&_4)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("readable"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("readable"), &__$false);
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_array_fetch_string(&_7, &meta, SL("mode"), PH_NOISY | PH_READONLY, "zeplara/Http/Stream.zep", 45);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "/a|w|r\\+|rb\\+|rw|x|c/");
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "/a|w|r\\+|rb\\+|rw|x|c/");
	zephir_preg_match(&_8, &_9, &_7, &_6, 0, 0 , 0 );
	if (zephir_get_boolval(&_8)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("writable"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("writable"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @return int|null
 */
PHP_METHOD(Zeplara_Http_Stream, getSize) {

	zend_bool _1;
	zval _0, _2, stats$$3, _3$$3, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&stats$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("size"), PH_NOISY_CC);
	_1 = Z_TYPE_P(&_0) == IS_NULL;
	if (_1) {
		ZEPHIR_OBS_VAR(&_2);
		zephir_read_property(&_2, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC);
		_1 = Z_TYPE_P(&_2) != IS_NULL;
	}
	if (_1) {
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&stats$$3, "fstat", NULL, 111, &_3$$3);
		zephir_check_call_status();
		if (zephir_array_isset_string(&stats$$3, SL("size"))) {
			zephir_array_fetch_string(&_4$$4, &stats$$3, SL("size"), PH_NOISY | PH_READONLY, "zeplara/Http/Stream.zep", 57);
			zephir_update_property_zval(this_ptr, ZEND_STRL("size"), &_4$$4);
		}
	}
	RETURN_MM_MEMBER(getThis(), "size");

}

/**
 * @return bool|int
 */
PHP_METHOD(Zeplara_Http_Stream, tell) {

	zval tell, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tell);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertdetachedstream", NULL, 112);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&tell, "ftell", NULL, 113, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&tell)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Uncaught position a stream.", "zeplara/Http/Stream.zep", 76);
		return;
	}
	RETURN_CCTOR(&tell);

}

/**
 * @return bool
 */
PHP_METHOD(Zeplara_Http_Stream, eof) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertdetachedstream", NULL, 112);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_feof(&_0));

}

/**
 * Returns whether or not the stream is seekable.
 *
 * @return bool
 */
PHP_METHOD(Zeplara_Http_Stream, isSeekable) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "seekable");

}

/**
 * @param int offset
 * @param int whence
 * @return void
 */
PHP_METHOD(Zeplara_Http_Stream, seek) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub, *whence = NULL, whence_sub, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&whence_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &offset, &whence);

	if (!whence) {
		whence = &whence_sub;
		ZEPHIR_INIT_VAR(whence);
		ZVAL_LONG(whence, 0);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertdetachedstream", NULL, 112);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("seekable"), PH_NOISY_CC | PH_READONLY);
	_1 = !zephir_is_true(&_0);
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_3, "fseek", NULL, 114, &_2, offset, whence);
		zephir_check_call_status();
		_1 = ZEPHIR_IS_LONG_IDENTICAL(&_3, -1);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could not seek in stream.", "zeplara/Http/Stream.zep", 111);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @return void
 */
PHP_METHOD(Zeplara_Http_Stream, rewind) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 115, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns whether or not the stream is writable.
 *
 * @return bool
 */
PHP_METHOD(Zeplara_Http_Stream, isWritable) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "writable");

}

/**
 * @param string value
 * @return bool|int
 */
PHP_METHOD(Zeplara_Http_Stream, write) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, __$null, write, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&write);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertdetachedstream", NULL, 112);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("writable"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The resource is not writable.", "zeplara/Http/Stream.zep", 143);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&write);
	zephir_fwrite(&write, &_1, value);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&write)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could'nt write to stream.", "zeplara/Http/Stream.zep", 148);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("size"), &__$null);
	RETURN_CCTOR(&write);

}

/**
 * Returns whether or not the stream is readable.
 *
 * @return bool
 */
PHP_METHOD(Zeplara_Http_Stream, isReadable) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "readable");

}

/**
 * @param int length
 * @return string
 */
PHP_METHOD(Zeplara_Http_Stream, read) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *length, length_sub, data, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &length);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertdetachedstream", NULL, 112);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(length, 0)) {
		RETURN_MM_STRING("");
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("readable"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The resource is not readable.", "zeplara/Http/Stream.zep", 177);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&data, "fread", NULL, 116, &_1, length);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could'nt read from stream.", "zeplara/Http/Stream.zep", 183);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * @return string
 */
PHP_METHOD(Zeplara_Http_Stream, getContents) {

	zval content, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertdetachedstream", NULL, 112);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&content, "stream_get_contents", NULL, 117, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&content)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Uncaught to read the stream.", "zeplara/Http/Stream.zep", 200);
		return;
	}
	RETURN_CCTOR(&content);

}

/**
 * @param null key
 * @return array|mixed|null
 */
PHP_METHOD(Zeplara_Http_Stream, getMetadata) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, __$null, _0, metaData, _1, _2$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		if (Z_TYPE_P(key) == IS_NULL) {
			RETVAL_ZVAL(key, 1, 0);
			RETURN_MM();
		}
		array_init(return_value);
		RETURN_MM();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&metaData, "stream_get_meta_data", NULL, 110, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(key) == IS_NULL) {
		RETURN_CCTOR(&metaData);
	}
	if (zephir_array_isset(&metaData, key)) {
		zephir_array_fetch(&_2$$6, &metaData, key, PH_NOISY | PH_READONLY, "zeplara/Http/Stream.zep", 225);
		RETURN_CTOR(&_2$$6);
	}
	RETURN_MM_NULL();

}

/**
 * @return resource|null
 */
PHP_METHOD(Zeplara_Http_Stream, detach) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, __$true, __$false, resource, _0;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&resource);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&resource, &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("size"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("resource"), &__$null);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("seekable"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("seekable"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("readable"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("readable"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("writable"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("writable"), &__$false);
	}
	RETURN_CCTOR(&resource);

}

/**
 * @return void
 */
PHP_METHOD(Zeplara_Http_Stream, close) {

	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC | PH_READONLY);
		zephir_fclose(&_1$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 118);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Zeplara_Http_Stream, __toString) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 119);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcontents", NULL, 120);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_0);
		ZVAL_OBJ(&_0, EG(exception));
		Z_ADDREF_P(&_0);
		ZEPHIR_INIT_VAR(&_1);
		if (zephir_instance_of_ev(&_0, spl_ce_RuntimeException)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_1, &_0);
			RETURN_MM_STRING("");
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Zeplara_Http_Stream, __destruct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "close", NULL, 121);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return void
 */
PHP_METHOD(Zeplara_Http_Stream, assertDetachedStream) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("resource"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "The stream has been detach.", "zeplara/Http/Stream.zep", 286);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

