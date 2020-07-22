#pragma once

#include "Core.h"

namespace GoblinEngine
{
	class ENGINE_API Game
	{
	public:
		Game();
		virtual ~Game();

		void Run();
	};

	// To be defined in Client
	Game* CreateGame();
}