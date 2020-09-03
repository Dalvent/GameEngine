#pragma once

#include <memory>

#ifdef IC_PLATFORM_WINDOWS
	#ifdef IC_USE_DLL
		#ifdef IC_BUILD_DLL
			#define IRONCAT_API _declspec(dllexport)
		#else
			#define IRONCAT_API _declspec(dllimport)
		#endif
	#else
		#define IRONCAT_API 
	#endif
#else
	#error Engine only support Windows!
#endif

#ifdef IC_ENABLE_ASSERTS
	#define IC_LOG_CORE_ASSERT(x, ...) if(!(x)) { IC_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }
	#define IC_LOG_CORE_ASSERT(x, ...) if(!(x)) { IC_LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }
#else
	#define IC_LOG_CORE_ASSERT(x, ...)
	#define IC_LOG_CORE_ASSERT(x, ...)
#endif

#define IC_BIT(x) (1 << x)

#define IC_BIND_EVENT(eventFunction) std::bind(&eventFunction, this, std::placeholders::_1)

namespace IronCat
{
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
}