#pragma once
#include <string>
#include <functional>
#include <memory>

#include "Engine/Core/Base.h"

#include "Engine/Events/Event.h"
#include "Engine/Window/Input/Input.h"
#include "Engine/Window/Render/RenderApi.h"

namespace GoblinEngine
{
	struct WindowProps
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& title = "Goblin Engine",
			unsigned int width = 1280,
			unsigned int height = 720) 
			: title(title), width(width), height(height)
		{
		}
	};

	using EventCallbackFunc = std::function<void(Event&)>;

	class Window
	{
	public:
		static Window& Get() { return *_instance; }
		static void SetInstance(Window* instance)
		{
			_instance = instance;
		}
		static void DeleteInstance()
		{
			delete _instance;
		}
	public: 
		Window(RenderApiFactory* factory) : u_rendFactory(factory)
		{
		}
		virtual ~Window() {}

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void* GetNativeWindow() const = 0;
		virtual bool IsVSync() const = 0;
		virtual Input& GetInput() const = 0;
		RenderApiFactory& GetRenderApiFactory() const { return *u_rendFactory; }
		
		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		
		virtual void OnUpdate() = 0;
	protected:
		std::unique_ptr<IGraphicsContext> u_context;
	private:
		static Window* _instance;
	private:
		std::unique_ptr<RenderApiFactory> u_rendFactory;
	};

}

#define GE_WINDOW GoblinEngine::Window::Get()
#define GE_INPUT GoblinEngine::Window::Get().GetInput()
#define GE_RENDER_API_FACTORY GoblinEngine::Window::Get().GetRenderApiFactory()