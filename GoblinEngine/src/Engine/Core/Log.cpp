#include "pch.h"

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace GoblinEngine
{
	std::shared_ptr<spdlog::logger> Log::_coreLogger;
	std::shared_ptr<spdlog::logger> Log::_clientogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v");
		_coreLogger = spdlog::stdout_color_mt("GoblinEngine");
		_coreLogger->set_level(spdlog::level::trace);
		_clientogger = spdlog::stdout_color_mt("App");
		_clientogger->set_level(spdlog::level::trace);
	}
}