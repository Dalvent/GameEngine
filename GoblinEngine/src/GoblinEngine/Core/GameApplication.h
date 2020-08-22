#pragma once

#include "GoblinEngine/Core/GameMode.h"
#include "GoblinEngine/Core/LayerList.h"
#include "GoblinEngine/Core/Time.h"

namespace GoblinEngine
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
		std::unique_ptr<GameMode> u_gameMode;
		bool _running = true;
	};
	
	// To define on Client.
	void SetupAppSettings(GameApplication& app);
}

#define GE_GAME_APPLICATON GoblinEngine::GameApplication::Get()
#define GE_GAMEMODE GoblinEngine::GameApplication::Get().GetGameMode()
#define GE_DELTATIME GoblinEngine::GameApplication::Get().GetDeltaTime()