#pragma once

#include "Platform/Window.h"

struct GLFWwindow;

namespace GoblinEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return _data.width; }
		unsigned int GetHeight() const override { return _data.height; }

		void SetEventCallback(const EventCallbackFunc& callback) override { _data.eventCallback = callback; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const { return _glfwWindow; }
	private:
		struct WindowData
		{
			std::string title;
			unsigned int width;
			unsigned int height;
			bool vSync;

			EventCallbackFunc eventCallback;
		};

		WindowData _data;
		GLFWwindow* _glfwWindow;

		virtual void Init(const WindowProps& props);
		virtual void Shutdow();
	};
}