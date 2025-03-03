#pragma once

#ifdef SP_PLATFORM_WINDOWS

	#ifdef SP_BUILD_DLL
		#define SAIPH_API __declspec(dllexport)

	#else
		#define SAIPH_API __declspec(dllimport)

	#endif

#else
	#error Saiph only supports windows

#endif

#ifdef SP_ENABLE_ASSERTS
	#define SP_ASSERT (x, ...) { if (!(x)) {SP_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SP_CORE_ASSERT (x, ...) { if (!(x)) {SP_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }

#else 
	#define SP_ASSET(x, ...)
	#define SP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SP_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)