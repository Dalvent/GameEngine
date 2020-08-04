#pragma once

#include "pch.h"

#include "Engine/Core/Base.h"
#include "Engine/Events/Event.h"
#include "Engine/Core/Input.h"

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

	class ENGINE_API Window
	{
	public: 
		static Window& GetCurrentWindow();

		virtual ~Window() {}

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void* GetNativeWindow() const = 0;
		virtual Input& GetInput() const = 0;
		virtual bool IsVSync() const = 0;

		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		
		virtual void OnUpdate() = 0;
	};
}