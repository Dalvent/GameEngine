#include "pch.h"
#include "Application.h"
#include <glad/glad.h>

namespace GoblinEngine
{
	
	Application* Application::_instance = nullptr;

	Application::Application()
	{
		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(GE_BIND_EVENT(Application::OnEvent));

		_instance = this;
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		glClearColor(0.65f, 0.17f, 0.35f, 1);
		while (_running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			for (auto layer = _layerList.Begin(); layer != _layerList.End(); ++layer)
			{
				(*layer)->OnUpdate();
			}
			_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		for (auto layer = _layerList.Begin(); layer != _layerList.End(); ++layer)
		{
			(*layer)->OnEvent(e);
		}
		GE_CORE_TRACE("{0}", e.ToString())
	}
	void Application::AddLayer(Layer* layer)
	{
		_layerList.Add(layer);
		layer->OnAttach();
	}

	void Application::RemoveLayer(Layer* layer)
	{
		_layerList.Add(layer);
		layer->OnDetach();
	}
}