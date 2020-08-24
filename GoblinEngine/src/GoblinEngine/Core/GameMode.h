#pragma once
#include "GoblinEngine/Events/Event.h"

namespace GoblinEngine
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