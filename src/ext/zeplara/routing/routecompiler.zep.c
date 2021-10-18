
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
	ZEPHIR_CALL_SELF(&_0, "parseregex", &_1, 159, &_2, &_3, &_4, &requirements);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, route, "getpattern", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "/");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "sDu");
	ZEPHIR_CALL_SELF(&_5, "parseregex", &_1, 159, &_6, &_3, &_4, &requirements);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 160, &_0, &_5);
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

	zval _191$$17, _197$$18, _425$$40, _431$$41;
	zend_bool _12$$3, _13$$3, _232$$3, _235$$3, _74$$9, _77$$9, _80$$9, _81$$9, _85$$9, _88$$9, _89$$9, _90$$9, _91$$9, _94$$9, _97$$9, _98$$9, _101$$9, _104$$9, _105$$9, _109$$9, _111$$9, _127$$11, _128$$11, _132$$11, _136$$11, _140$$11, _143$$11, _145$$11, _148$$11, _151$$11, _154$$11, _157$$11, _159$$11, _217$$20, _219$$20, _220$$20, _250$$26, _251$$26, _463$$26, _466$$26, _310$$32, _313$$32, _316$$32, _317$$32, _321$$32, _324$$32, _325$$32, _326$$32, _327$$32, _330$$32, _333$$32, _334$$32, _337$$32, _340$$32, _341$$32, _345$$32, _346$$32, _362$$34, _363$$34, _367$$34, _371$$34, _375$$34, _378$$34, _380$$34, _383$$34, _385$$34, _388$$34, _391$$34, _393$$34, _448$$43, _450$$43, _451$$43;
	zend_string *_9;
	zend_ulong _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_29 = NULL, *_30 = NULL, *_110 = NULL, *_150 = NULL, *_202 = NULL, *_210 = NULL, *_212 = NULL;
	zval *pattern, pattern_sub, *separator = NULL, separator_sub, *flags, flags_sub, *requirements = NULL, requirements_sub, i, match, requirement, regex, regexp, matches, variables, prevIdx, nextIdx, lastIdx, separatorRegex, nextSeparatorOfRequirement, _0, _2, _3, _4, _5, *_6, _7, _479, _480, _481, _10$$3, _11$$3, _14$$3, _15$$3, _16$$3, _31$$3, _32$$3, _40$$3, _41$$3, _42$$3, _43$$3, _44$$3, _45$$3, _52$$3, _53$$3, _60$$3, _61$$3, _62$$3, _63$$3, _67$$3, _68$$3, _123$$3, _124$$3, _179$$3, _180$$3, _184$$3, _185$$3, _223$$3, _224$$3, _225$$3, _226$$3, _227$$3, _228$$3, _229$$3, _230$$3, _231$$3, _233$$3, _234$$3, _236$$3, _237$$3, _241$$3, _242$$3, _243$$3, _244$$3, _245$$3, _246$$3, _247$$3, _17$$4, _18$$4, _19$$4, _20$$4, _21$$4, _22$$4, _23$$4, _24$$4, _25$$4, _26$$4, _27$$4, _28$$4, _33$$5, _34$$5, _35$$5, _36$$5, _37$$5, _38$$5, _39$$5, _46$$6, _47$$6, _48$$6, _49$$6, _50$$6, _51$$6, _54$$7, _55$$7, _56$$7, _57$$7, _58$$7, _59$$7, _64$$8, _65$$8, _66$$8, _69$$9, _70$$9, _71$$9, _72$$9, _73$$9, _75$$9, _76$$9, _78$$9, _79$$9, _82$$9, _83$$9, _84$$9, _86$$9, _87$$9, _92$$9, _93$$9, _95$$9, _96$$9, _99$$9, _100$$9, _102$$9, _103$$9, _106$$9, _107$$9, _108$$9, _112$$9, _113$$9, _114$$10, _115$$10, _116$$10, _117$$10, _118$$10, _119$$10, _120$$10, _121$$10, _122$$10, _125$$11, _126$$11, _129$$11, _130$$11, _131$$11, _133$$11, _134$$11, _135$$11, _137$$11, _138$$11, _139$$11, _141$$11, _142$$11, _144$$11, _146$$11, _147$$11, _149$$11, _152$$11, _153$$11, _155$$11, _156$$11, _158$$11, _160$$11, _161$$11, _162$$12, _163$$12, _164$$12, _165$$12, _166$$12, _167$$13, _168$$13, _169$$13, _170$$13, _171$$13, _172$$13, _173$$13, _174$$13, _175$$13, _176$$14, _177$$14, _178$$14, _181$$15, _182$$15, _183$$15, count$$16, _186$$16, _187$$16, _188$$16, _192$$16, _193$$16, _189$$17, _190$$17, _194$$18, _195$$18, _196$$18, _198$$19, _199$$19, _200$$19, _201$$19, _203$$20, _204$$20, _205$$20, _206$$20, _213$$20, _214$$20, _215$$20, _216$$20, _218$$20, _221$$20, _222$$20, _207$$21, _208$$22, _209$$22, _211$$22, _238$$24, _239$$24, _240$$24, _248$$26, _249$$26, _252$$26, _253$$26, _254$$26, _267$$26, _268$$26, _276$$26, _277$$26, _278$$26, _279$$26, _280$$26, _281$$26, _288$$26, _289$$26, _296$$26, _297$$26, _298$$26, _299$$26, _303$$26, _304$$26, _358$$26, _359$$26, _413$$26, _414$$26, _418$$26, _419$$26, _454$$26, _455$$26, _456$$26, _457$$26, _458$$26, _459$$26, _460$$26, _461$$26, _462$$26, _464$$26, _465$$26, _467$$26, _468$$26, _472$$26, _473$$26, _474$$26, _475$$26, _476$$26, _477$$26, _478$$26, _255$$27, _256$$27, _257$$27, _258$$27, _259$$27, _260$$27, _261$$27, _262$$27, _263$$27, _264$$27, _265$$27, _266$$27, _269$$28, _270$$28, _271$$28, _272$$28, _273$$28, _274$$28, _275$$28, _282$$29, _283$$29, _284$$29, _285$$29, _286$$29, _287$$29, _290$$30, _291$$30, _292$$30, _293$$30, _294$$30, _295$$30, _300$$31, _301$$31, _302$$31, _305$$32, _306$$32, _307$$32, _308$$32, _309$$32, _311$$32, _312$$32, _314$$32, _315$$32, _318$$32, _319$$32, _320$$32, _322$$32, _323$$32, _328$$32, _329$$32, _331$$32, _332$$32, _335$$32, _336$$32, _338$$32, _339$$32, _342$$32, _343$$32, _344$$32, _347$$32, _348$$32, _349$$33, _350$$33, _351$$33, _352$$33, _353$$33, _354$$33, _355$$33, _356$$33, _357$$33, _360$$34, _361$$34, _364$$34, _365$$34, _366$$34, _368$$34, _369$$34, _370$$34, _372$$34, _373$$34, _374$$34, _376$$34, _377$$34, _379$$34, _381$$34, _382$$34, _384$$34, _386$$34, _387$$34, _389$$34, _390$$34, _392$$34, _394$$34, _395$$34, _396$$35, _397$$35, _398$$35, _399$$35, _400$$35, _401$$36, _402$$36, _403$$36, _404$$36, _405$$36, _406$$36, _407$$36, _408$$36, _409$$36, _410$$37, _411$$37, _412$$37, _415$$38, _416$$38, _417$$38, count$$39, _420$$39, _421$$39, _422$$39, _426$$39, _427$$39, _423$$40, _424$$40, _428$$41, _429$$41, _430$$41, _432$$42, _433$$42, _434$$42, _435$$42, _436$$43, _437$$43, _438$$43, _439$$43, _444$$43, _445$$43, _446$$43, _447$$43, _449$$43, _452$$43, _453$$43, _440$$44, _441$$45, _442$$45, _443$$45, _469$$47, _470$$47, _471$$47;
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
	ZVAL_UNDEF(&_479);
	ZVAL_UNDEF(&_480);
	ZVAL_UNDEF(&_481);
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
	ZVAL_UNDEF(&_223$$3);
	ZVAL_UNDEF(&_224$$3);
	ZVAL_UNDEF(&_225$$3);
	ZVAL_UNDEF(&_226$$3);
	ZVAL_UNDEF(&_227$$3);
	ZVAL_UNDEF(&_228$$3);
	ZVAL_UNDEF(&_229$$3);
	ZVAL_UNDEF(&_230$$3);
	ZVAL_UNDEF(&_231$$3);
	ZVAL_UNDEF(&_233$$3);
	ZVAL_UNDEF(&_234$$3);
	ZVAL_UNDEF(&_236$$3);
	ZVAL_UNDEF(&_237$$3);
	ZVAL_UNDEF(&_241$$3);
	ZVAL_UNDEF(&_242$$3);
	ZVAL_UNDEF(&_243$$3);
	ZVAL_UNDEF(&_244$$3);
	ZVAL_UNDEF(&_245$$3);
	ZVAL_UNDEF(&_246$$3);
	ZVAL_UNDEF(&_247$$3);
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
	ZVAL_UNDEF(&count$$16);
	ZVAL_UNDEF(&_186$$16);
	ZVAL_UNDEF(&_187$$16);
	ZVAL_UNDEF(&_188$$16);
	ZVAL_UNDEF(&_192$$16);
	ZVAL_UNDEF(&_193$$16);
	ZVAL_UNDEF(&_189$$17);
	ZVAL_UNDEF(&_190$$17);
	ZVAL_UNDEF(&_194$$18);
	ZVAL_UNDEF(&_195$$18);
	ZVAL_UNDEF(&_196$$18);
	ZVAL_UNDEF(&_198$$19);
	ZVAL_UNDEF(&_199$$19);
	ZVAL_UNDEF(&_200$$19);
	ZVAL_UNDEF(&_201$$19);
	ZVAL_UNDEF(&_203$$20);
	ZVAL_UNDEF(&_204$$20);
	ZVAL_UNDEF(&_205$$20);
	ZVAL_UNDEF(&_206$$20);
	ZVAL_UNDEF(&_213$$20);
	ZVAL_UNDEF(&_214$$20);
	ZVAL_UNDEF(&_215$$20);
	ZVAL_UNDEF(&_216$$20);
	ZVAL_UNDEF(&_218$$20);
	ZVAL_UNDEF(&_221$$20);
	ZVAL_UNDEF(&_222$$20);
	ZVAL_UNDEF(&_207$$21);
	ZVAL_UNDEF(&_208$$22);
	ZVAL_UNDEF(&_209$$22);
	ZVAL_UNDEF(&_211$$22);
	ZVAL_UNDEF(&_238$$24);
	ZVAL_UNDEF(&_239$$24);
	ZVAL_UNDEF(&_240$$24);
	ZVAL_UNDEF(&_248$$26);
	ZVAL_UNDEF(&_249$$26);
	ZVAL_UNDEF(&_252$$26);
	ZVAL_UNDEF(&_253$$26);
	ZVAL_UNDEF(&_254$$26);
	ZVAL_UNDEF(&_267$$26);
	ZVAL_UNDEF(&_268$$26);
	ZVAL_UNDEF(&_276$$26);
	ZVAL_UNDEF(&_277$$26);
	ZVAL_UNDEF(&_278$$26);
	ZVAL_UNDEF(&_279$$26);
	ZVAL_UNDEF(&_280$$26);
	ZVAL_UNDEF(&_281$$26);
	ZVAL_UNDEF(&_288$$26);
	ZVAL_UNDEF(&_289$$26);
	ZVAL_UNDEF(&_296$$26);
	ZVAL_UNDEF(&_297$$26);
	ZVAL_UNDEF(&_298$$26);
	ZVAL_UNDEF(&_299$$26);
	ZVAL_UNDEF(&_303$$26);
	ZVAL_UNDEF(&_304$$26);
	ZVAL_UNDEF(&_358$$26);
	ZVAL_UNDEF(&_359$$26);
	ZVAL_UNDEF(&_413$$26);
	ZVAL_UNDEF(&_414$$26);
	ZVAL_UNDEF(&_418$$26);
	ZVAL_UNDEF(&_419$$26);
	ZVAL_UNDEF(&_454$$26);
	ZVAL_UNDEF(&_455$$26);
	ZVAL_UNDEF(&_456$$26);
	ZVAL_UNDEF(&_457$$26);
	ZVAL_UNDEF(&_458$$26);
	ZVAL_UNDEF(&_459$$26);
	ZVAL_UNDEF(&_460$$26);
	ZVAL_UNDEF(&_461$$26);
	ZVAL_UNDEF(&_462$$26);
	ZVAL_UNDEF(&_464$$26);
	ZVAL_UNDEF(&_465$$26);
	ZVAL_UNDEF(&_467$$26);
	ZVAL_UNDEF(&_468$$26);
	ZVAL_UNDEF(&_472$$26);
	ZVAL_UNDEF(&_473$$26);
	ZVAL_UNDEF(&_474$$26);
	ZVAL_UNDEF(&_475$$26);
	ZVAL_UNDEF(&_476$$26);
	ZVAL_UNDEF(&_477$$26);
	ZVAL_UNDEF(&_478$$26);
	ZVAL_UNDEF(&_255$$27);
	ZVAL_UNDEF(&_256$$27);
	ZVAL_UNDEF(&_257$$27);
	ZVAL_UNDEF(&_258$$27);
	ZVAL_UNDEF(&_259$$27);
	ZVAL_UNDEF(&_260$$27);
	ZVAL_UNDEF(&_261$$27);
	ZVAL_UNDEF(&_262$$27);
	ZVAL_UNDEF(&_263$$27);
	ZVAL_UNDEF(&_264$$27);
	ZVAL_UNDEF(&_265$$27);
	ZVAL_UNDEF(&_266$$27);
	ZVAL_UNDEF(&_269$$28);
	ZVAL_UNDEF(&_270$$28);
	ZVAL_UNDEF(&_271$$28);
	ZVAL_UNDEF(&_272$$28);
	ZVAL_UNDEF(&_273$$28);
	ZVAL_UNDEF(&_274$$28);
	ZVAL_UNDEF(&_275$$28);
	ZVAL_UNDEF(&_282$$29);
	ZVAL_UNDEF(&_283$$29);
	ZVAL_UNDEF(&_284$$29);
	ZVAL_UNDEF(&_285$$29);
	ZVAL_UNDEF(&_286$$29);
	ZVAL_UNDEF(&_287$$29);
	ZVAL_UNDEF(&_290$$30);
	ZVAL_UNDEF(&_291$$30);
	ZVAL_UNDEF(&_292$$30);
	ZVAL_UNDEF(&_293$$30);
	ZVAL_UNDEF(&_294$$30);
	ZVAL_UNDEF(&_295$$30);
	ZVAL_UNDEF(&_300$$31);
	ZVAL_UNDEF(&_301$$31);
	ZVAL_UNDEF(&_302$$31);
	ZVAL_UNDEF(&_305$$32);
	ZVAL_UNDEF(&_306$$32);
	ZVAL_UNDEF(&_307$$32);
	ZVAL_UNDEF(&_308$$32);
	ZVAL_UNDEF(&_309$$32);
	ZVAL_UNDEF(&_311$$32);
	ZVAL_UNDEF(&_312$$32);
	ZVAL_UNDEF(&_314$$32);
	ZVAL_UNDEF(&_315$$32);
	ZVAL_UNDEF(&_318$$32);
	ZVAL_UNDEF(&_319$$32);
	ZVAL_UNDEF(&_320$$32);
	ZVAL_UNDEF(&_322$$32);
	ZVAL_UNDEF(&_323$$32);
	ZVAL_UNDEF(&_328$$32);
	ZVAL_UNDEF(&_329$$32);
	ZVAL_UNDEF(&_331$$32);
	ZVAL_UNDEF(&_332$$32);
	ZVAL_UNDEF(&_335$$32);
	ZVAL_UNDEF(&_336$$32);
	ZVAL_UNDEF(&_338$$32);
	ZVAL_UNDEF(&_339$$32);
	ZVAL_UNDEF(&_342$$32);
	ZVAL_UNDEF(&_343$$32);
	ZVAL_UNDEF(&_344$$32);
	ZVAL_UNDEF(&_347$$32);
	ZVAL_UNDEF(&_348$$32);
	ZVAL_UNDEF(&_349$$33);
	ZVAL_UNDEF(&_350$$33);
	ZVAL_UNDEF(&_351$$33);
	ZVAL_UNDEF(&_352$$33);
	ZVAL_UNDEF(&_353$$33);
	ZVAL_UNDEF(&_354$$33);
	ZVAL_UNDEF(&_355$$33);
	ZVAL_UNDEF(&_356$$33);
	ZVAL_UNDEF(&_357$$33);
	ZVAL_UNDEF(&_360$$34);
	ZVAL_UNDEF(&_361$$34);
	ZVAL_UNDEF(&_364$$34);
	ZVAL_UNDEF(&_365$$34);
	ZVAL_UNDEF(&_366$$34);
	ZVAL_UNDEF(&_368$$34);
	ZVAL_UNDEF(&_369$$34);
	ZVAL_UNDEF(&_370$$34);
	ZVAL_UNDEF(&_372$$34);
	ZVAL_UNDEF(&_373$$34);
	ZVAL_UNDEF(&_374$$34);
	ZVAL_UNDEF(&_376$$34);
	ZVAL_UNDEF(&_377$$34);
	ZVAL_UNDEF(&_379$$34);
	ZVAL_UNDEF(&_381$$34);
	ZVAL_UNDEF(&_382$$34);
	ZVAL_UNDEF(&_384$$34);
	ZVAL_UNDEF(&_386$$34);
	ZVAL_UNDEF(&_387$$34);
	ZVAL_UNDEF(&_389$$34);
	ZVAL_UNDEF(&_390$$34);
	ZVAL_UNDEF(&_392$$34);
	ZVAL_UNDEF(&_394$$34);
	ZVAL_UNDEF(&_395$$34);
	ZVAL_UNDEF(&_396$$35);
	ZVAL_UNDEF(&_397$$35);
	ZVAL_UNDEF(&_398$$35);
	ZVAL_UNDEF(&_399$$35);
	ZVAL_UNDEF(&_400$$35);
	ZVAL_UNDEF(&_401$$36);
	ZVAL_UNDEF(&_402$$36);
	ZVAL_UNDEF(&_403$$36);
	ZVAL_UNDEF(&_404$$36);
	ZVAL_UNDEF(&_405$$36);
	ZVAL_UNDEF(&_406$$36);
	ZVAL_UNDEF(&_407$$36);
	ZVAL_UNDEF(&_408$$36);
	ZVAL_UNDEF(&_409$$36);
	ZVAL_UNDEF(&_410$$37);
	ZVAL_UNDEF(&_411$$37);
	ZVAL_UNDEF(&_412$$37);
	ZVAL_UNDEF(&_415$$38);
	ZVAL_UNDEF(&_416$$38);
	ZVAL_UNDEF(&_417$$38);
	ZVAL_UNDEF(&count$$39);
	ZVAL_UNDEF(&_420$$39);
	ZVAL_UNDEF(&_421$$39);
	ZVAL_UNDEF(&_422$$39);
	ZVAL_UNDEF(&_426$$39);
	ZVAL_UNDEF(&_427$$39);
	ZVAL_UNDEF(&_423$$40);
	ZVAL_UNDEF(&_424$$40);
	ZVAL_UNDEF(&_428$$41);
	ZVAL_UNDEF(&_429$$41);
	ZVAL_UNDEF(&_430$$41);
	ZVAL_UNDEF(&_432$$42);
	ZVAL_UNDEF(&_433$$42);
	ZVAL_UNDEF(&_434$$42);
	ZVAL_UNDEF(&_435$$42);
	ZVAL_UNDEF(&_436$$43);
	ZVAL_UNDEF(&_437$$43);
	ZVAL_UNDEF(&_438$$43);
	ZVAL_UNDEF(&_439$$43);
	ZVAL_UNDEF(&_444$$43);
	ZVAL_UNDEF(&_445$$43);
	ZVAL_UNDEF(&_446$$43);
	ZVAL_UNDEF(&_447$$43);
	ZVAL_UNDEF(&_449$$43);
	ZVAL_UNDEF(&_452$$43);
	ZVAL_UNDEF(&_453$$43);
	ZVAL_UNDEF(&_440$$44);
	ZVAL_UNDEF(&_441$$45);
	ZVAL_UNDEF(&_442$$45);
	ZVAL_UNDEF(&_443$$45);
	ZVAL_UNDEF(&_469$$47);
	ZVAL_UNDEF(&_470$$47);
	ZVAL_UNDEF(&_471$$47);
	ZVAL_UNDEF(&_191$$17);
	ZVAL_UNDEF(&_197$$18);
	ZVAL_UNDEF(&_425$$40);
	ZVAL_UNDEF(&_431$$41);

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
	ZEPHIR_CALL_FUNCTION(&_0, "preg_quote", &_1, 161, separator);
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
	zephir_is_iterable(&matches, 1, "zeplara/Routing/RouteCompiler.zep", 146);
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
				ZEPHIR_CALL_METHOD(NULL, &_17$$4, "__construct", &_30, 66, &_28$$4);
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
				ZEPHIR_CALL_METHOD(NULL, &_33$$5, "__construct", &_30, 66, &_39$$5);
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
				ZEPHIR_CALL_METHOD(NULL, &_46$$6, "__construct", &_30, 66, &_51$$6);
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
				ZEPHIR_CALL_METHOD(NULL, &_54$$7, "__construct", &_30, 66, &_59$$7);
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
				ZEPHIR_CALL_FUNCTION(&_66$$8, "preg_quote", &_1, 161, &_65$$8);
				zephir_check_call_status();
				zephir_array_update_multi(&match, &_66$$8, SL("ll"), 2, 1, 0);
			}
			zephir_array_fetch_long(&_67$$3, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 75);
			zephir_array_fetch_long(&_68$$3, &_67$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 75);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_68$$3, "")) {
				zephir_array_fetch_long(&_69$$9, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 76);
				zephir_array_fetch_long(&_70$$9, &_69$$9, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 76);
				ZEPHIR_CALL_FUNCTION(&_71$$9, "preg_quote", &_1, 161, &_70$$9);
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
						ZEPHIR_CALL_SELF(&_71$$9, "hasnextstaticprefixonnextmatch", &_110, 162, &nextIdx, &lastIdx, &matches);
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
					ZEPHIR_CALL_FUNCTION(&_121$$10, "preg_quote", &_1, 161, &_120$$10);
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
						ZEPHIR_CALL_SELF(&_137$$11, "hasnextstaticprefixonnextmatch", &_110, 162, &nextIdx, &lastIdx, &matches);
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
						ZEPHIR_CALL_SELF(&_149$$11, "hasstaticprefixwithoutseparatoronprevmatch", &_150, 163, &prevIdx, &matches);
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
					ZEPHIR_CALL_FUNCTION(&_165$$12, "preg_quote", &_1, 161, &_164$$12);
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
					ZEPHIR_CALL_FUNCTION(&_174$$13, "preg_quote", &_1, 161, &_173$$13);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_174$$13, SL("ll"), 2, 5, 2);
					ZEPHIR_INIT_NVAR(&_175$$13);
					ZVAL_STRING(&_175$$13, "");
					zephir_array_update_multi(&match, &_175$$13, SL("ll"), 2, 5, 0);
				} else {
					zephir_array_fetch_long(&_176$$14, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 94);
					zephir_array_fetch_long(&_177$$14, &_176$$14, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 94);
					ZEPHIR_CALL_FUNCTION(&_178$$14, "preg_quote", &_1, 161, &_177$$14);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_178$$14, SL("ll"), 2, 5, 0);
				}
			}
			zephir_array_fetch_long(&_179$$3, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 98);
			zephir_array_fetch_long(&_180$$3, &_179$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 98);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_180$$3, "")) {
				zephir_array_fetch_long(&_181$$15, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 99);
				zephir_array_fetch_long(&_182$$15, &_181$$15, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 99);
				ZEPHIR_CALL_FUNCTION(&_183$$15, "preg_quote", &_1, 161, &_182$$15);
				zephir_check_call_status();
				zephir_array_update_multi(&match, &_183$$15, SL("ll"), 2, 6, 0);
			}
			ZEPHIR_OBS_NVAR(&requirement);
			zephir_array_fetch_long(&_184$$3, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 102);
			zephir_array_fetch_long(&_185$$3, &_184$$3, 0, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 102);
			if (zephir_array_isset_fetch(&requirement, requirements, &_185$$3, 0)) {
				ZVAL_LONG(&_186$$16, 0);
				ZVAL_LONG(&_187$$16, 1);
				ZEPHIR_INIT_NVAR(&_188$$16);
				zephir_substr(&_188$$16, &requirement, 0 , 1 , 0);
				if (ZEPHIR_IS_STRING(&_188$$16, "^")) {
					ZVAL_LONG(&_189$$17, 1);
					ZEPHIR_INIT_NVAR(&_190$$17);
					zephir_substr(&_190$$17, &requirement, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_get_strval(&_191$$17, &_190$$17);
					ZEPHIR_CPY_WRT(&requirement, &_191$$17);
				}
				ZVAL_LONG(&_192$$16, -1);
				ZEPHIR_INIT_NVAR(&_193$$16);
				zephir_substr(&_193$$16, &requirement, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				if (ZEPHIR_IS_STRING(&_193$$16, "$")) {
					ZVAL_LONG(&_194$$18, 0);
					ZVAL_LONG(&_195$$18, -1);
					ZEPHIR_INIT_NVAR(&_196$$18);
					zephir_substr(&_196$$18, &requirement, 0 , -1 , 0);
					zephir_get_strval(&_197$$18, &_196$$18);
					ZEPHIR_CPY_WRT(&requirement, &_197$$18);
				}
				do {
					ZEPHIR_INIT_NVAR(&_198$$19);
					ZEPHIR_INIT_NVAR(&_198$$19);
					zephir_create_closure_ex(&_198$$19, NULL, zeplara_5__closure_ce, SL("__invoke"));
					ZEPHIR_INIT_NVAR(&_199$$19);
					ZVAL_STRING(&_199$$19, "#\\(((?!\\?\\:|\\*\\)|\\+\\)|\\?\\)).+)\\)#");
					ZVAL_LONG(&_200$$19, -1);
					ZEPHIR_MAKE_REF(&count$$16);
					ZEPHIR_CALL_FUNCTION(&_201$$19, "preg_replace_callback", &_202, 42, &_199$$19, &_198$$19, &requirement, &_200$$19, &count$$16);
					ZEPHIR_UNREF(&count$$16);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&requirement, &_201$$19);
				} while (zephir_is_true(&count$$16));
			} else {
				zephir_array_fetch_long(&_203$$20, &match, 5, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
				if (zephir_array_isset_long(&_203$$20, 2)) {
					zephir_array_fetch_long(&_204$$20, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
					ZEPHIR_OBS_NVAR(&nextSeparatorOfRequirement);
					zephir_array_fetch_long(&nextSeparatorOfRequirement, &_204$$20, 2, PH_NOISY, "zeplara/Routing/RouteCompiler.zep", 119);
				} else {
					zephir_array_fetch_long(&_205$$20, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
					ZEPHIR_OBS_NVAR(&nextSeparatorOfRequirement);
					zephir_array_fetch_long(&nextSeparatorOfRequirement, &_205$$20, 0, PH_NOISY, "zeplara/Routing/RouteCompiler.zep", 119);
				}
				ZEPHIR_INIT_NVAR(&_206$$20);
				zephir_fast_strpos(&_206$$20, &nextSeparatorOfRequirement, separator, 0 );
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_206$$20)) {
					ZEPHIR_INIT_NVAR(&_207$$21);
					ZEPHIR_CONCAT_VV(&_207$$21, separator, &nextSeparatorOfRequirement);
					ZEPHIR_CPY_WRT(&nextSeparatorOfRequirement, &_207$$21);
				} else {
					ZEPHIR_INIT_NVAR(&_208$$22);
					ZEPHIR_CONCAT_VV(&_208$$22, separator, &nextSeparatorOfRequirement);
					ZEPHIR_CALL_FUNCTION(&_209$$22, "str_split", &_210, 97, &_208$$22);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_211$$22, "array_unique", &_212, 150, &_209$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&nextSeparatorOfRequirement);
					zephir_fast_join_str(&nextSeparatorOfRequirement, SL(""), &_211$$22);
				}
				ZEPHIR_INIT_NVAR(&_213$$20);
				ZVAL_STRING(&_213$$20, "[^%s]+");
				ZEPHIR_CALL_FUNCTION(&_214$$20, "sprintf", &_29, 2, &_213$$20, &nextSeparatorOfRequirement);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&requirement, &_214$$20);
				zephir_array_fetch_long(&_215$$20, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 128);
				zephir_array_fetch_long(&_216$$20, &_215$$20, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 128);
				_217$$20 = !ZEPHIR_IS_STRING_IDENTICAL(&_216$$20, "");
				if (!(_217$$20)) {
					zephir_array_fetch_long(&_218$$20, &match, 5, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 128);
					_217$$20 = zephir_array_isset_long(&_218$$20, 2) == 1;
				}
				_219$$20 = _217$$20;
				if (!(_219$$20)) {
					_220$$20 = ZEPHIR_IS_IDENTICAL(&i, &lastIdx);
					if (_220$$20) {
						zephir_array_fetch_long(&_221$$20, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 128);
						zephir_array_fetch_long(&_222$$20, &_221$$20, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 128);
						_220$$20 = ZEPHIR_IS_STRING_IDENTICAL(&_222$$20, "");
					}
					_219$$20 = _220$$20;
				}
				if (_219$$20) {
					zephir_concat_self_str(&requirement, SL("+"));
				}
			}
			zephir_array_fetch_long(&_223$$3, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
			zephir_array_fetch_long(&_224$$3, &_223$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
			zephir_array_fetch_long(&_225$$3, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
			zephir_array_fetch_long(&_226$$3, &_225$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
			zephir_array_fetch_long(&_227$$3, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
			zephir_array_fetch_long(&_228$$3, &_227$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
			ZEPHIR_INIT_NVAR(&_44$$3);
			ZVAL_STRING(&_44$$3, "%s(?P<%s>%s)%s");
			ZEPHIR_CALL_FUNCTION(&_229$$3, "sprintf", &_29, 2, &_44$$3, &_224$$3, &_226$$3, &requirement, &_228$$3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&regexp, &_229$$3);
			zephir_array_fetch_long(&_230$$3, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
			zephir_array_fetch_long(&_231$$3, &_230$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
			_232$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_231$$3, "");
			if (!(_232$$3)) {
				zephir_array_fetch_long(&_233$$3, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
				zephir_array_fetch_long(&_234$$3, &_233$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
				_235$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_234$$3, "");
				if (_235$$3) {
					zephir_array_fetch_long(&_236$$3, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
					zephir_array_fetch_long(&_237$$3, &_236$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
					_235$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_237$$3, "");
				}
				_232$$3 = _235$$3;
			}
			if (_232$$3) {
				ZEPHIR_INIT_NVAR(&_239$$24);
				ZVAL_STRING(&_239$$24, "(?:%s)");
				ZEPHIR_CALL_FUNCTION(&_240$$24, "sprintf", &_29, 2, &_239$$24, &regexp);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&regexp, &_240$$24);
			}
			zephir_array_fetch_long(&_241$$3, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 139);
			zephir_array_fetch_long(&_242$$3, &_241$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 139);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_242$$3, "")) {
				zephir_concat_self_str(&regexp, SL("?"));
			}
			zephir_array_fetch_long(&_243$$3, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 143);
			zephir_array_fetch_long(&_244$$3, &_243$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 143);
			zephir_array_fetch_long(&_245$$3, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 143);
			zephir_array_fetch_long(&_246$$3, &_245$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 143);
			ZEPHIR_INIT_NVAR(&_247$$3);
			ZEPHIR_CONCAT_VVV(&_247$$3, &_244$$3, &regexp, &_246$$3);
			zephir_concat_self(&regex, &_247$$3);
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
				zephir_array_fetch_long(&_248$$26, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
				zephir_array_fetch_long(&_249$$26, &_248$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
				_250$$26 = !ZEPHIR_IS_STRING_IDENTICAL(&_249$$26, "");
				if (_250$$26) {
					_251$$26 = zephir_array_isset(&matches, &nextIdx);
					if (_251$$26) {
						zephir_array_fetch(&_252$$26, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
						zephir_array_fetch_long(&_253$$26, &_252$$26, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
						zephir_array_fetch_long(&_254$$26, &_253$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 53);
						_251$$26 = ZEPHIR_IS_STRING_IDENTICAL(&_254$$26, "");
					}
					_250$$26 = _251$$26;
				}
				if (_250$$26) {
					ZEPHIR_INIT_NVAR(&_255$$27);
					object_init_ex(&_255$$27, zeplara_routing_routecompilerexception_ce);
					zephir_array_fetch_long(&_257$$27, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					zephir_array_fetch_long(&_258$$27, &_257$$27, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					zephir_array_fetch_long(&_259$$27, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					zephir_array_fetch_long(&_260$$27, &_259$$27, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					ZEPHIR_INIT_NVAR(&_261$$27);
					ZEPHIR_CONCAT_VV(&_261$$27, &_258$$27, &_260$$27);
					zephir_array_fetch(&_262$$27, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					zephir_array_fetch_long(&_263$$27, &_262$$27, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					zephir_array_fetch_long(&_264$$27, &_263$$27, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 54);
					ZEPHIR_INIT_NVAR(&_265$$27);
					ZVAL_STRING(&_265$$27, "Cannot set optional pattern \"{%s}\" when the next pattern \"{%s}\" is required.");
					ZEPHIR_CALL_FUNCTION(&_266$$27, "sprintf", &_29, 2, &_265$$27, &_261$$27, &_264$$27);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_255$$27, "__construct", &_30, 66, &_266$$27);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_255$$27, "zeplara/Routing/RouteCompiler.zep", 54);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch_long(&_267$$26, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 57);
				zephir_array_fetch_long(&_268$$26, &_267$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 57);
				if (zephir_fast_strlen_ev(&_268$$26) > 32) {
					ZEPHIR_INIT_NVAR(&_269$$28);
					object_init_ex(&_269$$28, zeplara_routing_routecompilerexception_ce);
					zephir_array_fetch_long(&_271$$28, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 58);
					zephir_array_fetch_long(&_272$$28, &_271$$28, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 58);
					ZEPHIR_INIT_NVAR(&_273$$28);
					ZVAL_STRING(&_273$$28, "Variable \"%s\" is too long. maximum is %d characters.");
					ZVAL_LONG(&_274$$28, 32);
					ZEPHIR_CALL_FUNCTION(&_275$$28, "sprintf", &_29, 2, &_273$$28, &_272$$28, &_274$$28);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_269$$28, "__construct", &_30, 66, &_275$$28);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_269$$28, "zeplara/Routing/RouteCompiler.zep", 58);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_276$$26);
				zephir_array_fetch_long(&_277$$26, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 61);
				zephir_array_fetch_long(&_278$$26, &_277$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 61);
				ZEPHIR_INIT_NVAR(&_279$$26);
				ZVAL_STRING(&_279$$26, "/^\\d/");
				ZEPHIR_INIT_NVAR(&_280$$26);
				ZEPHIR_INIT_NVAR(&_281$$26);
				ZVAL_STRING(&_281$$26, "/^\\d/");
				zephir_preg_match(&_280$$26, &_281$$26, &_278$$26, &_276$$26, 0, 0 , 0 );
				if (zephir_get_boolval(&_280$$26) == 1) {
					ZEPHIR_INIT_NVAR(&_282$$29);
					object_init_ex(&_282$$29, zeplara_routing_routecompilerexception_ce);
					zephir_array_fetch_long(&_284$$29, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 62);
					zephir_array_fetch_long(&_285$$29, &_284$$29, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 62);
					ZEPHIR_INIT_NVAR(&_286$$29);
					ZVAL_STRING(&_286$$29, "Variable \"%s\" cannot start with digit.");
					ZEPHIR_CALL_FUNCTION(&_287$$29, "sprintf", &_29, 2, &_286$$29, &_285$$29);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_282$$29, "__construct", &_30, 66, &_287$$29);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_282$$29, "zeplara/Routing/RouteCompiler.zep", 62);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch_long(&_288$$26, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 65);
				zephir_array_fetch_long(&_289$$26, &_288$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 65);
				if (zephir_fast_in_array(&_289$$26, &variables) == 1) {
					ZEPHIR_INIT_NVAR(&_290$$30);
					object_init_ex(&_290$$30, zeplara_routing_routecompilerexception_ce);
					zephir_array_fetch_long(&_292$$30, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 66);
					zephir_array_fetch_long(&_293$$30, &_292$$30, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 66);
					ZEPHIR_INIT_NVAR(&_294$$30);
					ZVAL_STRING(&_294$$30, "Variable \"%s\" must be unique.");
					ZEPHIR_CALL_FUNCTION(&_295$$30, "sprintf", &_29, 2, &_294$$30, &_293$$30);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_290$$30, "__construct", &_30, 66, &_295$$30);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_290$$30, "zeplara/Routing/RouteCompiler.zep", 66);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch_long(&_296$$26, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 69);
				zephir_array_fetch_long(&_297$$26, &_296$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 69);
				zephir_array_append(&variables, &_297$$26, PH_SEPARATE, "zeplara/Routing/RouteCompiler.zep", 69);
				zephir_array_fetch_long(&_298$$26, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 71);
				zephir_array_fetch_long(&_299$$26, &_298$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 71);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_299$$26, "")) {
					zephir_array_fetch_long(&_300$$31, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 72);
					zephir_array_fetch_long(&_301$$31, &_300$$31, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 72);
					ZEPHIR_CALL_FUNCTION(&_302$$31, "preg_quote", &_1, 161, &_301$$31);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_302$$31, SL("ll"), 2, 1, 0);
				}
				zephir_array_fetch_long(&_303$$26, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 75);
				zephir_array_fetch_long(&_304$$26, &_303$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 75);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_304$$26, "")) {
					zephir_array_fetch_long(&_305$$32, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 76);
					zephir_array_fetch_long(&_306$$32, &_305$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 76);
					ZEPHIR_CALL_FUNCTION(&_307$$32, "preg_quote", &_1, 161, &_306$$32);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_307$$32, SL("ll"), 2, 2, 0);
					zephir_array_fetch_long(&_308$$32, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
					zephir_array_fetch_long(&_309$$32, &_308$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
					_310$$32 = !ZEPHIR_IS_STRING_IDENTICAL(&_309$$32, "");
					if (_310$$32) {
						zephir_array_fetch_long(&_311$$32, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						zephir_array_fetch_long(&_312$$32, &_311$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						_313$$32 = !ZEPHIR_IS_STRING_IDENTICAL(&_312$$32, "");
						if (_313$$32) {
							zephir_array_fetch_long(&_314$$32, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_315$$32, &_314$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							_313$$32 = !ZEPHIR_IS_STRING_IDENTICAL(&_315$$32, "");
						}
						_316$$32 = _313$$32;
						if (!(_316$$32)) {
							_317$$32 = zephir_array_isset(&matches, &prevIdx);
							if (_317$$32) {
								zephir_array_fetch(&_318$$32, &matches, &prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								zephir_array_fetch_long(&_319$$32, &_318$$32, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								zephir_array_fetch_long(&_320$$32, &_319$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								_317$$32 = !ZEPHIR_IS_STRING_IDENTICAL(&_320$$32, "");
							}
							_321$$32 = _317$$32;
							if (_321$$32) {
								zephir_array_fetch_long(&_322$$32, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								zephir_array_fetch_long(&_323$$32, &_322$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								_324$$32 = !ZEPHIR_IS_STRING_IDENTICAL(&_323$$32, "");
								if (!(_324$$32)) {
									_324$$32 = !ZEPHIR_IS_IDENTICAL(&i, &lastIdx);
								}
								_321$$32 = _324$$32;
							}
							_316$$32 = _321$$32;
						}
						_325$$32 = _316$$32;
						if (!(_325$$32)) {
							_326$$32 = ZEPHIR_IS_LONG_IDENTICAL(&i, 0);
							if (_326$$32) {
								_326$$32 = ZEPHIR_IS_IDENTICAL(&i, &lastIdx);
							}
							_327$$32 = _326$$32;
							if (_327$$32) {
								zephir_array_fetch_long(&_328$$32, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								zephir_array_fetch_long(&_329$$32, &_328$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								_327$$32 = !ZEPHIR_IS_STRING_IDENTICAL(&_329$$32, "");
							}
							_330$$32 = _327$$32;
							if (_330$$32) {
								zephir_array_fetch_long(&_331$$32, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								zephir_array_fetch_long(&_332$$32, &_331$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
								_330$$32 = !ZEPHIR_IS_STRING_IDENTICAL(&_332$$32, "");
							}
							_325$$32 = _330$$32;
						}
						_310$$32 = _325$$32;
					}
					_333$$32 = _310$$32;
					if (!(_333$$32)) {
						_334$$32 = ZEPHIR_IS_LONG_IDENTICAL(&i, 0);
						if (_334$$32) {
							zephir_array_fetch_long(&_335$$32, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_336$$32, &_335$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							_334$$32 = ZEPHIR_IS_STRING_IDENTICAL(&_336$$32, "");
						}
						_333$$32 = _334$$32;
					}
					_337$$32 = _333$$32;
					if (!(_337$$32)) {
						zephir_array_fetch_long(&_338$$32, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						zephir_array_fetch_long(&_339$$32, &_338$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						_340$$32 = !ZEPHIR_IS_STRING_IDENTICAL(&_339$$32, "");
						if (_340$$32) {
							_340$$32 = zephir_array_isset(&matches, &nextIdx);
						}
						_341$$32 = _340$$32;
						if (_341$$32) {
							zephir_array_fetch(&_342$$32, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_343$$32, &_342$$32, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							zephir_array_fetch_long(&_344$$32, &_343$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
							_341$$32 = ZEPHIR_IS_STRING_IDENTICAL(&_344$$32, "");
						}
						_345$$32 = _341$$32;
						if (_345$$32) {
							ZEPHIR_CALL_SELF(&_307$$32, "hasnextstaticprefixonnextmatch", &_110, 162, &nextIdx, &lastIdx, &matches);
							zephir_check_call_status();
							_345$$32 = ZEPHIR_IS_TRUE_IDENTICAL(&_307$$32);
						}
						_337$$32 = _345$$32;
					}
					_346$$32 = _337$$32;
					if (!(_346$$32)) {
						zephir_array_fetch_long(&_347$$32, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						zephir_array_fetch_long(&_348$$32, &_347$$32, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 77);
						_346$$32 = ZEPHIR_IS_STRING_IDENTICAL(&_348$$32, "");
					}
					if (_346$$32) {
						zephir_array_fetch_long(&_349$$33, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
						zephir_array_fetch_long(&_350$$33, &_349$$33, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
						zephir_array_fetch_long(&_351$$33, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
						zephir_array_fetch_long(&_352$$33, &_351$$33, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 78);
						ZEPHIR_INIT_NVAR(&_353$$33);
						ZEPHIR_CONCAT_VV(&_353$$33, &_350$$33, &_352$$33);
						zephir_array_update_multi(&match, &_353$$33, SL("ll"), 2, 1, 0);
						zephir_array_fetch_long(&_354$$33, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 79);
						zephir_array_fetch_long(&_355$$33, &_354$$33, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 79);
						ZEPHIR_CALL_FUNCTION(&_356$$33, "preg_quote", &_1, 161, &_355$$33);
						zephir_check_call_status();
						zephir_array_update_multi(&match, &_356$$33, SL("ll"), 2, 2, 2);
						ZEPHIR_INIT_NVAR(&_357$$33);
						ZVAL_STRING(&_357$$33, "");
						zephir_array_update_multi(&match, &_357$$33, SL("ll"), 2, 2, 0);
					}
				}
				zephir_array_fetch_long(&_358$$26, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 84);
				zephir_array_fetch_long(&_359$$26, &_358$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 84);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_359$$26, "")) {
					zephir_array_fetch_long(&_360$$34, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
					zephir_array_fetch_long(&_361$$34, &_360$$34, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
					_362$$34 = ZEPHIR_IS_STRING_IDENTICAL(&_361$$34, "");
					if (_362$$34) {
						_363$$34 = zephir_array_isset(&matches, &nextIdx);
						if (_363$$34) {
							zephir_array_fetch(&_364$$34, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							zephir_array_fetch_long(&_365$$34, &_364$$34, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							zephir_array_fetch_long(&_366$$34, &_365$$34, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							_363$$34 = !ZEPHIR_IS_STRING_IDENTICAL(&_366$$34, "");
						}
						_367$$34 = _363$$34;
						if (_367$$34) {
							zephir_array_fetch(&_368$$34, &matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							zephir_array_fetch_long(&_369$$34, &_368$$34, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							zephir_array_fetch_long(&_370$$34, &_369$$34, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 85);
							_367$$34 = ZEPHIR_IS_STRING_IDENTICAL(&_370$$34, "");
						}
						_371$$34 = _367$$34;
						if (_371$$34) {
							ZEPHIR_CALL_SELF(&_372$$34, "hasnextstaticprefixonnextmatch", &_110, 162, &nextIdx, &lastIdx, &matches);
							zephir_check_call_status();
							_371$$34 = ZEPHIR_IS_FALSE_IDENTICAL(&_372$$34);
						}
						_362$$34 = _371$$34;
					}
					zephir_array_fetch_long(&_373$$34, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
					zephir_array_fetch_long(&_374$$34, &_373$$34, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
					_375$$34 = !ZEPHIR_IS_STRING_IDENTICAL(&_374$$34, "");
					if (_375$$34) {
						zephir_array_fetch_long(&_376$$34, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
						zephir_array_fetch_long(&_377$$34, &_376$$34, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
						_378$$34 = ZEPHIR_IS_STRING_IDENTICAL(&_377$$34, "");
						if (_378$$34) {
							zephir_array_fetch_long(&_379$$34, &match, 2, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							_378$$34 = !(zephir_array_isset_long(&_379$$34, 2));
						}
						_380$$34 = _378$$34;
						if (_380$$34) {
							zephir_array_fetch_long(&_381$$34, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							zephir_array_fetch_long(&_382$$34, &_381$$34, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							_380$$34 = !ZEPHIR_IS_STRING_IDENTICAL(&_382$$34, "");
						}
						_383$$34 = _380$$34;
						if (_383$$34) {
							ZEPHIR_CALL_SELF(&_384$$34, "hasstaticprefixwithoutseparatoronprevmatch", &_150, 163, &prevIdx, &matches);
							zephir_check_call_status();
							_383$$34 = zephir_is_true(&_384$$34);
						}
						_385$$34 = _383$$34;
						if (!(_385$$34)) {
							zephir_array_fetch_long(&_386$$34, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							zephir_array_fetch_long(&_387$$34, &_386$$34, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
							_388$$34 = !ZEPHIR_IS_STRING_IDENTICAL(&_387$$34, "");
							if (_388$$34) {
								zephir_array_fetch_long(&_389$$34, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
								zephir_array_fetch_long(&_390$$34, &_389$$34, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
								_388$$34 = ZEPHIR_IS_STRING_IDENTICAL(&_390$$34, "");
							}
							_391$$34 = _388$$34;
							if (_391$$34) {
								zephir_array_fetch_long(&_392$$34, &match, 2, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
								_391$$34 = !(zephir_array_isset_long(&_392$$34, 2));
							}
							_393$$34 = _391$$34;
							if (_393$$34) {
								zephir_array_fetch_long(&_394$$34, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
								zephir_array_fetch_long(&_395$$34, &_394$$34, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 89);
								_393$$34 = !ZEPHIR_IS_STRING_IDENTICAL(&_395$$34, "");
							}
							_385$$34 = _393$$34;
						}
						_375$$34 = _385$$34;
					}
					if (_362$$34) {
						zephir_array_fetch_long(&_396$$35, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 86);
						zephir_array_fetch_long(&_397$$35, &_396$$35, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 86);
						zephir_array_update_multi(&matches, &_397$$35, SL("zll"), 3, &nextIdx, 2, 0);
						zephir_array_fetch_long(&_397$$35, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 87);
						zephir_array_fetch_long(&_398$$35, &_397$$35, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 87);
						ZEPHIR_CALL_FUNCTION(&_399$$35, "preg_quote", &_1, 161, &_398$$35);
						zephir_check_call_status();
						zephir_array_update_multi(&match, &_399$$35, SL("ll"), 2, 5, 2);
						ZEPHIR_INIT_NVAR(&_400$$35);
						ZVAL_STRING(&_400$$35, "");
						zephir_array_update_multi(&match, &_400$$35, SL("ll"), 2, 5, 0);
					} else if (_375$$34) {
						zephir_array_fetch_long(&_401$$36, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
						zephir_array_fetch_long(&_402$$36, &_401$$36, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
						zephir_array_fetch_long(&_403$$36, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
						zephir_array_fetch_long(&_404$$36, &_403$$36, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 90);
						ZEPHIR_INIT_NVAR(&_405$$36);
						ZEPHIR_CONCAT_VV(&_405$$36, &_402$$36, &_404$$36);
						zephir_array_update_multi(&match, &_405$$36, SL("ll"), 2, 6, 0);
						zephir_array_fetch_long(&_406$$36, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 91);
						zephir_array_fetch_long(&_407$$36, &_406$$36, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 91);
						ZEPHIR_CALL_FUNCTION(&_408$$36, "preg_quote", &_1, 161, &_407$$36);
						zephir_check_call_status();
						zephir_array_update_multi(&match, &_408$$36, SL("ll"), 2, 5, 2);
						ZEPHIR_INIT_NVAR(&_409$$36);
						ZVAL_STRING(&_409$$36, "");
						zephir_array_update_multi(&match, &_409$$36, SL("ll"), 2, 5, 0);
					} else {
						zephir_array_fetch_long(&_410$$37, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 94);
						zephir_array_fetch_long(&_411$$37, &_410$$37, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 94);
						ZEPHIR_CALL_FUNCTION(&_412$$37, "preg_quote", &_1, 161, &_411$$37);
						zephir_check_call_status();
						zephir_array_update_multi(&match, &_412$$37, SL("ll"), 2, 5, 0);
					}
				}
				zephir_array_fetch_long(&_413$$26, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 98);
				zephir_array_fetch_long(&_414$$26, &_413$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 98);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_414$$26, "")) {
					zephir_array_fetch_long(&_415$$38, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 99);
					zephir_array_fetch_long(&_416$$38, &_415$$38, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 99);
					ZEPHIR_CALL_FUNCTION(&_417$$38, "preg_quote", &_1, 161, &_416$$38);
					zephir_check_call_status();
					zephir_array_update_multi(&match, &_417$$38, SL("ll"), 2, 6, 0);
				}
				ZEPHIR_OBS_NVAR(&requirement);
				zephir_array_fetch_long(&_418$$26, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 102);
				zephir_array_fetch_long(&_419$$26, &_418$$26, 0, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 102);
				if (zephir_array_isset_fetch(&requirement, requirements, &_419$$26, 0)) {
					ZVAL_LONG(&_420$$39, 0);
					ZVAL_LONG(&_421$$39, 1);
					ZEPHIR_INIT_NVAR(&_422$$39);
					zephir_substr(&_422$$39, &requirement, 0 , 1 , 0);
					if (ZEPHIR_IS_STRING(&_422$$39, "^")) {
						ZVAL_LONG(&_423$$40, 1);
						ZEPHIR_INIT_NVAR(&_424$$40);
						zephir_substr(&_424$$40, &requirement, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
						zephir_get_strval(&_425$$40, &_424$$40);
						ZEPHIR_CPY_WRT(&requirement, &_425$$40);
					}
					ZVAL_LONG(&_426$$39, -1);
					ZEPHIR_INIT_NVAR(&_427$$39);
					zephir_substr(&_427$$39, &requirement, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					if (ZEPHIR_IS_STRING(&_427$$39, "$")) {
						ZVAL_LONG(&_428$$41, 0);
						ZVAL_LONG(&_429$$41, -1);
						ZEPHIR_INIT_NVAR(&_430$$41);
						zephir_substr(&_430$$41, &requirement, 0 , -1 , 0);
						zephir_get_strval(&_431$$41, &_430$$41);
						ZEPHIR_CPY_WRT(&requirement, &_431$$41);
					}
					do {
						ZEPHIR_INIT_NVAR(&_432$$42);
						ZEPHIR_INIT_NVAR(&_432$$42);
						zephir_create_closure_ex(&_432$$42, NULL, zeplara_6__closure_ce, SL("__invoke"));
						ZEPHIR_INIT_NVAR(&_433$$42);
						ZVAL_STRING(&_433$$42, "#\\(((?!\\?\\:|\\*\\)|\\+\\)|\\?\\)).+)\\)#");
						ZVAL_LONG(&_434$$42, -1);
						ZEPHIR_MAKE_REF(&count$$39);
						ZEPHIR_CALL_FUNCTION(&_435$$42, "preg_replace_callback", &_202, 42, &_433$$42, &_432$$42, &requirement, &_434$$42, &count$$39);
						ZEPHIR_UNREF(&count$$39);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&requirement, &_435$$42);
					} while (zephir_is_true(&count$$39));
				} else {
					zephir_array_fetch_long(&_436$$43, &match, 5, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
					if (zephir_array_isset_long(&_436$$43, 2)) {
						zephir_array_fetch_long(&_437$$43, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
						ZEPHIR_OBS_NVAR(&nextSeparatorOfRequirement);
						zephir_array_fetch_long(&nextSeparatorOfRequirement, &_437$$43, 2, PH_NOISY, "zeplara/Routing/RouteCompiler.zep", 119);
					} else {
						zephir_array_fetch_long(&_438$$43, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 119);
						ZEPHIR_OBS_NVAR(&nextSeparatorOfRequirement);
						zephir_array_fetch_long(&nextSeparatorOfRequirement, &_438$$43, 0, PH_NOISY, "zeplara/Routing/RouteCompiler.zep", 119);
					}
					ZEPHIR_INIT_NVAR(&_439$$43);
					zephir_fast_strpos(&_439$$43, &nextSeparatorOfRequirement, separator, 0 );
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_439$$43)) {
						ZEPHIR_INIT_NVAR(&_440$$44);
						ZEPHIR_CONCAT_VV(&_440$$44, separator, &nextSeparatorOfRequirement);
						ZEPHIR_CPY_WRT(&nextSeparatorOfRequirement, &_440$$44);
					} else {
						ZEPHIR_INIT_NVAR(&_441$$45);
						ZEPHIR_CONCAT_VV(&_441$$45, separator, &nextSeparatorOfRequirement);
						ZEPHIR_CALL_FUNCTION(&_442$$45, "str_split", &_210, 97, &_441$$45);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_443$$45, "array_unique", &_212, 150, &_442$$45);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&nextSeparatorOfRequirement);
						zephir_fast_join_str(&nextSeparatorOfRequirement, SL(""), &_443$$45);
					}
					ZEPHIR_INIT_NVAR(&_444$$43);
					ZVAL_STRING(&_444$$43, "[^%s]+");
					ZEPHIR_CALL_FUNCTION(&_445$$43, "sprintf", &_29, 2, &_444$$43, &nextSeparatorOfRequirement);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&requirement, &_445$$43);
					zephir_array_fetch_long(&_446$$43, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 128);
					zephir_array_fetch_long(&_447$$43, &_446$$43, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 128);
					_448$$43 = !ZEPHIR_IS_STRING_IDENTICAL(&_447$$43, "");
					if (!(_448$$43)) {
						zephir_array_fetch_long(&_449$$43, &match, 5, PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 128);
						_448$$43 = zephir_array_isset_long(&_449$$43, 2) == 1;
					}
					_450$$43 = _448$$43;
					if (!(_450$$43)) {
						_451$$43 = ZEPHIR_IS_IDENTICAL(&i, &lastIdx);
						if (_451$$43) {
							zephir_array_fetch_long(&_452$$43, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 128);
							zephir_array_fetch_long(&_453$$43, &_452$$43, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 128);
							_451$$43 = ZEPHIR_IS_STRING_IDENTICAL(&_453$$43, "");
						}
						_450$$43 = _451$$43;
					}
					if (_450$$43) {
						zephir_concat_self_str(&requirement, SL("+"));
					}
				}
				zephir_array_fetch_long(&_454$$26, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
				zephir_array_fetch_long(&_455$$26, &_454$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
				zephir_array_fetch_long(&_456$$26, &match, 3, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
				zephir_array_fetch_long(&_457$$26, &_456$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
				zephir_array_fetch_long(&_458$$26, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
				zephir_array_fetch_long(&_459$$26, &_458$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 133);
				ZEPHIR_INIT_NVAR(&_280$$26);
				ZVAL_STRING(&_280$$26, "%s(?P<%s>%s)%s");
				ZEPHIR_CALL_FUNCTION(&_460$$26, "sprintf", &_29, 2, &_280$$26, &_455$$26, &_457$$26, &requirement, &_459$$26);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&regexp, &_460$$26);
				zephir_array_fetch_long(&_461$$26, &match, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
				zephir_array_fetch_long(&_462$$26, &_461$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
				_463$$26 = !ZEPHIR_IS_STRING_IDENTICAL(&_462$$26, "");
				if (!(_463$$26)) {
					zephir_array_fetch_long(&_464$$26, &match, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
					zephir_array_fetch_long(&_465$$26, &_464$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
					_466$$26 = !ZEPHIR_IS_STRING_IDENTICAL(&_465$$26, "");
					if (_466$$26) {
						zephir_array_fetch_long(&_467$$26, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
						zephir_array_fetch_long(&_468$$26, &_467$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 135);
						_466$$26 = !ZEPHIR_IS_STRING_IDENTICAL(&_468$$26, "");
					}
					_463$$26 = _466$$26;
				}
				if (_463$$26) {
					ZEPHIR_INIT_NVAR(&_470$$47);
					ZVAL_STRING(&_470$$47, "(?:%s)");
					ZEPHIR_CALL_FUNCTION(&_471$$47, "sprintf", &_29, 2, &_470$$47, &regexp);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&regexp, &_471$$47);
				}
				zephir_array_fetch_long(&_472$$26, &match, 4, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 139);
				zephir_array_fetch_long(&_473$$26, &_472$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 139);
				if (!ZEPHIR_IS_STRING_IDENTICAL(&_473$$26, "")) {
					zephir_concat_self_str(&regexp, SL("?"));
				}
				zephir_array_fetch_long(&_474$$26, &match, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 143);
				zephir_array_fetch_long(&_475$$26, &_474$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 143);
				zephir_array_fetch_long(&_476$$26, &match, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 143);
				zephir_array_fetch_long(&_477$$26, &_476$$26, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 143);
				ZEPHIR_INIT_NVAR(&_478$$26);
				ZEPHIR_CONCAT_VVV(&_478$$26, &_475$$26, &regexp, &_477$$26);
				zephir_concat_self(&regex, &_478$$26);
			ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&match);
	ZEPHIR_INIT_NVAR(&i);
	if (ZEPHIR_IS_STRING_IDENTICAL(&regex, "")) {
		ZEPHIR_CALL_FUNCTION(&regex, "preg_quote", &_1, 161, pattern);
		zephir_check_call_status();
	}
	object_init_ex(return_value, zeplara_routing_regex_ce);
	ZEPHIR_INIT_VAR(&_480);
	ZVAL_STRING(&_480, "{^%s$}%s");
	ZEPHIR_CALL_FUNCTION(&_481, "sprintf", &_29, 2, &_480, &regex, flags);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 164, &_481, &variables);
	zephir_check_call_status();
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
		zephir_array_fetch(&_0$$3, matches, nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 162);
		zephir_array_fetch_long(&_1$$3, &_0$$3, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 162);
		zephir_array_fetch_long(&_2$$3, &_1$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 162);
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
		zephir_array_fetch(&_0$$3, matches, prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
		zephir_array_fetch_long(&_1$$3, &_0$$3, 1, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
		zephir_array_fetch_long(&_2$$3, &_1$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
		_3$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_2$$3, "");
		if (_3$$3) {
			zephir_array_fetch(&_4$$3, matches, prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
			zephir_array_fetch_long(&_5$$3, &_4$$3, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
			zephir_array_fetch_long(&_6$$3, &_5$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
			_3$$3 = ZEPHIR_IS_STRING_IDENTICAL(&_6$$3, "");
		}
		_7$$3 = _3$$3;
		if (_7$$3) {
			zephir_array_fetch(&_8$$3, matches, prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
			zephir_array_fetch_long(&_9$$3, &_8$$3, 5, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
			zephir_array_fetch_long(&_10$$3, &_9$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
			_11$$3 = ZEPHIR_IS_STRING_IDENTICAL(&_10$$3, "");
			if (!(_11$$3)) {
				zephir_array_fetch(&_12$$3, matches, prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
				zephir_array_fetch_long(&_13$$3, &_12$$3, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
				zephir_array_fetch_long(&_14$$3, &_13$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
				_11$$3 = ZEPHIR_IS_STRING_IDENTICAL(&_14$$3, "");
			}
			_7$$3 = _11$$3;
		}
		_15$$3 = _7$$3;
		if (!(_15$$3)) {
			zephir_array_fetch(&_16$$3, matches, prevIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
			zephir_array_fetch_long(&_17$$3, &_16$$3, 6, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
			zephir_array_fetch_long(&_18$$3, &_17$$3, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 184);
			_15$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&_18$$3, "");
		}
		if (_15$$3) {
			ZEPHIR_INIT_NVAR(&nextIdx);
			ZVAL_LONG(&nextIdx, (zephir_get_numberval(prevIdx) + 1));
			while (1) {
				if (!(ZEPHIR_LE(&nextIdx, &lastIdx))) {
					break;
				}
				zephir_array_fetch(&_19$$5, matches, &nextIdx, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 189);
				zephir_array_fetch_long(&_20$$5, &_19$$5, 2, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 189);
				zephir_array_fetch_long(&_21$$5, &_20$$5, 0, PH_NOISY | PH_READONLY, "zeplara/Routing/RouteCompiler.zep", 189);
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

