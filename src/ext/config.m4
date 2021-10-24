PHP_ARG_ENABLE(zeplara, whether to enable zeplara, [ --enable-zeplara   Enable Zeplara])

if test "$PHP_ZEPLARA" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, ZEPLARA_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_ZEPLARA, 1, [Whether you have Zeplara])
	zeplara_sources="zeplara.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c zeplara/interfaces/file/finder/filter.zep.c
	zeplara/interfaces/routing/attribute.zep.c
	zeplara/interfaces/config/loader.zep.c
	zeplara/interfaces/repository.zep.c
	zeplara/http/abstractmessage.zep.c
	zeplara/routing/abstractattribute.zep.c
	zeplara/support/abstractrepository.zep.c
	zeplara/interfaces/container/container.zep.c
	zeplara/interfaces/file/parser/parser.zep.c
	zeplara/container/containerexception.zep.c
	zeplara/file/parser/abstractparser.zep.c
	zeplara/http/request.zep.c
	zeplara/interfaces/config/loaderexception.zep.c
	zeplara/interfaces/config/repository.zep.c
	zeplara/interfaces/container/bindingresolutionexception.zep.c
	zeplara/interfaces/container/invalidabstractexception.zep.c
	zeplara/interfaces/cookie/cookie.zep.c
	zeplara/interfaces/cookie/queue.zep.c
	zeplara/interfaces/encryption/encrypter.zep.c
	zeplara/interfaces/encryption/encryptionexception.zep.c
	zeplara/interfaces/file/finder/finder.zep.c
	zeplara/interfaces/file/finder/iterator.zep.c
	zeplara/interfaces/file/parser/compiledvalue.zep.c
	zeplara/interfaces/file/parser/linesiterator.zep.c
	zeplara/interfaces/file/parser/parserexception.zep.c
	zeplara/interfaces/file/parser/rawvalue.zep.c
	zeplara/interfaces/file/splfileinfo.zep.c
	zeplara/interfaces/pipeline/pipeline.zep.c
	zeplara/interfaces/routing/compiledroute.zep.c
	zeplara/interfaces/routing/group.zep.c
	zeplara/interfaces/routing/regex.zep.c
	zeplara/interfaces/routing/registrar.zep.c
	zeplara/interfaces/routing/route.zep.c
	zeplara/interfaces/routing/routecompiler.zep.c
	zeplara/interfaces/routing/routecompilerexception.zep.c
	zeplara/interfaces/routing/router.zep.c
	zeplara/interfaces/session/manager.zep.c
	zeplara/config/envloader.zep.c
	zeplara/config/iniloader.zep.c
	zeplara/config/jsonloader.zep.c
	zeplara/config/loaderexception.zep.c
	zeplara/config/phploader.zep.c
	zeplara/config/repository.zep.c
	zeplara/config/xmlloader.zep.c
	zeplara/config/yamlloader.zep.c
	zeplara/container/bindingresolutionexception.zep.c
	zeplara/container/container.zep.c
	zeplara/container/invalidabstractexception.zep.c
	zeplara/cookie/cookie.zep.c
	zeplara/cookie/factory.zep.c
	zeplara/cookie/queue.zep.c
	zeplara/encryption/encrypter.zep.c
	zeplara/encryption/encryptionexception.zep.c
	zeplara/file/finder/callbackfilter.zep.c
	zeplara/file/finder/datefilter.zep.c
	zeplara/file/finder/directoryfilter.zep.c
	zeplara/file/finder/executablefilter.zep.c
	zeplara/file/finder/fileextensionfilter.zep.c
	zeplara/file/finder/filefilter.zep.c
	zeplara/file/finder/filterfactory.zep.c
	zeplara/file/finder/finder.zep.c
	zeplara/file/finder/ignoredotfilefilter.zep.c
	zeplara/file/finder/iterator.zep.c
	zeplara/file/finder/linkfilter.zep.c
	zeplara/file/finder/readablefilter.zep.c
	zeplara/file/finder/writablefilter.zep.c
	zeplara/file/parser/compiledvalue.zep.c
	zeplara/file/parser/envparser.zep.c
	zeplara/file/parser/linesiterator.zep.c
	zeplara/file/parser/parserexception.zep.c
	zeplara/file/parser/rawvalue.zep.c
	zeplara/file/splfileinfo.zep.c
	zeplara/http/requestfactory.zep.c
	zeplara/http/response.zep.c
	zeplara/http/responsefactory.zep.c
	zeplara/http/serverrequest.zep.c
	zeplara/http/serverrequestfactory.zep.c
	zeplara/http/stream.zep.c
	zeplara/http/streamfactory.zep.c
	zeplara/http/uploadedfile.zep.c
	zeplara/http/uploadedfilefactory.zep.c
	zeplara/http/uri.zep.c
	zeplara/http/urifactory.zep.c
	zeplara/interfaces/application.zep.c
	zeplara/interfaces/session/flash.zep.c
	zeplara/pipeline/carry.zep.c
	zeplara/pipeline/pipeline.zep.c
	zeplara/routing/compiledroute.zep.c
	zeplara/routing/group.zep.c
	zeplara/routing/regex.zep.c
	zeplara/routing/registrar.zep.c
	zeplara/routing/route.zep.c
	zeplara/routing/routecompiler.zep.c
	zeplara/routing/routecompilerexception.zep.c
	zeplara/routing/router.zep.c
	zeplara/session/cookiesessionhandler.zep.c
	zeplara/session/filesessionhandler.zep.c
	zeplara/session/flash.zep.c
	zeplara/session/manager.zep.c
	zeplara/support/arr.zep.c
	zeplara/support/facades/abstractfacade.zep.c
	zeplara/support/str.zep.c
	zeplara/0__closure.zep.c
	zeplara/1__closure.zep.c
	zeplara/2__closure.zep.c
	zeplara/3__closure.zep.c
	zeplara/4__closure.zep.c
	zeplara/5__closure.zep.c
	zeplara/6__closure.zep.c
	zeplara/7__closure.zep.c
	zeplara/8__closure.zep.c
	zeplara/9__closure.zep.c "
	PHP_NEW_EXTENSION(zeplara, $zeplara_sources, $ext_shared,, )
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	PHP_ADD_BUILD_DIR([$ext_builddir/zeplara/])
	PHP_SUBST(ZEPLARA_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([zeplara], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([zeplara], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/zeplara], [php_ZEPLARA.h])

fi
