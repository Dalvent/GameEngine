#pragma once
#include "Engine/Core/Window.h"

namespace GoblinEngine
{
	class Platform
	{
	public:
		virtual Window* CreatePlatformWindow(WindowProps& props) = 0;
	};
}