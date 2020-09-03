#pragma once
#include <string>
#include <functional>
#include <memory>

#include "IronCat/Core/Base.h"

#include "IronCat/Events/Event.h"
#include "IronCat/Window/Input/Input.h"

namespace IronCat
{
	struct WindowProps
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& title = "IronCat Engine",
			unsigned int width = 1280,
			unsigned int height = 1280)
			: title(title), width(width), height(height)
		{
		}
	};

	using EventCallbackFunc = std::function<void(Event&)>;

	class Window
	{
	public:
		static Window& Get();
		static void SetInstance(Window* instance);
		static void DeleteInstance();
	public: 
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void* GetNativeWindow() const = 0;
		virtual bool IsVSync() const = 0;
		virtual Input& GetInput() const = 0;
		virtual double GetTime() = 0;
		
		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		
		virtual void OnUpdate() = 0;
	private:
		static Window* _instance;
	};

}

#define IC_WINDOW IronCat::Window::Get()
#define IC_INPUT IronCat::Window::Get().GetInput()
#define IC_CURRENT_TIME IronCat::Window::Get().GetTime()
