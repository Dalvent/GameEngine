#pragma once
#include "Engine/Core/Window.h" 
#include "Platforms/OpenGL/GLFWInput.h"

struct GLFWwindow;

namespace GoblinEngine
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

		void SetVSync(bool enabled) override;
		void SetEventCallback(const EventCallbackFunc& callback) override { _data.eventCallback = callback; }
		void OnUpdate() override;
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
		std::unique_ptr<GLFWInput> u_input;

		virtual void Init(const WindowProps& props);
		virtual void Shutdow();
	};
}