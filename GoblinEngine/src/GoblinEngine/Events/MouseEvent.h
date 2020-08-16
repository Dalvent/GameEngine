#pragma once

#include "Event.h"

namespace GoblinEngine
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: _x(x), _y(y)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _x << " " << _y;
			return ss.str();
		}

		MouseKeyCode GetX() { return _x; }
		MouseKeyCode GetY() { return _y; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
		EVENT_CLASS_TYPE(MouseMoved)
	private:
		float _x;
		float _y;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float offsetX, float offsetY)
			: _offsetX(offsetX), _offsetY(offsetY)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolled: " << _offsetX << " " << _offsetY;
			return ss.str();
		}

		MouseKeyCode GetOffsetX() { return _offsetX; }
		MouseKeyCode GetOffsetY() { return _offsetY; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
		EVENT_CLASS_TYPE(MouseScrolled)
	private:
		float _offsetX;
		float _offsetY;
	};

	class MouseButtonEvent : public Event
	{
	public:
		MouseKeyCode GetMouseButton() const { return _mouseKey; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(MouseKeyCode mouseKey)
			: _mouseKey(mouseKey) {}

		MouseKeyCode _mouseKey;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(MouseKeyCode mouseKey)
			: MouseButtonEvent(mouseKey) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << _mouseKey;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(MouseKeyCode mouseKey)
			: MouseButtonEvent(mouseKey) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << _mouseKey;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}