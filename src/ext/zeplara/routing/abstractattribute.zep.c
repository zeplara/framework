
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Zeplara_Routing_AbstractAttribute) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Routing, AbstractAttribute, zeplara, routing_abstractattribute, zeplara_routing_abstractattribute_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_routing_abstractattribute_ce, SL("attributes"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(zeplara_routing_abstractattribute_ce, SL("methodsCache"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zeplara_routing_abstractattribute_ce->create_object = zephir_init_properties_Zeplara_Routing_AbstractAttribute;

	zend_class_implements(zeplara_routing_abstractattribute_ce, 1, zeplara_contracts_routing_attribute_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Zeplara_Routing_AbstractAttribute, getAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "attributes");

}

/**
 * @param array attributes
 * @return void
 */
PHP_METHOD(Zeplara_Routing_AbstractAttribute, setAttributes) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, key, value, method, *_0, _1, _4$$3, _6$$3, _7$$3, _11$$6, _12$$6, _13$$6;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	zephir_is_iterable(&attributes, 0, "zeplara/Routing/AbstractAttribute.zep", 39);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (zephir_is_numeric(&key)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The key of attributes should be string type.", "zeplara/Routing/AbstractAttribute.zep", 29);
				return;
			}
			ZEPHIR_CALL_CE_STATIC(&_4$$3, zeplara_support_str_ce, "studly", &_5, 0, &key);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZVAL_STRING(&_6$$3, "init%sAttribute");
			ZEPHIR_CALL_FUNCTION(&_7$$3, "sprintf", &_8, 2, &_6$$3, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&method, &_7$$3);
			ZEPHIR_CALL_METHOD(&_7$$3, this_ptr, "methodexists", &_9, 3, &method);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$3)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwbadmethodcallexception", &_10, 4, &method);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &method, NULL, 0, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_is_numeric(&key)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The key of attributes should be string type.", "zeplara/Routing/AbstractAttribute.zep", 29);
					return;
				}
				ZEPHIR_CALL_CE_STATIC(&_11$$6, zeplara_support_str_ce, "studly", &_5, 0, &key);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$6);
				ZVAL_STRING(&_12$$6, "init%sAttribute");
				ZEPHIR_CALL_FUNCTION(&_13$$6, "sprintf", &_8, 2, &_12$$6, &_11$$6);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&method, &_13$$6);
				ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "methodexists", &_9, 3, &method);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_13$$6)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwbadmethodcallexception", &_10, 4, &method);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &method, NULL, 0, &value);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string name
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Zeplara_Routing_AbstractAttribute, __call) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_5 = NULL;
	zval arguments, _10, _6$$3;
	zval *name, name_sub, *arguments_param = NULL, method, _7, _8, _9, _0$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &arguments_param);

	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&arguments, arguments_param);
	}


	if (ZEPHIR_IS_EMPTY(&arguments)) {
		ZEPHIR_CALL_CE_STATIC(&_0$$3, zeplara_support_str_ce, "studly", &_1, 0, name);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "get%sAttribute");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 2, &_2$$3, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&method, &_3$$3);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "methodexists", &_4, 3, &method);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$3)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwbadmethodcallexception", &_5, 4, &method);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_create_array(&_6$$3, 2, 0);
		zephir_array_fast_append(&_6$$3, this_ptr);
		zephir_array_fast_append(&_6$$3, &method);
		ZEPHIR_CALL_USER_FUNC(return_value, &_6$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_CE_STATIC(&_7, zeplara_support_str_ce, "studly", &_1, 0, name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "set%sAttribute");
	ZEPHIR_CALL_FUNCTION(&_9, "sprintf", NULL, 2, &_8, &_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&method, &_9);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "methodexists", &_4, 3, &method);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_9)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwbadmethodcallexception", &_5, 4, &method);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_8);
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 2, 0);
	zephir_array_fast_append(&_10, this_ptr);
	zephir_array_fast_append(&_10, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_8, &_10, &arguments);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * @param string method
 * @return bool
 */
PHP_METHOD(Zeplara_Routing_AbstractAttribute, methodExists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, __$true, calledClass, _0, _3, _4, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&calledClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method);



	ZEPHIR_INIT_VAR(&calledClass);
	zephir_get_called_class(&calledClass);
	zephir_read_static_property_ce(&_0, zeplara_routing_abstractattribute_ce, SL("methodsCache"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &calledClass))) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "get_class_methods", NULL, 5, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2$$3, "array_fill_keys", NULL, 6, &_1$$3, &__$true);
		zephir_check_call_status();
		zephir_update_static_property_array_multi_ce(zeplara_routing_abstractattribute_ce, SL("methodsCache"), &_2$$3, SL("z"), 1, &calledClass);
	}
	zephir_read_static_property_ce(&_3, zeplara_routing_abstractattribute_ce, SL("methodsCache"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &calledClass, PH_READONLY, "zeplara/Routing/AbstractAttribute.zep", 85);
	RETURN_MM_BOOL(zephir_array_isset(&_4, method));

}

/**
 * @param string method
 */
PHP_METHOD(Zeplara_Routing_AbstractAttribute, throwBadMethodCallException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_called_class(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Method %s::%s does not exists.");
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 2, &_3, &_2, method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 7, &_4);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "zeplara/Routing/AbstractAttribute.zep", 93);
	ZEPHIR_MM_RESTORE();
	return;

}

zend_object *zephir_init_properties_Zeplara_Routing_AbstractAttribute(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

void zephir_init_static_properties_Zeplara_Routing_AbstractAttribute(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(zeplara_routing_abstractattribute_ce, ZEND_STRL("methodsCache"), &_0);
	ZEPHIR_MM_RESTORE();

}

