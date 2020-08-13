#pragma once

#include "Engine/Window/Input/Input.h"

namespace GoblinEngine
{
	class GLFWInput : public Input
	{
	public:
		virtual bool IsKeyPressed(KeyCode keyCode) override;
		virtual bool IsMouseButtonPressed(MouseKeyCode button) override;
		virtual std::pair<float, float> GetMousePosition() override;
		virtual float GetMousePositionX() override;
		virtual float GetMousePositionY() override;
	};
}