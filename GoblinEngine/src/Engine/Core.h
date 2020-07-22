#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
		#define ENGINE_API _declspec(dllexport)
	#else
		#define ENGINE_API _declspec(dllimport)
	#endif
#else
	#error Engine only support Windows!
#endif

#define BIT(x) (1 << x)