#pragma once
#include "KeyCode.h"
namespace GoblinEngine
{
	class ENGINE_API Input
	{
	public:
		static Input& GetCurrentInput();
		static bool IsKeyPressed(KeyCode keyCode);
		static bool IsMouseButtonPressed(MouseKeyCode button);
		static std::pair<float, float> GetMousePosition();
		static bool GetMousePositionX();
		static bool GetMousePositionY();
	protected:
		virtual bool IsKeyPressedImpl(KeyCode keyCode) = 0;
		virtual bool IsMouseButtonPressedImpl(MouseKeyCode button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMousePositionXImpl() = 0;
		virtual float GetMousePositionYImpl() = 0;
	};
}