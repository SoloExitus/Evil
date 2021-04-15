#pragma once

#include "Evil/Core/Base.h"
#include "Evil/Core/Log.h"
#include <filesystem>

#ifdef EVIL_ENABLE_ASSERTS
	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define EVIL_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { EVIL##type##ERROR(msg, __VA_ARGS__); EVIL_DEBUGBREAK(); } }
	#define EVIL_INTERNAL_ASSERT_WITH_MSG(type, check, ...) EVIL_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define EVIL_INTERNAL_ASSERT_NO_MSG(type, check) EVIL_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", EVIL_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define EVIL_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define EVIL_INTERNAL_ASSERT_GET_MACRO(...) EVIL_EXPAND_MACRO( EVIL_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, EVIL_INTERNAL_ASSERT_WITH_MSG, EVIL_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define EVIL_ASSERT(...) EVIL_EXPAND_MACRO( EVIL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define EVIL_CORE_ASSERT(...) EVIL_EXPAND_MACRO( EVIL_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define EVIL_ASSERT(...)
	#define EVIL_CORE_ASSERT(...)
#endif
