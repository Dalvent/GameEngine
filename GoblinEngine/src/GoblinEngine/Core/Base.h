#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_USE_DLL
		#ifdef GE_BUILD_DLL
			#define ENGINE_API _declspec(dllexport)
		#else
			#define ENGINE_API _declspec(dllimport)
		#endif
	#else
		#define ENGINE_API 
	#endif
#else
	#error Engine only support Windows!
#endif

#ifdef GE_ENABLE_ASSERTS
	#define GE_LOG_ASSERT(x, ...) { if(!(x)) { GE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GE_LOG_CORE_ASSERT(x, ...) { if(!(x)) { GE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GE_LOG_ASSERT(x, ...)
	#define GE_LOG_CORE_ASSERT(x, ...)
#endif

#define GE_BIT(x) (1 << x)

#define GE_BIND_EVENT(eventFunction) std::bind(&eventFunction, this, std::placeholders::_1)