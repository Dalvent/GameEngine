#pragma once

#include "Event.h"

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