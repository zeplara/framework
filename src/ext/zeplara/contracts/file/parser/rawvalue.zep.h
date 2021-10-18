
extern zend_class_entry *zeplara_contracts_file_parser_rawvalue_ce;

ZEPHIR_INIT_CLASS(Zeplara_Contracts_File_Parser_RawValue);

ZEPHIR_INIT_FUNCS(zeplara_contracts_file_parser_rawvalue_method_entry) {
	PHP_ABSTRACT_ME(Zeplara_Contracts_File_Parser_RawValue, getValue, NULL)
	PHP_ABSTRACT_ME(Zeplara_Contracts_File_Parser_RawValue, getLines, NULL)
	PHP_FE_END
};
