#pragma once

#include "spdlog/spdlog.h"
#include "IronCat/Core/Base.h"

namespace IronCat
{
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger> GetCoreLogger() { return _coreLogger; }
		static Ref<spdlog::logger> GetClientLogger() { return _clientogger; }
	private:
		static Ref<spdlog::logger> _coreLogger;
		static Ref<spdlog::logger> _clientogger;
	};
}

// Core log macros.
#define IC_LOG_CORE_TRACE(...)  ::IronCat::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define IC_LOG_CORE_INFO(...)   ::IronCat::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IC_LOG_CORE_WARN(...)   ::IronCat::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IC_LOG_CORE_ERROR(...)  ::IronCat::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IC_LOG_CORE_FATAL(...)  ::IronCat::Log::GetCoreLogger()->fatal(__VA_ARGS__)
// Client log macros.
#define IC_LOG_TRACE(...)		::IronCat::Log::GetClientLogger()->trace(__VA_ARGS__)
#define IC_LOG_INFO(...)		::IronCat::Log::GetClientLogger()->info(__VA_ARGS__)
#define IC_LOG_WARN(...)		::IronCat::Log::GetClientLogger()->warn(__VA_ARGS__)
#define IC_LOG_ERROR(...)		::IronCat::Log::GetClientLogger()->error(__VA_ARGS__)
#define IC_LOG_FATAL(...)		::IronCat::Log::GetClientLogger()->fatal(__VA_ARGS__)
