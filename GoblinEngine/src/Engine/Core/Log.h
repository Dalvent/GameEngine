#pragma once

#include "spdlog/spdlog.h"
#include "Engine/Core/Base.h"

namespace GoblinEngine
{
	class ENGINE_API Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _coreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _clientogger; }
	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientogger;
	};
}

// Core log macros.
#define GE_CORE_TRACE(...)  ::GoblinEngine::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define GE_CORE_INFO(...)   ::GoblinEngine::Log::GetCoreLogger()->info(__VA_ARGS__);
#define GE_CORE_WARN(...)   ::GoblinEngine::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define GE_CORE_ERROR(...)  ::GoblinEngine::Log::GetCoreLogger()->error(__VA_ARGS__);
#define GE_CORE_FATAL(...)  ::GoblinEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__);
// Client log macros.
#define GE_TRACE(...)		::GoblinEngine::Log::GetClientLogger()->trace(__VA_ARGS__);
#define GE_INFO(...)		::GoblinEngine::Log::GetClientLogger()->info(__VA_ARGS__);
#define GE_WARN(...)		::GoblinEngine::Log::GetClientLogger()->warn(__VA_ARGS__);
#define GE_ERROR(...)		::GoblinEngine::Log::GetClientLogger()->error(__VA_ARGS__);
#define GE_FATAL(...)		::GoblinEngine::Log::GetClientLogger()->fatal(__VA_ARGS__);