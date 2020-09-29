#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Evil
{
	class EVIL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return ptr_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ptr_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> ptr_CoreLogger;
		static std::shared_ptr<spdlog::logger> ptr_ClientLogger;
	};
}

// Core log macros
#define EVIL_CORE_TRACE(...)	::Evil::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define EVIL_CORE_INFO(...)		::Evil::Log::GetCoreLogger()->info(__VA_ARGS__);
#define EVIL_CORE_WARN(...)		::Evil::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define EVIL_CORE_ERROR(...)	::Evil::Log::GetCoreLogger()->error(__VA_ARGS__);
#define EVIL_CORE_FATAL(...)	::Evil::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// Client log macros

#define EVIL_TRACE(...)		::Evil::Log::GetClientLogger()->trace(__VA_ARGS__);
#define EVIL_INFO(...)		::Evil::Log::GetClientLogger()->info(__VA_ARGS__);
#define EVIL_WARN(...)		::Evil::Log::GetClientLogger()->warn(__VA_ARGS__);
#define EVIL_ERROR(...)		::Evil::Log::GetClientLogger()->error(__VA_ARGS__);
#define EVIL_FATAL(...)		::Evil::Log::GetClientLogger()->fatal(__VA_ARGS__);
