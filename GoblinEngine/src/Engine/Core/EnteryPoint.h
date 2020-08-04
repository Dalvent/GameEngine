#pragma once
#include "Platforms/Windows/WindowsPlatform.h"
#ifdef GE_PLATFORM_WINDOWS
#else
	#error Supported platform not selected.
#endif

extern void GoblinEngine::SetupAppSettings(GoblinEngine::GameApplication& app);

int main(int arc, char** argv)
{
	GoblinEngine::Log::Init();
	GoblinEngine::GameApplication::CreateInstance(GoblinEngine::WindowsPlatform());

	GoblinEngine::GameApplication& app = GoblinEngine::GameApplication::Get();
	GoblinEngine::SetupAppSettings(app);
	app.Run();

	GoblinEngine::GameApplication::DeleteInstance();
}
