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

#ifdef EVIL_ENABLE_ASSERTS
	#define EVIL_ASSERT(x, ...) { if(!(x)){ EVIL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak()}; } }
	#define EVIL_CORE_ASSERT(x, ...) { if(!(x)){ EVIL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak()}; } }
#else
	#define EVIL_ASSERT(x, ...)
	#define EVIL_CORE_ASSERT(x, ...)
#endif //EVIL_ENABLE_ASSERTS

#define BIT(x) (1 << x)

#define EVIL_BIND_EVENT_FN(fn)  std::bind(&fn, this, std::placeholders::_1)