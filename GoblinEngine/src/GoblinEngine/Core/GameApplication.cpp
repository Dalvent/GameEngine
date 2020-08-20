#include "pch.h"

#include "GameApplication.h"
#include "GoblinEngine/Window/Window.h"
#include "GoblinEngine/ImGUI/ImGUILayer.h"
#include "GoblinEngine/Window/Render/Renderer.h"
#include "GoblinEngine/Window/Render/OrthogriphicCamera.h"

namespace GoblinEngine
{
	GameApplication* GameApplication::_instance = nullptr;

	GameApplication::GameApplication()
	{
		GE_WINDOW.SetEventCallback(GE_BIND_EVENT(GameApplication::OnEvent));
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
		GE_RENDER_API.SetClearColor(glm::vec4(0.65f, 0.17f, 0.35f, 1));

		auto imGuiLayer = new ImGUILayer();
		this->AddLayer(imGuiLayer);

		OrthogriphicCamera camera(-1.0f, 1.0f, -1.0f, 1.0f);
		camera.SetPosition(glm::vec3(0, 0, 0));
		GE_INFO("{0} {1} {2}", camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);

		while (_running)
		{
			Renderer::BeginScene(camera);

			if (GE_INPUT.IsKeyPressed(GE_KEY_W))
			{
				camera.SetPosition(camera.GetPosition() + glm::vec3(0, -0.01f, 0));
			}

			if (GE_INPUT.IsKeyPressed(GE_KEY_A))
			{
				camera.SetPosition(camera.GetPosition() + glm::vec3(0.01f, 0, 0));
			}

			if (GE_INPUT.IsKeyPressed(GE_KEY_S))
			{
				camera.SetPosition(camera.GetPosition() + glm::vec3(0, 0.01f, 0));
			}

			if (GE_INPUT.IsKeyPressed(GE_KEY_D))
			{
				camera.SetPosition(camera.GetPosition() + glm::vec3(-0.01f, 0, 0));
			}

			if (GE_INPUT.IsKeyPressed(GE_KEY_Q))
			{
				camera.SetRotaion(camera.GetRotation() + 1.01f);
			}

			if (GE_INPUT.IsKeyPressed(GE_KEY_E))
			{
				camera.SetRotaion(camera.GetRotation() + -1.01f);
			}


			GE_RENDER_API.Clear();
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

			Renderer::EndScene();

			GE_WINDOW.OnUpdate();
			u_gameMode->OnUpdate();
			//camera.SetPosition(camera.GetPosition() + 0.001f);

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