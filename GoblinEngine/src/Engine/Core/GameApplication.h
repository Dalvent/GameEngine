#pragma once

#include "Engine/Core/Base.h"
#include "Engine/Core/Window.h"
#include "Engine/Core/Layer.h"
#include "Engine/Core/LayerList.h"
#include "Engine/Core/GameMode.h"
#include "Platforms/Platform.h"

namespace GoblinEngine
{
	class ENGINE_API GameApplication final
	{
	public:
		static GameApplication& Get() { return *_instance; }
		static void CreateInstance(Platform& platform);
		static void DeleteInstance();
	public:
		GameMode& GetGameMode() const { return *u_gameMode; }
		Window& GetWindow() const { return *u_window; }

		void SetGameMod(GameMode* gameMode);
		
		void AddLayer(Layer* layer);
		void RemoveLayer(Layer* layer);
		
		void Run();
		void OnEvent(Event& e);
	private:
		GameApplication(Platform& platform);
	private:
		static GameApplication* _instance;
	private:
		LayerList _layerList;
		std::unique_ptr<GameMode> u_gameMode;
		std::unique_ptr<Window> u_window;
		bool _running = true;
	};
	
	// To define on Client.
	void SetupAppSettings(GameApplication& app);
}