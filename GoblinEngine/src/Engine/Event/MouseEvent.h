#pragma once

#include "Event.h"

typedef int MouseKeyCode;


namespace GoblinEngine
{
	class MouseEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	};

	class MouseButtonPressedEvent : public Event
	{
	public:
		MouseButtonPressedEvent() = default;
		~MouseButtonPressedEvent() = default;

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public Event
	{
	public:
		MouseButtonReleasedEvent() = default;
		~MouseButtonReleasedEvent() = default;

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent() = default;
		~MouseMovedEvent() = default;

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent() = default;
		~MouseScrolledEvent() = default;

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	};
}