#pragma once
#include "Platforms/Platform.h"
#include "Platforms/Windows/WindowsWindow.h"

namespace GoblinEngine
{
	class ENGINE_API WindowsPlatform : public Platform
	{
	public:
		Window* CreatePlatformWindow(WindowProps& props) override;
	};
}