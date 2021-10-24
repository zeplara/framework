
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * @method Finder|FileFilter file()
 * @method Finder|FileFilter files()
 * @method Finder|IgnoreDotFileFilter ignoreDotFile()
 * @method Finder|IgnoreDotFileFilter ignoreDotFiles()
 * @method Finder|FileExtensionFilter extension($extensions, $state = FileExtensionFilter::EXPECTED)
 * @method Finder|FileExtensionFilter extensions($extensions, $state = FileExtensionFilter::EXPECTED)
 * @method Finder|DirectoryFilter directory()
 * @method Finder|DirectoryFilter directories()
 * @method Finder|DirectoryFilter dir()
 * @method Finder|DirectoryFilter dirs()
 * @method Finder|ExecutableFilter executable()
 * @method Finder|LinkFilter link()
 * @method Finder|LinkFilter links()
 * @method Finder|ReadableFilter readable()
 * @method Finder|WriteableFilter writeable()
 * @method Finder|CallbackFilter callback(callable $callback)
 * @method Finder|DateFilter date($time, $operator)
 */
ZEPHIR_INIT_CLASS(Zeplara_File_Finder_Finder) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\File\\Finder, Finder, zeplara, file_finder_finder, zeplara_file_finder_finder_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(zeplara_file_finder_finder_ce, SL("path"), ZEND_ACC_PROTECTED);

	/**
	 * @var int
	 */
	zend_declare_property_null(zeplara_file_finder_finder_ce, SL("depth"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_file_finder_finder_ce, SL("filters"), ZEND_ACC_PROTECTED);

	zend_class_implements(zeplara_file_finder_finder_ce, 1, zeplara_interfaces_file_finder_finder_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_File_Finder_Finder, getPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "path");

}

/**
 */
PHP_METHOD(Zeplara_File_Finder_Finder, getDepth) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "depth");

}

/**
 */
PHP_METHOD(Zeplara_File_Finder_Finder, setDepth) {

	zval *depth_param = NULL, _0;
	zend_long depth;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &depth_param);

	depth = zephir_get_intval(depth_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, depth);
	zephir_update_property_zval(this_ptr, ZEND_STRL("depth"), &_0);
	RETURN_THISW();

}

/**
 */
PHP_METHOD(Zeplara_File_Finder_Finder, getFilters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "filters");

}

/**
 */
PHP_METHOD(Zeplara_File_Finder_Finder, setFilters) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filters_param = NULL;
	zval filters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filters_param);

	zephir_get_arrval(&filters, filters_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("filters"), &filters);
	RETURN_THIS();

}

/**
 * @param string path
 * @param depth
 * @param array filters
 */
PHP_METHOD(Zeplara_File_Finder_Finder, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filters;
	zval *path, path_sub, *depth = NULL, depth_sub, *filters_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&depth_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&filters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path, &depth, &filters_param);

	if (!depth) {
		depth = &depth_sub;
		ZEPHIR_INIT_VAR(depth);
		ZVAL_LONG(depth, 512);
	}
	if (!filters_param) {
		ZEPHIR_INIT_VAR(&filters);
		array_init(&filters);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&filters, filters_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizepath", NULL, 71, path);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdepth", NULL, 72, depth);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfilters", NULL, 73, &filters);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param Filter filter
 * @return void
 */
PHP_METHOD(Zeplara_File_Finder_Finder, addFilter) {

	zval *filter, filter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &filter);



	zephir_update_property_array_append(this_ptr, SL("filters"), filter);

}

/**
 * @return Iterator
 */
PHP_METHOD(Zeplara_File_Finder_Finder, getIterator) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zeplara_file_finder_iterator_ce);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("arrayiterator")));
	zephir_read_property(&_2, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("depth"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "loadpath", NULL, 74, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 75, &_1);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 76, &_0, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string name
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Zeplara_File_Finder_Finder, __call) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _2$$3, _23$$4;
	zval *name, name_sub, *arguments_param = NULL, factory, _1$$3, filter$$4, methodName$$4, _4$$4, _6$$4, _7$$4, _8$$4, _22$$4, _9$$5, _10$$5, _11$$5, _12$$6, _13$$7, _14$$7, _15$$7, _16$$7, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&factory);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&filter$$4);
	ZVAL_UNDEF(&methodName$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &arguments_param);

	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SS(&_0, "Zeplara\\File\\Finder", "\\FilterFactory");
	ZEPHIR_CPY_WRT(&factory, &_0);
	if ((zephir_method_exists(&factory, name)  == SUCCESS) == 1) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 2, 0);
		zephir_array_fast_append(&_2$$3, &factory);
		zephir_array_fast_append(&_2$$3, name);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_1$$3, &_2$$3, &arguments);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addfilter", NULL, 77, &_1$$3);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&filter$$4, zeplara_support_arr_ce, "last", &_3, 0, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&methodName$$4, zeplara_support_str_ce, "studly", &_5, 0, name);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$4, 0);
		ZVAL_LONG(&_7$$4, 3);
		ZEPHIR_INIT_VAR(&_8$$4);
		zephir_substr(&_8$$4, &methodName$$4, 0 , 3 , 0);
		if (ZEPHIR_IS_STRING(&_8$$4, "Set")) {
			ZVAL_LONG(&_9$$5, 3);
			ZEPHIR_INIT_VAR(&_10$$5);
			zephir_substr(&_10$$5, &methodName$$4, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_VAR(&_11$$5);
			ZEPHIR_CONCAT_SV(&_11$$5, "set", &_10$$5);
			ZEPHIR_CPY_WRT(&methodName$$4, &_11$$5);
		} else {
			ZEPHIR_INIT_VAR(&_12$$6);
			ZEPHIR_CONCAT_SV(&_12$$6, "set", &methodName$$4);
			ZEPHIR_CPY_WRT(&methodName$$4, &_12$$6);
		}
		if (Z_TYPE_P(&filter$$4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$7);
			object_init_ex(&_13$$7, spl_ce_BadMethodCallException);
			ZEPHIR_INIT_VAR(&_15$$7);
			ZVAL_STRING(&_15$$7, "Method %s::%s does not exists.");
			ZEPHIR_CALL_FUNCTION(&_16$$7, "sprintf", NULL, 2, &_15$$7, &factory, name);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_13$$7, "__construct", NULL, 7, &_16$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_13$$7, "zeplara/File/Finder/Finder.zep", 102);
			ZEPHIR_MM_RESTORE();
			return;
		} else if ((zephir_method_exists(&filter$$4, &methodName$$4)  == SUCCESS) == 0) {
			ZEPHIR_INIT_VAR(&_17$$8);
			object_init_ex(&_17$$8, spl_ce_BadMethodCallException);
			ZEPHIR_INIT_VAR(&_19$$8);
			zephir_get_class(&_19$$8, &filter$$4, 0);
			ZEPHIR_INIT_VAR(&_20$$8);
			ZVAL_STRING(&_20$$8, "Method %s::%s does not exists.");
			ZEPHIR_CALL_FUNCTION(&_21$$8, "sprintf", NULL, 2, &_20$$8, &_19$$8, &methodName$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_17$$8, "__construct", NULL, 7, &_21$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_17$$8, "zeplara/File/Finder/Finder.zep", 104);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_22$$4);
		ZEPHIR_INIT_VAR(&_23$$4);
		zephir_create_array(&_23$$4, 2, 0);
		zephir_array_fast_append(&_23$$4, &filter$$4);
		zephir_array_fast_append(&_23$$4, &methodName$$4);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_22$$4, &_23$$4, &arguments);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * @param string path
 * @param int depth
 * @param array filters
 * @return static
 */
PHP_METHOD(Zeplara_File_Finder_Finder, instance) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filters;
	zval *path, path_sub, *depth = NULL, depth_sub, *filters_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&depth_sub);
	ZVAL_UNDEF(&filters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path, &depth, &filters_param);

	if (!depth) {
		depth = &depth_sub;
		ZEPHIR_INIT_VAR(depth);
		ZVAL_LONG(depth, 512);
	}
	if (!filters_param) {
		ZEPHIR_INIT_VAR(&filters);
		array_init(&filters);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&filters, filters_param);
	}


	object_init_ex(return_value, zeplara_file_finder_finder_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 78, path, depth, &filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string path
 * @param int depth
 * @param array filters
 * @return static
 */
PHP_METHOD(Zeplara_File_Finder_Finder, create) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filters;
	zval *path, path_sub, *depth = NULL, depth_sub, *filters_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&depth_sub);
	ZVAL_UNDEF(&filters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path, &depth, &filters_param);

	if (!depth) {
		depth = &depth_sub;
		ZEPHIR_INIT_VAR(depth);
		ZVAL_LONG(depth, 512);
	}
	if (!filters_param) {
		ZEPHIR_INIT_VAR(&filters);
		array_init(&filters);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&filters, filters_param);
	}


	ZEPHIR_RETURN_CALL_SELF("instance", NULL, 0, path, depth, &filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string path
 * @param int depth
 * @param array filters
 * @return static
 */
PHP_METHOD(Zeplara_File_Finder_Finder, make) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filters;
	zval *path, path_sub, *depth = NULL, depth_sub, *filters_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&depth_sub);
	ZVAL_UNDEF(&filters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path, &depth, &filters_param);

	if (!depth) {
		depth = &depth_sub;
		ZEPHIR_INIT_VAR(depth);
		ZVAL_LONG(depth, 512);
	}
	if (!filters_param) {
		ZEPHIR_INIT_VAR(&filters);
		array_init(&filters);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&filters, filters_param);
	}


	ZEPHIR_RETURN_CALL_SELF("instance", NULL, 0, path, depth, &filters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string path
 * @param int depth
 * @return array
 * @throws \Exception
 */
PHP_METHOD(Zeplara_File_Finder_Finder, loadPath) {

	zend_bool _4$$4, _13$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL, *_17 = NULL;
	zend_long depth, ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, *depth_param = NULL, handle, entry, entries, separator, _0, _1, _2, _5$$4, _6$$4, _7$$4, _9$$4, _11$$4, _14$$7, _15$$7, _16$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&entry);
	ZVAL_UNDEF(&entries);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path, &depth_param);

	if (UNEXPECTED(Z_TYPE_P(depth_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'depth' must be of the type int"));
		RETURN_MM_NULL();
	}
	depth = Z_LVAL_P(depth_param);


	ZEPHIR_INIT_VAR(&separator);
	ZVAL_STRING(&separator, "/");
	ZVAL_LONG(&_0, -1);
	ZEPHIR_INIT_VAR(&_1);
	zephir_substr(&_1, path, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	if (ZEPHIR_IS_STRING(&_1, "/")) {
		ZEPHIR_INIT_NVAR(&separator);
		ZVAL_STRING(&separator, "/");
	}
	ZEPHIR_CALL_FUNCTION(NULL, "error_clear_last", NULL, 48);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_closure_ex(&_2, NULL, zeplara_0__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 49, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&entries);
	array_init(&entries);
	ZEPHIR_CALL_FUNCTION(&handle, "opendir", NULL, 79, path);
	zephir_check_call_status();
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&entry, "readdir", &_3, 80, &handle);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&entry)) {
			break;
		}
		_4$$4 = ZEPHIR_IS_STRING(&entry, ".");
		if (!(_4$$4)) {
			_4$$4 = ZEPHIR_IS_STRING(&entry, "..");
		}
		if (_4$$4) {
			continue;
		}
		ZEPHIR_INIT_NVAR(&_5$$4);
		ZEPHIR_INIT_NVAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "\\/");
		zephir_fast_trim(&_5$$4, path, &_6$$4, ZEPHIR_TRIM_RIGHT);
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZEPHIR_CONCAT_VVV(&_7$$4, &_5$$4, &separator, &entry);
		ZEPHIR_CALL_METHOD(&entry, this_ptr, "normalizepath", &_8, 71, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_9$$4);
		object_init_ex(&_9$$4, zeplara_file_splfileinfo_ce);
		ZEPHIR_CALL_METHOD(NULL, &_9$$4, "__construct", &_10, 81, &entry);
		zephir_check_call_status();
		zephir_array_append(&entries, &_9$$4, PH_SEPARATE, "zeplara/File/Finder/Finder.zep", 184);
		ZEPHIR_CALL_FUNCTION(&_11$$4, "is_dir", &_12, 82, &entry);
		zephir_check_call_status();
		_13$$4 = zephir_is_true(&_11$$4);
		if (_13$$4) {
			_13$$4 = depth > 0;
		}
		if (_13$$4) {
			depth--;
			ZEPHIR_INIT_NVAR(&_14$$7);
			ZVAL_LONG(&_16$$7, depth);
			ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "loadpath", &_17, 74, &entry, &_16$$7);
			zephir_check_call_status();
			zephir_fast_array_merge(&_14$$7, &entries, &_15$$7);
			ZEPHIR_CPY_WRT(&entries, &_14$$7);
		}
	}
	ZEPHIR_CALL_FUNCTION(NULL, "closedir", NULL, 83, &handle);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 55);
	zephir_check_call_status();
	RETURN_CCTOR(&entries);

}

/**
 * @param string path
 * @return string
 */
PHP_METHOD(Zeplara_File_Finder_Finder, normalizePath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *path = NULL, path_sub, _0, _1, _2, _3, _4, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);

	ZEPHIR_SEPARATE_PARAM(path);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\/");
	zephir_fast_trim(&_0, path, &_1, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_CPY_WRT(path, &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/^(?:ssh2\\.)?s?ftp\\:\\/\\//");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/^(?:ssh2\\.)?s?ftp\\:\\/\\//");
	zephir_preg_match(&_3, &_4, path, &_2, 0, 0 , 0 );
	if (zephir_get_boolval(&_3)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_VS(&_5$$3, path, "/");
		ZEPHIR_CPY_WRT(path, &_5$$3);
	}
	RETVAL_ZVAL(path, 1, 0);
	RETURN_MM();

}

