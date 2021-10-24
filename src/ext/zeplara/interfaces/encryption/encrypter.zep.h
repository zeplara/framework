
extern zend_class_entry *zeplara_interfaces_encryption_encrypter_ce;

ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Encryption_Encrypter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_encryption_encrypter_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_interfaces_encryption_encrypter_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_interfaces_encryption_encrypter_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Encryption_Encrypter, getKey, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Encryption_Encrypter, getCipher, NULL)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Encryption_Encrypter, encrypt, arginfo_zeplara_interfaces_encryption_encrypter_encrypt)
	PHP_ABSTRACT_ME(Zeplara_Interfaces_Encryption_Encrypter, decrypt, arginfo_zeplara_interfaces_encryption_encrypter_decrypt)
	PHP_FE_END
};
