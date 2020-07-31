#pragma once

#include "pch.h"

#include "Engine/Core.h"
#include "Engine/Event/Event.h"

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

	class ENGINE_API Window
	{
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}