#include "pch.h"

#include "GameApplication.h"
#include "IronCat/Window/Window.h"
#include "IronCat/ImGUI/ImGUILayer.h"
#include "IronCat/Render/Renderer.h"
#include "IronCat/Render/OrthogriphicCamera.h"

namespace IronCat
{
	GameApplication* GameApplication::_instance = nullptr;

	GameApplication::GameApplication()
	{
		IC_WINDOW.SetEventCallback(IC_BIND_EVENT(GameApplication::OnEvent));
	}

	GameApplication& GameApplication::Get()
	{
		return *_instance;
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

		auto imGuiLayer = new ImGUILayer();
		this->AddLayer(imGuiLayer);

		_frameTime = FrameTime(IC_WINDOW.GetTime());
		while (_running)
		{
			u_gameMode->OnBeginRenderFrame();

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

			IC_WINDOW.OnUpdate();

			u_gameMode->OnEndRenderFrame();
			_frameTime.NextFrame(IC_WINDOW.GetTime());
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