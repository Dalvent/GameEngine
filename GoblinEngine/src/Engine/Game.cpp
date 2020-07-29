#include "pch.h"
#include "Game.h"
#include <glad/glad.h>

namespace GoblinEngine
{
#define BIND_EVENT(eventFunction) std::bind(&eventFunction, this, std::placeholders::_1)

	Game::Game()
	{
		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT(Game::OnEvent));
	}

	Game::~Game()
	{
	}

	void Game::Run()
	{
		GE_TRACE("GO!");
		glClearColor(0.15686274509, 0.1725490196, 0.20784313725, 1);
		while (_running)
		{
			for (auto layer = _layerList.Begin(); layer != _layerList.End(); ++layer)
			{
				std::cout << "SCREAM";
				(*layer)->OnUpdate();
			}

			glClear(GL_COLOR_BUFFER_BIT);
			_window->OnUpdate();
		}
	}

	void Game::OnEvent(Event& e)
	{
		for (auto layer = _layerList.Begin(); layer != _layerList.End(); layer++)
		{
			(*layer)->OnEvent(e);
		}

		GE_CORE_TRACE("{0}", e.ToString())
	}
	void Game::AddLayer(Layer* layer)
	{
		_layerList.Add(layer);
		layer->OnAttach();
	}

	void Game::RemoveLayer(Layer* layer)
	{
		_layerList.Add(layer);
		layer->OnDetach();
	}
}