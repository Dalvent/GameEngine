#pragma once
#include "Engine/Core/Input.h"

namespace GoblinEngine
{
	class GLFWInput : public Input
	{
	public:
		virtual bool IsKeyPressedImpl(KeyCode keyCode) override;
		virtual bool IsMouseButtonPressedImpl(MouseKeyCode button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMousePositionXImpl() override;
		virtual float GetMousePositionYImpl() override;
	};
}