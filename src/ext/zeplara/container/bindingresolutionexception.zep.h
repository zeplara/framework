
extern zend_class_entry *zeplara_container_bindingresolutionexception_ce;

ZEPHIR_INIT_CLASS(Zeplara_Container_BindingResolutionException);

PHP_METHOD(Zeplara_Container_BindingResolutionException, getReflector);
PHP_METHOD(Zeplara_Container_BindingResolutionException, getParameter);
PHP_METHOD(Zeplara_Container_BindingResolutionException, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zeplara_container_bindingresolutionexception___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, reflector, Reflector, 0)
	ZEND_ARG_OBJ_INFO(0, parameter, ReflectionParameter, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zeplara_container_bindingresolutionexception_method_entry) {
	PHP_ME(Zeplara_Container_BindingResolutionException, getReflector, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_BindingResolutionException, getParameter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Zeplara_Container_BindingResolutionException, __construct, arginfo_zeplara_container_bindingresolutionexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
