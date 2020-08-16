#include "GoblinEngine/Window/Window.h"

extern void GoblinEngine::SetupAppSettings(GoblinEngine::GameApplication& app);

int main(int arc, char** argv)
{
	GoblinEngine::Log::Init();
#ifdef GE_PLATFORM_WINDOWS
	 GoblinEngine::Window::SetInstance(new GoblinEngine::WindowsWindow(new GoblinEngine::OpenGLApi(), *(new GoblinEngine::WindowProps())));
#else
	#error No supported platform selected! 
#endif
	GoblinEngine::GameApplication::Init();

	GoblinEngine::GameApplication& app = GoblinEngine::GameApplication::Get();
	GoblinEngine::SetupAppSettings(app);
	app.Run();

	GoblinEngine::GameApplication::Deinit();
}
