#include "pch.h"
#include "Input.h"
#include "Engine/Core/Window.h"

namespace GoblinEngine
{
    Input& Input::GetCurrentInput()
    {
        return GoblinEngine::Window::GetCurrentWindow().GetInput();
    }
    bool Input::IsKeyPressed(KeyCode keyCode)
    {
        return GetCurrentInput().IsKeyPressedImpl(keyCode);
    }
    bool Input::IsMouseButtonPressed(MouseKeyCode button)
    {
        return GetCurrentInput().IsMouseButtonPressedImpl(button);
    }
    std::pair<float, float> Input::GetMousePosition()
    {
        return GetCurrentInput().GetMousePositionImpl();
    }
    bool Input::GetMousePositionX()
    {
        return GetCurrentInput().GetMousePositionXImpl();
    }
    bool Input::GetMousePositionY()
    {
        return GetCurrentInput().GetMousePositionYImpl();
    }
}