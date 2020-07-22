#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace GoblinEngine
{
	class ENGINE_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_Clientogger;
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_Clientogger; }
	};
}

// Core log macros.
#define GE_CORE_TRACE(...)   ::GoblinEngine::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define GE_CORE_INFO(...)    ::GoblinEngine::Log::GetCoreLogger()->info(__VA_ARGS__);
#define GE_CORE_WARN(...)    ::GoblinEngine::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define GE_CORE_ERROR(...)   ::GoblinEngine::Log::GetCoreLogger()->error(__VA_ARGS__);
#define GE_CORE_FATAL(...)   ::GoblinEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__);
// Client log macros.
#define GE_TRACE(...)		 ::GoblinEngine::Log::GetClientLogger()->trace(__VA_ARGS__);
#define GE_INFO(...)		 ::GoblinEngine::Log::GetClientLogger()->info(__VA_ARGS__);
#define GE_WARN(...)		 ::GoblinEngine::Log::GetClientLogger()->warn(__VA_ARGS__);
#define GE_ERROR(...)		 ::GoblinEngine::Log::GetClientLogger()->error(__VA_ARGS__);
#define GE_FATAL(...)		 ::GoblinEngine::Log::GetClientLogger()->fatal(__VA_ARGS__);