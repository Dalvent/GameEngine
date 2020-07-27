#pragma once

#include "Core.h"
#include "Platform/Window.h"

namespace GoblinEngine
{
	class ENGINE_API Game
	{
	public:
		Game();
		virtual ~Game();

		void Run();
	private:
		std::unique_ptr<Window> _window;
		bool _running = true;
	};

	// To be defined in Client
	Game* CreateGame();
}