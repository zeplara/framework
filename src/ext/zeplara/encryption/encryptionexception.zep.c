
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


ZEPHIR_INIT_CLASS(Zeplara_Encryption_EncryptionException) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\Encryption, EncryptionException, zeplara, encryption_encryptionexception, zend_exception_get_default(TSRMLS_C), NULL, 0);

	zend_class_implements(zeplara_encryption_encryptionexception_ce, 1, zeplara_contracts_encryption_encryptionexception_ce);
	return SUCCESS;

}

