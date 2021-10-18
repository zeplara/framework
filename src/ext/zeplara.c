
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "zeplara.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *zeplara_contracts_file_finder_filter_ce;
zend_class_entry *zeplara_contracts_routing_attribute_ce;
zend_class_entry *zeplara_contracts_config_loader_ce;
zend_class_entry *zeplara_contracts_repository_ce;
zend_class_entry *zeplara_contracts_file_parser_parser_ce;
zend_class_entry *zeplara_contracts_container_container_ce;
zend_class_entry *zeplara_contracts_config_loaderexception_ce;
zend_class_entry *zeplara_contracts_config_repository_ce;
zend_class_entry *zeplara_contracts_container_bindingresolutionexception_ce;
zend_class_entry *zeplara_contracts_container_invalidabstractexception_ce;
zend_class_entry *zeplara_contracts_cookie_cookie_ce;
zend_class_entry *zeplara_contracts_cookie_queue_ce;
zend_class_entry *zeplara_contracts_encryption_encrypter_ce;
zend_class_entry *zeplara_contracts_encryption_encryptionexception_ce;
zend_class_entry *zeplara_contracts_file_finder_finder_ce;
zend_class_entry *zeplara_contracts_file_finder_iterator_ce;
zend_class_entry *zeplara_contracts_file_parser_compiledvalue_ce;
zend_class_entry *zeplara_contracts_file_parser_linesiterator_ce;
zend_class_entry *zeplara_contracts_file_parser_parserexception_ce;
zend_class_entry *zeplara_contracts_file_parser_rawvalue_ce;
zend_class_entry *zeplara_contracts_file_splfileinfo_ce;
zend_class_entry *zeplara_contracts_pipeline_pipeline_ce;
zend_class_entry *zeplara_contracts_routing_compiledroute_ce;
zend_class_entry *zeplara_contracts_routing_group_ce;
zend_class_entry *zeplara_contracts_routing_regex_ce;
zend_class_entry *zeplara_contracts_routing_registrar_ce;
zend_class_entry *zeplara_contracts_routing_route_ce;
zend_class_entry *zeplara_contracts_routing_routecompiler_ce;
zend_class_entry *zeplara_contracts_routing_routecompilerexception_ce;
zend_class_entry *zeplara_contracts_routing_router_ce;
zend_class_entry *zeplara_contracts_session_manager_ce;
zend_class_entry *zeplara_contracts_application_ce;
zend_class_entry *zeplara_contracts_session_flash_ce;
zend_class_entry *zeplara_http_abstractmessage_ce;
zend_class_entry *zeplara_routing_abstractattribute_ce;
zend_class_entry *zeplara_support_abstractrepository_ce;
zend_class_entry *zeplara_container_containerexception_ce;
zend_class_entry *zeplara_file_parser_abstractparser_ce;
zend_class_entry *zeplara_http_request_ce;
zend_class_entry *zeplara_0__closure_ce;
zend_class_entry *zeplara_1__closure_ce;
zend_class_entry *zeplara_2__closure_ce;
zend_class_entry *zeplara_3__closure_ce;
zend_class_entry *zeplara_4__closure_ce;
zend_class_entry *zeplara_5__closure_ce;
zend_class_entry *zeplara_6__closure_ce;
zend_class_entry *zeplara_7__closure_ce;
zend_class_entry *zeplara_8__closure_ce;
zend_class_entry *zeplara_9__closure_ce;
zend_class_entry *zeplara_config_envloader_ce;
zend_class_entry *zeplara_config_iniloader_ce;
zend_class_entry *zeplara_config_jsonloader_ce;
zend_class_entry *zeplara_config_loaderexception_ce;
zend_class_entry *zeplara_config_phploader_ce;
zend_class_entry *zeplara_config_repository_ce;
zend_class_entry *zeplara_config_xmlloader_ce;
zend_class_entry *zeplara_config_yamlloader_ce;
zend_class_entry *zeplara_container_bindingresolutionexception_ce;
zend_class_entry *zeplara_container_container_ce;
zend_class_entry *zeplara_container_invalidabstractexception_ce;
zend_class_entry *zeplara_cookie_cookie_ce;
zend_class_entry *zeplara_cookie_factory_ce;
zend_class_entry *zeplara_cookie_queue_ce;
zend_class_entry *zeplara_encryption_encrypter_ce;
zend_class_entry *zeplara_encryption_encryptionexception_ce;
zend_class_entry *zeplara_file_finder_callbackfilter_ce;
zend_class_entry *zeplara_file_finder_datefilter_ce;
zend_class_entry *zeplara_file_finder_directoryfilter_ce;
zend_class_entry *zeplara_file_finder_executablefilter_ce;
zend_class_entry *zeplara_file_finder_fileextensionfilter_ce;
zend_class_entry *zeplara_file_finder_filefilter_ce;
zend_class_entry *zeplara_file_finder_filterfactory_ce;
zend_class_entry *zeplara_file_finder_finder_ce;
zend_class_entry *zeplara_file_finder_ignoredotfilefilter_ce;
zend_class_entry *zeplara_file_finder_iterator_ce;
zend_class_entry *zeplara_file_finder_linkfilter_ce;
zend_class_entry *zeplara_file_finder_readablefilter_ce;
zend_class_entry *zeplara_file_finder_writablefilter_ce;
zend_class_entry *zeplara_file_parser_compiledvalue_ce;
zend_class_entry *zeplara_file_parser_envparser_ce;
zend_class_entry *zeplara_file_parser_linesiterator_ce;
zend_class_entry *zeplara_file_parser_parserexception_ce;
zend_class_entry *zeplara_file_parser_rawvalue_ce;
zend_class_entry *zeplara_file_splfileinfo_ce;
zend_class_entry *zeplara_http_requestfactory_ce;
zend_class_entry *zeplara_http_response_ce;
zend_class_entry *zeplara_http_responsefactory_ce;
zend_class_entry *zeplara_http_serverrequest_ce;
zend_class_entry *zeplara_http_serverrequestfactory_ce;
zend_class_entry *zeplara_http_stream_ce;
zend_class_entry *zeplara_http_streamfactory_ce;
zend_class_entry *zeplara_http_uploadedfile_ce;
zend_class_entry *zeplara_http_uploadedfilefactory_ce;
zend_class_entry *zeplara_http_uri_ce;
zend_class_entry *zeplara_http_urifactory_ce;
zend_class_entry *zeplara_pipeline_carry_ce;
zend_class_entry *zeplara_pipeline_pipeline_ce;
zend_class_entry *zeplara_routing_compiledroute_ce;
zend_class_entry *zeplara_routing_group_ce;
zend_class_entry *zeplara_routing_regex_ce;
zend_class_entry *zeplara_routing_registrar_ce;
zend_class_entry *zeplara_routing_route_ce;
zend_class_entry *zeplara_routing_routecompiler_ce;
zend_class_entry *zeplara_routing_routecompilerexception_ce;
zend_class_entry *zeplara_routing_router_ce;
zend_class_entry *zeplara_session_cookiesessionhandler_ce;
zend_class_entry *zeplara_session_filesessionhandler_ce;
zend_class_entry *zeplara_session_flash_ce;
zend_class_entry *zeplara_session_manager_ce;
zend_class_entry *zeplara_support_arr_ce;
zend_class_entry *zeplara_support_facades_abstractfacade_ce;
zend_class_entry *zeplara_support_str_ce;

ZEND_DECLARE_MODULE_GLOBALS(zeplara)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(zeplara)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Zeplara_Contracts_File_Finder_Filter);
	ZEPHIR_INIT(Zeplara_Contracts_Routing_Attribute);
	ZEPHIR_INIT(Zeplara_Contracts_Config_Loader);
	ZEPHIR_INIT(Zeplara_Contracts_Repository);
	ZEPHIR_INIT(Zeplara_Contracts_File_Parser_Parser);
	ZEPHIR_INIT(Zeplara_Contracts_Container_Container);
	ZEPHIR_INIT(Zeplara_Contracts_Config_LoaderException);
	ZEPHIR_INIT(Zeplara_Contracts_Config_Repository);
	ZEPHIR_INIT(Zeplara_Contracts_Container_BindingResolutionException);
	ZEPHIR_INIT(Zeplara_Contracts_Container_InvalidAbstractException);
	ZEPHIR_INIT(Zeplara_Contracts_Cookie_Cookie);
	ZEPHIR_INIT(Zeplara_Contracts_Cookie_Queue);
	ZEPHIR_INIT(Zeplara_Contracts_Encryption_Encrypter);
	ZEPHIR_INIT(Zeplara_Contracts_Encryption_EncryptionException);
	ZEPHIR_INIT(Zeplara_Contracts_File_Finder_Finder);
	ZEPHIR_INIT(Zeplara_Contracts_File_Finder_Iterator);
	ZEPHIR_INIT(Zeplara_Contracts_File_Parser_CompiledValue);
	ZEPHIR_INIT(Zeplara_Contracts_File_Parser_LinesIterator);
	ZEPHIR_INIT(Zeplara_Contracts_File_Parser_ParserException);
	ZEPHIR_INIT(Zeplara_Contracts_File_Parser_RawValue);
	ZEPHIR_INIT(Zeplara_Contracts_File_SplFileInfo);
	ZEPHIR_INIT(Zeplara_Contracts_Pipeline_Pipeline);
	ZEPHIR_INIT(Zeplara_Contracts_Routing_CompiledRoute);
	ZEPHIR_INIT(Zeplara_Contracts_Routing_Group);
	ZEPHIR_INIT(Zeplara_Contracts_Routing_Regex);
	ZEPHIR_INIT(Zeplara_Contracts_Routing_Registrar);
	ZEPHIR_INIT(Zeplara_Contracts_Routing_Route);
	ZEPHIR_INIT(Zeplara_Contracts_Routing_RouteCompiler);
	ZEPHIR_INIT(Zeplara_Contracts_Routing_RouteCompilerException);
	ZEPHIR_INIT(Zeplara_Contracts_Routing_Router);
	ZEPHIR_INIT(Zeplara_Contracts_Session_Manager);
	ZEPHIR_INIT(Zeplara_Contracts_Application);
	ZEPHIR_INIT(Zeplara_Contracts_Session_Flash);
	ZEPHIR_INIT(Zeplara_Http_AbstractMessage);
	ZEPHIR_INIT(Zeplara_Routing_AbstractAttribute);
	ZEPHIR_INIT(Zeplara_Support_AbstractRepository);
	ZEPHIR_INIT(Zeplara_Container_ContainerException);
	ZEPHIR_INIT(Zeplara_File_Parser_AbstractParser);
	ZEPHIR_INIT(Zeplara_Http_Request);
	ZEPHIR_INIT(Zeplara_Config_EnvLoader);
	ZEPHIR_INIT(Zeplara_Config_IniLoader);
	ZEPHIR_INIT(Zeplara_Config_JsonLoader);
	ZEPHIR_INIT(Zeplara_Config_LoaderException);
	ZEPHIR_INIT(Zeplara_Config_PhpLoader);
	ZEPHIR_INIT(Zeplara_Config_Repository);
	ZEPHIR_INIT(Zeplara_Config_XmlLoader);
	ZEPHIR_INIT(Zeplara_Config_YamlLoader);
	ZEPHIR_INIT(Zeplara_Container_BindingResolutionException);
	ZEPHIR_INIT(Zeplara_Container_Container);
	ZEPHIR_INIT(Zeplara_Container_InvalidAbstractException);
	ZEPHIR_INIT(Zeplara_Cookie_Cookie);
	ZEPHIR_INIT(Zeplara_Cookie_Factory);
	ZEPHIR_INIT(Zeplara_Cookie_Queue);
	ZEPHIR_INIT(Zeplara_Encryption_Encrypter);
	ZEPHIR_INIT(Zeplara_Encryption_EncryptionException);
	ZEPHIR_INIT(Zeplara_File_Finder_CallbackFilter);
	ZEPHIR_INIT(Zeplara_File_Finder_DateFilter);
	ZEPHIR_INIT(Zeplara_File_Finder_DirectoryFilter);
	ZEPHIR_INIT(Zeplara_File_Finder_ExecutableFilter);
	ZEPHIR_INIT(Zeplara_File_Finder_FileExtensionFilter);
	ZEPHIR_INIT(Zeplara_File_Finder_FileFilter);
	ZEPHIR_INIT(Zeplara_File_Finder_FilterFactory);
	ZEPHIR_INIT(Zeplara_File_Finder_Finder);
	ZEPHIR_INIT(Zeplara_File_Finder_IgnoreDotFileFilter);
	ZEPHIR_INIT(Zeplara_File_Finder_Iterator);
	ZEPHIR_INIT(Zeplara_File_Finder_LinkFilter);
	ZEPHIR_INIT(Zeplara_File_Finder_ReadableFilter);
	ZEPHIR_INIT(Zeplara_File_Finder_WritableFilter);
	ZEPHIR_INIT(Zeplara_File_Parser_CompiledValue);
	ZEPHIR_INIT(Zeplara_File_Parser_EnvParser);
	ZEPHIR_INIT(Zeplara_File_Parser_LinesIterator);
	ZEPHIR_INIT(Zeplara_File_Parser_ParserException);
	ZEPHIR_INIT(Zeplara_File_Parser_RawValue);
	ZEPHIR_INIT(Zeplara_File_SplFileInfo);
	ZEPHIR_INIT(Zeplara_Http_RequestFactory);
	ZEPHIR_INIT(Zeplara_Http_Response);
	ZEPHIR_INIT(Zeplara_Http_ResponseFactory);
	ZEPHIR_INIT(Zeplara_Http_ServerRequest);
	ZEPHIR_INIT(Zeplara_Http_ServerRequestFactory);
	ZEPHIR_INIT(Zeplara_Http_Stream);
	ZEPHIR_INIT(Zeplara_Http_StreamFactory);
	ZEPHIR_INIT(Zeplara_Http_UploadedFile);
	ZEPHIR_INIT(Zeplara_Http_UploadedFileFactory);
	ZEPHIR_INIT(Zeplara_Http_Uri);
	ZEPHIR_INIT(Zeplara_Http_UriFactory);
	ZEPHIR_INIT(Zeplara_Pipeline_Carry);
	ZEPHIR_INIT(Zeplara_Pipeline_Pipeline);
	ZEPHIR_INIT(Zeplara_Routing_CompiledRoute);
	ZEPHIR_INIT(Zeplara_Routing_Group);
	ZEPHIR_INIT(Zeplara_Routing_Regex);
	ZEPHIR_INIT(Zeplara_Routing_Registrar);
	ZEPHIR_INIT(Zeplara_Routing_Route);
	ZEPHIR_INIT(Zeplara_Routing_RouteCompiler);
	ZEPHIR_INIT(Zeplara_Routing_RouteCompilerException);
	ZEPHIR_INIT(Zeplara_Routing_Router);
	ZEPHIR_INIT(Zeplara_Session_CookieSessionHandler);
	ZEPHIR_INIT(Zeplara_Session_FileSessionHandler);
	ZEPHIR_INIT(Zeplara_Session_Flash);
	ZEPHIR_INIT(Zeplara_Session_Manager);
	ZEPHIR_INIT(Zeplara_Support_Arr);
	ZEPHIR_INIT(Zeplara_Support_Facades_AbstractFacade);
	ZEPHIR_INIT(Zeplara_Support_Str);
	ZEPHIR_INIT(zeplara_0__closure);
	ZEPHIR_INIT(zeplara_1__closure);
	ZEPHIR_INIT(zeplara_2__closure);
	ZEPHIR_INIT(zeplara_3__closure);
	ZEPHIR_INIT(zeplara_4__closure);
	ZEPHIR_INIT(zeplara_5__closure);
	ZEPHIR_INIT(zeplara_6__closure);
	ZEPHIR_INIT(zeplara_7__closure);
	ZEPHIR_INIT(zeplara_8__closure);
	ZEPHIR_INIT(zeplara_9__closure);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(zeplara)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_zeplara_globals *zeplara_globals TSRMLS_DC)
{
	zeplara_globals->initialized = 0;

	/* Cache Enabled */
	zeplara_globals->cache_enabled = 1;

	/* Recursive Lock */
	zeplara_globals->recursive_lock = 0;

	/* Static cache */
	memset(zeplara_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_zeplara_globals *zeplara_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(zeplara)
{
	zend_zeplara_globals *zeplara_globals_ptr;
	zeplara_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zeplara_globals_ptr);
	zephir_initialize_memory(zeplara_globals_ptr);

		zephir_init_static_properties_Zeplara_Routing_AbstractAttribute(TSRMLS_C);
		zephir_init_static_properties_Zeplara_Encryption_Encrypter(TSRMLS_C);
		zephir_init_static_properties_Zeplara_File_Parser_EnvParser(TSRMLS_C);
		zephir_init_static_properties_Zeplara_Http_Response(TSRMLS_C);
		zephir_init_static_properties_Zeplara_Http_UploadedFile(TSRMLS_C);
		zephir_init_static_properties_Zeplara_Support_Str(TSRMLS_C);
	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(zeplara)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(zeplara)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_ZEPLARA_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_ZEPLARA_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_ZEPLARA_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_ZEPLARA_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_ZEPLARA_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(zeplara)
{
#if defined(COMPILE_DL_ZEPLARA) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(zeplara_globals);
	php_zephir_init_module_globals(zeplara_globals);
}

static PHP_GSHUTDOWN_FUNCTION(zeplara)
{
	
}


zend_function_entry php_zeplara_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_zeplara_deps[] = {
	ZEND_MOD_REQUIRED("psr")
	ZEND_MOD_REQUIRED("json")
	ZEND_MOD_REQUIRED("openssl")
	ZEND_MOD_END
};

zend_module_entry zeplara_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_zeplara_deps,
	PHP_ZEPLARA_EXTNAME,
	php_zeplara_functions,
	PHP_MINIT(zeplara),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(zeplara),
#else
	NULL,
#endif
	PHP_RINIT(zeplara),
	PHP_RSHUTDOWN(zeplara),
	PHP_MINFO(zeplara),
	PHP_ZEPLARA_VERSION,
	ZEND_MODULE_GLOBALS(zeplara),
	PHP_GINIT(zeplara),
	PHP_GSHUTDOWN(zeplara),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(zeplara),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_ZEPLARA
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(zeplara)
#endif
