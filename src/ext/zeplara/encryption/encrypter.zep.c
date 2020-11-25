
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Zeplara_Encryption_Encrypter) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Encryption, Encrypter, zeplara, encryption_encrypter, zeplara_encryption_encrypter_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_encryption_encrypter_ce, SL("key"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_encryption_encrypter_ce, SL("cipher"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_encryption_encrypter_ce, SL("cipherMethods"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_encryption_encrypter_ce, SL("ivLengthCache"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_class_implements(zeplara_encryption_encrypter_ce, 1, zeplara_contracts_encryption_encrypter_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Encryption_Encrypter, getKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "key");

}

/**
 */
PHP_METHOD(Zeplara_Encryption_Encrypter, getCipher) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cipher");

}

/**
 * @param string key
 * @param string cipher
 * @throws EncryptionException
 */
PHP_METHOD(Zeplara_Encryption_Encrypter, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *key_param = NULL, *cipher_param = NULL, _0, _2, _3$$3, _4$$3, _5$$3;
	zval key, cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &cipher_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	if (UNEXPECTED(Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cipher_param) == IS_STRING)) {
		zephir_get_strval(&cipher, cipher_param);
	} else {
		ZEPHIR_INIT_VAR(&cipher);
		ZVAL_EMPTY_STRING(&cipher);
	}


	ZEPHIR_CALL_CE_STATIC(&_0, zeplara_support_str_ce, "upper", &_1, 0, &cipher);
	zephir_check_call_status();
	zephir_get_strval(&cipher, &_0);
	zephir_read_static_property_ce(&_2, zeplara_encryption_encrypter_ce, SL("cipherMethods"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_2, &cipher))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Cipher %s is not supported.");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", NULL, 2, &_4$$3, &cipher);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwencryptionexception", NULL, 46, &_5$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("key"), &key);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cipher"), &cipher);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param value
 * @return string
 * @throws EncryptionException
 */
PHP_METHOD(Zeplara_Encryption_Encrypter, encrypt) {

	zval _0, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, iv, _1, _2, _3, _4, _5, _8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_CALL_FUNCTION(NULL, "error_clear_last", NULL, 47);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "throwEncryptError");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 48, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&iv, this_ptr, "generateiv", NULL, 49);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "serialize", NULL, 50, value);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("key"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_CALL_FUNCTION(value, "openssl_encrypt", NULL, 51, &_2, &_3, &_4, &_5, &iv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwencrypterror", &_6, 52);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0);
	ZEPHIR_CALL_FUNCTION(&_8, "base64_encode", &_9, 53, &iv);
	zephir_check_call_status();
	zephir_array_update_string(&_7, SL("iv"), &_8, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_7, SL("value"), value, PH_COPY | PH_SEPARATE);
	zephir_json_encode(&_1, &_7, 0 );
	ZEPHIR_CALL_FUNCTION(value, "base64_encode", &_9, 53, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_8, "json_last_error", NULL, 15);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_8, 0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwencrypterror", &_6, 52);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 54);
	zephir_check_call_status();
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * @param string value
 * @return mixed
 */
PHP_METHOD(Zeplara_Encryption_Encrypter, decrypt) {

	zend_bool _6;
	zval _0, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, __$true, _1, _2, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	if (Z_TYPE_P(value) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The encrypted value must be string.", "zeplara/Encryption/Encrypter.zep", 176);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "error_clear_last", NULL, 47);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "throwDecryptError");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 48, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "base64_decode", &_3, 55, value);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, &_2);
	if (ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdecrypterror", &_4, 56);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_1);
	zephir_json_decode(&_1, value, zephir_get_intval(&__$true) );
	ZEPHIR_CPY_WRT(value, &_1);
	ZEPHIR_CALL_FUNCTION(&_2, "json_last_error", NULL, 15);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_2, 0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdecrypterror", &_4, 56);
		zephir_check_call_status();
	}
	zephir_get_arrval(&_5, value);
	ZEPHIR_CPY_WRT(value, &_5);
	_6 = zephir_array_isset_string(value, SL("iv")) == 0;
	if (_6) {
		_6 = zephir_array_isset_string(value, SL("value")) == 0;
	}
	if (_6) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdecrypterror", &_4, 56);
		zephir_check_call_status();
	}
	zephir_array_fetch_string(&_7, value, SL("iv"), PH_NOISY | PH_READONLY, "zeplara/Encryption/Encrypter.zep", 200);
	ZEPHIR_CALL_FUNCTION(&_8, "base64_decode", &_3, 55, &_7);
	zephir_check_call_status();
	zephir_array_update_string(value, SL("iv"), &_8, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_10, value, SL("iv"), PH_NOISY | PH_READONLY, "zeplara/Encryption/Encrypter.zep", 202);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "isvalidiv", NULL, 57, &_10);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_9)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdecrypterror", &_4, 56);
		zephir_check_call_status();
	}
	zephir_array_fetch_string(&_11, value, SL("value"), PH_NOISY | PH_READONLY, "zeplara/Encryption/Encrypter.zep", 206);
	zephir_read_property(&_12, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_13, this_ptr, ZEND_STRL("key"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_14, value, SL("iv"), PH_NOISY | PH_READONLY, "zeplara/Encryption/Encrypter.zep", 206);
	ZVAL_LONG(&_15, 0);
	ZEPHIR_CALL_FUNCTION(value, "openssl_decrypt", NULL, 58, &_11, &_12, &_13, &_15, &_14);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwdecrypterror", &_4, 56);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_16, "unserialize", NULL, 59, value);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, &_16);
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 54);
	zephir_check_call_status();
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * @return int
 */
PHP_METHOD(Zeplara_Encryption_Encrypter, IvLength) {

	zval _0, _1, _5, _6, _7, _2$$3, _3$$3, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, zeplara_encryption_encrypter_ce, SL("ivLengthCache"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &_1))) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "openssl_cipher_iv_length", NULL, 60, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&_4$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC);
		zephir_update_static_property_array_multi_ce(zeplara_encryption_encrypter_ce, SL("ivLengthCache"), &_3$$3, SL("z"), 1, &_4$$3);
	}
	zephir_read_static_property_ce(&_5, zeplara_encryption_encrypter_ce, SL("ivLengthCache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_6);
	ZEPHIR_OBS_VAR(&_7);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC);
	zephir_array_fetch(&_6, &_5, &_7, PH_NOISY, "zeplara/Encryption/Encrypter.zep", 228);
	RETURN_MM_LONG(zephir_get_intval(&_6));

}

/**
 * @return string
 */
PHP_METHOD(Zeplara_Encryption_Encrypter, generateIv) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "ivlength", NULL, 61);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_random_pseudo_bytes", NULL, 62, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string iv
 * @return bool
 */
PHP_METHOD(Zeplara_Encryption_Encrypter, isValidIv) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *iv, iv_sub, ivLength, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&iv_sub);
	ZVAL_UNDEF(&ivLength);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &iv);



	ZEPHIR_CALL_METHOD(&ivLength, this_ptr, "ivlength", NULL, 61);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "8bit");
	ZEPHIR_CALL_FUNCTION(&_2, "mb_strcut", NULL, 63, iv, &_0, &ivLength, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "8bit");
	ZEPHIR_CALL_FUNCTION(&_3, "mb_strlen", NULL, 64, &_2, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&ivLength, zephir_get_intval(&_3)));

}

/**
 * @param string message
 * @throws EncryptionException
 */
PHP_METHOD(Zeplara_Encryption_Encrypter, throwEncryptionException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zeplara_encryption_encryptionexception_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 65, message);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "zeplara/Encryption/Encrypter.zep", 257);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * @throws EncryptionException
 */
PHP_METHOD(Zeplara_Encryption_Encrypter, throwEncryptError) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Could not encrypt data.");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwencryptionexception", NULL, 46, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @throws EncryptionException
 */
PHP_METHOD(Zeplara_Encryption_Encrypter, throwDecryptError) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Could not decrypt data.");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwencryptionexception", NULL, 46, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

void zephir_init_static_properties_Zeplara_Encryption_Encrypter(TSRMLS_D) {

	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(zeplara_encryption_encrypter_ce, ZEND_STRL("ivLengthCache"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 92, 0);
	add_assoc_stringl_ex(&_1, SL("AES-128-CBC"), SL("AES-128-CBC"));
	add_assoc_stringl_ex(&_1, SL("AES-128-CBC-HMAC-SHA1"), SL("AES-128-CBC-HMAC-SHA1"));
	add_assoc_stringl_ex(&_1, SL("AES-128-CBC-HMAC-SHA256"), SL("AES-128-CBC-HMAC-SHA256"));
	add_assoc_stringl_ex(&_1, SL("AES-128-CFB"), SL("AES-128-CFB"));
	add_assoc_stringl_ex(&_1, SL("AES-128-CFB1"), SL("AES-128-CFB1"));
	add_assoc_stringl_ex(&_1, SL("AES-128-CFB8"), SL("AES-128-CFB8"));
	add_assoc_stringl_ex(&_1, SL("AES-128-CTR"), SL("AES-128-CTR"));
	add_assoc_stringl_ex(&_1, SL("AES-128-OFB"), SL("AES-128-OFB"));
	add_assoc_stringl_ex(&_1, SL("AES-192-CBC"), SL("AES-192-CBC"));
	add_assoc_stringl_ex(&_1, SL("AES-192-CFB"), SL("AES-192-CFB"));
	add_assoc_stringl_ex(&_1, SL("AES-192-CFB1"), SL("AES-192-CFB1"));
	add_assoc_stringl_ex(&_1, SL("AES-192-CFB8"), SL("AES-192-CFB8"));
	add_assoc_stringl_ex(&_1, SL("AES-192-CTR"), SL("AES-192-CTR"));
	add_assoc_stringl_ex(&_1, SL("AES-192-OFB"), SL("AES-192-OFB"));
	add_assoc_stringl_ex(&_1, SL("AES-256-CBC"), SL("AES-256-CBC"));
	add_assoc_stringl_ex(&_1, SL("AES-256-CBC-HMAC-SHA1"), SL("AES-256-CBC-HMAC-SHA1"));
	add_assoc_stringl_ex(&_1, SL("AES-256-CBC-HMAC-SHA256"), SL("AES-256-CBC-HMAC-SHA256"));
	add_assoc_stringl_ex(&_1, SL("AES-256-CFB"), SL("AES-256-CFB"));
	add_assoc_stringl_ex(&_1, SL("AES-256-CFB1"), SL("AES-256-CFB1"));
	add_assoc_stringl_ex(&_1, SL("AES-256-CFB8"), SL("AES-256-CFB8"));
	add_assoc_stringl_ex(&_1, SL("AES-256-CTR"), SL("AES-256-CTR"));
	add_assoc_stringl_ex(&_1, SL("AES-256-OFB"), SL("AES-256-OFB"));
	add_assoc_stringl_ex(&_1, SL("ARIA-128-CBC"), SL("ARIA-128-CBC"));
	add_assoc_stringl_ex(&_1, SL("ARIA-128-CFB"), SL("ARIA-128-CFB"));
	add_assoc_stringl_ex(&_1, SL("ARIA-128-CFB1"), SL("ARIA-128-CFB1"));
	add_assoc_stringl_ex(&_1, SL("ARIA-128-CFB8"), SL("ARIA-128-CFB8"));
	add_assoc_stringl_ex(&_1, SL("ARIA-128-CTR"), SL("ARIA-128-CTR"));
	add_assoc_stringl_ex(&_1, SL("ARIA-128-OFB"), SL("ARIA-128-OFB"));
	add_assoc_stringl_ex(&_1, SL("ARIA-192-CBC"), SL("ARIA-192-CBC"));
	add_assoc_stringl_ex(&_1, SL("ARIA-192-CFB"), SL("ARIA-192-CFB"));
	add_assoc_stringl_ex(&_1, SL("ARIA-192-CFB1"), SL("ARIA-192-CFB1"));
	add_assoc_stringl_ex(&_1, SL("ARIA-192-CFB8"), SL("ARIA-192-CFB8"));
	add_assoc_stringl_ex(&_1, SL("ARIA-192-CTR"), SL("ARIA-192-CTR"));
	add_assoc_stringl_ex(&_1, SL("ARIA-192-OFB"), SL("ARIA-192-OFB"));
	add_assoc_stringl_ex(&_1, SL("ARIA-256-CBC"), SL("ARIA-256-CBC"));
	add_assoc_stringl_ex(&_1, SL("ARIA-256-CFB"), SL("ARIA-256-CFB"));
	add_assoc_stringl_ex(&_1, SL("ARIA-256-CFB1"), SL("ARIA-256-CFB1"));
	add_assoc_stringl_ex(&_1, SL("ARIA-256-CFB8"), SL("ARIA-256-CFB8"));
	add_assoc_stringl_ex(&_1, SL("ARIA-256-CTR"), SL("ARIA-256-CTR"));
	add_assoc_stringl_ex(&_1, SL("ARIA-256-OFB"), SL("ARIA-256-OFB"));
	add_assoc_stringl_ex(&_1, SL("BF-CBC"), SL("BF-CBC"));
	add_assoc_stringl_ex(&_1, SL("BF-CFB"), SL("BF-CFB"));
	add_assoc_stringl_ex(&_1, SL("BF-OFB"), SL("BF-OFB"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-128-CBC"), SL("CAMELLIA-128-CBC"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-128-CFB"), SL("CAMELLIA-128-CFB"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-128-CFB1"), SL("CAMELLIA-128-CFB1"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-128-CFB8"), SL("CAMELLIA-128-CFB8"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-128-CTR"), SL("CAMELLIA-128-CTR"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-128-OFB"), SL("CAMELLIA-128-OFB"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-192-CBC"), SL("CAMELLIA-192-CBC"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-192-CFB"), SL("CAMELLIA-192-CFB"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-192-CFB1"), SL("CAMELLIA-192-CFB1"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-192-CFB8"), SL("CAMELLIA-192-CFB8"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-192-CTR"), SL("CAMELLIA-192-CTR"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-192-OFB"), SL("CAMELLIA-192-OFB"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-256-CBC"), SL("CAMELLIA-256-CBC"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-256-CFB"), SL("CAMELLIA-256-CFB"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-256-CFB1"), SL("CAMELLIA-256-CFB1"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-256-CFB8"), SL("CAMELLIA-256-CFB8"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-256-CTR"), SL("CAMELLIA-256-CTR"));
	add_assoc_stringl_ex(&_1, SL("CAMELLIA-256-OFB"), SL("CAMELLIA-256-OFB"));
	add_assoc_stringl_ex(&_1, SL("CAST5-CBC"), SL("CAST5-CBC"));
	add_assoc_stringl_ex(&_1, SL("CAST5-CFB"), SL("CAST5-CFB"));
	add_assoc_stringl_ex(&_1, SL("CAST5-OFB"), SL("CAST5-OFB"));
	add_assoc_stringl_ex(&_1, SL("CHACHA20"), SL("CHACHA20"));
	add_assoc_stringl_ex(&_1, SL("CHACHA20-POLY1305"), SL("CHACHA20-POLY1305"));
	add_assoc_stringl_ex(&_1, SL("DES-CBC"), SL("DES-CBC"));
	add_assoc_stringl_ex(&_1, SL("DES-CFB"), SL("DES-CFB"));
	add_assoc_stringl_ex(&_1, SL("DES-CFB1"), SL("DES-CFB1"));
	add_assoc_stringl_ex(&_1, SL("DES-CFB8"), SL("DES-CFB8"));
	add_assoc_stringl_ex(&_1, SL("DES-EDE-CBC"), SL("DES-EDE-CBC"));
	add_assoc_stringl_ex(&_1, SL("DES-EDE-CFB"), SL("DES-EDE-CFB"));
	add_assoc_stringl_ex(&_1, SL("DES-EDE-OFB"), SL("DES-EDE-OFB"));
	add_assoc_stringl_ex(&_1, SL("DES-EDE3-CBC"), SL("DES-EDE3-CBC"));
	add_assoc_stringl_ex(&_1, SL("DES-EDE3-CFB"), SL("DES-EDE3-CFB"));
	add_assoc_stringl_ex(&_1, SL("DES-EDE3-CFB1"), SL("DES-EDE3-CFB1"));
	add_assoc_stringl_ex(&_1, SL("DES-EDE3-CFB8"), SL("DES-EDE3-CFB8"));
	add_assoc_stringl_ex(&_1, SL("DES-EDE3-OFB"), SL("DES-EDE3-OFB"));
	add_assoc_stringl_ex(&_1, SL("DES-OFB"), SL("DES-OFB"));
	add_assoc_stringl_ex(&_1, SL("DESX-CBC"), SL("DESX-CBC"));
	add_assoc_stringl_ex(&_1, SL("RC2-40-CBC"), SL("RC2-40-CBC"));
	add_assoc_stringl_ex(&_1, SL("RC2-64-CBC"), SL("RC2-64-CBC"));
	add_assoc_stringl_ex(&_1, SL("RC2-CBC"), SL("RC2-CBC"));
	add_assoc_stringl_ex(&_1, SL("RC2-CFB"), SL("RC2-CFB"));
	add_assoc_stringl_ex(&_1, SL("RC2-OFB"), SL("RC2-OFB"));
	add_assoc_stringl_ex(&_1, SL("SEED-CBC"), SL("SEED-CBC"));
	add_assoc_stringl_ex(&_1, SL("SEED-CFB"), SL("SEED-CFB"));
	add_assoc_stringl_ex(&_1, SL("SEED-OFB"), SL("SEED-OFB"));
	add_assoc_stringl_ex(&_1, SL("SM4-CBC"), SL("SM4-CBC"));
	add_assoc_stringl_ex(&_1, SL("SM4-CFB"), SL("SM4-CFB"));
	add_assoc_stringl_ex(&_1, SL("SM4-CTR"), SL("SM4-CTR"));
	add_assoc_stringl_ex(&_1, SL("SM4-OFB"), SL("SM4-OFB"));
	zephir_update_static_property_ce(zeplara_encryption_encrypter_ce, ZEND_STRL("cipherMethods"), &_1);
	ZEPHIR_MM_RESTORE();

}

