
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Encryption_Encrypter) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Encryption, Encrypter, zeplara, interfaces_encryption_encrypter, zeplara_interfaces_encryption_encrypter_method_entry);

	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Encryption_Encrypter, getKey);

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Encryption_Encrypter, getCipher);

/**
 * @param value
 * @return string
 * @throws EncryptionException
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Encryption_Encrypter, encrypt);

/**
 * @param string value
 * @return mixed
 * @throws EncryptionException
 */
ZEPHIR_DOC_METHOD(Zeplara_Interfaces_Encryption_Encrypter, decrypt);

