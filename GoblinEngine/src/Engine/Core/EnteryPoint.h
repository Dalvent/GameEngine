
extern void GoblinEngine::SetupAppSettings(GoblinEngine::GameApplication& app);
#ifdef GE_PLATFORM_WINDOWS
	#include "Engine/Window/Platforms/Windows/WindowsWindow.h"
	#include "Engine/Window/Platforms/OpenGL/OpenGLApiFactory.h"
#else
	#error No supported platform selected! 
#endif
int main(int arc, char** argv)
{
	GoblinEngine::Log::Init();

#ifdef GE_PLATFORM_WINDOWS
	 GoblinEngine::Window::SetInstance(new GoblinEngine::WindowsWindow(&(new WindowProps()), new GoblinEngine::OpenGLApiFactory()));
#else
#error No supported platform selected! 
#endif
	GoblinEngine::GameApplication::Init();

	GoblinEngine::GameApplication& app = GoblinEngine::GameApplication::Get();
	GoblinEngine::SetupAppSettings(app);
	app.Run();

	GoblinEngine::GameApplication::Deinit();
}
