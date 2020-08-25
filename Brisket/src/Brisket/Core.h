#pragma once

#ifdef BK_PLATFORM_WINDOWS
	#ifdef BK_BUILD_DLL
		#define BRISKET_API __declspec(dllexport)
	#else
		#define BRISKET_API __declspec(dllimport)
	#endif
#else
	#error Brisket only supports the right OP, Windows!
#endif

#ifdef BK_ENABLE_ASSERTS
	#define BK_ASSERT(x, ...) {if(!(x)) {BK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define BK_CORE_ASSERT(x, ...) {if(!(x)) {BK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define BK_ASSERT(x, ...)
	#define BK_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)