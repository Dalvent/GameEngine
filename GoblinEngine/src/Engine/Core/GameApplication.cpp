#include "pch.h"

#include "GameApplication.h"
#include "Engine/Window/Window.h"
#include "Engine/ImGUI/ImGUILayer.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace GoblinEngine
{
	GameApplication* GameApplication::_instance = nullptr;

	GameApplication::GameApplication()
	{
		GE_WINDOW.SetEventCallback(GE_BIND_EVENT(GameApplication::OnEvent));
	}

	void GameApplication::Init()
	{
		_instance = new GameApplication();
	}
	void GameApplication::Deinit()
	{
		delete _instance;
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

		auto imGuiLayer = new ImGUILayer();
		this->AddLayer(imGuiLayer);

		while (_running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			for (auto layer = _layerList.Begin(); layer != _layerList.End(); ++layer)
			{
				(*layer)->OnUpdate();
			}

			imGuiLayer->Start();
			for (auto layer = _layerList.Begin(); layer != _layerList.End(); ++layer)
			{
				(*layer)->OnImGuiRender();
			}
			imGuiLayer->End();

			GE_WINDOW.OnUpdate();
			u_gameMode->OnUpdate();
		}
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