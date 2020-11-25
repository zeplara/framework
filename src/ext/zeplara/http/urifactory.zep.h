
extern zend_class_entry *zeplara_http_urifactory_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_UriFactory);

PHP_METHOD(Zeplara_Http_UriFactory, createUri);
PHP_METHOD(Zeplara_Http_UriFactory, create);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_zeplara_http_urifactory_createuri, 0, 0, Psr\\Http\\Message\\UriInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_zeplara_http_urifactory_createuri, 0, 0, IS_OBJECT, "Psr\\Http\\Message\\UriInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_urifactory_create, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_urifactory_method_entry) {
	PHP_ME(Zeplara_Http_UriFactory, createUri, arginfo_zeplara_http_urifactory_createuri, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_UriFactory, create, arginfo_zeplara_http_urifactory_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
