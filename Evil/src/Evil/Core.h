#pragma once

#ifdef EVIL_PLATFORM_WINDOWS
	#ifdef EVIL_BUILD_DLL
		#define EVIL_API __declspec(dllexport)
	#else
		#define EVIL_API __declspec(dllimport)
	#endif //EVIL_BUILD_DLL
#else
	#error Evil Engine only supports Windows!
#endif //EVIL_PLATFORM_WINDOWS

#define BIT(x) (1 << x)