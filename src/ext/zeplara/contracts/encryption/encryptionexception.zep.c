
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Encryption_EncryptionException) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Encryption, EncryptionException, zeplara, contracts_encryption_encryptionexception, NULL);

	zend_class_implements(zeplara_contracts_encryption_encryptionexception_ce, 1, zephir_get_internal_ce(SL("throwable")));
	return SUCCESS;

}

