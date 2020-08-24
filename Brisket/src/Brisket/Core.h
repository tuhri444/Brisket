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

#define BIT(x) (1 << x)