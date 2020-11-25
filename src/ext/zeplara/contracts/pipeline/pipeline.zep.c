
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Zeplara_Contracts_Pipeline_Pipeline) {

	ZEPHIR_REGISTER_INTERFACE(Zeplara\\Contracts\\Pipeline, Pipeline, zeplara, contracts_pipeline_pipeline, zeplara_contracts_pipeline_pipeline_method_entry);

	return SUCCESS;

}

/**
 * @return \Zeplara\Contracts\Container\Container
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Pipeline_Pipeline, getContainer);

/**
 * @return array
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Pipeline_Pipeline, getPipes);

/**
 * @param array pipes
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Pipeline_Pipeline, setPipes);

/**
 * @return void
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Pipeline_Pipeline, addPipe);

/**
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Zeplara_Contracts_Pipeline_Pipeline, send);

