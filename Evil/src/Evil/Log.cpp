#include "evilpch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Evil
{
	std::shared_ptr<spdlog::logger> Log::ptr_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::ptr_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		ptr_CoreLogger = spdlog::stdout_color_mt("Evil");
		ptr_CoreLogger->set_level(spdlog::level::trace);
		ptr_ClientLogger = spdlog::stdout_color_mt("APP");
		ptr_ClientLogger->set_level(spdlog::level::trace);
	}

}