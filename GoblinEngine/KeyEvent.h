#pragma once

#include "Event.h"

typedef int KeyCode;

namespace GoblinEngine
{
	class KeyEvent : public Event
	{
	public:
		KeyCode GetKeyCode() const { return _keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(KeyCode keycode)
			: _keyCode(keycode) {}

		KeyCode _keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keyCode) :
			KeyEvent(keyCode)
		{
		}
		
		KeyCode GetKeyCode() const { return _keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	private:
		KeyCode _keyCode;
	};

	class KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent()
		{
		}

		EVENT_CLASS_TYPE(KeyReleased)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	};

	class KeyTypedEvent : public Event
	{
	public:
		KeyTypedEvent() = default;
		~KeyTypedEvent() = default;

		EVENT_CLASS_TYPE(KeyTyped)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	};

	class MouseButtonDownEvent : public Event
	{
	public:
		MouseButtonDownEvent() = default;
		~MouseButtonDownEvent() = default;

		EVENT_CLASS_TYPE(MouseButtonDown)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	};

	class MouseButtonUpEvent : public Event
	{
	public:
		MouseButtonUpEvent() = default;
		~MouseButtonUpEvent() = default;

		EVENT_CLASS_TYPE(MouseButtonUp)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
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