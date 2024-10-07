#pragma once

#ifdef NN_PLATFORM_WINDOWS
#if NN_DYNAMIC_LINK
	#ifdef NN_BUILD_DLL
		#define NNUTS_API __declspec(dllexport)
	#else
		#define NNUTS_API __declspec(dllimport)
	#endif
#else
	#define NNUTS_API
#endif
#else
	#error Nnuts only for Windows at the moment!
#endif

#ifdef NN_DEBUG
	#define NN_ENABLE_ASSERTS
#endif

#ifdef NN_ENABLE_ASSERTS
	#define NN_ASSERT(x, ...) { if (!(x)) { NN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define NN_CORE_ASSERT(x, ...) { if (!(x)) { NN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NN_ASSERT(x, ...)
	#define NN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define NN_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)