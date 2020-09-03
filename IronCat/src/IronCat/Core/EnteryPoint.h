#pragma once
#include "IronCat/Window/Window.h"

extern void IronCat::SetupAppSettings(IronCat::GameApplication& app);

int main(int arc, char** argv)
{
	IronCat::Log::Init();
#ifdef IC_PLATFORM_WINDOWS
	 IronCat::Window::SetInstance(new IronCat::WindowsWindow(*(new IronCat::WindowProps())));
	 IronCat::RenderApi::Init(IronCat::SupportedRenderApiType::OpenGL);
#else
	#error No supported platform selected! 
#endif
	IronCat::GameApplication::Init();

	IronCat::GameApplication& app = IronCat::GameApplication::Get();
	IronCat::SetupAppSettings(app);
	app.Run();

	IronCat::GameApplication::Deinit();
}
