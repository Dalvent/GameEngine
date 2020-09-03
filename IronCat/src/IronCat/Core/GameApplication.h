#pragma once

#include "IronCat/Core/GameMode.h"
#include "IronCat/Core/LayerList.h"
#include "IronCat/Core/Time.h"

namespace IronCat
{
	class GameApplication final
	{
	public:
		static GameApplication& Get();
		static void Init();
		static void Deinit();
	public:
		GameMode& GetGameMode() const { return *u_gameMode; }
		void SetGameMod(GameMode* gameMode);
		float GetDeltaTime() { return _frameTime.GetDeltaTime(); }
		
		void AddLayer(Layer* layer);
		void RemoveLayer(Layer* layer);
		
		void Run();
		void OnEvent(Event& e);
	private:
		static GameApplication* _instance;
	private:
		GameApplication();
	private:
		LayerList _layerList;
		FrameTime _frameTime;
		Scope<GameMode> u_gameMode;
		bool _running = true;
	};
	
	// To define on Client.
	void SetupAppSettings(GameApplication& app);
}

#define IC_GAME_APPLICATON IronCat::GameApplication::Get()
#define IC_GAMEMODE IronCat::GameApplication::Get().GetGameMode()
#define IC_DELTATIME IronCat::GameApplication::Get().GetDeltaTime()
