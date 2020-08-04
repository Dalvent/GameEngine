#include "pch.h"
#include "GameApplication.h"
#include <glad/glad.h>
namespace GoblinEngine
{
	GameApplication* GameApplication::_instance = nullptr;

	void GameApplication::CreateInstance(Platform& platform)
	{
		_instance = new GameApplication(platform);
	}

	void GameApplication::DeleteInstance()
	{
		delete _instance;
	}

	GameApplication::GameApplication(Platform& platform)
	{
		u_window = std::unique_ptr<Window>(platform
			.CreatePlatformWindow(*(new WindowProps())));

		u_window->SetEventCallback(GE_BIND_EVENT(GameApplication::OnEvent));
	}

	void GameApplication::SetGameMod(GameMode* gameMode)
	{
		u_gameMode.reset(gameMode);
	}

	void GameApplication::AddLayer(Layer* layer)
	{
		_layerList.Add(layer);
		layer->OnAttach();
	}

	void GameApplication::RemoveLayer(Layer* layer)
	{
		_layerList.Remove(layer);
		layer->OnDetach();
	}

	void GameApplication::Run()
	{
		u_gameMode->OnBegin();
		glClearColor(0.65f, 0.17f, 0.35f, 1);
		while (_running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			for (auto layer = _layerList.Begin(); layer != _layerList.End(); ++layer)
			{
				(*layer)->OnUpdate();
			}
			u_window->OnUpdate();
			u_gameMode->OnUpdate();
		}
		u_gameMode->OnEnd();
	}

	void GameApplication::OnEvent(Event& e)
	{
		for (auto layer = _layerList.Begin(); layer != _layerList.End(); ++layer)
		{
			(*layer)->OnEvent(e);
		}
		u_gameMode->OnEnd();
	}
}