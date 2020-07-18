#pragma once
#include "../GoblinEngine.h";

#ifdef GE_PLATFORM_WINDOWS

extern GoblinEngine::GameApplication* GoblinEngine::CreateApplication();

int main(int arc, char** argv)
{
	auto app = GoblinEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif