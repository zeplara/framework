
extern zend_class_entry *zeplara_support_str_ce;

ZEPHIR_INIT_CLASS(Zeplara_Support_Str);

PHP_METHOD(Zeplara_Support_Str, __construct);
PHP_METHOD(Zeplara_Support_Str, studly);
PHP_METHOD(Zeplara_Support_Str, snake);
PHP_METHOD(Zeplara_Support_Str, kebab);
PHP_METHOD(Zeplara_Support_Str, lower);
PHP_METHOD(Zeplara_Support_Str, upper);
PHP_METHOD(Zeplara_Support_Str, title);
PHP_METHOD(Zeplara_Support_Str, ascii);
PHP_METHOD(Zeplara_Support_Str, slug);
PHP_METHOD(Zeplara_Support_Str, uuid);
PHP_METHOD(Zeplara_Support_Str, capitalize);
PHP_METHOD(Zeplara_Support_Str, random);
PHP_METHOD(Zeplara_Support_Str, splitByDashWhiteSpaceUnderscore);
void zephir_init_static_properties_Zeplara_Support_Str(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_str_studly, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_str_snake, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, delimiter)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_str_kebab, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_str_lower, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_str_upper, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_str_title, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_str_ascii, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, language, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, language)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_str_slug, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, separator, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, separator)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, language, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, language)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_str_capitalize, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_str_random, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, length)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_support_str_splitbydashwhitespaceunderscore, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_support_str_method_entry) {
	PHP_ME(Zeplara_Support_Str, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Support_Str, studly, arginfo_zeplara_support_str_studly, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Str, snake, arginfo_zeplara_support_str_snake, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Str, kebab, arginfo_zeplara_support_str_kebab, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Str, lower, arginfo_zeplara_support_str_lower, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Str, upper, arginfo_zeplara_support_str_upper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Str, title, arginfo_zeplara_support_str_title, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Str, ascii, arginfo_zeplara_support_str_ascii, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Str, slug, arginfo_zeplara_support_str_slug, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Str, uuid, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Str, capitalize, arginfo_zeplara_support_str_capitalize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Str, random, arginfo_zeplara_support_str_random, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Zeplara_Support_Str, splitByDashWhiteSpaceUnderscore, arginfo_zeplara_support_str_splitbydashwhitespaceunderscore, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
