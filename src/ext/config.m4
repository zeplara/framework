PHP_ARG_ENABLE(zeplara, whether to enable zeplara, [ --enable-zeplara   Enable Zeplara])

if test "$PHP_ZEPLARA" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, ZEPLARA_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_ZEPLARA, 1, [Whether you have Zeplara])
	zeplara_sources="zeplara.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c zeplara/contracts/routing/attribute.zep.c
	zeplara/support/file/finder/abstractfilter.zep.c
	zeplara/contracts/config/loader.zep.c
	zeplara/contracts/repository.zep.c
	zeplara/http/abstractmessage.zep.c
	zeplara/routing/attribute.zep.c
	zeplara/support/repository.zep.c
	zeplara/contracts/container/container.zep.c
	zeplara/container/containerexception.zep.c
	zeplara/contracts/config/loaderexception.zep.c
	zeplara/contracts/config/repository.zep.c
	zeplara/contracts/container/bindingresolutionexception.zep.c
	zeplara/contracts/container/invalidabstractexception.zep.c
	zeplara/contracts/cookie/cookie.zep.c
	zeplara/contracts/cookie/queue.zep.c
	zeplara/contracts/encryption/encrypter.zep.c
	zeplara/contracts/encryption/encryptionexception.zep.c
	zeplara/contracts/pipeline/pipeline.zep.c
	zeplara/contracts/routing/compiledroute.zep.c
	zeplara/contracts/routing/group.zep.c
	zeplara/contracts/routing/regex.zep.c
	zeplara/contracts/routing/registrar.zep.c
	zeplara/contracts/routing/route.zep.c
	zeplara/contracts/routing/routecompiler.zep.c
	zeplara/contracts/routing/routecompilerexception.zep.c
	zeplara/contracts/routing/router.zep.c
	zeplara/contracts/session/manager.zep.c
	zeplara/http/request.zep.c
	zeplara/support/file/parser/abstractparser.zep.c
	zeplara/config/envloader.zep.c
	zeplara/config/iniloader.zep.c
	zeplara/config/jsonloader.zep.c
	zeplara/config/loaderexception.zep.c
	zeplara/config/phploader.zep.c
	zeplara/config/repository.zep.c
	zeplara/config/xmlloader.zep.c
	zeplara/container/bindingresolutionexception.zep.c
	zeplara/container/container.zep.c
	zeplara/container/invalidabstractexception.zep.c
	zeplara/contracts/application.zep.c
	zeplara/contracts/session/flash.zep.c
	zeplara/cookie/cookie.zep.c
	zeplara/cookie/factory.zep.c
	zeplara/cookie/queue.zep.c
	zeplara/encryption/encrypter.zep.c
	zeplara/encryption/encryptionexception.zep.c
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
	zeplara/support/facades/facade.zep.c
	zeplara/support/file/finder/callbackfilter.zep.c
	zeplara/support/file/finder/datefilter.zep.c
	zeplara/support/file/finder/directoryfilter.zep.c
	zeplara/support/file/finder/executablefilter.zep.c
	zeplara/support/file/finder/fileextensionfilter.zep.c
	zeplara/support/file/finder/filefilter.zep.c
	zeplara/support/file/finder/filefinder.zep.c
	zeplara/support/file/finder/filterfactory.zep.c
	zeplara/support/file/finder/ignoredotfilefilter.zep.c
	zeplara/support/file/finder/iterator.zep.c
	zeplara/support/file/finder/linkfilter.zep.c
	zeplara/support/file/finder/readablefilter.zep.c
	zeplara/support/file/finder/writablefilter.zep.c
	zeplara/support/file/parser/compiledvalue.zep.c
	zeplara/support/file/parser/envparser.zep.c
	zeplara/support/file/parser/linesiterator.zep.c
	zeplara/support/file/parser/parserexception.zep.c
	zeplara/support/file/parser/rawvalue.zep.c
	zeplara/support/file/splfileinfo.zep.c
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
