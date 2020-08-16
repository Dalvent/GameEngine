#pragma once

#include "GoblinEngine/Window/Input/KeyCode.h"

namespace GoblinEngine
{
	class Input
	{
	public:
		virtual bool IsKeyPressed(KeyCode keyCode) = 0;
		virtual bool IsMouseButtonPressed(MouseKeyCode button) = 0;
		virtual std::pair<float, float> GetMousePosition() = 0;
		virtual float GetMousePositionX() = 0;
		virtual float GetMousePositionY() = 0;
	};
}