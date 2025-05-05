#pragma once

#ifdef PX_PLATFORM_WINDOWS
	#ifdef PX_BUILD_DLL
		#define PIXELYN_API __declspec(dllexport)
	#else
		#define PIXELYN_API __declspec(dllimport)
	#endif
#else
	#error Pixelyn only supports Windows!
#endif

#define BIT(x) (1 << x)
