#pragma once

#include "Core.h"
#include "Platform/Window.h"
#include "Engine/Layer.h"
#include "Engine/LayerList.h"

namespace GoblinEngine
{
	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		static Application& Get() { return *_instance; }
		Window& GetWindow() { return *_window; }

		void Run();
		void OnEvent(Event& e);
			
		void AddLayer(Layer* layer);
		void RemoveLayer(Layer* layer);
	private:
		static Application* _instance;
	private:
		LayerList _layerList;
		std::unique_ptr<Window> _window;
		bool _running = true;
	};

	// To be defined in Client
	Application* CreateGame();
}