
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Zeplara_Routing_RouteCompiler) {

	ZEPHIR_REGISTER_CLASS(Zeplara\\Routing, RouteCompiler, zeplara, routing_routecompiler, zeplara_routing_routecompiler_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(zeplara_routing_routecompiler_ce, SL("MAX_VARIABLE_LEN"), 32);

	zend_class_implements(zeplara_routing_routecompiler_ce, 1, zeplara_contracts_routing_routecompiler_ce);
	return SUCCESS;

}

/**
 * @param RouteContract route
 * @return CompiledRoute
 */
PHP_METHOD(Zeplara_Routing_RouteCompiler, compile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *route, route_sub, requirements, _0, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&requirements);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route);



	ZEPHIR_CALL_METHOD(&requirements, route, "requirements", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, zeplara_routing_compiledroute_ce);
	ZEPHIR_CALL_METHOD(&_2, route, "host", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, ".");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "sDui");
	ZEPHIR_CALL_SELF(&_0, "parseregex", &_1, 129, &_2, &_3, &_4, &requirements);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, route, "getpattern", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "/");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "sDu");
	ZEPHIR_CALL_SELF(&_5, "parseregex", &_1, 129, &_6, &_3, &_4, &requirements);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 130, &_0, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string pattern
 * @param string separator
 * @param string flags
 * @param array requirements
 * @return Regex
 * @throws RouteCompilerException
 */
PHP_METHOD(Zeplara_Routing_RouteCompiler, parseRegex) {

	zend_bool _12$$3, _13$$3, _217$$3, _220$$3, _74$$9, _77$$9, _80$$9, _81$$9, _85$$9, _88$$9, _89$$9, _90$$9, _91$$9, _94$$9, _97$$9, _98$$9, _101$$9, _104$$9, _105$$9, _109$$9, _111$$9, _127$$11, _128$$11, _132$$11, _136$$11, _140$$11, _143$$11, _145$$11, _148$$11, _151$$11, _154$$11, _157$$11, _159$$11, _202$$17, _204$$17, _205$$17, _235$$23, _236$$23, _433$$23, _436$$23, _295$$29, _298$$29, _301$$29, _302$$29, _306$$29, _309$$29, _310$$29, _311$$29, _312$$29, _315$$29, _318$$29, _319$$29, _322$$29, _325$$29, _326$$29, _330$$29, _331$$29, _347$$31, _348$$31, _352$$31, _356$$31, _360$$31, _363$$31, _365$$31, _368$$31, _370$$31, _373$$31, _376$$31, _378$$31, _418$$37, _420$$37, _421$$37;
	zend_string *_9;
	zend_ulong _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_29 = NULL, *_30 = NULL, *_110 = NULL, *_150 = NULL, *_187 = NULL, *_195 = NULL, *_197 = NULL;
	zval *pattern, pattern_sub, *separator = NULL, separator_sub, *flags, flags_sub, *requirements = NULL, requirements_sub, i, match, requirement, regex, regexp, matches, variables, prevIdx, nextIdx, lastIdx, separatorRegex, nextSeparatorOfRequirement, _0, _2, _3, _4, _5, *_6, _7, _449, _450, _451, _10$$3, _11$$3, _14$$3, _15$$3, _16$$3, _31$$3, _32$$3, _40$$3, _41$$3, _42$$3, _43$$3, _44$$3, _45$$3, _52$$3, _53$$3, _60$$3, _61$$3, _62$$3, _63$$3, _67$$3, _68$$3, _123$$3, _124$$3, _179$$3, _180$$3, _184$$3, _185$$3, _208$$3, _209$$3, _210$$3, _211$$3, _212$$3, _213$$3, _214$$3, _215$$3, _216$$3, _218$$3, _219$$3, _221$$3, _222$$3, _226$$3, _227$$3, _228$$3, _229$$3, _230$$3, _231$$3, _232$$3, _17$$4, _18$$4, _19$$4, _20$$4, _21$$4, _22$$4, _23$$4, _24$$4, _25$$4, _26$$4, _27$$4, _28$$4, _33$$5, _34$$5, _35$$5, _36$$5, _37$$5, _38$$5, _39$$5, _46$$6, _47$$6, _48$$6, _49$$6, _50$$6, _51$$6, _54$$7, _55$$7, _56$$7, _57$$7, _58$$7, _59$$7, _64$$8, _65$$8, _66$$8, _69$$9, _70$$9, _71$$9, _72$$9, _73$$9, _75$$9, _76$$9, _78$$9, _79$$9, _82$$9, _83$$9, _84$$9, _86$$9, _87$$9, _92$$9, _93$$9, _95$$9, _96$$9, _99$$9, _100$$9, _102$$9, _103$$9, _106$$9, _107$$9, _108$$9, _112$$9, _113$$9, _114$$10, _115$$10, _116$$10, _117$$10, _118$$10, _119$$10, _120$$10, _121$$10, _122$$10, _125$$11, _126$$11, _129$$11, _130$$11, _131$$11, _133$$11, _134$$11, _135$$11, _137$$11, _138$$11, _139$$11, _141$$11, _142$$11, _144$$11, _146$$11, _147$$11, _149$$11, _152$$11, _153$$11, _155$$11, _156$$11, _158$$11, _160$$11, _161$$11, _162$$12, _163$$12, _164$$12, _165$$12, _166$$12, _167$$13, _168$$13, _169$$13, _170$$13, _171$$13, _172$$13, _173$$13, _174$$13, _175$$13, _176$$14, _177$$14, _178$$14, _181$$15, _182$$15, _183$$15, _186$$16, _188$$17, _189$$17, _190$$17, _191$$17, _198$$17, _199$$17, _200$$17, _201$$17, _203$$17, _206$$17, _207$$17, _192$$18, _193$$19, _194$$19, _196$$19, _223$$21, _224$$21, _225$$21, _233$$23, _234$$23, _237$$23, _238$$23, _239$$23, _252$$23, _253$$23, _261$$23, _262$$23, _263$$23, _264$$23, _265$$23, _266$$23, _273$$23, _274$$23, _281$$23, _282$$23, _283$$23, _284$$23, _288$$23, _289$$23, _343$$23, _344$$23, _398$$23, _399$$23, _403$$23, _404$$23, _424$$23, _425$$23, _426$$23, _427$$23, _428$$23, _429$$23, _430$$23, _431$$23, _432$$23, _434$$23, _435$$23, _437$$23, _438$$23, _442$$23, _443$$23, _444$$23, _445$$23, _446$$23, _447$$23, _448$$23, _240$$24, _241$$24, _242$$24, _243$$24, _244$$24, _245$$24, _246$$24, _247$$24, _248$$24, _249$$24, _250$$24, _251$$24, _254$$25, _255$$25, _256$$25, _257$$25, _258$$25, _259$$25, _260$$25, _267$$26, _268$$26, _269$$26, _270$$26, _271$$26, _272$$26, _275$$27, _276$$27, _277$$27, _278$$27, _279$$27, _280$$27, _285$$28, _286$$28, _287$$28, _290$$29, _291$$29, _292$$29, _293$$29, _294$$29, _296$$29, _297$$29, _299$$29, _300$$29, _303$$29, _304$$29, _305$$29, _307$$29, _308$$29, _313$$29, _314$$29, _316$$29, _317$$29, _320$$29, _321$$29, _323$$29, _324$$29, _327$$29, _328$$29, _329$$29, _332$$29, _333$$29, _334$$30, _335$$30, _336$$30, _337$$30, _338$$30, _339$$30, _340$$30, _341$$30, _342$$30, _345$$31, _346$$31, _349$$31, _350$$31, _351$$31, _353$$31, _354$$31, _355$$31, _357$$31, _358$$31, _359$$31, _361$$31, _362$$31, _364$$31, _366$$31, _367$$31, _369$$31, _371$$31, _372$$31, _374$$31, _375$$31, _377$$31, _379$$31, _380$$31, _381$$32, _382$$32, _383$$32, _384$$32, _385$$32, _386$$33, _387$$33, _388$$33, _389$$33, _390$$33, _391$$33, _392$$33, _393$$33, _394$$33, _395$$34, _396$$34, _397$$34, _400$$35, _401$$35, _402$$35, _405$$36, _406$$37, _407$$37, _408$$37, _409$$37, _414$$37, _415$$37, _416$$37, _417$$37, _419$$37, _422$$37, _423$$37, _410$$38, _411$$39, _412$$39, _413$$39, _439$$41, _440$$41, _441$$41;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&separator_sub);
	ZVAL_UNDEF(&flags_sub);
	ZVAL_UNDEF(&requirements_sub);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&requirement);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&regexp);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&variables);
	ZVAL_UNDEF(&prevIdx);
	ZVAL_UNDEF(&nextIdx);
	ZVAL_UNDEF(&lastIdx);
	ZVAL_UNDEF(&separatorRegex);
	ZVAL_UNDEF(&nextSeparatorOfRequirement);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_449);
	ZVAL_UNDEF(&_450);
	ZVAL_UNDEF(&_451);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_31$$3);
	ZVAL_UNDEF(&_32$$3);
	ZVAL_UNDEF(&_40$$3);
	ZVAL_UNDEF(&_41$$3);
	ZVAL_UNDEF(&_42$$3);
	ZVAL_UNDEF(&_43$$3);
	ZVAL_UNDEF(&_44$$3);
	ZVAL_UNDEF(&_45$$3);
	ZVAL_UNDEF(&_52$$3);
	ZVAL_UNDEF(&_53$$3);
	ZVAL_UNDEF(&_60$$3);
	ZVAL_UNDEF(&_61$$3);
	ZVAL_UNDEF(&_62$$3);
	ZVAL_UNDEF(&_63$$3);
	ZVAL_UNDEF(&_67$$3);
	ZVAL_UNDEF(&_68$$3);
	ZVAL_UNDEF(&_123$$3);
	ZVAL_UNDEF(&_124$$3);
	ZVAL_UNDEF(&_179$$3);
	ZVAL_UNDEF(&_180$$3);
	ZVAL_UNDEF(&_184$$3);
	ZVAL_UNDEF(&_185$$3);
	ZVAL_UNDEF(&_208$$3);
	ZVAL_UNDEF(&_209$$3);
	ZVAL_UNDEF(&_210$$3);
	ZVAL_UNDEF(&_211$$3);
	ZVAL_UNDEF(&_212$$3);
	ZVAL_UNDEF(&_213$$3);
	ZVAL_UNDEF(&_214$$3);
	ZVAL_UNDEF(&_215$$3);
	ZVAL_UNDEF(&_216$$3);
	ZVAL_UNDEF(&_218$$3);
	ZVAL_UNDEF(&_219$$3);
	ZVAL_UNDEF(&_221$$3);
	ZVAL_UNDEF(&_222$$3);
	ZVAL_UNDEF(&_226$$3);
	ZVAL_UNDEF(&_227$$3);
	ZVAL_UNDEF(&_228$$3);
	ZVAL_UNDEF(&_229$$3);
	ZVAL_UNDEF(&_230$$3);
	ZVAL_UNDEF(&_231$$3);
	ZVAL_UNDEF(&_232$$3);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_27$$4);
	ZVAL_UNDEF(&_28$$4);
	ZVAL_UNDEF(&_33$$5);
	ZVAL_UNDEF(&_34$$5);
	ZVAL_UNDEF(&_35$$5);
	ZVAL_UNDEF(&_36$$5);
	ZVAL_UNDEF(&_37$$5);
	ZVAL_UNDEF(&_38$$5);
	ZVAL_UNDEF(&_39$$5);
	ZVAL_UNDEF(&_46$$6);
	ZVAL_UNDEF(&_47$$6);
	ZVAL_UNDEF(&_48$$6);
	ZVAL_UNDEF(&_49$$6);
	ZVAL_UNDEF(&_50$$6);
	ZVAL_UNDEF(&_51$$6);
	ZVAL_UNDEF(&_54$$7);
	ZVAL_UNDEF(&_55$$7);
	ZVAL_UNDEF(&_56$$7);
	ZVAL_UNDEF(&_57$$7);
	ZVAL_UNDEF(&_58$$7);
	ZVAL_UNDEF(&_59$$7);
	ZVAL_UNDEF(&_64$$8);
	ZVAL_UNDEF(&_65$$8);
	ZVAL_UNDEF(&_66$$8);
	ZVAL_UNDEF(&_69$$9);
	ZVAL_UNDEF(&_70$$9);
	ZVAL_UNDEF(&_71$$9);
	ZVAL_UNDEF(&_72$$9);
	ZVAL_UNDEF(&_73$$9);
	ZVAL_UNDEF(&_75$$9);
	ZVAL_UNDEF(&_76$$9);
	ZVAL_UNDEF(&_78$$9);
	ZVAL_UNDEF(&_79$$9);
	ZVAL_UNDEF(&_82$$9);
	ZVAL_UNDEF(&_83$$9);
	ZVAL_UNDEF(&_84$$9);
	ZVAL_UNDEF(&_86$$9);
	ZVAL_UNDEF(&_87$$9);
	ZVAL_UNDEF(&_92$$9);
	ZVAL_UNDEF(&_93$$9);
	ZVAL_UNDEF(&_95$$9);
	ZVAL_UNDEF(&_96$$9);
	ZVAL_UNDEF(&_99$$9);
	ZVAL_UNDEF(&_100$$9);
	ZVAL_UNDEF(&_102$$9);
	ZVAL_UNDEF(&_103$$9);
	ZVAL_UNDEF(&_106$$9);
	ZVAL_UNDEF(&_107$$9);
	ZVAL_UNDEF(&_108$$9);
	ZVAL_UNDEF(&_112$$9);
	ZVAL_UNDEF(&_113$$9);
	ZVAL_UNDEF(&_114$$10);
	ZVAL_UNDEF(&_115$$10);
	ZVAL_UNDEF(&_116$$10);
	ZVAL_UNDEF(&_117$$10);
	ZVAL_UNDEF(&_118$$10);
	ZVAL_UNDEF(&_119$$10);
	ZVAL_UNDEF(&_120$$10);
	ZVAL_UNDEF(&_121$$10);
	ZVAL_UNDEF(&_122$$10);
	ZVAL_UNDEF(&_125$$11);
	ZVAL_UNDEF(&_126$$11);
	ZVAL_UNDEF(&_129$$11);
	ZVAL_UNDEF(&_130$$11);
	ZVAL_UNDEF(&_131$$11);
	ZVAL_UNDEF(&_133$$11);
	ZVAL_UNDEF(&_134$$11);
	ZVAL_UNDEF(&_135$$11);
	ZVAL_UNDEF(&_137$$11);
	ZVAL_UNDEF(&_138$$11);
	ZVAL_UNDEF(&_139$$11);
	ZVAL_UNDEF(&_141$$11);
	ZVAL_UNDEF(&_142$$11);
	ZVAL_UNDEF(&_144$$11);
	ZVAL_UNDEF(&_146$$11);
	ZVAL_UNDEF(&_147$$11);
	ZVAL_UNDEF(&_149$$11);
	ZVAL_UNDEF(&_152$$11);
	ZVAL_UNDEF(&_153$$11);
	ZVAL_UNDEF(&_155$$11);
	ZVAL_UNDEF(&_156$$11);
	ZVAL_UNDEF(&_158$$11);
	ZVAL_UNDEF(&_160$$11);
	ZVAL_UNDEF(&_161$$11);
	ZVAL_UNDEF(&_162$$12);
	ZVAL_UNDEF(&_163$$12);
	ZVAL_UNDEF(&_164$$12);
	ZVAL_UNDEF(&_165$$12);
	ZVAL_UNDEF(&_166$$12);
	ZVAL_UNDEF(&_167$$13);
	ZVAL_UNDEF(&_168$$13);
	ZVAL_UNDEF(&_169$$13);
	ZVAL_UNDEF(&_170$$13);
	ZVAL_UNDEF(&_171$$13);
	ZVAL_UNDEF(&_172$$13);
	ZVAL_UNDEF(&_173$$13);
	ZVAL_UNDEF(&_174$$13);
	ZVAL_UNDEF(&_175$$13);
	ZVAL_UNDEF(&_176$$14);
	ZVAL_UNDEF(&_177$$14);
	ZVAL_UNDEF(&_178$$14);
	ZVAL_UNDEF(&_181$$15);
	ZVAL_UNDEF(&_182$$15);
	ZVAL_UNDEF(&_183$$15);
	ZVAL_UNDEF(&_186$$16);
	ZVAL_UNDEF(&_188$$17);
	ZVAL_UNDEF(&_189$$17);
	ZVAL_UNDEF(&_190$$17);
	ZVAL_UNDEF(&_191$$17);
	ZVAL_UNDEF(&_198$$17);
	ZVAL_UNDEF(&_199$$17);
	ZVAL_UNDEF(&_200$$17);
	ZVAL_UNDEF(&_201$$17);
	ZVAL_UNDEF(&_203$$17);
	ZVAL_UNDEF(&_206$$17);
	ZVAL_UNDEF(&_207$$17);
	ZVAL_UNDEF(&_192$$18);
	ZVAL_UNDEF(&_193$$19);
	ZVAL_UNDEF(&_194$$19);
	ZVAL_UNDEF(&_196$$19);
	ZVAL_UNDEF(&_223$$21);
	ZVAL_UNDEF(&_224$$21);
	ZVAL_UNDEF(&_225$$21);
	ZVAL_UNDEF(&_233$$23);
	ZVAL_UNDEF(&_234$$23);
	ZVAL_UNDEF(&_237$$23);
	ZVAL_UNDEF(&_238$$23);
	ZVAL_UNDEF(&_239$$23);
	ZVAL_UNDEF(&_252$$23);
	ZVAL_UNDEF(&_253$$23);
	ZVAL_UNDEF(&_261$$23);
	ZVAL_UNDEF(&_262$$23);
	ZVAL_UNDEF(&_263$$23);
	ZVAL_UNDEF(&_264$$23);
	ZVAL_UNDEF(&_265$$23);
	ZVAL_UNDEF(&_266$$23);
	ZVAL_UNDEF(&_273$$23);
	ZVAL_UNDEF(&_274$$23);
	ZVAL_UNDEF(&_281$$23);
	ZVAL_UNDEF(&_282$$23);
	ZVAL_UNDEF(&_283$$23);
	ZVAL_UNDEF(&_284$$23);
	ZVAL_UNDEF(&_288$$23);
	ZVAL_UNDEF(&_289$$23);
	ZVAL_UNDEF(&_343$$23);
	ZVAL_UNDEF(&_344$$23);
	ZVAL_UNDEF(&_398$$23);
	ZVAL_UNDEF(&_399$$23);
	ZVAL_UNDEF(&_403$$23);
	ZVAL_UNDEF(&_404$$23);
	ZVAL_UNDEF(&_424$$23);
	ZVAL_UNDEF(&_425$$23);
	ZVAL_UNDEF(&_426$$23);
	ZVAL_UNDEF(&_427$$23);
	ZVAL_UNDEF(&_428$$23);
	ZVAL_UNDEF(&_429$$23);
	ZVAL_UNDEF(&_430$$23);
	ZVAL_UNDEF(&_431$$23);
	ZVAL_UNDEF(&_432$$23);
	ZVAL_UNDEF(&_434$$23);
	ZVAL_UNDEF(&_435$$23);
	ZVAL_UNDEF(&_437$$23);
	ZVAL_UNDEF(&_438$$23);
	ZVAL_UNDEF(&_442$$23);
	ZVAL_UNDEF(&_443$$23);
	ZVAL_UNDEF(&_444$$23);
	ZVAL_UNDEF(&_445$$23);
	ZVAL_UNDEF(&_446$$23);
	ZVAL_UNDEF(&_447$$23);
	ZVAL_UNDEF(&_448$$23);
	ZVAL_UNDEF(&_240$$24);
	ZVAL_UNDEF(&_241$$24);
	ZVAL_UNDEF(&_242$$24);
	ZVAL_UNDEF(&_243$$24);
	ZVAL_UNDEF(&_244$$24);
	ZVAL_UNDEF(&_245$$24);
	ZVAL_UNDEF(&_246$$24);
	ZVAL_UNDEF(&_247$$24);
	ZVAL_UNDEF(&_248$$24);
	ZVAL_UNDEF(&_249$$24);
	ZVAL_UNDEF(&_250$$24);
	ZVAL_UNDEF(&_251$$24);
	ZVAL_UNDEF(&_254$$25);
	ZVAL_UNDEF(&_255$$25);
	ZVAL_UNDEF(&_256$$25);
	ZVAL_UNDEF(&_257$$25);
	ZVAL_UNDEF(&_258$$25);
	ZVAL_UNDEF(&_259$$25);
	ZVAL_UNDEF(&_260$$25);
	ZVAL_UNDEF(&_267$$26);
	ZVAL_UNDEF(&_268$$26);
	ZVAL_UNDEF(&_269$$26);
	ZVAL_UNDEF(&_270$$26);
	ZVAL_UNDEF(&_271$$26);
	ZVAL_UNDEF(&_272$$26);
	ZVAL_UNDEF(&_275$$27);
	ZVAL_UNDEF(&_276$$27);
	ZVAL_UNDEF(&_277$$27);
	ZVAL_UNDEF(&_278$$27);
	ZVAL_UNDEF(&_279$$27);
	ZVAL_UNDEF(&_280$$27);
	ZVAL_UNDEF(&_285$$28);
	ZVAL_UNDEF(&_286$$28);
	ZVAL_UNDEF(&_287$$28);
	ZVAL_UNDEF(&_290$$29);
	ZVAL_UNDEF(&_291$$29);
	ZVAL_UNDEF(&_292$$29);
	ZVAL_UNDEF(&_293$$29);
	ZVAL_UNDEF(&_294$$29);
	ZVAL_UNDEF(&_296$$29);
	ZVAL_UNDEF(&_297$$29);
	ZVAL_UNDEF(&_299$$29);
	ZVAL_UNDEF(&_300$$29);
	ZVAL_UNDEF(&_303$$29);
	ZVAL_UNDEF(&_304$$29);
	ZVAL_UNDEF(&_305$$29);
	ZVAL_UNDEF(&_307$$29);
	ZVAL_UNDEF(&_308$$29);
	ZVAL_UNDEF(&_313$$29);
	ZVAL_UNDEF(&_314$$29);
	ZVAL_UNDEF(&_316$$29);
	ZVAL_UNDEF(&_317$$29);
	ZVAL_UNDEF(&_320$$29);
	ZVAL_UNDEF(&_321$$29);
	ZVAL_UNDEF(&_323$$29);
	ZVAL_UNDEF(&_324$$29);
	ZVAL_UNDEF(&_327$$29);
	ZVAL_UNDEF(&_328$$29);
	ZVAL_UNDEF(&_329$$29);
	ZVAL_UNDEF(&_332$$29);
	ZVAL_UNDEF(&_333$$29);
	ZVAL_UNDEF(&_334$$30);
	ZVAL_UNDEF(&_335$$30);
	ZVAL_UNDEF(&_336$$30);
	ZVAL_UNDEF(&_337$$30);
	ZVAL_UNDEF(&_338$$30);
	ZVAL_UNDEF(&_339$$30);
	ZVAL_UNDEF(&_340$$30);
	ZVAL_UNDEF(&_341$$30);
	ZVAL_UNDEF(&_342$$30);
	ZVAL_UNDEF(&_345$$31);
	ZVAL_UNDEF(&_346$$31);
	ZVAL_UNDEF(&_349$$31);
	ZVAL_UNDEF(&_350$$31);
	ZVAL_UNDEF(&_351$$31);
	ZVAL_UNDEF(&_353$$31);
	ZVAL_UNDEF(&_354$$31);
	ZVAL_UNDEF(&_355$$31);
	ZVAL_UNDEF(&_357$$31);
	ZVAL_UNDEF(&_358$$31);
	ZVAL_UNDEF(&_359$$31);
	ZVAL_UNDEF(&_361$$31);
	ZVAL_UNDEF(&_362$$31);
	ZVAL_UNDEF(&_364$$31);
	ZVAL_UNDEF(&_366$$31);
	ZVAL_UNDEF(&_367$$31);
	ZVAL_UNDEF(&_369$$31);
	ZVAL_UNDEF(&_371$$31);
	ZVAL_UNDEF(&_372$$31);
	ZVAL_UNDEF(&_374$$31);
	ZVAL_UNDEF(&_375$$31);
	ZVAL_UNDEF(&_377$$31);
	ZVAL_UNDEF(&_379$$31);
	ZVAL_UNDEF(&_380$$31);
	ZVAL_UNDEF(&_381$$32);
	ZVAL_UNDEF(&_382$$32);
	ZVAL_UNDEF(&_383$$32);
	ZVAL_UNDEF(&_384$$32);
	ZVAL_UNDEF(&_385$$32);
	ZVAL_UNDEF(&_386$$33);
	ZVAL_UNDEF(&_387$$33);
	ZVAL_UNDEF(&_388$$33);
	ZVAL_UNDEF(&_389$$33);
	ZVAL_UNDEF(&_390$$33);
	ZVAL_UNDEF(&_391$$33);
	ZVAL_UNDEF(&_392$$33);
	ZVAL_UNDEF(&_393$$33);
	ZVAL_UNDEF(&_394$$33);
	ZVAL_UNDEF(&_395$$34);
	ZVAL_UNDEF(&_396$$34);
	ZVAL_UNDEF(&_397$$34);
	ZVAL_UNDEF(&_400$$35);
	ZVAL_UNDEF(&_401$$35);
	ZVAL_UNDEF(&_402$$35);
	ZVAL_UNDEF(&_405$$36);
	ZVAL_UNDEF(&_406$$37);
	ZVAL_UNDEF(&_407$$37);
	ZVAL_UNDEF(&_408$$37);
	ZVAL_UNDEF(&_409$$37);
	ZVAL_UNDEF(&_414$$37);
	ZVAL_UNDEF(&_415$$37);
	ZVAL_UNDEF(&_416$$37);
	ZVAL_UNDEF(&_417$$37);
	ZVAL_UNDEF(&_419$$37);
	ZVAL_UNDEF(&_422$$37);
	ZVAL_UNDEF(&_423$$37);
	ZVAL_UNDEF(&_410$$38);
	ZVAL_UNDEF(&_411$$39);
	ZVAL_UNDEF(&_412$$39);
	ZVAL_UNDEF(&_413$$39);
	ZVAL_UNDEF(&_439$$41);
	ZVAL_UNDEF(&_440$$41);
	ZVAL_UNDEF(&_441$$41);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &pattern, &separator, &flags, &requirements);

	ZEPHIR_SEPARATE_PARAM(separator);
	if (!requirements) {
		requirements = &requirements_sub;
		ZEPHIR_INIT_VAR(requirements);
		array_init(requirements);
	}


	ZEPHIR_INIT_VAR(&regex);
	ZVAL_STRING(&regex, "");
	ZEPHIR_CALL_FUNCTION(&_0, "preg_quote", &_1, 131, separator);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(separator, &_0);
	ZEPHIR_INIT_VAR(&variables);
	array_init(&variables);
	ZEPHIR_INIT_VAR(&separatorRegex);
	ZVAL_STRING(&separatorRegex, "/|,|;|\\.|\\:|\\-|_|~|\\+|\\*|\\=|@|\\|");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "#((?>(?:(?!\\{\\w+\\?{0,}\\}).)*(?<!%1$s))*)((?:%1$s)*)\\{(\\w+)((?:\\?)*)\\}((?:%1$s)*)((?:(?:(?!\\{\\w+\\?{0,}\\}).)*(?(?!$)(?<!%1$s)))*)#");
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", NULL, 2, &_2, &separatorRegex);
	zephir_check_call_status();
	ZVAL_LONG(&_4, (256 | 2));
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_5, (256 | 2));
	zephir_preg_match(&_2, &_3, pattern, &matches, 1, zephir_get_intval(&_4) , 0 );
	ZEPHIR_INIT_VAR(&lastIdx);
	ZVAL_LONG(&lastIdx, (zephir_fast_count_int(&matches) - 1));
	zephir_is_iterable(&matches, 1, "zeplara/Routing/RouteCompiler.zep", 132);
	if (Z_TYPE_P(&matches) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&matches), _8, _9, _6)
		{
			ZEPHIR_INIT_NVAR(&i);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&i, _9);
			} else {
				ZVAL_LONG(&i, _8);
			}
			ZEPHIR_INIT_NVAR(&match);
			ZVAL_COPY(&match, _6);
			ZEPHIR_INIT_NVAR(&nextIdx);
			ZVAL_LONG(&nextIdx, (zephir_get_numberval(&i) + 1));
			ZEPHIR_INIT_NVAR(&prevIdx);
			ZVAL_LONG(&prevIdx, (zephir_get_numberval(&i) - 1));
			zephir_array_fetch_long(&_10$$3, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
			zephir_array_fetch_long(&_11$$3, &_10$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
			_12$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_11$$3, "");
			if (_12$$3) {
				_13$$3 = zephir_array_isset(&matches, &nextIdx);
				if (_13$$3) {
					zephir_array_fetch(&_14$$3, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
					zephir_array_fetch_long(&_15$$3, &_14$$3, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
					zephir_array_fetch_long(&_16$$3, &_15$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
					_13$$3 = ZEPHIR_IS_STRING_IDENTICAL(&_16$$3, "");
				}
				_12$$3 = _13$$3;
			}
			if (_12$$3) {
				ZEPHIR_INIT_NVAR(&_17$$4);
				object_init_ex(&_17$$4, zeplara_routing_routecompilerexception_ce);
				zephir_array_fetch_long(&_19$$4, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
				zephir_array_fetch_long(&_20$$4, &_19$$4, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
				zephir_array_fetch_long(&_21$$4, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
				zephir_array_fetch_long(&_22$$4, &_21$$4, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
				ZEPHIR_INIT_NVAR(&_23$$4);
				ZEPHIR_CONCAT_VV(&_23$$4, &_20$$4, &_22$$4);
				zephir_array_fetch(&_24$$4, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
				zephir_array_fetch_long(&_25$$4, &_24$$4, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
				zephir_array_fetch_long(&_26$$4, &_25$$4, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
				ZEPHIR_INIT_NVAR(&_27$$4);
				ZVAL_STRING(&_27$$4, "Cannot set optional pattern \"{%s}\" when the next pattern \"{%s}\" is required.");
				ZEPHIR_CALL_FUNCTION(&_28$$4, "sprintf", &_29, 2, &_27$$4, &_23$$4, &_26$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_17$$4, "__construct", &_30, 65, &_28$$4);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_17$$4, "zeplara/Routing/RouteCompiler.zep", 54);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch_long(&_31$$3, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 57);
			zephir_array_fetch_long(&_32$$3, &_31$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 57);
			if (zephir_fast_strlen_ev(&_32$$3) > 32) {
				ZEPHIR_INIT_NVAR(&_33$$5);
				object_init_ex(&_33$$5, zeplara_routing_routecompilerexception_ce);
				zephir_array_fetch_long(&_35$$5, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 58);
				zephir_array_fetch_long(&_36$$5, &_35$$5, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 58);
				ZEPHIR_INIT_NVAR(&_37$$5);
				ZVAL_STRING(&_37$$5, "Variable \"%s\" is too long. maximum is %d characters.");
				ZVAL_LONG(&_38$$5, 32);
				ZEPHIR_CALL_FUNCTION(&_39$$5, "sprintf", &_29, 2, &_37$$5, &_36$$5, &_38$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_33$$5, "__construct", &_30, 65, &_39$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_33$$5, "zeplara/Routing/RouteCompiler.zep", 58);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_40$$3);
			zephir_array_fetch_long(&_41$$3, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 61);
			zephir_array_fetch_long(&_42$$3, &_41$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 61);
			ZEPHIR_INIT_NVAR(&_43$$3);
			ZVAL_STRING(&_43$$3, "/^\\d/");
			ZEPHIR_INIT_NVAR(&_44$$3);
			ZEPHIR_INIT_NVAR(&_45$$3);
			ZVAL_STRING(&_45$$3, "/^\\d/");
			zephir_preg_match(&_44$$3, &_45$$3, &_42$$3, &_40$$3, 0, 0 , 0 );
			if (zephir_get_boolval(&_44$$3) == 1) {
				ZEPHIR_INIT_NVAR(&_46$$6);
				object_init_ex(&_46$$6, zeplara_routing_routecompilerexception_ce);
				zephir_array_fetch_long(&_48$$6, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 62);
				zephir_array_fetch_long(&_49$$6, &_48$$6, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 62);
				ZEPHIR_INIT_NVAR(&_50$$6);
				ZVAL_STRING(&_50$$6, "Variable \"%s\" cannot start with digit.");
				ZEPHIR_CALL_FUNCTION(&_51$$6, "sprintf", &_29, 2, &_50$$6, &_49$$6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_46$$6, "__construct", &_30, 65, &_51$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_46$$6, "zeplara/Routing/RouteCompiler.zep", 62);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch_long(&_52$$3, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 65);
			zephir_array_fetch_long(&_53$$3, &_52$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 65);
			if (zephir_fast_in_array(&_53$$3, &variables) == 1) {
				ZEPHIR_INIT_NVAR(&_54$$7);
				object_init_ex(&_54$$7, zeplara_routing_routecompilerexception_ce);
				zephir_array_fetch_long(&_56$$7, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 66);
				zephir_array_fetch_long(&_57$$7, &_56$$7, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 66);
				ZEPHIR_INIT_NVAR(&_58$$7);
				ZVAL_STRING(&_58$$7, "Variable \"%s\" must be unique.");
				ZEPHIR_CALL_FUNCTION(&_59$$7, "sprintf", &_29, 2, &_58$$7, &_57$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_54$$7, "__construct", &_30, 65, &_59$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_54$$7, "zeplara/Routing/RouteCompiler.zep", 66);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch_long(&_60$$3, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 69);
			zephir_array_fetch_long(&_61$$3, &_60$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 69);
			zephir_array_append(&variables, &_61$$3, PH_SEPARATE, "zeplara/Routing/RouteCompiler.zep", 69);
			zephir_array_fetch_long(&_62$$3, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 71);
			zephir_array_fetch_long(&_63$$3, &_62$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 71);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_63$$3, "")) {
				zephir_array_fetch_long(&_64$$8, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 72);
				zephir_array_fetch_long(&_65$$8, &_64$$8, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 72);
				ZEPHIR_CALL_FUNCTION(&_66$$8, "preg_quote", &_1, 131, &_65$$8);
				zephir_check_call_status();
				zephir_array_update_multi(&match, &_66$$8, SL("ll"), 2, 1, 0);
			}
			zephir_array_fetch_long(&_67$$3, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 75);
			zephir_array_fetch_long(&_68$$3, &_67$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 75);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_68$$3, "")) {
				zephir_array_fetch_long(&_69$$9, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 76);
				zephir_array_fetch_long(&_70$$9, &_69$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 76);
				ZEPHIR_CALL_FUNCTION(&_71$$9, "preg_quote", &_1, 131, &_70$$9);
				zephir_check_call_status();
				zephir_array_update_multi(&match, &_71$$9, SL("ll"), 2, 2, 0);
				zephir_array_fetch_long(&_72$$9, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
				zephir_array_fetch_long(&_73$$9, &_72$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
				_74$$9 = !ZEPHIR_IS_STRING_IDENTICAL(&_73$$9, "");
				if (_74$$9) {
					zephir_array_fetch_long(&_75$$9, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
					zephir_array_fetch_long(&_76$$9, &_75$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
					_77$$9 = !ZEPHIR_IS_STRING_IDENTICAL(&_76$$9, "");
					if (_77$$9) {
						zephir_array_fetch_long(&_78$$9, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						zephir_array_fetch_long(&_79$$9, &_78$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						_77$$9 = !ZEPHIR_IS_STRING_IDENTICAL(&_79$$9, "");
					}
					_80$$9 = _77$$9;
					if (!(_80$$9)) {
						_81$$9 = zephir_array_isset(&matches, &prevIdx);
						if (_81$$9) {
							zephir_array_fetch(&_82$$9, &matches, &prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_83$$9, &_82$$9, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_84$$9, &_83$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							_81$$9 = !ZEPHIR_IS_STRING_IDENTICAL(&_84$$9, "");
						}
						_85$$9 = _81$$9;
						if (_85$$9) {
							zephir_array_fetch_long(&_86$$9, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_87$$9, &_86$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							_88$$9 = !ZEPHIR_IS_STRING_IDENTICAL(&_87$$9, "");
							if (!(_88$$9)) {
								_88$$9 = !ZEPHIR_IS_IDENTICAL(&i, &lastIdx);
							}
							_85$$9 = _88$$9;
						}
						_80$$9 = _85$$9;
					}
					_89$$9 = _80$$9;
					if (!(_89$$9)) {
						_90$$9 = ZEPHIR_IS_LONG_IDENTICAL(&i, 0);
						if (_90$$9) {
							_90$$9 = ZEPHIR_IS_IDENTICAL(&i, &lastIdx);
						}
						_91$$9 = _90$$9;
						if (_91$$9) {
							zephir_array_fetch_long(&_92$$9, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_93$$9, &_92$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							_91$$9 = !ZEPHIR_IS_STRING_IDENTICAL(&_93$$9, "");
						}
						_94$$9 = _91$$9;
						if (_94$$9) {
							zephir_array_fetch_long(&_95$$9, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_96$$9, &_95$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							_94$$9 = !ZEPHIR_IS_STRING_IDENTICAL(&_96$$9, "");
						}
						_89$$9 = _94$$9;
					}
					_74$$9 = _89$$9;
				}
				_97$$9 = _74$$9;
				if (!(_97$$9)) {
					_98$$9 = ZEPHIR_IS_LONG_IDENTICAL(&i, 0);
					if (_98$$9) {
						zephir_array_fetch_long(&_99$$9, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						zephir_array_fetch_long(&_100$$9, &_99$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						_98$$9 = ZEPHIR_IS_STRING_IDENTICAL(&_100$$9, "");
					}
					_97$$9 = _98$$9;
				}
				_101$$9 = _97$$9;
				if (!(_101$$9)) {
					zephir_array_fetch_long(&_102$$9, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
					zephir_array_fetch_long(&_103$$9, &_102$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
					_104$$9 = !ZEPHIR_IS_STRING_IDENTICAL(&_103$$9, "");
					if (_104$$9) {
						_104$$9 = zephir_array_isset(&matches, &nextIdx);
					}
					_105$$9 = _104$$9;
					if (_105$$9) {
						zephir_array_fetch(&_106$$9, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						zephir_array_fetch_long(&_107$$9, &_106$$9, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						zephir_array_fetch_long(&_108$$9, &_107$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						_105$$9 = ZEPHIR_IS_STRING_IDENTICAL(&_108$$9, "");
					}
					_109$$9 = _105$$9;
					if (_109$$9) {
						ZEPHIR_CALL_SELF(&_71$$9, "hasnextstaticprefixonnextmatch", &_110, 132, &nextIdx, &lastIdx, &matches);
						zephir_check_call_status();
						_109$$9 = ZEPHIR_IS_TRUE_IDENTICAL(&_71$$9);
					}
					_101$$9 = _109$$9;
				}
				_111$$9 = _101$$9;
				if (!(_111$$9)) {
					zephir_array_fetch_long(&_112$$9, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
					zephir_array_fetch_long(&_113$$9, &_112$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
					_111$$9 = ZEPHIR_IS_STRING_IDENTICAL(&_113$$9, "");
				}
				if (_111$$9) {
					zephir_array_fetch_long(&_114$$10, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
					zephir_array_fetch_long(&_115$$10, &_114$$10, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
					zephir_array_fetch_long(&_116$$10, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
					zephir_array_fetch_long(&_117$$10, &_116$$10, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
					ZEPHIR_INIT_NVAR(&_118$$10);
					ZEPHIR_CONCAT_VV(&_118$$10, &_115$$10, &_117$$10);
					zephir_array_update_multi(&match, &_118$$10, SL("ll"), 2, 1, 0);
					zephir_array_fetch_long(&_119$$10, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 79);
					zephir_array_fetch_long(&_120$$10, &_119$$10, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 79);
					ZEPHIR_CALL_FUNCTION(&_121$$10, "preg_quote", &_1, 131, &_120$$10);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_121$$10, SL("ll"), 2, 2, 2);
					ZEPHIR_INIT_NVAR(&_122$$10);
					ZVAL_STRING(&_122$$10, "");
					zephir_array_update_multi(&match, &_122$$10, SL("ll"), 2, 2, 0);
				}
			}
			zephir_array_fetch_long(&_123$$3, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 84);
			zephir_array_fetch_long(&_124$$3, &_123$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 84);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_124$$3, "")) {
				zephir_array_fetch_long(&_125$$11, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
				zephir_array_fetch_long(&_126$$11, &_125$$11, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
				_127$$11 = ZEPHIR_IS_STRING_IDENTICAL(&_126$$11, "");
				if (_127$$11) {
					_128$$11 = zephir_array_isset(&matches, &nextIdx);
					if (_128$$11) {
						zephir_array_fetch(&_129$$11, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
						zephir_array_fetch_long(&_130$$11, &_129$$11, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
						zephir_array_fetch_long(&_131$$11, &_130$$11, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
						_128$$11 = !ZEPHIR_IS_STRING_IDENTICAL(&_131$$11, "");
					}
					_132$$11 = _128$$11;
					if (_132$$11) {
						zephir_array_fetch(&_133$$11, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
						zephir_array_fetch_long(&_134$$11, &_133$$11, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
						zephir_array_fetch_long(&_135$$11, &_134$$11, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
						_132$$11 = ZEPHIR_IS_STRING_IDENTICAL(&_135$$11, "");
					}
					_136$$11 = _132$$11;
					if (_136$$11) {
						ZEPHIR_CALL_SELF(&_137$$11, "hasnextstaticprefixonnextmatch", &_110, 132, &nextIdx, &lastIdx, &matches);
						zephir_check_call_status();
						_136$$11 = ZEPHIR_IS_FALSE_IDENTICAL(&_137$$11);
					}
					_127$$11 = _136$$11;
				}
				zephir_array_fetch_long(&_138$$11, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
				zephir_array_fetch_long(&_139$$11, &_138$$11, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
				_140$$11 = !ZEPHIR_IS_STRING_IDENTICAL(&_139$$11, "");
				if (_140$$11) {
					zephir_array_fetch_long(&_141$$11, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
					zephir_array_fetch_long(&_142$$11, &_141$$11, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
					_143$$11 = ZEPHIR_IS_STRING_IDENTICAL(&_142$$11, "");
					if (_143$$11) {
						zephir_array_fetch_long(&_144$$11, &match, 2, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
						_143$$11 = !(zephir_array_isset_long(&_144$$11, 2));
					}
					_145$$11 = _143$$11;
					if (_145$$11) {
						zephir_array_fetch_long(&_146$$11, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
						zephir_array_fetch_long(&_147$$11, &_146$$11, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
						_145$$11 = !ZEPHIR_IS_STRING_IDENTICAL(&_147$$11, "");
					}
					_148$$11 = _145$$11;
					if (_148$$11) {
						ZEPHIR_CALL_SELF(&_149$$11, "hasstaticprefixwithoutseparatoronprevmatch", &_150, 133, &prevIdx, &matches);
						zephir_check_call_status();
						_148$$11 = zephir_is_true(&_149$$11);
					}
					_151$$11 = _148$$11;
					if (!(_151$$11)) {
						zephir_array_fetch_long(&_152$$11, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
						zephir_array_fetch_long(&_153$$11, &_152$$11, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
						_154$$11 = !ZEPHIR_IS_STRING_IDENTICAL(&_153$$11, "");
						if (_154$$11) {
							zephir_array_fetch_long(&_155$$11, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							zephir_array_fetch_long(&_156$$11, &_155$$11, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							_154$$11 = ZEPHIR_IS_STRING_IDENTICAL(&_156$$11, "");
						}
						_157$$11 = _154$$11;
						if (_157$$11) {
							zephir_array_fetch_long(&_158$$11, &match, 2, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							_157$$11 = !(zephir_array_isset_long(&_158$$11, 2));
						}
						_159$$11 = _157$$11;
						if (_159$$11) {
							zephir_array_fetch_long(&_160$$11, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							zephir_array_fetch_long(&_161$$11, &_160$$11, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							_159$$11 = !ZEPHIR_IS_STRING_IDENTICAL(&_161$$11, "");
						}
						_151$$11 = _159$$11;
					}
					_140$$11 = _151$$11;
				}
				if (_127$$11) {
					zephir_array_fetch_long(&_162$$12, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 86);
					zephir_array_fetch_long(&_163$$12, &_162$$12, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 86);
					zephir_array_update_multi(&matches, &_163$$12, SL("zll"), 3, &nextIdx, 2, 0);
					zephir_array_fetch_long(&_163$$12, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 87);
					zephir_array_fetch_long(&_164$$12, &_163$$12, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 87);
					ZEPHIR_CALL_FUNCTION(&_165$$12, "preg_quote", &_1, 131, &_164$$12);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_165$$12, SL("ll"), 2, 5, 2);
					ZEPHIR_INIT_NVAR(&_166$$12);
					ZVAL_STRING(&_166$$12, "");
					zephir_array_update_multi(&match, &_166$$12, SL("ll"), 2, 5, 0);
				} else if (_140$$11) {
					zephir_array_fetch_long(&_167$$13, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
					zephir_array_fetch_long(&_168$$13, &_167$$13, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
					zephir_array_fetch_long(&_169$$13, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
					zephir_array_fetch_long(&_170$$13, &_169$$13, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
					ZEPHIR_INIT_NVAR(&_171$$13);
					ZEPHIR_CONCAT_VV(&_171$$13, &_168$$13, &_170$$13);
					zephir_array_update_multi(&match, &_171$$13, SL("ll"), 2, 6, 0);
					zephir_array_fetch_long(&_172$$13, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 91);
					zephir_array_fetch_long(&_173$$13, &_172$$13, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 91);
					ZEPHIR_CALL_FUNCTION(&_174$$13, "preg_quote", &_1, 131, &_173$$13);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_174$$13, SL("ll"), 2, 5, 2);
					ZEPHIR_INIT_NVAR(&_175$$13);
					ZVAL_STRING(&_175$$13, "");
					zephir_array_update_multi(&match, &_175$$13, SL("ll"), 2, 5, 0);
				} else {
					zephir_array_fetch_long(&_176$$14, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 94);
					zephir_array_fetch_long(&_177$$14, &_176$$14, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 94);
					ZEPHIR_CALL_FUNCTION(&_178$$14, "preg_quote", &_1, 131, &_177$$14);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_178$$14, SL("ll"), 2, 5, 0);
				}
			}
			zephir_array_fetch_long(&_179$$3, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 98);
			zephir_array_fetch_long(&_180$$3, &_179$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 98);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_180$$3, "")) {
				zephir_array_fetch_long(&_181$$15, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 99);
				zephir_array_fetch_long(&_182$$15, &_181$$15, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 99);
				ZEPHIR_CALL_FUNCTION(&_183$$15, "preg_quote", &_1, 131, &_182$$15);
				zephir_check_call_status();
				zephir_array_update_multi(&match, &_183$$15, SL("ll"), 2, 6, 0);
			}
			ZEPHIR_OBS_NVAR(&requirement);
			zephir_array_fetch_long(&_184$$3, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 102);
			zephir_array_fetch_long(&_185$$3, &_184$$3, 0, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 102);
			if (zephir_array_isset_fetch(&requirement, requirements, &_185$$3, 0)) {
				ZEPHIR_CALL_SELF(&_186$$16, "resolverequirement", &_187, 134, &requirement);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&requirement, &_186$$16);
			} else {
				zephir_array_fetch_long(&_188$$17, &match, 5, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 105);
				if (zephir_array_isset_long(&_188$$17, 2)) {
					zephir_array_fetch_long(&_189$$17, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 105);
					ZEPHIR_OBS_NVAR(&nextSeparatorOfRequirement);
					zephir_array_fetch_long(&nextSeparatorOfRequirement, &_189$$17, 2, PH_NOISY, "zeplara/Routing/RouteCompiler.zep", 105);
				} else {
					zephir_array_fetch_long(&_190$$17, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 105);
					ZEPHIR_OBS_NVAR(&nextSeparatorOfRequirement);
					zephir_array_fetch_long(&nextSeparatorOfRequirement, &_190$$17, 0, PH_NOISY, "zeplara/Routing/RouteCompiler.zep", 105);
				}
				ZEPHIR_INIT_NVAR(&_191$$17);
				zephir_fast_strpos(&_191$$17, &nextSeparatorOfRequirement, separator, 0 );
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_191$$17)) {
					ZEPHIR_INIT_NVAR(&_192$$18);
					ZEPHIR_CONCAT_VV(&_192$$18, separator, &nextSeparatorOfRequirement);
					ZEPHIR_CPY_WRT(&nextSeparatorOfRequirement, &_192$$18);
				} else {
					ZEPHIR_INIT_NVAR(&_193$$19);
					ZEPHIR_CONCAT_VV(&_193$$19, separator, &nextSeparatorOfRequirement);
					ZEPHIR_CALL_FUNCTION(&_194$$19, "str_split", &_195, 135, &_193$$19);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_196$$19, "array_unique", &_197, 117, &_194$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&nextSeparatorOfRequirement);
					zephir_fast_join_str(&nextSeparatorOfRequirement, SL(""), &_196$$19);
				}
				ZEPHIR_INIT_NVAR(&_198$$17);
				ZVAL_STRING(&_198$$17, "[^%s]+");
				ZEPHIR_CALL_FUNCTION(&_199$$17, "sprintf", &_29, 2, &_198$$17, &nextSeparatorOfRequirement);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&requirement, &_199$$17);
				zephir_array_fetch_long(&_200$$17, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 114);
				zephir_array_fetch_long(&_201$$17, &_200$$17, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 114);
				_202$$17 = !ZEPHIR_IS_STRING_IDENTICAL(&_201$$17, "");
				if (!(_202$$17)) {
					zephir_array_fetch_long(&_203$$17, &match, 5, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 114);
					_202$$17 = zephir_array_isset_long(&_203$$17, 2) == 1;
				}
				_204$$17 = _202$$17;
				if (!(_204$$17)) {
					_205$$17 = ZEPHIR_IS_IDENTICAL(&i, &lastIdx);
					if (_205$$17) {
						zephir_array_fetch_long(&_206$$17, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 114);
						zephir_array_fetch_long(&_207$$17, &_206$$17, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 114);
						_205$$17 = ZEPHIR_IS_STRING_IDENTICAL(&_207$$17, "");
					}
					_204$$17 = _205$$17;
				}
				if (_204$$17) {
					zephir_concat_self_str(&requirement, SL("+"));
				}
			}
			zephir_array_fetch_long(&_208$$3, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
			zephir_array_fetch_long(&_209$$3, &_208$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
			zephir_array_fetch_long(&_210$$3, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
			zephir_array_fetch_long(&_211$$3, &_210$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
			zephir_array_fetch_long(&_212$$3, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
			zephir_array_fetch_long(&_213$$3, &_212$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
			ZEPHIR_INIT_NVAR(&_44$$3);
			ZVAL_STRING(&_44$$3, "%s(?P<%s>%s)%s");
			ZEPHIR_CALL_FUNCTION(&_214$$3, "sprintf", &_29, 2, &_44$$3, &_209$$3, &_211$$3, &requirement, &_213$$3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&regexp, &_214$$3);
			zephir_array_fetch_long(&_215$$3, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
			zephir_array_fetch_long(&_216$$3, &_215$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
			_217$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_216$$3, "");
			if (!(_217$$3)) {
				zephir_array_fetch_long(&_218$$3, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
				zephir_array_fetch_long(&_219$$3, &_218$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
				_220$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_219$$3, "");
				if (_220$$3) {
					zephir_array_fetch_long(&_221$$3, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
					zephir_array_fetch_long(&_222$$3, &_221$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
					_220$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_222$$3, "");
				}
				_217$$3 = _220$$3;
			}
			if (_217$$3) {
				ZEPHIR_INIT_NVAR(&_224$$21);
				ZVAL_STRING(&_224$$21, "(?:%s)");
				ZEPHIR_CALL_FUNCTION(&_225$$21, "sprintf", &_29, 2, &_224$$21, &regexp);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&regexp, &_225$$21);
			}
			zephir_array_fetch_long(&_226$$3, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 125);
			zephir_array_fetch_long(&_227$$3, &_226$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 125);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_227$$3, "")) {
				zephir_concat_self_str(&regexp, SL("?"));
			}
			zephir_array_fetch_long(&_228$$3, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 129);
			zephir_array_fetch_long(&_229$$3, &_228$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 129);
			zephir_array_fetch_long(&_230$$3, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 129);
			zephir_array_fetch_long(&_231$$3, &_230$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 129);
			ZEPHIR_INIT_NVAR(&_232$$3);
			ZEPHIR_CONCAT_VVV(&_232$$3, &_229$$3, &regexp, &_231$$3);
			zephir_concat_self(&regex, &_232$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &matches, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &matches, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&i, &matches, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&match, &matches, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&nextIdx);
				ZVAL_LONG(&nextIdx, (zephir_get_numberval(&i) + 1));
				ZEPHIR_INIT_NVAR(&prevIdx);
				ZVAL_LONG(&prevIdx, (zephir_get_numberval(&i) - 1));
				zephir_array_fetch_long(&_233$$23, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
				zephir_array_fetch_long(&_234$$23, &_233$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
				_235$$23 = !ZEPHIR_IS_STRING_IDENTICAL(&_234$$23, "");
				if (_235$$23) {
					_236$$23 = zephir_array_isset(&matches, &nextIdx);
					if (_236$$23) {
						zephir_array_fetch(&_237$$23, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
						zephir_array_fetch_long(&_238$$23, &_237$$23, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
						zephir_array_fetch_long(&_239$$23, &_238$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
						_236$$23 = ZEPHIR_IS_STRING_IDENTICAL(&_239$$23, "");
					}
					_235$$23 = _236$$23;
				}
				if (_235$$23) {
					ZEPHIR_INIT_NVAR(&_240$$24);
					object_init_ex(&_240$$24, zeplara_routing_routecompilerexception_ce);
					zephir_array_fetch_long(&_242$$24, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					zephir_array_fetch_long(&_243$$24, &_242$$24, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					zephir_array_fetch_long(&_244$$24, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					zephir_array_fetch_long(&_245$$24, &_244$$24, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					ZEPHIR_INIT_NVAR(&_246$$24);
					ZEPHIR_CONCAT_VV(&_246$$24, &_243$$24, &_245$$24);
					zephir_array_fetch(&_247$$24, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					zephir_array_fetch_long(&_248$$24, &_247$$24, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					zephir_array_fetch_long(&_249$$24, &_248$$24, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					ZEPHIR_INIT_NVAR(&_250$$24);
					ZVAL_STRING(&_250$$24, "Cannot set optional pattern \"{%s}\" when the next pattern \"{%s}\" is required.");
					ZEPHIR_CALL_FUNCTION(&_251$$24, "sprintf", &_29, 2, &_250$$24, &_246$$24, &_249$$24);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_240$$24, "__construct", &_30, 65, &_251$$24);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_240$$24, "zeplara/Routing/RouteCompiler.zep", 54);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch_long(&_252$$23, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 57);
				zephir_array_fetch_long(&_253$$23, &_252$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 57);
				if (zephir_fast_strlen_ev(&_253$$23) > 32) {
					ZEPHIR_INIT_NVAR(&_254$$25);
					object_init_ex(&_254$$25, zeplara_routing_routecompilerexception_ce);
					zephir_array_fetch_long(&_256$$25, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 58);
					zephir_array_fetch_long(&_257$$25, &_256$$25, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 58);
					ZEPHIR_INIT_NVAR(&_258$$25);
					ZVAL_STRING(&_258$$25, "Variable \"%s\" is too long. maximum is %d characters.");
					ZVAL_LONG(&_259$$25, 32);
					ZEPHIR_CALL_FUNCTION(&_260$$25, "sprintf", &_29, 2, &_258$$25, &_257$$25, &_259$$25);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_254$$25, "__construct", &_30, 65, &_260$$25);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_254$$25, "zeplara/Routing/RouteCompiler.zep", 58);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_261$$23);
				zephir_array_fetch_long(&_262$$23, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 61);
				zephir_array_fetch_long(&_263$$23, &_262$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 61);
				ZEPHIR_INIT_NVAR(&_264$$23);
				ZVAL_STRING(&_264$$23, "/^\\d/");
				ZEPHIR_INIT_NVAR(&_265$$23);
				ZEPHIR_INIT_NVAR(&_266$$23);
				ZVAL_STRING(&_266$$23, "/^\\d/");
				zephir_preg_match(&_265$$23, &_266$$23, &_263$$23, &_261$$23, 0, 0 , 0 );
				if (zephir_get_boolval(&_265$$23) == 1) {
					ZEPHIR_INIT_NVAR(&_267$$26);
					object_init_ex(&_267$$26, zeplara_routing_routecompilerexception_ce);
					zephir_array_fetch_long(&_269$$26, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 62);
					zephir_array_fetch_long(&_270$$26, &_269$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 62);
					ZEPHIR_INIT_NVAR(&_271$$26);
					ZVAL_STRING(&_271$$26, "Variable \"%s\" cannot start with digit.");
					ZEPHIR_CALL_FUNCTION(&_272$$26, "sprintf", &_29, 2, &_271$$26, &_270$$26);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_267$$26, "__construct", &_30, 65, &_272$$26);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_267$$26, "zeplara/Routing/RouteCompiler.zep", 62);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch_long(&_273$$23, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 65);
				zephir_array_fetch_long(&_274$$23, &_273$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 65);
				if (zephir_fast_in_array(&_274$$23, &variables) == 1) {
					ZEPHIR_INIT_NVAR(&_275$$27);
					object_init_ex(&_275$$27, zeplara_routing_routecompilerexception_ce);
					zephir_array_fetch_long(&_277$$27, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 66);
					zephir_array_fetch_long(&_278$$27, &_277$$27, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 66);
					ZEPHIR_INIT_NVAR(&_279$$27);
					ZVAL_STRING(&_279$$27, "Variable \"%s\" must be unique.");
					ZEPHIR_CALL_FUNCTION(&_280$$27, "sprintf", &_29, 2, &_279$$27, &_278$$27);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_275$$27, "__construct", &_30, 65, &_280$$27);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_275$$27, "zeplara/Routing/RouteCompiler.zep", 66);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch_long(&_281$$23, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 69);
				zephir_array_fetch_long(&_282$$23, &_281$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 69);
				zephir_array_append(&variables, &_282$$23, PH_SEPARATE, "zeplara/Routing/RouteCompiler.zep", 69);
				zephir_array_fetch_long(&_283$$23, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 71);
				zephir_array_fetch_long(&_284$$23, &_283$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 71);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_284$$23, "")) {
					zephir_array_fetch_long(&_285$$28, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 72);
					zephir_array_fetch_long(&_286$$28, &_285$$28, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 72);
					ZEPHIR_CALL_FUNCTION(&_287$$28, "preg_quote", &_1, 131, &_286$$28);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_287$$28, SL("ll"), 2, 1, 0);
				}
				zephir_array_fetch_long(&_288$$23, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 75);
				zephir_array_fetch_long(&_289$$23, &_288$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 75);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_289$$23, "")) {
					zephir_array_fetch_long(&_290$$29, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 76);
					zephir_array_fetch_long(&_291$$29, &_290$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 76);
					ZEPHIR_CALL_FUNCTION(&_292$$29, "preg_quote", &_1, 131, &_291$$29);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_292$$29, SL("ll"), 2, 2, 0);
					zephir_array_fetch_long(&_293$$29, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
					zephir_array_fetch_long(&_294$$29, &_293$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
					_295$$29 = !ZEPHIR_IS_STRING_IDENTICAL(&_294$$29, "");
					if (_295$$29) {
						zephir_array_fetch_long(&_296$$29, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						zephir_array_fetch_long(&_297$$29, &_296$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						_298$$29 = !ZEPHIR_IS_STRING_IDENTICAL(&_297$$29, "");
						if (_298$$29) {
							zephir_array_fetch_long(&_299$$29, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_300$$29, &_299$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							_298$$29 = !ZEPHIR_IS_STRING_IDENTICAL(&_300$$29, "");
						}
						_301$$29 = _298$$29;
						if (!(_301$$29)) {
							_302$$29 = zephir_array_isset(&matches, &prevIdx);
							if (_302$$29) {
								zephir_array_fetch(&_303$$29, &matches, &prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								zephir_array_fetch_long(&_304$$29, &_303$$29, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								zephir_array_fetch_long(&_305$$29, &_304$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								_302$$29 = !ZEPHIR_IS_STRING_IDENTICAL(&_305$$29, "");
							}
							_306$$29 = _302$$29;
							if (_306$$29) {
								zephir_array_fetch_long(&_307$$29, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								zephir_array_fetch_long(&_308$$29, &_307$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								_309$$29 = !ZEPHIR_IS_STRING_IDENTICAL(&_308$$29, "");
								if (!(_309$$29)) {
									_309$$29 = !ZEPHIR_IS_IDENTICAL(&i, &lastIdx);
								}
								_306$$29 = _309$$29;
							}
							_301$$29 = _306$$29;
						}
						_310$$29 = _301$$29;
						if (!(_310$$29)) {
							_311$$29 = ZEPHIR_IS_LONG_IDENTICAL(&i, 0);
							if (_311$$29) {
								_311$$29 = ZEPHIR_IS_IDENTICAL(&i, &lastIdx);
							}
							_312$$29 = _311$$29;
							if (_312$$29) {
								zephir_array_fetch_long(&_313$$29, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								zephir_array_fetch_long(&_314$$29, &_313$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								_312$$29 = !ZEPHIR_IS_STRING_IDENTICAL(&_314$$29, "");
							}
							_315$$29 = _312$$29;
							if (_315$$29) {
								zephir_array_fetch_long(&_316$$29, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								zephir_array_fetch_long(&_317$$29, &_316$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								_315$$29 = !ZEPHIR_IS_STRING_IDENTICAL(&_317$$29, "");
							}
							_310$$29 = _315$$29;
						}
						_295$$29 = _310$$29;
					}
					_318$$29 = _295$$29;
					if (!(_318$$29)) {
						_319$$29 = ZEPHIR_IS_LONG_IDENTICAL(&i, 0);
						if (_319$$29) {
							zephir_array_fetch_long(&_320$$29, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_321$$29, &_320$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							_319$$29 = ZEPHIR_IS_STRING_IDENTICAL(&_321$$29, "");
						}
						_318$$29 = _319$$29;
					}
					_322$$29 = _318$$29;
					if (!(_322$$29)) {
						zephir_array_fetch_long(&_323$$29, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						zephir_array_fetch_long(&_324$$29, &_323$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						_325$$29 = !ZEPHIR_IS_STRING_IDENTICAL(&_324$$29, "");
						if (_325$$29) {
							_325$$29 = zephir_array_isset(&matches, &nextIdx);
						}
						_326$$29 = _325$$29;
						if (_326$$29) {
							zephir_array_fetch(&_327$$29, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_328$$29, &_327$$29, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_329$$29, &_328$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							_326$$29 = ZEPHIR_IS_STRING_IDENTICAL(&_329$$29, "");
						}
						_330$$29 = _326$$29;
						if (_330$$29) {
							ZEPHIR_CALL_SELF(&_292$$29, "hasnextstaticprefixonnextmatch", &_110, 132, &nextIdx, &lastIdx, &matches);
							zephir_check_call_status();
							_330$$29 = ZEPHIR_IS_TRUE_IDENTICAL(&_292$$29);
						}
						_322$$29 = _330$$29;
					}
					_331$$29 = _322$$29;
					if (!(_331$$29)) {
						zephir_array_fetch_long(&_332$$29, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						zephir_array_fetch_long(&_333$$29, &_332$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						_331$$29 = ZEPHIR_IS_STRING_IDENTICAL(&_333$$29, "");
					}
					if (_331$$29) {
						zephir_array_fetch_long(&_334$$30, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
						zephir_array_fetch_long(&_335$$30, &_334$$30, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
						zephir_array_fetch_long(&_336$$30, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
						zephir_array_fetch_long(&_337$$30, &_336$$30, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
						ZEPHIR_INIT_NVAR(&_338$$30);
						ZEPHIR_CONCAT_VV(&_338$$30, &_335$$30, &_337$$30);
						zephir_array_update_multi(&match, &_338$$30, SL("ll"), 2, 1, 0);
						zephir_array_fetch_long(&_339$$30, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 79);
						zephir_array_fetch_long(&_340$$30, &_339$$30, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 79);
						ZEPHIR_CALL_FUNCTION(&_341$$30, "preg_quote", &_1, 131, &_340$$30);
						zephir_check_call_status();
						zephir_array_update_multi(&match, &_341$$30, SL("ll"), 2, 2, 2);
						ZEPHIR_INIT_NVAR(&_342$$30);
						ZVAL_STRING(&_342$$30, "");
						zephir_array_update_multi(&match, &_342$$30, SL("ll"), 2, 2, 0);
					}
				}
				zephir_array_fetch_long(&_343$$23, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 84);
				zephir_array_fetch_long(&_344$$23, &_343$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 84);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_344$$23, "")) {
					zephir_array_fetch_long(&_345$$31, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
					zephir_array_fetch_long(&_346$$31, &_345$$31, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
					_347$$31 = ZEPHIR_IS_STRING_IDENTICAL(&_346$$31, "");
					if (_347$$31) {
						_348$$31 = zephir_array_isset(&matches, &nextIdx);
						if (_348$$31) {
							zephir_array_fetch(&_349$$31, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							zephir_array_fetch_long(&_350$$31, &_349$$31, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							zephir_array_fetch_long(&_351$$31, &_350$$31, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							_348$$31 = !ZEPHIR_IS_STRING_IDENTICAL(&_351$$31, "");
						}
						_352$$31 = _348$$31;
						if (_352$$31) {
							zephir_array_fetch(&_353$$31, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							zephir_array_fetch_long(&_354$$31, &_353$$31, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							zephir_array_fetch_long(&_355$$31, &_354$$31, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							_352$$31 = ZEPHIR_IS_STRING_IDENTICAL(&_355$$31, "");
						}
						_356$$31 = _352$$31;
						if (_356$$31) {
							ZEPHIR_CALL_SELF(&_357$$31, "hasnextstaticprefixonnextmatch", &_110, 132, &nextIdx, &lastIdx, &matches);
							zephir_check_call_status();
							_356$$31 = ZEPHIR_IS_FALSE_IDENTICAL(&_357$$31);
						}
						_347$$31 = _356$$31;
					}
					zephir_array_fetch_long(&_358$$31, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
					zephir_array_fetch_long(&_359$$31, &_358$$31, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
					_360$$31 = !ZEPHIR_IS_STRING_IDENTICAL(&_359$$31, "");
					if (_360$$31) {
						zephir_array_fetch_long(&_361$$31, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
						zephir_array_fetch_long(&_362$$31, &_361$$31, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
						_363$$31 = ZEPHIR_IS_STRING_IDENTICAL(&_362$$31, "");
						if (_363$$31) {
							zephir_array_fetch_long(&_364$$31, &match, 2, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							_363$$31 = !(zephir_array_isset_long(&_364$$31, 2));
						}
						_365$$31 = _363$$31;
						if (_365$$31) {
							zephir_array_fetch_long(&_366$$31, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							zephir_array_fetch_long(&_367$$31, &_366$$31, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							_365$$31 = !ZEPHIR_IS_STRING_IDENTICAL(&_367$$31, "");
						}
						_368$$31 = _365$$31;
						if (_368$$31) {
							ZEPHIR_CALL_SELF(&_369$$31, "hasstaticprefixwithoutseparatoronprevmatch", &_150, 133, &prevIdx, &matches);
							zephir_check_call_status();
							_368$$31 = zephir_is_true(&_369$$31);
						}
						_370$$31 = _368$$31;
						if (!(_370$$31)) {
							zephir_array_fetch_long(&_371$$31, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							zephir_array_fetch_long(&_372$$31, &_371$$31, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							_373$$31 = !ZEPHIR_IS_STRING_IDENTICAL(&_372$$31, "");
							if (_373$$31) {
								zephir_array_fetch_long(&_374$$31, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
								zephir_array_fetch_long(&_375$$31, &_374$$31, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
								_373$$31 = ZEPHIR_IS_STRING_IDENTICAL(&_375$$31, "");
							}
							_376$$31 = _373$$31;
							if (_376$$31) {
								zephir_array_fetch_long(&_377$$31, &match, 2, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
								_376$$31 = !(zephir_array_isset_long(&_377$$31, 2));
							}
							_378$$31 = _376$$31;
							if (_378$$31) {
								zephir_array_fetch_long(&_379$$31, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
								zephir_array_fetch_long(&_380$$31, &_379$$31, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
								_378$$31 = !ZEPHIR_IS_STRING_IDENTICAL(&_380$$31, "");
							}
							_370$$31 = _378$$31;
						}
						_360$$31 = _370$$31;
					}
					if (_347$$31) {
						zephir_array_fetch_long(&_381$$32, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 86);
						zephir_array_fetch_long(&_382$$32, &_381$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 86);
						zephir_array_update_multi(&matches, &_382$$32, SL("zll"), 3, &nextIdx, 2, 0);
						zephir_array_fetch_long(&_382$$32, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 87);
						zephir_array_fetch_long(&_383$$32, &_382$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 87);
						ZEPHIR_CALL_FUNCTION(&_384$$32, "preg_quote", &_1, 131, &_383$$32);
						zephir_check_call_status();
						zephir_array_update_multi(&match, &_384$$32, SL("ll"), 2, 5, 2);
						ZEPHIR_INIT_NVAR(&_385$$32);
						ZVAL_STRING(&_385$$32, "");
						zephir_array_update_multi(&match, &_385$$32, SL("ll"), 2, 5, 0);
					} else if (_360$$31) {
						zephir_array_fetch_long(&_386$$33, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
						zephir_array_fetch_long(&_387$$33, &_386$$33, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
						zephir_array_fetch_long(&_388$$33, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
						zephir_array_fetch_long(&_389$$33, &_388$$33, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
						ZEPHIR_INIT_NVAR(&_390$$33);
						ZEPHIR_CONCAT_VV(&_390$$33, &_387$$33, &_389$$33);
						zephir_array_update_multi(&match, &_390$$33, SL("ll"), 2, 6, 0);
						zephir_array_fetch_long(&_391$$33, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 91);
						zephir_array_fetch_long(&_392$$33, &_391$$33, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 91);
						ZEPHIR_CALL_FUNCTION(&_393$$33, "preg_quote", &_1, 131, &_392$$33);
						zephir_check_call_status();
						zephir_array_update_multi(&match, &_393$$33, SL("ll"), 2, 5, 2);
						ZEPHIR_INIT_NVAR(&_394$$33);
						ZVAL_STRING(&_394$$33, "");
						zephir_array_update_multi(&match, &_394$$33, SL("ll"), 2, 5, 0);
					} else {
						zephir_array_fetch_long(&_395$$34, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 94);
						zephir_array_fetch_long(&_396$$34, &_395$$34, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 94);
						ZEPHIR_CALL_FUNCTION(&_397$$34, "preg_quote", &_1, 131, &_396$$34);
						zephir_check_call_status();
						zephir_array_update_multi(&match, &_397$$34, SL("ll"), 2, 5, 0);
					}
				}
				zephir_array_fetch_long(&_398$$23, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 98);
				zephir_array_fetch_long(&_399$$23, &_398$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 98);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_399$$23, "")) {
					zephir_array_fetch_long(&_400$$35, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 99);
					zephir_array_fetch_long(&_401$$35, &_400$$35, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 99);
					ZEPHIR_CALL_FUNCTION(&_402$$35, "preg_quote", &_1, 131, &_401$$35);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_402$$35, SL("ll"), 2, 6, 0);
				}
				ZEPHIR_OBS_NVAR(&requirement);
				zephir_array_fetch_long(&_403$$23, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 102);
				zephir_array_fetch_long(&_404$$23, &_403$$23, 0, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 102);
				if (zephir_array_isset_fetch(&requirement, requirements, &_404$$23, 0)) {
					ZEPHIR_CALL_SELF(&_405$$36, "resolverequirement", &_187, 134, &requirement);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&requirement, &_405$$36);
				} else {
					zephir_array_fetch_long(&_406$$37, &match, 5, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 105);
					if (zephir_array_isset_long(&_406$$37, 2)) {
						zephir_array_fetch_long(&_407$$37, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 105);
						ZEPHIR_OBS_NVAR(&nextSeparatorOfRequirement);
						zephir_array_fetch_long(&nextSeparatorOfRequirement, &_407$$37, 2, PH_NOISY, "zeplara/Routing/RouteCompiler.zep", 105);
					} else {
						zephir_array_fetch_long(&_408$$37, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 105);
						ZEPHIR_OBS_NVAR(&nextSeparatorOfRequirement);
						zephir_array_fetch_long(&nextSeparatorOfRequirement, &_408$$37, 0, PH_NOISY, "zeplara/Routing/RouteCompiler.zep", 105);
					}
					ZEPHIR_INIT_NVAR(&_409$$37);
					zephir_fast_strpos(&_409$$37, &nextSeparatorOfRequirement, separator, 0 );
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_409$$37)) {
						ZEPHIR_INIT_NVAR(&_410$$38);
						ZEPHIR_CONCAT_VV(&_410$$38, separator, &nextSeparatorOfRequirement);
						ZEPHIR_CPY_WRT(&nextSeparatorOfRequirement, &_410$$38);
					} else {
						ZEPHIR_INIT_NVAR(&_411$$39);
						ZEPHIR_CONCAT_VV(&_411$$39, separator, &nextSeparatorOfRequirement);
						ZEPHIR_CALL_FUNCTION(&_412$$39, "str_split", &_195, 135, &_411$$39);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_413$$39, "array_unique", &_197, 117, &_412$$39);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&nextSeparatorOfRequirement);
						zephir_fast_join_str(&nextSeparatorOfRequirement, SL(""), &_413$$39);
					}
					ZEPHIR_INIT_NVAR(&_414$$37);
					ZVAL_STRING(&_414$$37, "[^%s]+");
					ZEPHIR_CALL_FUNCTION(&_415$$37, "sprintf", &_29, 2, &_414$$37, &nextSeparatorOfRequirement);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&requirement, &_415$$37);
					zephir_array_fetch_long(&_416$$37, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 114);
					zephir_array_fetch_long(&_417$$37, &_416$$37, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 114);
					_418$$37 = !ZEPHIR_IS_STRING_IDENTICAL(&_417$$37, "");
					if (!(_418$$37)) {
						zephir_array_fetch_long(&_419$$37, &match, 5, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 114);
						_418$$37 = zephir_array_isset_long(&_419$$37, 2) == 1;
					}
					_420$$37 = _418$$37;
					if (!(_420$$37)) {
						_421$$37 = ZEPHIR_IS_IDENTICAL(&i, &lastIdx);
						if (_421$$37) {
							zephir_array_fetch_long(&_422$$37, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 114);
							zephir_array_fetch_long(&_423$$37, &_422$$37, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 114);
							_421$$37 = ZEPHIR_IS_STRING_IDENTICAL(&_423$$37, "");
						}
						_420$$37 = _421$$37;
					}
					if (_420$$37) {
						zephir_concat_self_str(&requirement, SL("+"));
					}
				}
				zephir_array_fetch_long(&_424$$23, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
				zephir_array_fetch_long(&_425$$23, &_424$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
				zephir_array_fetch_long(&_426$$23, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
				zephir_array_fetch_long(&_427$$23, &_426$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
				zephir_array_fetch_long(&_428$$23, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
				zephir_array_fetch_long(&_429$$23, &_428$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
				ZEPHIR_INIT_NVAR(&_265$$23);
				ZVAL_STRING(&_265$$23, "%s(?P<%s>%s)%s");
				ZEPHIR_CALL_FUNCTION(&_430$$23, "sprintf", &_29, 2, &_265$$23, &_425$$23, &_427$$23, &requirement, &_429$$23);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&regexp, &_430$$23);
				zephir_array_fetch_long(&_431$$23, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
				zephir_array_fetch_long(&_432$$23, &_431$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
				_433$$23 = !ZEPHIR_IS_STRING_IDENTICAL(&_432$$23, "");
				if (!(_433$$23)) {
					zephir_array_fetch_long(&_434$$23, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
					zephir_array_fetch_long(&_435$$23, &_434$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
					_436$$23 = !ZEPHIR_IS_STRING_IDENTICAL(&_435$$23, "");
					if (_436$$23) {
						zephir_array_fetch_long(&_437$$23, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
						zephir_array_fetch_long(&_438$$23, &_437$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 121);
						_436$$23 = !ZEPHIR_IS_STRING_IDENTICAL(&_438$$23, "");
					}
					_433$$23 = _436$$23;
				}
				if (_433$$23) {
					ZEPHIR_INIT_NVAR(&_440$$41);
					ZVAL_STRING(&_440$$41, "(?:%s)");
					ZEPHIR_CALL_FUNCTION(&_441$$41, "sprintf", &_29, 2, &_440$$41, &regexp);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&regexp, &_441$$41);
				}
				zephir_array_fetch_long(&_442$$23, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 125);
				zephir_array_fetch_long(&_443$$23, &_442$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 125);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_443$$23, "")) {
					zephir_concat_self_str(&regexp, SL("?"));
				}
				zephir_array_fetch_long(&_444$$23, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 129);
				zephir_array_fetch_long(&_445$$23, &_444$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 129);
				zephir_array_fetch_long(&_446$$23, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 129);
				zephir_array_fetch_long(&_447$$23, &_446$$23, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 129);
				ZEPHIR_INIT_NVAR(&_448$$23);
				ZEPHIR_CONCAT_VVV(&_448$$23, &_445$$23, &regexp, &_447$$23);
				zephir_concat_self(&regex, &_448$$23);
			ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&match);
	ZEPHIR_INIT_NVAR(&i);
	if (ZEPHIR_IS_STRING_IDENTICAL(&regex, "")) {
		ZEPHIR_CALL_FUNCTION(&regex, "preg_quote", &_1, 131, pattern);
		zephir_check_call_status();
	}
	object_init_ex(return_value, zeplara_routing_regex_ce);
	ZEPHIR_INIT_VAR(&_450);
	ZVAL_STRING(&_450, "{^%s$}%s");
	ZEPHIR_CALL_FUNCTION(&_451, "sprintf", &_29, 2, &_450, &regex, flags);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 136, &_451, &variables);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string requirement
 * @return string
 */
PHP_METHOD(Zeplara_Routing_RouteCompiler, resolveRequirement) {

	zval _5$$3, _11$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_16 = NULL;
	zval *requirement = NULL, requirement_sub, count, _0, _1, _2, _6, _7, _3$$3, _4$$3, _8$$4, _9$$4, _10$$4, _12$$5, _13$$5, _14$$5, _15$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requirement_sub);
	ZVAL_UNDEF(&count);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_11$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &requirement);

	ZEPHIR_SEPARATE_PARAM(requirement);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, requirement, 0 , 1 , 0);
	if (ZEPHIR_IS_STRING(&_2, "^")) {
		ZVAL_LONG(&_3$$3, 1);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_substr(&_4$$3, requirement, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(&_5$$3, &_4$$3);
		ZEPHIR_CPY_WRT(requirement, &_5$$3);
	}
	ZVAL_LONG(&_6, -1);
	ZEPHIR_INIT_VAR(&_7);
	zephir_substr(&_7, requirement, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	if (ZEPHIR_IS_STRING(&_7, "$")) {
		ZVAL_LONG(&_8$$4, 0);
		ZVAL_LONG(&_9$$4, -1);
		ZEPHIR_INIT_VAR(&_10$$4);
		zephir_substr(&_10$$4, requirement, 0 , -1 , 0);
		zephir_get_strval(&_11$$4, &_10$$4);
		ZEPHIR_CPY_WRT(requirement, &_11$$4);
	}
	do {
		ZEPHIR_INIT_NVAR(&_12$$5);
		ZEPHIR_INIT_NVAR(&_12$$5);
		zephir_create_closure_ex(&_12$$5, NULL, zeplara_2__closure_ce, SL("__invoke"));
		ZEPHIR_INIT_NVAR(&_13$$5);
		ZVAL_STRING(&_13$$5, "#\\(((?!\\?\\:|\\*\\)|\\+\\)|\\?\\)).+)\\)#");
		ZVAL_LONG(&_14$$5, -1);
		ZEPHIR_MAKE_REF(&count);
		ZEPHIR_CALL_FUNCTION(&_15$$5, "preg_replace_callback", &_16, 41, &_13$$5, &_12$$5, requirement, &_14$$5, &count);
		ZEPHIR_UNREF(&count);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(requirement, &_15$$5);
	} while (zephir_is_true(&count));
	RETVAL_ZVAL(requirement, 1, 0);
	RETURN_MM();

}

/**
 * @param nextIdx
 * @param lastIdx
 * @param matches
 * @return bool
 */
PHP_METHOD(Zeplara_Routing_RouteCompiler, hasNextStaticPrefixOnNextMatch) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *nextIdx, nextIdx_sub, *lastIdx, lastIdx_sub, *matches, matches_sub, _0$$3, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nextIdx_sub);
	ZVAL_UNDEF(&lastIdx_sub);
	ZVAL_UNDEF(&matches_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &nextIdx, &lastIdx, &matches);

	ZEPHIR_SEPARATE_PARAM(nextIdx);


	while (1) {
		if (!(ZEPHIR_LE(nextIdx, lastIdx))) {
			break;
		}
		zephir_array_fetch(&_0$$3, matches, nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 173);
		zephir_array_fetch_long(&_1$$3, &_0$$3, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 173);
		zephir_array_fetch_long(&_2$$3, &_1$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 173);
		if (!ZEPHIR_IS_STRING_IDENTICAL(&_2$$3, "")) {
			RETURN_MM_BOOL(1);
		}
		ZEPHIR_SEPARATE(nextIdx);
		zephir_increment(nextIdx);
	}
	RETURN_MM_BOOL(0);

}

/**
 * @param prevIdx
 * @param matches
 * @return bool
 */
PHP_METHOD(Zeplara_Routing_RouteCompiler, hasStaticPrefixWithoutSeparatorOnPrevMatch) {

	zend_bool _3$$3, _7$$3, _11$$3, _15$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prevIdx, prevIdx_sub, *matches, matches_sub, nextIdx, lastIdx, _0$$3, _1$$3, _2$$3, _4$$3, _5$$3, _6$$3, _8$$3, _9$$3, _10$$3, _12$$3, _13$$3, _14$$3, _16$$3, _17$$3, _18$$3, _19$$5, _20$$5, _21$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prevIdx_sub);
	ZVAL_UNDEF(&matches_sub);
	ZVAL_UNDEF(&nextIdx);
	ZVAL_UNDEF(&lastIdx);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &prevIdx, &matches);

	ZEPHIR_SEPARATE_PARAM(prevIdx);


	ZEPHIR_CPY_WRT(&lastIdx, prevIdx);
	while (1) {
		if (!(ZEPHIR_GE_LONG(prevIdx, 0))) {
			break;
		}
		zephir_array_fetch(&_0$$3, matches, prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
		zephir_array_fetch_long(&_1$$3, &_0$$3, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
		zephir_array_fetch_long(&_2$$3, &_1$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
		_3$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_2$$3, "");
		if (_3$$3) {
			zephir_array_fetch(&_4$$3, matches, prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
			zephir_array_fetch_long(&_5$$3, &_4$$3, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
			zephir_array_fetch_long(&_6$$3, &_5$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
			_3$$3 = ZEPHIR_IS_STRING_IDENTICAL(&_6$$3, "");
		}
		_7$$3 = _3$$3;
		if (_7$$3) {
			zephir_array_fetch(&_8$$3, matches, prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
			zephir_array_fetch_long(&_9$$3, &_8$$3, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
			zephir_array_fetch_long(&_10$$3, &_9$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
			_11$$3 = ZEPHIR_IS_STRING_IDENTICAL(&_10$$3, "");
			if (!(_11$$3)) {
				zephir_array_fetch(&_12$$3, matches, prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
				zephir_array_fetch_long(&_13$$3, &_12$$3, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
				zephir_array_fetch_long(&_14$$3, &_13$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
				_11$$3 = ZEPHIR_IS_STRING_IDENTICAL(&_14$$3, "");
			}
			_7$$3 = _11$$3;
		}
		_15$$3 = _7$$3;
		if (!(_15$$3)) {
			zephir_array_fetch(&_16$$3, matches, prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
			zephir_array_fetch_long(&_17$$3, &_16$$3, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
			zephir_array_fetch_long(&_18$$3, &_17$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 195);
			_15$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_18$$3, "");
		}
		if (_15$$3) {
			ZEPHIR_INIT_NVAR(&nextIdx);
			ZVAL_LONG(&nextIdx, (zephir_get_numberval(prevIdx) + 1));
			while (1) {
				if (!(ZEPHIR_LE(&nextIdx, &lastIdx))) {
					break;
				}
				zephir_array_fetch(&_19$$5, matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 200);
				zephir_array_fetch_long(&_20$$5, &_19$$5, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 200);
				zephir_array_fetch_long(&_21$$5, &_20$$5, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 200);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_21$$5, "")) {
					RETURN_MM_BOOL(0);
				}
				ZEPHIR_SEPARATE(&nextIdx);
				zephir_increment(&nextIdx);
			}
			RETURN_MM_BOOL(1);
		}
		ZEPHIR_SEPARATE(prevIdx);
		zephir_decrement(prevIdx);
	}
	RETURN_MM_BOOL(0);

}

