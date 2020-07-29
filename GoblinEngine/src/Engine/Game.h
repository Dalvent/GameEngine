#pragma once

#include "Core.h"
#include "Platform/Window.h"
#include "Engine/Layer.h"
#include "Engine/LayerList.h"

namespace GoblinEngine
{
	class ENGINE_API Game
	{
	public:
		Game();
		virtual ~Game();

		void Run();
		void OnEvent(Event& e);

		void AddLayer(Layer* layer);
		void RemoveLayer(Layer* layer);
	private:
		LayerList _layerList;
		std::unique_ptr<Window> _window;
		bool _running = true;
	};

	// To be defined in Client
	Game* CreateGame();
}