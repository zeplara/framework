
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Interfaces_Encryption_EncryptionException) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Interfaces\\Encryption, EncryptionException, zeplara, interfaces_encryption_encryptionexception, NULL);

	zend_class_implements(zeplara_interfaces_encryption_encryptionexception_ce, 1, zephir_get_internal_ce(SL("throwable")));
	return SUCCESS;

}

