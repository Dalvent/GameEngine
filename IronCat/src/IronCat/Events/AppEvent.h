#pragma once

#include "Event.h"

namespace IronCat
{
	class AppEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryApp)
	};

	class WindowCloseEvent : public AppEvent
	{
	public:
		EVENT_CLASS_TYPE(WindowClose)
	};

	class WindowResizeEvent : public AppEvent
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) :
			_width(width), _height(height)
		{
		}

		unsigned int GetWidth() const { return _width; }
		unsigned int GetHeight() const { return _height; }

		virtual std::string ToString() const override
		{
			auto result = std::stringstream();
			result << "WindowResizeEvent: width - " << _width << ", height - " << _height;
			return result.str();
		}

		EVENT_CLASS_TYPE(WindowResize)

	private:
		unsigned int _width;
		unsigned int _height;
	};

	class WindowFocusEvent : public AppEvent
	{
	public:
		EVENT_CLASS_TYPE(WindowFocus)
	};

	class WindowLostFocusEvent : public AppEvent
	{
	public:
		EVENT_CLASS_TYPE(WindowLostFocus)
	};

	class WindowMovedEvent : public AppEvent
	{
	public:
		WindowMovedEvent(unsigned int x, unsigned int y) : 
			_x(x), _y(y) 
		{
		}

		unsigned int GetX() const { return _x; }
		unsigned int GetY() const { return _y; }

		virtual std::string ToString() const override
		{
			auto result = std::stringstream();
			result << "WindowMovedEvent: y - " << _x << ", x - " << _y;
			return result.str();
		}

		EVENT_CLASS_TYPE(WindowMoved)
		
	private:
		unsigned int _x;
		unsigned int _y;
	};

	class AppTickEvent : public AppEvent
	{
	public:
		EVENT_CLASS_TYPE(AppTick)
	};

	class AppUpdateEvent : public AppEvent
	{
	public:
		EVENT_CLASS_TYPE(AppUpdate)
	};

	class AppRenderEvent : public AppEvent
	{
	public:
		EVENT_CLASS_TYPE(AppRender)
	};
}