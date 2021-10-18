
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Zeplara_File_Parser_EnvParser) {

	ZEPHIR_REGISTER_CLASS_EX(Zeplara\\File\\Parser, EnvParser, zeplara, file_parser_envparser, zeplara_file_parser_abstractparser_ce, zeplara_file_parser_envparser_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_file_parser_envparser_ce, SL("compilerMethodsCache"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(zeplara_file_parser_envparser_ce, SL("VARIABLE_VALUE_REGEX"), "\\$\\{([a-zA-Z0-9_.]+)\\}");

	zend_class_implements(zeplara_file_parser_envparser_ce, 1, zeplara_contracts_file_parser_parser_ce);
	return SUCCESS;

}

/**
 * @param string contents
 * @return array
 * @throws ParserException
 */
PHP_METHOD(Zeplara_File_Parser_EnvParser, parse) {

	zval _46$$9, _90$$19;
	zend_string *_4;
	zend_ulong _3;
	zend_bool shouldSkipKey = 0, _16$$4, _22$$4, _64$$14, _69$$14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL, *_15 = NULL, *_21 = NULL, *_30 = NULL, *_33 = NULL, *_42 = NULL, *_44 = NULL, *_52 = NULL, *_88 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *contents_param = NULL, i, x, y, key, val, value, lines, parts, values, rawKey, compiled, linesCount, _0, *_1, _2, _5$$3, _6$$3, _7$$4, _8$$4, _9$$4, _11$$4, _13$$4, _14$$4, _17$$4, _18$$4, _19$$4, _20$$4, _23$$4, _24$$4, _25$$4, _34$$4, _26$$5, _27$$5, _28$$5, _29$$5, _31$$6, _32$$6, _35$$7, _36$$7, _37$$7, _38$$7, _39$$9, _40$$9, _41$$9, _43$$9, _45$$9, _47$$9, _48$$9, _49$$9, _50$$10, _51$$10, _53$$8, _54$$11, _55$$11, _56$$13, _57$$13, _58$$14, _59$$14, _60$$14, _61$$14, _62$$14, _63$$14, _65$$14, _66$$14, _67$$14, _68$$14, _70$$14, _71$$14, _72$$14, _79$$14, _73$$15, _74$$15, _75$$15, _76$$15, _77$$16, _78$$16, _80$$17, _81$$17, _82$$17, _83$$17, _84$$19, _85$$19, _86$$19, _87$$19, _89$$19, _91$$19, _92$$19, _93$$19, _94$$20, _95$$20, _96$$18, _97$$21, _98$$21;
	zval contents;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&x);
	ZVAL_UNDEF(&y);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&rawKey);
	ZVAL_UNDEF(&compiled);
	ZVAL_UNDEF(&linesCount);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_34$$4);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_27$$5);
	ZVAL_UNDEF(&_28$$5);
	ZVAL_UNDEF(&_29$$5);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_32$$6);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_36$$7);
	ZVAL_UNDEF(&_37$$7);
	ZVAL_UNDEF(&_38$$7);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_45$$9);
	ZVAL_UNDEF(&_47$$9);
	ZVAL_UNDEF(&_48$$9);
	ZVAL_UNDEF(&_49$$9);
	ZVAL_UNDEF(&_50$$10);
	ZVAL_UNDEF(&_51$$10);
	ZVAL_UNDEF(&_53$$8);
	ZVAL_UNDEF(&_54$$11);
	ZVAL_UNDEF(&_55$$11);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_58$$14);
	ZVAL_UNDEF(&_59$$14);
	ZVAL_UNDEF(&_60$$14);
	ZVAL_UNDEF(&_61$$14);
	ZVAL_UNDEF(&_62$$14);
	ZVAL_UNDEF(&_63$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_66$$14);
	ZVAL_UNDEF(&_67$$14);
	ZVAL_UNDEF(&_68$$14);
	ZVAL_UNDEF(&_70$$14);
	ZVAL_UNDEF(&_71$$14);
	ZVAL_UNDEF(&_72$$14);
	ZVAL_UNDEF(&_79$$14);
	ZVAL_UNDEF(&_73$$15);
	ZVAL_UNDEF(&_74$$15);
	ZVAL_UNDEF(&_75$$15);
	ZVAL_UNDEF(&_76$$15);
	ZVAL_UNDEF(&_77$$16);
	ZVAL_UNDEF(&_78$$16);
	ZVAL_UNDEF(&_80$$17);
	ZVAL_UNDEF(&_81$$17);
	ZVAL_UNDEF(&_82$$17);
	ZVAL_UNDEF(&_83$$17);
	ZVAL_UNDEF(&_84$$19);
	ZVAL_UNDEF(&_85$$19);
	ZVAL_UNDEF(&_86$$19);
	ZVAL_UNDEF(&_87$$19);
	ZVAL_UNDEF(&_89$$19);
	ZVAL_UNDEF(&_91$$19);
	ZVAL_UNDEF(&_92$$19);
	ZVAL_UNDEF(&_93$$19);
	ZVAL_UNDEF(&_94$$20);
	ZVAL_UNDEF(&_95$$20);
	ZVAL_UNDEF(&_96$$18);
	ZVAL_UNDEF(&_97$$21);
	ZVAL_UNDEF(&_98$$21);
	ZVAL_UNDEF(&_46$$9);
	ZVAL_UNDEF(&_90$$19);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &contents_param);

	if (UNEXPECTED(Z_TYPE_P(contents_param) != IS_STRING && Z_TYPE_P(contents_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'contents' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(contents_param) == IS_STRING)) {
		zephir_get_strval(&contents, contents_param);
	} else {
		ZEPHIR_INIT_VAR(&contents);
		ZVAL_EMPTY_STRING(&contents);
	}


	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&lines);
	object_init_ex(&lines, zeplara_file_parser_linesiterator_ce);
	ZEPHIR_CALL_METHOD(NULL, &lines, "__construct", NULL, 87, &contents);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&linesCount, &lines, "count", NULL, 88);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_is_iterable(&lines, 1, "zeplara/File/Parser/EnvParser.zep", 85);
	if (Z_TYPE_P(&lines) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&lines), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&i);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&i, _4);
			} else {
				ZVAL_LONG(&i, _3);
			}
			ZEPHIR_INIT_NVAR(&_0);
			ZVAL_COPY(&_0, _1);
			ZEPHIR_INIT_NVAR(&_5$$3);
			zephir_array_fetch(&_6$$3, &lines, &i, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 35);
			zephir_fast_trim(&_5$$3, &_6$$3, NULL , ZEPHIR_TRIM_BOTH);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_5$$3, "")) {
				ZEPHIR_INIT_NVAR(&x);
				ZVAL_LONG(&x, (zephir_get_numberval(&i) + 1));
				ZEPHIR_INIT_NVAR(&_7$$4);
				zephir_array_fetch(&_8$$4, &lines, &i, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 37);
				zephir_fast_explode_str(&_7$$4, SL("="), &_8$$4, 2 );
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZVAL_STRING(&_9$$4, "trim");
				ZEPHIR_CALL_FUNCTION(&parts, "array_map", &_10, 67, &_9$$4, &_7$$4);
				zephir_check_call_status();
				ZVAL_LONG(&_13$$4, 0);
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZVAL_STRING(&_9$$4, "");
				ZEPHIR_CALL_CE_STATIC(&_11$$4, zeplara_support_arr_ce, "get", &_12, 0, &parts, &_13$$4, &_9$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&rawKey);
				zephir_fast_trim(&rawKey, &_11$$4, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CALL_METHOD(&_14$$4, this_ptr, "clearcomments", &_15, 89, &rawKey);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&key);
				zephir_fast_trim(&key, &_14$$4, NULL , ZEPHIR_TRIM_BOTH);
				_16$$4 = !ZEPHIR_IS_STRING_IDENTICAL(&rawKey, "");
				if (_16$$4) {
					_16$$4 = ZEPHIR_IS_STRING_IDENTICAL(&key, "");
				}
				shouldSkipKey = _16$$4;
				ZVAL_LONG(&_13$$4, 1);
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZVAL_STRING(&_9$$4, "");
				ZEPHIR_CALL_CE_STATIC(&_18$$4, zeplara_support_arr_ce, "get", &_12, 0, &parts, &_13$$4, &_9$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_17$$4, this_ptr, "clearcomments", &_15, 89, &_18$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&value);
				zephir_fast_trim(&value, &_17$$4, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CPY_WRT(&val, &value);
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZVAL_STRING(&_9$$4, "%s=%s");
				ZEPHIR_CALL_FUNCTION(&_20$$4, "sprintf", &_21, 2, &_9$$4, &rawKey, &value);
				zephir_check_call_status();
				zephir_array_update_zval(&lines, &i, &_20$$4, PH_COPY | PH_SEPARATE);
				_22$$4 = shouldSkipKey == 0;
				if (_22$$4) {
					ZEPHIR_INIT_NVAR(&_23$$4);
					ZEPHIR_INIT_NVAR(&_9$$4);
					ZVAL_STRING(&_9$$4, "~\\A[a-zA-Z0-9_.]+\\z~");
					ZEPHIR_INIT_NVAR(&_24$$4);
					ZEPHIR_INIT_NVAR(&_25$$4);
					ZVAL_STRING(&_25$$4, "~\\A[a-zA-Z0-9_.]+\\z~");
					zephir_preg_match(&_24$$4, &_25$$4, &key, &_23$$4, 0, 0 , 0 );
					_22$$4 = zephir_get_boolval(&_24$$4) == 0;
				}
				if (_22$$4) {
					ZEPHIR_INIT_NVAR(&_27$$5);
					ZVAL_STRING(&_27$$5, "Syntax error [%s], is invalid key.");
					ZEPHIR_CALL_FUNCTION(&_28$$5, "sprintf", &_21, 2, &_27$$5, &key);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_27$$5);
					ZVAL_STRING(&_27$$5, "");
					ZVAL_LONG(&_29$$5, (zephir_get_numberval(&i) + 1));
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexception", &_30, 0, &_28$$5, &_27$$5, &_29$$5);
					zephir_check_call_status();
				}
				while (1) {
					if (!(ZEPHIR_LT(&x, &linesCount))) {
						break;
					}
					zephir_array_fetch(&_31$$6, &lines, &x, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 50);
					ZEPHIR_INIT_NVAR(&_32$$6);
					ZEPHIR_CONCAT_SV(&_32$$6, "\n", &_31$$6);
					zephir_concat_self(&val, &_32$$6);
					ZEPHIR_SEPARATE(&x);
					zephir_increment(&x);
				}
				ZVAL_LONG(&_13$$4, (zephir_get_numberval(&i) + 1));
				ZEPHIR_CALL_METHOD(&compiled, this_ptr, "compilevalue", &_33, 90, &val, &values, &_13$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_24$$4);
				ZVAL_STRING(&_24$$4, " ");
				ZEPHIR_INIT_NVAR(&_34$$4);
				zephir_fast_strpos(&_34$$4, &value, &_24$$4, 0 );
				if (Z_TYPE_P(&compiled) != IS_NULL) {
					ZEPHIR_CPY_WRT(&x, &i);
					ZEPHIR_CALL_METHOD(&_35$$7, &compiled, "getrawvalue", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_36$$7, &_35$$7, "getlines", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_37$$7, &_36$$7, "count", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_38$$7);
					zephir_add_function(&_38$$7, &_37$$7, &i);
					ZEPHIR_INIT_NVAR(&y);
					ZVAL_LONG(&y, (zephir_get_numberval(&_38$$7) - 1));
					while (1) {
						if (!(ZEPHIR_LE(&x, &y))) {
							break;
						}
						if (ZEPHIR_IS_IDENTICAL(&x, &y)) {
							ZEPHIR_INIT_NVAR(&_39$$9);
							zephir_array_fetch(&_40$$9, &lines, &x, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 64);
							ZEPHIR_CALL_METHOD(&_43$$9, &compiled, "getrawvalue", &_44, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_45$$9, &_43$$9, "getlines", NULL, 0);
							zephir_check_call_status();
							zephir_get_arrval(&_46$$9, &_45$$9);
							ZEPHIR_CALL_CE_STATIC(&_41$$9, zeplara_support_arr_ce, "last", &_42, 0, &_46$$9);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_47$$9);
							if (ZEPHIR_IS_IDENTICAL(&x, &i)) {
								ZEPHIR_INIT_NVAR(&_47$$9);
								ZVAL_LONG(&_47$$9, ((zephir_fast_strlen_ev(&rawKey) + 1)));
							} else {
								ZEPHIR_INIT_NVAR(&_47$$9);
								ZVAL_LONG(&_47$$9, 0);
							}
							ZVAL_LONG(&_48$$9, (zephir_fast_strlen_ev(&_41$$9) + zephir_get_numberval(&_47$$9)));
							ZEPHIR_INIT_NVAR(&_49$$9);
							zephir_substr(&_49$$9, &_40$$9, zephir_get_intval(&_48$$9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
							zephir_fast_trim(&_39$$9, &_49$$9, NULL , ZEPHIR_TRIM_BOTH);
							if (!ZEPHIR_IS_STRING_IDENTICAL(&_39$$9, "")) {
								zephir_array_fetch(&_50$$10, &lines, &x, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 65);
								ZVAL_LONG(&_51$$10, (zephir_get_numberval(&i) + 1));
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexceptionuimv", &_52, 91, &_50$$10, &_51$$10);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&_53$$8);
						ZVAL_STRING(&_53$$8, "");
						zephir_array_update_zval(&lines, &x, &_53$$8, PH_COPY | PH_SEPARATE);
						ZEPHIR_SEPARATE(&x);
						zephir_increment(&x);
					}
					ZEPHIR_CALL_METHOD(&value, &compiled, "getvalue", NULL, 0);
					zephir_check_call_status();
				} else if (!ZEPHIR_IS_FALSE_IDENTICAL(&_34$$4)) {
					zephir_array_fetch(&_54$$11, &lines, &i, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 75);
					ZVAL_LONG(&_55$$11, (zephir_get_numberval(&i) + 1));
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexceptionuimv", &_52, 91, &_54$$11, &_55$$11);
					zephir_check_call_status();
				}
				if (shouldSkipKey == 0) {
					zephir_array_update_zval(&values, &key, &value, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &lines, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &lines, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&i, &lines, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_0, &lines, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_56$$13);
				zephir_array_fetch(&_57$$13, &lines, &i, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 35);
				zephir_fast_trim(&_56$$13, &_57$$13, NULL , ZEPHIR_TRIM_BOTH);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_56$$13, "")) {
					ZEPHIR_INIT_NVAR(&x);
					ZVAL_LONG(&x, (zephir_get_numberval(&i) + 1));
					ZEPHIR_INIT_NVAR(&_58$$14);
					zephir_array_fetch(&_59$$14, &lines, &i, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 37);
					zephir_fast_explode_str(&_58$$14, SL("="), &_59$$14, 2 );
					ZEPHIR_INIT_NVAR(&_60$$14);
					ZVAL_STRING(&_60$$14, "trim");
					ZEPHIR_CALL_FUNCTION(&parts, "array_map", &_10, 67, &_60$$14, &_58$$14);
					zephir_check_call_status();
					ZVAL_LONG(&_62$$14, 0);
					ZEPHIR_INIT_NVAR(&_60$$14);
					ZVAL_STRING(&_60$$14, "");
					ZEPHIR_CALL_CE_STATIC(&_61$$14, zeplara_support_arr_ce, "get", &_12, 0, &parts, &_62$$14, &_60$$14);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&rawKey);
					zephir_fast_trim(&rawKey, &_61$$14, NULL , ZEPHIR_TRIM_BOTH);
					ZEPHIR_CALL_METHOD(&_63$$14, this_ptr, "clearcomments", &_15, 89, &rawKey);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&key);
					zephir_fast_trim(&key, &_63$$14, NULL , ZEPHIR_TRIM_BOTH);
					_64$$14 = !ZEPHIR_IS_STRING_IDENTICAL(&rawKey, "");
					if (_64$$14) {
						_64$$14 = ZEPHIR_IS_STRING_IDENTICAL(&key, "");
					}
					shouldSkipKey = _64$$14;
					ZVAL_LONG(&_62$$14, 1);
					ZEPHIR_INIT_NVAR(&_60$$14);
					ZVAL_STRING(&_60$$14, "");
					ZEPHIR_CALL_CE_STATIC(&_66$$14, zeplara_support_arr_ce, "get", &_12, 0, &parts, &_62$$14, &_60$$14);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_65$$14, this_ptr, "clearcomments", &_15, 89, &_66$$14);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&value);
					zephir_fast_trim(&value, &_65$$14, NULL , ZEPHIR_TRIM_BOTH);
					ZEPHIR_CPY_WRT(&val, &value);
					ZEPHIR_INIT_NVAR(&_60$$14);
					ZVAL_STRING(&_60$$14, "%s=%s");
					ZEPHIR_CALL_FUNCTION(&_68$$14, "sprintf", &_21, 2, &_60$$14, &rawKey, &value);
					zephir_check_call_status();
					zephir_array_update_zval(&lines, &i, &_68$$14, PH_COPY | PH_SEPARATE);
					_69$$14 = shouldSkipKey == 0;
					if (_69$$14) {
						ZEPHIR_INIT_NVAR(&_70$$14);
						ZEPHIR_INIT_NVAR(&_60$$14);
						ZVAL_STRING(&_60$$14, "~\\A[a-zA-Z0-9_.]+\\z~");
						ZEPHIR_INIT_NVAR(&_71$$14);
						ZEPHIR_INIT_NVAR(&_72$$14);
						ZVAL_STRING(&_72$$14, "~\\A[a-zA-Z0-9_.]+\\z~");
						zephir_preg_match(&_71$$14, &_72$$14, &key, &_70$$14, 0, 0 , 0 );
						_69$$14 = zephir_get_boolval(&_71$$14) == 0;
					}
					if (_69$$14) {
						ZEPHIR_INIT_NVAR(&_74$$15);
						ZVAL_STRING(&_74$$15, "Syntax error [%s], is invalid key.");
						ZEPHIR_CALL_FUNCTION(&_75$$15, "sprintf", &_21, 2, &_74$$15, &key);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_74$$15);
						ZVAL_STRING(&_74$$15, "");
						ZVAL_LONG(&_76$$15, (zephir_get_numberval(&i) + 1));
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexception", &_30, 0, &_75$$15, &_74$$15, &_76$$15);
						zephir_check_call_status();
					}
					while (1) {
						if (!(ZEPHIR_LT(&x, &linesCount))) {
							break;
						}
						zephir_array_fetch(&_77$$16, &lines, &x, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 50);
						ZEPHIR_INIT_NVAR(&_78$$16);
						ZEPHIR_CONCAT_SV(&_78$$16, "\n", &_77$$16);
						zephir_concat_self(&val, &_78$$16);
						ZEPHIR_SEPARATE(&x);
						zephir_increment(&x);
					}
					ZVAL_LONG(&_62$$14, (zephir_get_numberval(&i) + 1));
					ZEPHIR_CALL_METHOD(&compiled, this_ptr, "compilevalue", &_33, 90, &val, &values, &_62$$14);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_71$$14);
					ZVAL_STRING(&_71$$14, " ");
					ZEPHIR_INIT_NVAR(&_79$$14);
					zephir_fast_strpos(&_79$$14, &value, &_71$$14, 0 );
					if (Z_TYPE_P(&compiled) != IS_NULL) {
						ZEPHIR_CPY_WRT(&x, &i);
						ZEPHIR_CALL_METHOD(&_80$$17, &compiled, "getrawvalue", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_81$$17, &_80$$17, "getlines", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_82$$17, &_81$$17, "count", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_83$$17);
						zephir_add_function(&_83$$17, &_82$$17, &i);
						ZEPHIR_INIT_NVAR(&y);
						ZVAL_LONG(&y, (zephir_get_numberval(&_83$$17) - 1));
						while (1) {
							if (!(ZEPHIR_LE(&x, &y))) {
								break;
							}
							if (ZEPHIR_IS_IDENTICAL(&x, &y)) {
								ZEPHIR_INIT_NVAR(&_84$$19);
								zephir_array_fetch(&_85$$19, &lines, &x, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 64);
								ZEPHIR_CALL_METHOD(&_87$$19, &compiled, "getrawvalue", &_88, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_89$$19, &_87$$19, "getlines", NULL, 0);
								zephir_check_call_status();
								zephir_get_arrval(&_90$$19, &_89$$19);
								ZEPHIR_CALL_CE_STATIC(&_86$$19, zeplara_support_arr_ce, "last", &_42, 0, &_90$$19);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_91$$19);
								if (ZEPHIR_IS_IDENTICAL(&x, &i)) {
									ZEPHIR_INIT_NVAR(&_91$$19);
									ZVAL_LONG(&_91$$19, ((zephir_fast_strlen_ev(&rawKey) + 1)));
								} else {
									ZEPHIR_INIT_NVAR(&_91$$19);
									ZVAL_LONG(&_91$$19, 0);
								}
								ZVAL_LONG(&_92$$19, (zephir_fast_strlen_ev(&_86$$19) + zephir_get_numberval(&_91$$19)));
								ZEPHIR_INIT_NVAR(&_93$$19);
								zephir_substr(&_93$$19, &_85$$19, zephir_get_intval(&_92$$19), 0, ZEPHIR_SUBSTR_NO_LENGTH);
								zephir_fast_trim(&_84$$19, &_93$$19, NULL , ZEPHIR_TRIM_BOTH);
								if (!ZEPHIR_IS_STRING_IDENTICAL(&_84$$19, "")) {
									zephir_array_fetch(&_94$$20, &lines, &x, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 65);
									ZVAL_LONG(&_95$$20, (zephir_get_numberval(&i) + 1));
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexceptionuimv", &_52, 91, &_94$$20, &_95$$20);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&_96$$18);
							ZVAL_STRING(&_96$$18, "");
							zephir_array_update_zval(&lines, &x, &_96$$18, PH_COPY | PH_SEPARATE);
							ZEPHIR_SEPARATE(&x);
							zephir_increment(&x);
						}
						ZEPHIR_CALL_METHOD(&value, &compiled, "getvalue", NULL, 0);
						zephir_check_call_status();
					} else if (!ZEPHIR_IS_FALSE_IDENTICAL(&_79$$14)) {
						zephir_array_fetch(&_97$$21, &lines, &i, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 75);
						ZVAL_LONG(&_98$$21, (zephir_get_numberval(&i) + 1));
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexceptionuimv", &_52, 91, &_97$$21, &_98$$21);
						zephir_check_call_status();
					}
					if (shouldSkipKey == 0) {
						zephir_array_update_zval(&values, &key, &value, PH_COPY | PH_SEPARATE);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &lines, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&i);
	RETURN_CCTOR(&values);

}

/**
 * @param string value
 * @param array values
 * @param int line
 * @return CompiledValue|null
 */
PHP_METHOD(Zeplara_File_Parser_EnvParser, compileArrayValue) {

	zval _98$$6, _188$$16;
	zval _55$$6, _59$$6, _147$$16, _151$$16;
	zend_bool _5, _102$$6, _121$$6, _191$$16, _210$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_19 = NULL, *_23 = NULL, *_31 = NULL, *_54 = NULL, *_63 = NULL, *_84 = NULL, *_101 = NULL, *_105 = NULL, *_116 = NULL, *_126 = NULL, *_138 = NULL, *_194 = NULL, *_205 = NULL, *_215 = NULL, *_227 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, signedKey$$3 = 0;
	zval *value = NULL, value_sub, *values, values_sub, *line, line_sub, matches, _0, _1, _2, _3, _4, _6, _7, match$$3, items$$3, contents$$3, boundary$$3, boundaries$$3, compiled$$3, contentsLen$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$3, *_16$$3, _17$$3, _43$$3, _44$$3, _45$$3, _46$$3, _47$$3, *_48$$3, _49$$3, _18$$4, _20$$4, _21$$4, _22$$4, _24$$4, _25$$4, _26$$4, _27$$4, _28$$4, _29$$4, _30$$4, _32$$5, _33$$5, _34$$5, _35$$5, _36$$5, _37$$5, _38$$5, _39$$5, _40$$5, _41$$5, _42$$5, _50$$6, _51$$6, _52$$6, _53$$6, _56$$6, _57$$6, _58$$6, _60$$6, _61$$6, _62$$6, _64$$6, _65$$6, _66$$6, _67$$6, _68$$6, _69$$6, _70$$6, _71$$6, _72$$6, _73$$6, _74$$6, _75$$6, _76$$6, _85$$6, _86$$6, _87$$6, _88$$6, _89$$6, _90$$6, _91$$6, _92$$6, _96$$6, _97$$6, _99$$6, _100$$6, _103$$6, _104$$6, _106$$6, _107$$6, _117$$6, _118$$6, _119$$6, _120$$6, _122$$6, _123$$6, _124$$6, _125$$6, _127$$6, _128$$6, _129$$6, _139$$6, _140$$6, _141$$6, _142$$6, _77$$8, _78$$8, _79$$8, _80$$8, _81$$8, _82$$8, _83$$8, _93$$9, _94$$11, _95$$11, _108$$12, _109$$12, _110$$12, _111$$12, _112$$12, _113$$12, _114$$12, _115$$13, _130$$14, _131$$14, _132$$14, _133$$14, _134$$14, _135$$14, _136$$14, _137$$15, _143$$16, _144$$16, _145$$16, _146$$16, _148$$16, _149$$16, _150$$16, _152$$16, _153$$16, _154$$16, _155$$16, _156$$16, _157$$16, _158$$16, _159$$16, _160$$16, _161$$16, _162$$16, _163$$16, _164$$16, _165$$16, _166$$16, _167$$16, _175$$16, _176$$16, _177$$16, _178$$16, _179$$16, _180$$16, _181$$16, _182$$16, _186$$16, _187$$16, _189$$16, _190$$16, _192$$16, _193$$16, _195$$16, _196$$16, _206$$16, _207$$16, _208$$16, _209$$16, _211$$16, _212$$16, _213$$16, _214$$16, _216$$16, _217$$16, _218$$16, _228$$16, _229$$16, _230$$16, _231$$16, _168$$18, _169$$18, _170$$18, _171$$18, _172$$18, _173$$18, _174$$18, _183$$19, _184$$21, _185$$21, _197$$22, _198$$22, _199$$22, _200$$22, _201$$22, _202$$22, _203$$22, _204$$23, _219$$24, _220$$24, _221$$24, _222$$24, _223$$24, _224$$24, _225$$24, _226$$25;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&match$$3);
	ZVAL_UNDEF(&items$$3);
	ZVAL_UNDEF(&contents$$3);
	ZVAL_UNDEF(&boundary$$3);
	ZVAL_UNDEF(&boundaries$$3);
	ZVAL_UNDEF(&compiled$$3);
	ZVAL_UNDEF(&contentsLen$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_43$$3);
	ZVAL_UNDEF(&_44$$3);
	ZVAL_UNDEF(&_45$$3);
	ZVAL_UNDEF(&_46$$3);
	ZVAL_UNDEF(&_47$$3);
	ZVAL_UNDEF(&_49$$3);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_27$$4);
	ZVAL_UNDEF(&_28$$4);
	ZVAL_UNDEF(&_29$$4);
	ZVAL_UNDEF(&_30$$4);
	ZVAL_UNDEF(&_32$$5);
	ZVAL_UNDEF(&_33$$5);
	ZVAL_UNDEF(&_34$$5);
	ZVAL_UNDEF(&_35$$5);
	ZVAL_UNDEF(&_36$$5);
	ZVAL_UNDEF(&_37$$5);
	ZVAL_UNDEF(&_38$$5);
	ZVAL_UNDEF(&_39$$5);
	ZVAL_UNDEF(&_40$$5);
	ZVAL_UNDEF(&_41$$5);
	ZVAL_UNDEF(&_42$$5);
	ZVAL_UNDEF(&_50$$6);
	ZVAL_UNDEF(&_51$$6);
	ZVAL_UNDEF(&_52$$6);
	ZVAL_UNDEF(&_53$$6);
	ZVAL_UNDEF(&_56$$6);
	ZVAL_UNDEF(&_57$$6);
	ZVAL_UNDEF(&_58$$6);
	ZVAL_UNDEF(&_60$$6);
	ZVAL_UNDEF(&_61$$6);
	ZVAL_UNDEF(&_62$$6);
	ZVAL_UNDEF(&_64$$6);
	ZVAL_UNDEF(&_65$$6);
	ZVAL_UNDEF(&_66$$6);
	ZVAL_UNDEF(&_67$$6);
	ZVAL_UNDEF(&_68$$6);
	ZVAL_UNDEF(&_69$$6);
	ZVAL_UNDEF(&_70$$6);
	ZVAL_UNDEF(&_71$$6);
	ZVAL_UNDEF(&_72$$6);
	ZVAL_UNDEF(&_73$$6);
	ZVAL_UNDEF(&_74$$6);
	ZVAL_UNDEF(&_75$$6);
	ZVAL_UNDEF(&_76$$6);
	ZVAL_UNDEF(&_85$$6);
	ZVAL_UNDEF(&_86$$6);
	ZVAL_UNDEF(&_87$$6);
	ZVAL_UNDEF(&_88$$6);
	ZVAL_UNDEF(&_89$$6);
	ZVAL_UNDEF(&_90$$6);
	ZVAL_UNDEF(&_91$$6);
	ZVAL_UNDEF(&_92$$6);
	ZVAL_UNDEF(&_96$$6);
	ZVAL_UNDEF(&_97$$6);
	ZVAL_UNDEF(&_99$$6);
	ZVAL_UNDEF(&_100$$6);
	ZVAL_UNDEF(&_103$$6);
	ZVAL_UNDEF(&_104$$6);
	ZVAL_UNDEF(&_106$$6);
	ZVAL_UNDEF(&_107$$6);
	ZVAL_UNDEF(&_117$$6);
	ZVAL_UNDEF(&_118$$6);
	ZVAL_UNDEF(&_119$$6);
	ZVAL_UNDEF(&_120$$6);
	ZVAL_UNDEF(&_122$$6);
	ZVAL_UNDEF(&_123$$6);
	ZVAL_UNDEF(&_124$$6);
	ZVAL_UNDEF(&_125$$6);
	ZVAL_UNDEF(&_127$$6);
	ZVAL_UNDEF(&_128$$6);
	ZVAL_UNDEF(&_129$$6);
	ZVAL_UNDEF(&_139$$6);
	ZVAL_UNDEF(&_140$$6);
	ZVAL_UNDEF(&_141$$6);
	ZVAL_UNDEF(&_142$$6);
	ZVAL_UNDEF(&_77$$8);
	ZVAL_UNDEF(&_78$$8);
	ZVAL_UNDEF(&_79$$8);
	ZVAL_UNDEF(&_80$$8);
	ZVAL_UNDEF(&_81$$8);
	ZVAL_UNDEF(&_82$$8);
	ZVAL_UNDEF(&_83$$8);
	ZVAL_UNDEF(&_93$$9);
	ZVAL_UNDEF(&_94$$11);
	ZVAL_UNDEF(&_95$$11);
	ZVAL_UNDEF(&_108$$12);
	ZVAL_UNDEF(&_109$$12);
	ZVAL_UNDEF(&_110$$12);
	ZVAL_UNDEF(&_111$$12);
	ZVAL_UNDEF(&_112$$12);
	ZVAL_UNDEF(&_113$$12);
	ZVAL_UNDEF(&_114$$12);
	ZVAL_UNDEF(&_115$$13);
	ZVAL_UNDEF(&_130$$14);
	ZVAL_UNDEF(&_131$$14);
	ZVAL_UNDEF(&_132$$14);
	ZVAL_UNDEF(&_133$$14);
	ZVAL_UNDEF(&_134$$14);
	ZVAL_UNDEF(&_135$$14);
	ZVAL_UNDEF(&_136$$14);
	ZVAL_UNDEF(&_137$$15);
	ZVAL_UNDEF(&_143$$16);
	ZVAL_UNDEF(&_144$$16);
	ZVAL_UNDEF(&_145$$16);
	ZVAL_UNDEF(&_146$$16);
	ZVAL_UNDEF(&_148$$16);
	ZVAL_UNDEF(&_149$$16);
	ZVAL_UNDEF(&_150$$16);
	ZVAL_UNDEF(&_152$$16);
	ZVAL_UNDEF(&_153$$16);
	ZVAL_UNDEF(&_154$$16);
	ZVAL_UNDEF(&_155$$16);
	ZVAL_UNDEF(&_156$$16);
	ZVAL_UNDEF(&_157$$16);
	ZVAL_UNDEF(&_158$$16);
	ZVAL_UNDEF(&_159$$16);
	ZVAL_UNDEF(&_160$$16);
	ZVAL_UNDEF(&_161$$16);
	ZVAL_UNDEF(&_162$$16);
	ZVAL_UNDEF(&_163$$16);
	ZVAL_UNDEF(&_164$$16);
	ZVAL_UNDEF(&_165$$16);
	ZVAL_UNDEF(&_166$$16);
	ZVAL_UNDEF(&_167$$16);
	ZVAL_UNDEF(&_175$$16);
	ZVAL_UNDEF(&_176$$16);
	ZVAL_UNDEF(&_177$$16);
	ZVAL_UNDEF(&_178$$16);
	ZVAL_UNDEF(&_179$$16);
	ZVAL_UNDEF(&_180$$16);
	ZVAL_UNDEF(&_181$$16);
	ZVAL_UNDEF(&_182$$16);
	ZVAL_UNDEF(&_186$$16);
	ZVAL_UNDEF(&_187$$16);
	ZVAL_UNDEF(&_189$$16);
	ZVAL_UNDEF(&_190$$16);
	ZVAL_UNDEF(&_192$$16);
	ZVAL_UNDEF(&_193$$16);
	ZVAL_UNDEF(&_195$$16);
	ZVAL_UNDEF(&_196$$16);
	ZVAL_UNDEF(&_206$$16);
	ZVAL_UNDEF(&_207$$16);
	ZVAL_UNDEF(&_208$$16);
	ZVAL_UNDEF(&_209$$16);
	ZVAL_UNDEF(&_211$$16);
	ZVAL_UNDEF(&_212$$16);
	ZVAL_UNDEF(&_213$$16);
	ZVAL_UNDEF(&_214$$16);
	ZVAL_UNDEF(&_216$$16);
	ZVAL_UNDEF(&_217$$16);
	ZVAL_UNDEF(&_218$$16);
	ZVAL_UNDEF(&_228$$16);
	ZVAL_UNDEF(&_229$$16);
	ZVAL_UNDEF(&_230$$16);
	ZVAL_UNDEF(&_231$$16);
	ZVAL_UNDEF(&_168$$18);
	ZVAL_UNDEF(&_169$$18);
	ZVAL_UNDEF(&_170$$18);
	ZVAL_UNDEF(&_171$$18);
	ZVAL_UNDEF(&_172$$18);
	ZVAL_UNDEF(&_173$$18);
	ZVAL_UNDEF(&_174$$18);
	ZVAL_UNDEF(&_183$$19);
	ZVAL_UNDEF(&_184$$21);
	ZVAL_UNDEF(&_185$$21);
	ZVAL_UNDEF(&_197$$22);
	ZVAL_UNDEF(&_198$$22);
	ZVAL_UNDEF(&_199$$22);
	ZVAL_UNDEF(&_200$$22);
	ZVAL_UNDEF(&_201$$22);
	ZVAL_UNDEF(&_202$$22);
	ZVAL_UNDEF(&_203$$22);
	ZVAL_UNDEF(&_204$$23);
	ZVAL_UNDEF(&_219$$24);
	ZVAL_UNDEF(&_220$$24);
	ZVAL_UNDEF(&_221$$24);
	ZVAL_UNDEF(&_222$$24);
	ZVAL_UNDEF(&_223$$24);
	ZVAL_UNDEF(&_224$$24);
	ZVAL_UNDEF(&_225$$24);
	ZVAL_UNDEF(&_226$$25);
	ZVAL_UNDEF(&_55$$6);
	ZVAL_UNDEF(&_59$$6);
	ZVAL_UNDEF(&_147$$16);
	ZVAL_UNDEF(&_151$$16);
	ZVAL_UNDEF(&_98$$6);
	ZVAL_UNDEF(&_188$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &value, &values, &line);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "~\\[((?>\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^\\[\\]]|(?R))*)\\]~");
	ZVAL_LONG(&_1, 256);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "~\\[((?>\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^\\[\\]]|(?R))*)\\]~");
	ZVAL_LONG(&_4, 256);
	zephir_preg_match(&_2, &_3, value, &matches, 0, zephir_get_intval(&_1) , 0 );
	_5 = zephir_is_true(&matches);
	if (_5) {
		zephir_array_fetch_long(&_6, &matches, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 100);
		zephir_array_fetch_long(&_7, &_6, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 100);
		_5 = ZEPHIR_IS_LONG_IDENTICAL(&_7, 0);
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&items$$3);
		array_init(&items$$3);
		signedKey$$3 = 0;
		ZEPHIR_INIT_VAR(&boundaries$$3);
		array_init(&boundaries$$3);
		zephir_array_fetch_long(&_8$$3, &matches, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 106);
		ZEPHIR_OBS_NVAR(value);
		zephir_array_fetch_long(value, &_8$$3, 0, PH_NOISY, "zeplara/File/Parser/EnvParser.zep", 106);
		zephir_array_fetch_long(&_9$$3, &matches, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 107);
		zephir_array_fetch_long(&_10$$3, &_9$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 107);
		ZEPHIR_CALL_METHOD(&contents$$3, this_ptr, "clearcomments", NULL, 89, &_10$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&contentsLen$$3);
		ZVAL_LONG(&contentsLen$$3, zephir_fast_strlen_ev(&contents$$3));
		ZEPHIR_INIT_VAR(&_11$$3);
		ZVAL_STRING(&_11$$3, "~\\[(?>\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^\\[\\]]|(?R))*\\]~");
		ZVAL_LONG(&_12$$3, (256 | 2));
		ZEPHIR_INIT_VAR(&_13$$3);
		ZEPHIR_INIT_VAR(&_14$$3);
		ZVAL_STRING(&_14$$3, "~\\[(?>\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^\\[\\]]|(?R))*\\]~");
		ZVAL_LONG(&_15$$3, (256 | 2));
		zephir_preg_match(&_13$$3, &_14$$3, &contents$$3, &matches, 1, zephir_get_intval(&_12$$3) , 0 );
		zephir_is_iterable(&matches, 0, "zeplara/File/Parser/EnvParser.zep", 118);
		if (Z_TYPE_P(&matches) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _16$$3)
			{
				ZEPHIR_INIT_NVAR(&match$$3);
				ZVAL_COPY(&match$$3, _16$$3);
				ZVAL_LONG(&_20$$4, 32);
				ZEPHIR_CALL_CE_STATIC(&_18$$4, zeplara_support_str_ce, "random", &_19, 0, &_20$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$4);
				ZVAL_STRING(&_21$$4, "--boundary-%s--");
				ZEPHIR_CALL_FUNCTION(&_22$$4, "sprintf", &_23, 2, &_21$$4, &_18$$4);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&boundary$$3, &_22$$4);
				zephir_array_fetch_long(&_24$$4, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 114);
				zephir_array_fetch_long(&_25$$4, &_24$$4, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 114);
				zephir_array_update_zval(&boundaries$$3, &boundary$$3, &_25$$4, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_long(&_26$$4, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 115);
				zephir_array_fetch_long(&_27$$4, &_26$$4, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 115);
				zephir_array_fetch_long(&_28$$4, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 115);
				zephir_array_fetch_long(&_29$$4, &_28$$4, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 115);
				ZVAL_LONG(&_20$$4, (zephir_get_numberval(&_27$$4) + ((zephir_fast_strlen_ev(&contents$$3) - zephir_get_numberval(&contentsLen$$3)))));
				ZVAL_LONG(&_30$$4, zephir_fast_strlen_ev(&_29$$4));
				ZEPHIR_CALL_FUNCTION(&_22$$4, "substr_replace", &_31, 92, &contents$$3, &boundary$$3, &_20$$4, &_30$$4);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&contents$$3, &_22$$4);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &matches, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_17$$3, &matches, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&match$$3, &matches, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_33$$5, 32);
					ZEPHIR_CALL_CE_STATIC(&_32$$5, zeplara_support_str_ce, "random", &_19, 0, &_33$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_34$$5);
					ZVAL_STRING(&_34$$5, "--boundary-%s--");
					ZEPHIR_CALL_FUNCTION(&_35$$5, "sprintf", &_23, 2, &_34$$5, &_32$$5);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&boundary$$3, &_35$$5);
					zephir_array_fetch_long(&_36$$5, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 114);
					zephir_array_fetch_long(&_37$$5, &_36$$5, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 114);
					zephir_array_update_zval(&boundaries$$3, &boundary$$3, &_37$$5, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_long(&_38$$5, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 115);
					zephir_array_fetch_long(&_39$$5, &_38$$5, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 115);
					zephir_array_fetch_long(&_40$$5, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 115);
					zephir_array_fetch_long(&_41$$5, &_40$$5, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 115);
					ZVAL_LONG(&_33$$5, (zephir_get_numberval(&_39$$5) + ((zephir_fast_strlen_ev(&contents$$3) - zephir_get_numberval(&contentsLen$$3)))));
					ZVAL_LONG(&_42$$5, zephir_fast_strlen_ev(&_41$$5));
					ZEPHIR_CALL_FUNCTION(&_35$$5, "substr_replace", &_31, 92, &contents$$3, &boundary$$3, &_33$$5, &_42$$5);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&contents$$3, &_35$$5);
				ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&match$$3);
		ZEPHIR_INIT_VAR(&_43$$3);
		ZVAL_STRING(&_43$$3, "~\\s*(?:((?:\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^\\:,])++)\\:)?(?:((?:\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^,])++),?)\\s*~smu");
		ZVAL_LONG(&_44$$3, (256 | 2));
		ZEPHIR_INIT_VAR(&_45$$3);
		ZEPHIR_INIT_VAR(&_46$$3);
		ZVAL_STRING(&_46$$3, "~\\s*(?:((?:\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^\\:,])++)\\:)?(?:((?:\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^,])++),?)\\s*~smu");
		ZVAL_LONG(&_47$$3, (256 | 2));
		zephir_preg_match(&_45$$3, &_46$$3, &contents$$3, &matches, 1, zephir_get_intval(&_44$$3) , 0 );
		zephir_is_iterable(&matches, 0, "zeplara/File/Parser/EnvParser.zep", 170);
		if (Z_TYPE_P(&matches) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _48$$3)
			{
				ZEPHIR_INIT_NVAR(&match$$3);
				ZVAL_COPY(&match$$3, _48$$3);
				ZEPHIR_INIT_NVAR(&_50$$6);
				zephir_array_fetch_long(&_51$$6, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 121);
				zephir_array_fetch_long(&_52$$6, &_51$$6, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 121);
				zephir_fast_trim(&_50$$6, &_52$$6, NULL , ZEPHIR_TRIM_BOTH);
				if (ZEPHIR_IS_STRING_IDENTICAL(&_50$$6, "")) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_55$$6);
				zephir_create_array(&_55$$6, 2, 0);
				ZEPHIR_INIT_NVAR(&_56$$6);
				ZVAL_STRING(&_56$$6, "");
				zephir_array_fast_append(&_55$$6, &_56$$6);
				ZEPHIR_INIT_NVAR(&_56$$6);
				ZVAL_LONG(&_56$$6, -1);
				zephir_array_fast_append(&_55$$6, &_56$$6);
				ZVAL_LONG(&_57$$6, 1);
				ZEPHIR_CALL_CE_STATIC(&_53$$6, zeplara_support_arr_ce, "get", &_54, 0, &match$$3, &_57$$6, &_55$$6);
				zephir_check_call_status();
				zephir_array_update_long(&match$$3, 1, &_53$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				ZEPHIR_INIT_NVAR(&_59$$6);
				zephir_create_array(&_59$$6, 2, 0);
				ZEPHIR_INIT_NVAR(&_56$$6);
				ZVAL_STRING(&_56$$6, "");
				zephir_array_fast_append(&_59$$6, &_56$$6);
				ZEPHIR_INIT_NVAR(&_56$$6);
				ZVAL_LONG(&_56$$6, -1);
				zephir_array_fast_append(&_59$$6, &_56$$6);
				ZVAL_LONG(&_57$$6, 2);
				ZEPHIR_CALL_CE_STATIC(&_58$$6, zeplara_support_arr_ce, "get", &_54, 0, &match$$3, &_57$$6, &_59$$6);
				zephir_check_call_status();
				zephir_array_update_long(&match$$3, 2, &_58$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				zephir_array_fetch_long(&_61$$6, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 127);
				zephir_array_fetch_long(&_62$$6, &_61$$6, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 127);
				ZEPHIR_CALL_METHOD(&_60$$6, this_ptr, "findlinebypos", &_63, 93, &contents$$3, &_62$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_64$$6);
				zephir_add_function(&_64$$6, &_60$$6, line);
				ZEPHIR_INIT_NVAR(&_56$$6);
				ZVAL_LONG(&_56$$6, (zephir_get_numberval(&_64$$6) - 1));
				zephir_array_update_multi(&match$$3, &_56$$6, SL("ll"), 2, 0, 2);
				zephir_array_fetch_long(&_65$$6, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 128);
				zephir_array_fetch_long(&_66$$6, &_65$$6, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 128);
				ZEPHIR_CALL_METHOD(&_60$$6, this_ptr, "findlinebypos", &_63, 93, &contents$$3, &_66$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_67$$6);
				zephir_add_function(&_67$$6, &_60$$6, line);
				ZEPHIR_INIT_NVAR(&_56$$6);
				ZVAL_LONG(&_56$$6, (zephir_get_numberval(&_67$$6) - 1));
				zephir_array_update_multi(&match$$3, &_56$$6, SL("ll"), 2, 1, 2);
				zephir_array_fetch_long(&_68$$6, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 129);
				zephir_array_fetch_long(&_69$$6, &_68$$6, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 129);
				ZEPHIR_CALL_METHOD(&_60$$6, this_ptr, "findlinebypos", &_63, 93, &contents$$3, &_69$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_70$$6);
				zephir_add_function(&_70$$6, &_60$$6, line);
				ZEPHIR_INIT_NVAR(&_56$$6);
				ZVAL_LONG(&_56$$6, (zephir_get_numberval(&_70$$6) - 1));
				zephir_array_update_multi(&match$$3, &_56$$6, SL("ll"), 2, 2, 2);
				ZEPHIR_INIT_NVAR(&_56$$6);
				zephir_array_fetch_long(&_71$$6, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 131);
				zephir_array_fetch_long(&_72$$6, &_71$$6, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 131);
				zephir_fast_trim(&_56$$6, &_72$$6, NULL , ZEPHIR_TRIM_BOTH);
				zephir_array_update_multi(&match$$3, &_56$$6, SL("ll"), 2, 1, 0);
				ZEPHIR_INIT_NVAR(&_56$$6);
				zephir_array_fetch_long(&_73$$6, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 132);
				zephir_array_fetch_long(&_74$$6, &_73$$6, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 132);
				zephir_fast_trim(&_56$$6, &_74$$6, NULL , ZEPHIR_TRIM_BOTH);
				zephir_array_update_multi(&match$$3, &_56$$6, SL("ll"), 2, 2, 0);
				zephir_array_fetch_long(&_75$$6, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 134);
				zephir_array_fetch_long(&_76$$6, &_75$$6, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 134);
				if (ZEPHIR_IS_STRING_IDENTICAL(&_76$$6, "")) {
					zephir_array_fetch_long(&_78$$8, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 135);
					zephir_array_fetch_long(&_79$$8, &_78$$8, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 135);
					ZEPHIR_INIT_NVAR(&_80$$8);
					ZVAL_STRING(&_80$$8, "Syntax error [%s].");
					ZEPHIR_CALL_FUNCTION(&_81$$8, "sprintf", &_23, 2, &_80$$8, &_79$$8);
					zephir_check_call_status();
					zephir_array_fetch_long(&_82$$8, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 135);
					zephir_array_fetch_long(&_83$$8, &_82$$8, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 135);
					ZEPHIR_INIT_NVAR(&_80$$8);
					ZVAL_STRING(&_80$$8, "");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexception", &_84, 0, &_81$$8, &_80$$8, &_83$$8);
					zephir_check_call_status();
				}
				zephir_array_fetch_long(&_85$$6, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 138);
				zephir_array_fetch_long(&_86$$6, &_85$$6, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 138);
				zephir_array_fetch_long(&_87$$6, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 138);
				zephir_array_fetch_long(&_88$$6, &_87$$6, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 138);
				ZEPHIR_CALL_CE_STATIC(&_60$$6, zeplara_support_arr_ce, "get", &_54, 0, &boundaries$$3, &_86$$6, &_88$$6);
				zephir_check_call_status();
				zephir_array_update_multi(&match$$3, &_60$$6, SL("ll"), 2, 2, 0);
				zephir_array_fetch_long(&_89$$6, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 140);
				zephir_array_fetch_long(&_90$$6, &_89$$6, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 140);
				zephir_array_fetch_long(&_91$$6, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 147);
				zephir_array_fetch_long(&_92$$6, &_91$$6, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 147);
				if (ZEPHIR_IS_LONG_IDENTICAL(&_90$$6, -1)) {
					while (1) {
						if (!(zephir_array_isset_long(&items$$3, signedKey$$3))) {
							break;
						}
						signedKey$$3++;
					}
					ZEPHIR_INIT_NVAR(&_93$$9);
					ZVAL_LONG(&_93$$9, signedKey$$3);
					zephir_array_update_multi(&match$$3, &_93$$9, SL("ll"), 2, 1, 0);
					signedKey$$3++;
				} else if (zephir_is_numeric(&_92$$6)) {
					zephir_array_fetch_long(&_94$$11, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 148);
					zephir_array_fetch_long(&_95$$11, &_94$$11, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 148);
					signedKey$$3 = (zephir_get_numberval(&_95$$11) + 1);
				}
				zephir_array_fetch_long(&_96$$6, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 151);
				ZEPHIR_OBS_NVAR(&_97$$6);
				zephir_array_fetch_long(&_97$$6, &_96$$6, 0, PH_NOISY, "zeplara/File/Parser/EnvParser.zep", 151);
				zephir_get_strval(&_98$$6, &_97$$6);
				zephir_array_fetch_long(&_99$$6, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 151);
				zephir_array_fetch_long(&_100$$6, &_99$$6, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 151);
				ZEPHIR_CALL_METHOD(&compiled$$3, this_ptr, "compilevalue", &_101, 90, &_98$$6, values, &_100$$6);
				zephir_check_call_status();
				_102$$6 = Z_TYPE_P(&compiled$$3) == IS_NULL;
				if (!(_102$$6)) {
					ZEPHIR_INIT_NVAR(&_56$$6);
					zephir_array_fetch_long(&_103$$6, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 153);
					zephir_array_fetch_long(&_104$$6, &_103$$6, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 153);
					ZEPHIR_CALL_METHOD(&_60$$6, &compiled$$3, "getrawvalue", &_105, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_106$$6, &_60$$6, "getvalue", NULL, 0);
					zephir_check_call_status();
					ZVAL_LONG(&_57$$6, zephir_fast_strlen_ev(&_106$$6));
					ZEPHIR_INIT_NVAR(&_107$$6);
					zephir_substr(&_107$$6, &_104$$6, zephir_get_intval(&_57$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_fast_trim(&_56$$6, &_107$$6, NULL , ZEPHIR_TRIM_BOTH);
					_102$$6 = !ZEPHIR_IS_STRING_IDENTICAL(&_56$$6, "");
				}
				if (_102$$6) {
					zephir_array_fetch_long(&_109$$12, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 154);
					zephir_array_fetch_long(&_110$$12, &_109$$12, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 154);
					ZEPHIR_INIT_NVAR(&_111$$12);
					ZVAL_STRING(&_111$$12, "Syntax error [%s].");
					ZEPHIR_CALL_FUNCTION(&_112$$12, "sprintf", &_23, 2, &_111$$12, &_110$$12);
					zephir_check_call_status();
					zephir_array_fetch_long(&_113$$12, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 154);
					zephir_array_fetch_long(&_114$$12, &_113$$12, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 154);
					ZEPHIR_INIT_NVAR(&_111$$12);
					ZVAL_STRING(&_111$$12, "");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexception", &_84, 0, &_112$$12, &_111$$12, &_114$$12);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(&_115$$13, &compiled$$3, "getvalue", &_116, 0);
					zephir_check_call_status();
					zephir_array_update_multi(&match$$3, &_115$$13, SL("ll"), 2, 1, 0);
				}
				zephir_array_fetch_long(&_117$$6, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 159);
				zephir_array_fetch_long(&_118$$6, &_117$$6, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 159);
				zephir_array_fetch_long(&_119$$6, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 159);
				zephir_array_fetch_long(&_120$$6, &_119$$6, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 159);
				ZEPHIR_CALL_METHOD(&compiled$$3, this_ptr, "compilevalue", &_101, 90, &_118$$6, values, &_120$$6);
				zephir_check_call_status();
				_121$$6 = Z_TYPE_P(&compiled$$3) == IS_NULL;
				if (!(_121$$6)) {
					ZEPHIR_INIT_NVAR(&_122$$6);
					zephir_array_fetch_long(&_123$$6, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 161);
					zephir_array_fetch_long(&_124$$6, &_123$$6, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 161);
					ZEPHIR_CALL_METHOD(&_125$$6, &compiled$$3, "getrawvalue", &_126, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_127$$6, &_125$$6, "getvalue", NULL, 0);
					zephir_check_call_status();
					ZVAL_LONG(&_128$$6, zephir_fast_strlen_ev(&_127$$6));
					ZEPHIR_INIT_NVAR(&_129$$6);
					zephir_substr(&_129$$6, &_124$$6, zephir_get_intval(&_128$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_fast_trim(&_122$$6, &_129$$6, NULL , ZEPHIR_TRIM_BOTH);
					_121$$6 = !ZEPHIR_IS_STRING_IDENTICAL(&_122$$6, "");
				}
				if (_121$$6) {
					zephir_array_fetch_long(&_131$$14, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 162);
					zephir_array_fetch_long(&_132$$14, &_131$$14, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 162);
					ZEPHIR_INIT_NVAR(&_133$$14);
					ZVAL_STRING(&_133$$14, "Syntax error [%s].");
					ZEPHIR_CALL_FUNCTION(&_134$$14, "sprintf", &_23, 2, &_133$$14, &_132$$14);
					zephir_check_call_status();
					zephir_array_fetch_long(&_135$$14, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 162);
					zephir_array_fetch_long(&_136$$14, &_135$$14, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 162);
					ZEPHIR_INIT_NVAR(&_133$$14);
					ZVAL_STRING(&_133$$14, "");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexception", &_84, 0, &_134$$14, &_133$$14, &_136$$14);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(&_137$$15, &compiled$$3, "getvalue", &_138, 0);
					zephir_check_call_status();
					zephir_array_update_multi(&match$$3, &_137$$15, SL("ll"), 2, 2, 0);
				}
				zephir_array_fetch_long(&_139$$6, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 167);
				zephir_array_fetch_long(&_140$$6, &_139$$6, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 167);
				zephir_array_fetch_long(&_141$$6, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 167);
				ZEPHIR_OBS_NVAR(&_142$$6);
				zephir_array_fetch_long(&_142$$6, &_141$$6, 0, PH_NOISY, "zeplara/File/Parser/EnvParser.zep", 167);
				zephir_array_update_zval(&items$$3, &_142$$6, &_140$$6, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &matches, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_49$$3, &matches, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_49$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&match$$3, &matches, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_143$$16);
					zephir_array_fetch_long(&_144$$16, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 121);
					zephir_array_fetch_long(&_145$$16, &_144$$16, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 121);
					zephir_fast_trim(&_143$$16, &_145$$16, NULL , ZEPHIR_TRIM_BOTH);
					if (ZEPHIR_IS_STRING_IDENTICAL(&_143$$16, "")) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&_147$$16);
					zephir_create_array(&_147$$16, 2, 0);
					ZEPHIR_INIT_NVAR(&_148$$16);
					ZVAL_STRING(&_148$$16, "");
					zephir_array_fast_append(&_147$$16, &_148$$16);
					ZEPHIR_INIT_NVAR(&_148$$16);
					ZVAL_LONG(&_148$$16, -1);
					zephir_array_fast_append(&_147$$16, &_148$$16);
					ZVAL_LONG(&_149$$16, 1);
					ZEPHIR_CALL_CE_STATIC(&_146$$16, zeplara_support_arr_ce, "get", &_54, 0, &match$$3, &_149$$16, &_147$$16);
					zephir_check_call_status();
					zephir_array_update_long(&match$$3, 1, &_146$$16, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					ZEPHIR_INIT_NVAR(&_151$$16);
					zephir_create_array(&_151$$16, 2, 0);
					ZEPHIR_INIT_NVAR(&_148$$16);
					ZVAL_STRING(&_148$$16, "");
					zephir_array_fast_append(&_151$$16, &_148$$16);
					ZEPHIR_INIT_NVAR(&_148$$16);
					ZVAL_LONG(&_148$$16, -1);
					zephir_array_fast_append(&_151$$16, &_148$$16);
					ZVAL_LONG(&_149$$16, 2);
					ZEPHIR_CALL_CE_STATIC(&_150$$16, zeplara_support_arr_ce, "get", &_54, 0, &match$$3, &_149$$16, &_151$$16);
					zephir_check_call_status();
					zephir_array_update_long(&match$$3, 2, &_150$$16, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
					zephir_array_fetch_long(&_153$$16, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 127);
					zephir_array_fetch_long(&_154$$16, &_153$$16, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 127);
					ZEPHIR_CALL_METHOD(&_152$$16, this_ptr, "findlinebypos", &_63, 93, &contents$$3, &_154$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_155$$16);
					zephir_add_function(&_155$$16, &_152$$16, line);
					ZEPHIR_INIT_NVAR(&_148$$16);
					ZVAL_LONG(&_148$$16, (zephir_get_numberval(&_155$$16) - 1));
					zephir_array_update_multi(&match$$3, &_148$$16, SL("ll"), 2, 0, 2);
					zephir_array_fetch_long(&_156$$16, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 128);
					zephir_array_fetch_long(&_157$$16, &_156$$16, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 128);
					ZEPHIR_CALL_METHOD(&_152$$16, this_ptr, "findlinebypos", &_63, 93, &contents$$3, &_157$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_158$$16);
					zephir_add_function(&_158$$16, &_152$$16, line);
					ZEPHIR_INIT_NVAR(&_148$$16);
					ZVAL_LONG(&_148$$16, (zephir_get_numberval(&_158$$16) - 1));
					zephir_array_update_multi(&match$$3, &_148$$16, SL("ll"), 2, 1, 2);
					zephir_array_fetch_long(&_159$$16, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 129);
					zephir_array_fetch_long(&_160$$16, &_159$$16, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 129);
					ZEPHIR_CALL_METHOD(&_152$$16, this_ptr, "findlinebypos", &_63, 93, &contents$$3, &_160$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_161$$16);
					zephir_add_function(&_161$$16, &_152$$16, line);
					ZEPHIR_INIT_NVAR(&_148$$16);
					ZVAL_LONG(&_148$$16, (zephir_get_numberval(&_161$$16) - 1));
					zephir_array_update_multi(&match$$3, &_148$$16, SL("ll"), 2, 2, 2);
					ZEPHIR_INIT_NVAR(&_148$$16);
					zephir_array_fetch_long(&_162$$16, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 131);
					zephir_array_fetch_long(&_163$$16, &_162$$16, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 131);
					zephir_fast_trim(&_148$$16, &_163$$16, NULL , ZEPHIR_TRIM_BOTH);
					zephir_array_update_multi(&match$$3, &_148$$16, SL("ll"), 2, 1, 0);
					ZEPHIR_INIT_NVAR(&_148$$16);
					zephir_array_fetch_long(&_164$$16, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 132);
					zephir_array_fetch_long(&_165$$16, &_164$$16, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 132);
					zephir_fast_trim(&_148$$16, &_165$$16, NULL , ZEPHIR_TRIM_BOTH);
					zephir_array_update_multi(&match$$3, &_148$$16, SL("ll"), 2, 2, 0);
					zephir_array_fetch_long(&_166$$16, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 134);
					zephir_array_fetch_long(&_167$$16, &_166$$16, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 134);
					if (ZEPHIR_IS_STRING_IDENTICAL(&_167$$16, "")) {
						zephir_array_fetch_long(&_169$$18, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 135);
						zephir_array_fetch_long(&_170$$18, &_169$$18, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 135);
						ZEPHIR_INIT_NVAR(&_171$$18);
						ZVAL_STRING(&_171$$18, "Syntax error [%s].");
						ZEPHIR_CALL_FUNCTION(&_172$$18, "sprintf", &_23, 2, &_171$$18, &_170$$18);
						zephir_check_call_status();
						zephir_array_fetch_long(&_173$$18, &match$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 135);
						zephir_array_fetch_long(&_174$$18, &_173$$18, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 135);
						ZEPHIR_INIT_NVAR(&_171$$18);
						ZVAL_STRING(&_171$$18, "");
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexception", &_84, 0, &_172$$18, &_171$$18, &_174$$18);
						zephir_check_call_status();
					}
					zephir_array_fetch_long(&_175$$16, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 138);
					zephir_array_fetch_long(&_176$$16, &_175$$16, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 138);
					zephir_array_fetch_long(&_177$$16, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 138);
					zephir_array_fetch_long(&_178$$16, &_177$$16, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 138);
					ZEPHIR_CALL_CE_STATIC(&_152$$16, zeplara_support_arr_ce, "get", &_54, 0, &boundaries$$3, &_176$$16, &_178$$16);
					zephir_check_call_status();
					zephir_array_update_multi(&match$$3, &_152$$16, SL("ll"), 2, 2, 0);
					zephir_array_fetch_long(&_179$$16, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 140);
					zephir_array_fetch_long(&_180$$16, &_179$$16, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 140);
					zephir_array_fetch_long(&_181$$16, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 147);
					zephir_array_fetch_long(&_182$$16, &_181$$16, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 147);
					if (ZEPHIR_IS_LONG_IDENTICAL(&_180$$16, -1)) {
						while (1) {
							if (!(zephir_array_isset_long(&items$$3, signedKey$$3))) {
								break;
							}
							signedKey$$3++;
						}
						ZEPHIR_INIT_NVAR(&_183$$19);
						ZVAL_LONG(&_183$$19, signedKey$$3);
						zephir_array_update_multi(&match$$3, &_183$$19, SL("ll"), 2, 1, 0);
						signedKey$$3++;
					} else if (zephir_is_numeric(&_182$$16)) {
						zephir_array_fetch_long(&_184$$21, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 148);
						zephir_array_fetch_long(&_185$$21, &_184$$21, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 148);
						signedKey$$3 = (zephir_get_numberval(&_185$$21) + 1);
					}
					zephir_array_fetch_long(&_186$$16, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 151);
					ZEPHIR_OBS_NVAR(&_187$$16);
					zephir_array_fetch_long(&_187$$16, &_186$$16, 0, PH_NOISY, "zeplara/File/Parser/EnvParser.zep", 151);
					zephir_get_strval(&_188$$16, &_187$$16);
					zephir_array_fetch_long(&_189$$16, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 151);
					zephir_array_fetch_long(&_190$$16, &_189$$16, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 151);
					ZEPHIR_CALL_METHOD(&compiled$$3, this_ptr, "compilevalue", &_101, 90, &_188$$16, values, &_190$$16);
					zephir_check_call_status();
					_191$$16 = Z_TYPE_P(&compiled$$3) == IS_NULL;
					if (!(_191$$16)) {
						ZEPHIR_INIT_NVAR(&_148$$16);
						zephir_array_fetch_long(&_192$$16, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 153);
						zephir_array_fetch_long(&_193$$16, &_192$$16, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 153);
						ZEPHIR_CALL_METHOD(&_152$$16, &compiled$$3, "getrawvalue", &_194, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_195$$16, &_152$$16, "getvalue", NULL, 0);
						zephir_check_call_status();
						ZVAL_LONG(&_149$$16, zephir_fast_strlen_ev(&_195$$16));
						ZEPHIR_INIT_NVAR(&_196$$16);
						zephir_substr(&_196$$16, &_193$$16, zephir_get_intval(&_149$$16), 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_fast_trim(&_148$$16, &_196$$16, NULL , ZEPHIR_TRIM_BOTH);
						_191$$16 = !ZEPHIR_IS_STRING_IDENTICAL(&_148$$16, "");
					}
					if (_191$$16) {
						zephir_array_fetch_long(&_198$$22, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 154);
						zephir_array_fetch_long(&_199$$22, &_198$$22, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 154);
						ZEPHIR_INIT_NVAR(&_200$$22);
						ZVAL_STRING(&_200$$22, "Syntax error [%s].");
						ZEPHIR_CALL_FUNCTION(&_201$$22, "sprintf", &_23, 2, &_200$$22, &_199$$22);
						zephir_check_call_status();
						zephir_array_fetch_long(&_202$$22, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 154);
						zephir_array_fetch_long(&_203$$22, &_202$$22, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 154);
						ZEPHIR_INIT_NVAR(&_200$$22);
						ZVAL_STRING(&_200$$22, "");
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexception", &_84, 0, &_201$$22, &_200$$22, &_203$$22);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_METHOD(&_204$$23, &compiled$$3, "getvalue", &_205, 0);
						zephir_check_call_status();
						zephir_array_update_multi(&match$$3, &_204$$23, SL("ll"), 2, 1, 0);
					}
					zephir_array_fetch_long(&_206$$16, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 159);
					zephir_array_fetch_long(&_207$$16, &_206$$16, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 159);
					zephir_array_fetch_long(&_208$$16, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 159);
					zephir_array_fetch_long(&_209$$16, &_208$$16, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 159);
					ZEPHIR_CALL_METHOD(&compiled$$3, this_ptr, "compilevalue", &_101, 90, &_207$$16, values, &_209$$16);
					zephir_check_call_status();
					_210$$16 = Z_TYPE_P(&compiled$$3) == IS_NULL;
					if (!(_210$$16)) {
						ZEPHIR_INIT_NVAR(&_211$$16);
						zephir_array_fetch_long(&_212$$16, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 161);
						zephir_array_fetch_long(&_213$$16, &_212$$16, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 161);
						ZEPHIR_CALL_METHOD(&_214$$16, &compiled$$3, "getrawvalue", &_215, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_216$$16, &_214$$16, "getvalue", NULL, 0);
						zephir_check_call_status();
						ZVAL_LONG(&_217$$16, zephir_fast_strlen_ev(&_216$$16));
						ZEPHIR_INIT_NVAR(&_218$$16);
						zephir_substr(&_218$$16, &_213$$16, zephir_get_intval(&_217$$16), 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_fast_trim(&_211$$16, &_218$$16, NULL , ZEPHIR_TRIM_BOTH);
						_210$$16 = !ZEPHIR_IS_STRING_IDENTICAL(&_211$$16, "");
					}
					if (_210$$16) {
						zephir_array_fetch_long(&_220$$24, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 162);
						zephir_array_fetch_long(&_221$$24, &_220$$24, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 162);
						ZEPHIR_INIT_NVAR(&_222$$24);
						ZVAL_STRING(&_222$$24, "Syntax error [%s].");
						ZEPHIR_CALL_FUNCTION(&_223$$24, "sprintf", &_23, 2, &_222$$24, &_221$$24);
						zephir_check_call_status();
						zephir_array_fetch_long(&_224$$24, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 162);
						zephir_array_fetch_long(&_225$$24, &_224$$24, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 162);
						ZEPHIR_INIT_NVAR(&_222$$24);
						ZVAL_STRING(&_222$$24, "");
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexception", &_84, 0, &_223$$24, &_222$$24, &_225$$24);
						zephir_check_call_status();
					} else {
						ZEPHIR_CALL_METHOD(&_226$$25, &compiled$$3, "getvalue", &_227, 0);
						zephir_check_call_status();
						zephir_array_update_multi(&match$$3, &_226$$25, SL("ll"), 2, 2, 0);
					}
					zephir_array_fetch_long(&_228$$16, &match$$3, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 167);
					zephir_array_fetch_long(&_229$$16, &_228$$16, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 167);
					zephir_array_fetch_long(&_230$$16, &match$$3, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 167);
					ZEPHIR_OBS_NVAR(&_231$$16);
					zephir_array_fetch_long(&_231$$16, &_230$$16, 0, PH_NOISY, "zeplara/File/Parser/EnvParser.zep", 167);
					zephir_array_update_zval(&items$$3, &_231$$16, &_229$$16, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&match$$3);
		object_init_ex(return_value, zeplara_file_parser_compiledvalue_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 94, &items$$3, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @param array values
 * @param int line
 * @return CompiledValue|null
 */
PHP_METHOD(Zeplara_File_Parser_EnvParser, compileStringValue) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *values, values_sub, *line, line_sub, matches, _0, _1, _2, _3$$4, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &value, &values, &line);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "~^(?:\"([^\"\\\\]*(?:\\\\.[^\"\\\\]*)*)\"|'([^'\\\\]*(?:\\\\.[^'\\\\]*)*)')~");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "~^(?:\"([^\"\\\\]*(?:\\\\.[^\"\\\\]*)*)\"|'([^'\\\\]*(?:\\\\.[^'\\\\]*)*)')~");
	zephir_preg_match(&_1, &_2, value, &matches, 0, 0 , 0 );
	if (zephir_is_true(&matches)) {
		if (zephir_array_isset_long(&matches, 2)) {
			zephir_array_fetch_long(&_3$$4, &matches, 2, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 188);
			zephir_array_update_long(&matches, 1, &_3$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "error_clear_last", NULL, 48);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_create_closure_ex(&_4$$3, NULL, zeplara_1__closure_ce, SL("__invoke"));
		zephir_update_static_property_ce(zeplara_1__closure_ce, ZEND_STRL("line"), line);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 49, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "~%s~");
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "\\$\\{([a-zA-Z0-9_.]+)\\}");
		ZEPHIR_CALL_FUNCTION(&_8$$3, "sprintf", NULL, 2, &_6$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZEPHIR_INIT_NVAR(&_6$$3);
		zephir_create_closure_ex(&_6$$3, NULL, zeplara_2__closure_ce, SL("__invoke"));
		zephir_update_static_property_ce(zeplara_2__closure_ce, ZEND_STRL("values"), values);
		zephir_array_fetch_long(&_9$$3, &matches, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 201);
		ZEPHIR_CALL_FUNCTION(&_10$$3, "preg_replace_callback", NULL, 42, &_8$$3, &_6$$3, &_9$$3);
		zephir_check_call_status();
		zephir_array_update_long(&matches, 1, &_10$$3, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 55);
		zephir_check_call_status();
		object_init_ex(return_value, zeplara_file_parser_compiledvalue_ce);
		ZEPHIR_INIT_NVAR(&_7$$3);
		zephir_array_fetch_long(&_11$$3, &matches, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 205);
		zephir_stripslashes(&_7$$3, &_11$$3);
		zephir_array_fetch_long(&_12$$3, &matches, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 205);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 94, &_7$$3, &_12$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @param array values
 * @param int line
 * @return CompiledValue|null
 */
PHP_METHOD(Zeplara_File_Parser_EnvParser, compileBooleanValue) {

	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *value = NULL, value_sub, *values, values_sub, *line, line_sub, _1, _3, _5, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &value, &values, &line);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_explode_str(&_3, SL("\n"), value, LONG_MAX);
	ZEPHIR_CALL_CE_STATIC(&_1, zeplara_support_arr_ce, "first", &_2, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(value, zeplara_support_str_ce, "lower", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "true");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "false");
	zephir_array_fast_append(&_4, &_5);
	if (zephir_fast_in_array(value, &_4)) {
		object_init_ex(return_value, zeplara_file_parser_compiledvalue_ce);
		ZEPHIR_INIT_VAR(&_6$$3);
		if (ZEPHIR_IS_STRING(value, "true")) {
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZVAL_BOOL(&_6$$3, 1);
		} else {
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZVAL_BOOL(&_6$$3, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 94, &_6$$3, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @param array values
 * @param int line
 * @return CompiledValue|null
 */
PHP_METHOD(Zeplara_File_Parser_EnvParser, compileNullValue) {

	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *value = NULL, value_sub, *values, values_sub, *line, line_sub, _1, _3, _5, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &value, &values, &line);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_explode_str(&_3, SL("\n"), value, LONG_MAX);
	ZEPHIR_CALL_CE_STATIC(&_1, zeplara_support_arr_ce, "first", &_2, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(value, zeplara_support_str_ce, "lower", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "null");
	zephir_array_fast_append(&_4, &_5);
	if (zephir_fast_in_array(value, &_4)) {
		object_init_ex(return_value, zeplara_file_parser_compiledvalue_ce);
		ZVAL_NULL(&_6$$3);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 94, &_6$$3, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @param array values
 * @param int line
 * @return CompiledValue|null
 */
PHP_METHOD(Zeplara_File_Parser_EnvParser, compileIntegerOrFloatValue) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value = NULL, value_sub, *values, values_sub, *line, line_sub, _1, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &value, &values, &line);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_explode_str(&_1, SL("\n"), value, LONG_MAX);
	ZEPHIR_CALL_CE_STATIC(value, zeplara_support_arr_ce, "first", &_0, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_numeric(value)) {
		object_init_ex(return_value, zeplara_file_parser_compiledvalue_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "~^[-\\+]?(?:(?:\\.[0-9]+)|(?:[0-9]+\\.(?:[0-9]+)?)|(?:(?:[0-9]+[eE][0-9]+)))$~");
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "~^[-\\+]?(?:(?:\\.[0-9]+)|(?:[0-9]+\\.(?:[0-9]+)?)|(?:(?:[0-9]+[eE][0-9]+)))$~");
		zephir_preg_match(&_5$$3, &_6$$3, value, &_3$$3, 0, 0 , 0 );
		if (zephir_get_boolval(&_5$$3)) {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_DOUBLE(&_2$$3, zephir_get_doubleval(value));
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_LONG(&_2$$3, zephir_get_intval(value));
		}
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 94, &_2$$3, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @param array values
 * @param int line
 * @return CompiledValue|null
 */
PHP_METHOD(Zeplara_File_Parser_EnvParser, compileVariableValue) {

	zend_bool _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_10 = NULL, *_14 = NULL;
	zval *value = NULL, value_sub, *values, values_sub, *line, line_sub, matches, _1, _2, _3, _4, _5, _6, _7, _9, _11, _12, _13$$3, _15$$3, _16$$3, _17$$3, _18$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &value, &values, &line);

	ZEPHIR_SEPARATE_PARAM(value);


	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_explode_str(&_1, SL("\n"), value, LONG_MAX);
	ZEPHIR_CALL_CE_STATIC(value, zeplara_support_arr_ce, "first", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "~^%s$~");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "\\$\\{([a-zA-Z0-9_.]+)\\}");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 2, &_3, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 256);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_7, 256);
	zephir_preg_match(&_3, &_5, value, &matches, 0, zephir_get_intval(&_6) , 0 );
	_8 = zephir_is_true(&matches);
	if (_8) {
		zephir_array_fetch_long(&_11, &matches, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 268);
		zephir_array_fetch_long(&_12, &_11, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 268);
		ZEPHIR_CALL_CE_STATIC(&_9, zeplara_support_arr_ce, "has", &_10, 0, values, &_12);
		zephir_check_call_status();
		_8 = zephir_is_true(&_9);
	}
	if (_8) {
		object_init_ex(return_value, zeplara_file_parser_compiledvalue_ce);
		zephir_array_fetch_long(&_15$$3, &matches, 1, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 269);
		zephir_array_fetch_long(&_16$$3, &_15$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 269);
		ZEPHIR_CALL_CE_STATIC(&_13$$3, zeplara_support_arr_ce, "get", &_14, 0, values, &_16$$3);
		zephir_check_call_status();
		zephir_array_fetch_long(&_17$$3, &matches, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 269);
		zephir_array_fetch_long(&_18$$3, &_17$$3, 0, PH_NOISY | PH_READONLY, "zeplara/File/Parser/EnvParser.zep", 269);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 94, &_13$$3, &_18$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @param int line
 * @throws ParserException
 */
PHP_METHOD(Zeplara_File_Parser_EnvParser, throwParserExceptionUIMV) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *line, line_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &line);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Syntax error [%s], Unexpected Inline Multiple Variable.");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 2, &_1, value);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwparserexception", NULL, 0, &_2, &_1, line);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @param array values
 * @param int line
 * @return CompiledValue|null
 */
PHP_METHOD(Zeplara_File_Parser_EnvParser, compileValue) {

	zval _7$$4, _9$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *values, values_sub, *line, line_sub, _0, compiler, compiled, _4, *_5, _6, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&compiler);
	ZVAL_UNDEF(&compiled);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &value, &values, &line);



	zephir_read_static_property_ce(&_0, zeplara_file_parser_envparser_ce, SL("compilerMethodsCache"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "get_class_methods", NULL, 5, this_ptr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "~compile.+Value~i");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "preg_grep", NULL, 95, &_2$$3, &_1$$3);
		zephir_check_call_status();
		zephir_update_static_property_ce(zeplara_file_parser_envparser_ce, ZEND_STRL("compilerMethodsCache"), &_3$$3);
	}
	zephir_read_static_property_ce(&_4, zeplara_file_parser_envparser_ce, SL("compilerMethodsCache"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "zeplara/File/Parser/EnvParser.zep", 304);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&compiler);
			ZVAL_COPY(&compiler, _5);
			ZEPHIR_INIT_NVAR(&_7$$4);
			zephir_create_array(&_7$$4, 2, 0);
			zephir_array_fast_append(&_7$$4, this_ptr);
			zephir_array_fast_append(&_7$$4, &compiler);
			ZEPHIR_CALL_FUNCTION(&compiled, "call_user_func", &_8, 32, &_7$$4, value, values, line);
			zephir_check_call_status();
			if (Z_TYPE_P(&compiled) != IS_NULL) {
				RETURN_CCTOR(&compiled);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&compiler, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$6);
				zephir_create_array(&_9$$6, 2, 0);
				zephir_array_fast_append(&_9$$6, this_ptr);
				zephir_array_fast_append(&_9$$6, &compiler);
				ZEPHIR_CALL_FUNCTION(&compiled, "call_user_func", &_8, 32, &_9$$6, value, values, line);
				zephir_check_call_status();
				if (Z_TYPE_P(&compiled) != IS_NULL) {
					RETURN_CCTOR(&compiled);
				}
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&compiler);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string value
 * @return string
 */
PHP_METHOD(Zeplara_File_Parser_EnvParser, clearComments) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "~(?:\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*')(*SKIP)(*FAIL)|\\#(?:\"[^\"\\\\]*(?:\\\\.[^\"\\\\]*)*\"|'[^'\\\\]*(?:\\\\.[^'\\\\]*)*'|[^\\#\\\\\n]|(?:[^\\#\\\\\n]|\\\\.)*)*\\#?~smu");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 96, &_0, &_1, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string value
 * @param int pos
 * @return int
 */
PHP_METHOD(Zeplara_File_Parser_EnvParser, findLineByPos) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *value = NULL, value_sub, *pos = NULL, pos_sub, _0, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&pos_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &pos);

	ZEPHIR_SEPARATE_PARAM(value);
	ZEPHIR_SEPARATE_PARAM(pos);


	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_LE_LONG(pos, 0)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 1);
	} else {
		ZEPHIR_CPY_WRT(&_0, pos);
	}
	ZEPHIR_CPY_WRT(pos, &_0);
	ZEPHIR_CALL_FUNCTION(&_2, "str_split", NULL, 97, value, pos);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 0);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "");
	ZEPHIR_CALL_CE_STATIC(value, zeplara_support_arr_ce, "get", &_1, 0, &_2, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "\n");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "");
	zephir_fast_str_replace(&_4, &_5, &_6, value);
	RETURN_MM_LONG(((zephir_fast_strlen_ev(value) - zephir_fast_strlen_ev(&_4)) + 1));

}

void zephir_init_static_properties_Zeplara_File_Parser_EnvParser(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(zeplara_file_parser_envparser_ce, ZEND_STRL("compilerMethodsCache"), &_0);
	ZEPHIR_MM_RESTORE();

}

