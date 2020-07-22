#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GoblinEngine::Game* GoblinEngine::CreateGame();

int main(int arc, char** argv)
{
	GoblinEngine::Log::Init();

	GoblinEngine::Log::GetCoreLogger()->warn("12131234");
	GoblinEngine::Log::GetClientLogger()->info("12131234");

	auto app = new GoblinEngine::Game();
	app->Run();
	delete app;
}

#endif