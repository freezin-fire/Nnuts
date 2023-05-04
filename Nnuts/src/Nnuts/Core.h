#pragma once

#ifdef NN_PLATFORM_WINDOWS
	#ifdef NN_BUILD_DLL
		#define NNUTS_API __declspec(dllexport)
	#else
		#define NNUTS_API __declspec(dllimport)
	#endif
#else
	#error Nnuts only for Windows at the moment!
#endif

#define BIT(x) (1 << x)