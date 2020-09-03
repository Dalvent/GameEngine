#pragma once

#include "IronCat/Window/Window.h"
#include "IronCat/Platforms/GLFW/GLFWInput.h"
#include "IronCat/Platforms/GLFW/GLFWContext.h"

class GLFWwindow;

namespace IronCat
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		unsigned int GetWidth() const override { return _data.width; }
		unsigned int GetHeight() const override { return _data.height; }
		virtual void* GetNativeWindow() const { return _glfwWindow; }
		virtual Input& GetInput() const { return *(u_input.get()); }
		bool IsVSync() const override { return _data.vSync; }
		double GetTime() override;

		void SetVSync(bool enabled) override;
		void SetEventCallback(const EventCallbackFunc& callback) override 
		{
			_data.eventCallback = callback;
		}

		void OnUpdate() override;
	private:
		void Init(const WindowProps& props);
		void Shutdow();
	private:
		struct WindowData
		{
			std::string title;
			unsigned int width;
			unsigned int height;
			EventCallbackFunc eventCallback;
			bool vSync;
		};
		WindowData _data;
		Scope<GLFWContext> u_context;
		Scope<GLFWInput> u_input;
		GLFWwindow* _glfwWindow;
	};
}