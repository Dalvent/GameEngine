#pragma once

#include "Core.h"

namespace GoblinEngine
{
	ENGINE_API class GameApplication
	{
	public:
		GameApplication();
		virtual ~GameApplication();

		void Run();
	};

	// To be defined in Client
	GameApplication* CreateApplication();
}