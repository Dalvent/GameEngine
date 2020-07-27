#include "pch.h"
#include "WindowsWindow.h"

namespace GoblinEngine
{
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}
	
	WindowsWindow::~WindowsWindow()
	{
		Shutdow();
	}
	
	void WindowsWindow::OnUpdate()
	{
		glfwSwapBuffers(_glfwWindow);
	}
	
	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		_data.vSync = enabled;
	}
	
	bool WindowsWindow::IsVSync() const
	{
		return _data.vSync;
	}


	void WindowsWindow::Init(const WindowProps& windowProps)
	{
		_data.title = windowProps.title;
		_data.width = windowProps.width;
		_data.height = windowProps.height;

		GE_CORE_INFO("Creating window {0} ({1} {2})", 
			_data.title, _data.width, _data.height);

		if (GLFW_NOT_INITIALIZED)
		{
			int success = glfwInit();
			GE_CORE_ASSERT(success,"Could not intialize GLFW!");
		}

		_glfwWindow = glfwCreateWindow((int)_data.width, (int)_data.height, _data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_glfwWindow);
		glfwMakeContextCurrent(_glfwWindow);
		glfwSetWindowUserPointer(_glfwWindow, &_data);
		SetVSync(true);
	}
	void WindowsWindow::Shutdow()
	{
		glfwPollEvents();
	}
}