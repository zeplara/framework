
extern zend_class_entry *zeplara_http_stream_ce;

ZEPHIR_INIT_CLASS(Zeplara_Http_Stream);

PHP_METHOD(Zeplara_Http_Stream, __construct);
PHP_METHOD(Zeplara_Http_Stream, getSize);
PHP_METHOD(Zeplara_Http_Stream, tell);
PHP_METHOD(Zeplara_Http_Stream, eof);
PHP_METHOD(Zeplara_Http_Stream, isSeekable);
PHP_METHOD(Zeplara_Http_Stream, seek);
PHP_METHOD(Zeplara_Http_Stream, rewind);
PHP_METHOD(Zeplara_Http_Stream, isWritable);
PHP_METHOD(Zeplara_Http_Stream, write);
PHP_METHOD(Zeplara_Http_Stream, isReadable);
PHP_METHOD(Zeplara_Http_Stream, read);
PHP_METHOD(Zeplara_Http_Stream, getContents);
PHP_METHOD(Zeplara_Http_Stream, getMetadata);
PHP_METHOD(Zeplara_Http_Stream, detach);
PHP_METHOD(Zeplara_Http_Stream, close);
PHP_METHOD(Zeplara_Http_Stream, __toString);
PHP_METHOD(Zeplara_Http_Stream, __destruct);
PHP_METHOD(Zeplara_Http_Stream, assertDetachedStream);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_stream___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_stream_seek, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, whence)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_stream_write, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_stream_read, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_http_stream_getmetadata, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_http_stream_method_entry) {
	PHP_ME(Zeplara_Http_Stream, __construct, arginfo_zeplara_http_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Zeplara_Http_Stream, getSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, tell, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, eof, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, isSeekable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, seek, arginfo_zeplara_http_stream_seek, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, isWritable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, write, arginfo_zeplara_http_stream_write, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, isReadable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, read, arginfo_zeplara_http_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, getContents, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, getMetadata, arginfo_zeplara_http_stream_getmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, detach, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Http_Stream, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Zeplara_Http_Stream, assertDetachedStream, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
