
extern zend_class_entry *zeplara_encryption_encrypter_ce;

ZEPHIR_INIT_CLASS(Zeplara_Encryption_Encrypter);

PHP_METHOD(Zeplara_Encryption_Encrypter, getKey);
PHP_METHOD(Zeplara_Encryption_Encrypter, getCipher);
PHP_METHOD(Zeplara_Encryption_Encrypter, __construct);
PHP_METHOD(Zeplara_Encryption_Encrypter, encrypt);
PHP_METHOD(Zeplara_Encryption_Encrypter, decrypt);
PHP_METHOD(Zeplara_Encryption_Encrypter, IvLength);
PHP_METHOD(Zeplara_Encryption_Encrypter, generateIv);
PHP_METHOD(Zeplara_Encryption_Encrypter, isValidIv);
PHP_METHOD(Zeplara_Encryption_Encrypter, throwEncryptionException);
PHP_METHOD(Zeplara_Encryption_Encrypter, throwEncryptError);
PHP_METHOD(Zeplara_Encryption_Encrypter, throwDecryptError);
void zephir_init_static_properties_Zeplara_Encryption_Encrypter(TSRMLS_D);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_encryption_encrypter_getkey, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_encryption_encrypter_getkey, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_encryption_encrypter_getcipher, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_encryption_encrypter_getcipher, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_encryption_encrypter___construct, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cipher, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, cipher)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_encryption_encrypter_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_encryption_encrypter_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_encryption_encrypter_isvalidiv, 0, 0, 1)
	ZEND_ARG_INFO(0, iv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_encryption_encrypter_throwencryptionexception, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_encryption_encrypter_method_entry) {
	PHP_ME(Zeplara_Encryption_Encrypter, getKey, arginfo_zeplara_encryption_encrypter_getkey, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Encryption_Encrypter, getCipher, arginfo_zeplara_encryption_encrypter_getcipher, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Encryption_Encrypter, __construct, arginfo_zeplara_encryption_encrypter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Encryption_Encrypter, encrypt, arginfo_zeplara_encryption_encrypter_encrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Encryption_Encrypter, decrypt, arginfo_zeplara_encryption_encrypter_decrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Encryption_Encrypter, IvLength, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Encryption_Encrypter, generateIv, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Encryption_Encrypter, isValidIv, arginfo_zeplara_encryption_encrypter_isvalidiv, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Encryption_Encrypter, throwEncryptionException, arginfo_zeplara_encryption_encrypter_throwencryptionexception, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Encryption_Encrypter, throwEncryptError, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Zeplara_Encryption_Encrypter, throwDecryptError, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
