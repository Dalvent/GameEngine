#include "pch.h"

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace GoblinEngine
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_Clientogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v");
		s_CoreLogger = spdlog::stdout_color_mt("GoblinEngine");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_Clientogger = spdlog::stdout_color_mt("App");
		s_Clientogger->set_level(spdlog::level::trace);
	}
}