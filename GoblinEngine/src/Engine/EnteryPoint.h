#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GoblinEngine::Game* GoblinEngine::CreateGame();

int main(int arc, char** argv)
{
	GoblinEngine::Log::Init();

	auto app = GoblinEngine::CreateGame();
	app->Run();
	delete app;
}

#endif