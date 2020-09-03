#pragma once
#include "IronCat/Events/Event.h"

namespace IronCat
{
	class GameMode
	{
	public:
		virtual void OnBegin() {}
		virtual void OnEnd() {}
		virtual void OnBeginRenderFrame() {}
		virtual void OnEndRenderFrame() {}
		virtual void OnEvent(Event& e) {}
	};
}