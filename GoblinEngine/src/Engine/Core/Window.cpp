#include "pch.h"
#include "Window.h"
#include "Engine/Core/GameApplication.h"

GoblinEngine::Window& GoblinEngine::Window::GetCurrentWindow()
{
    return GoblinEngine::GameApplication::Get().GetWindow();
}
