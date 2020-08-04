#include "pch.h"
#include "GLFWInput.h"
#include <GLFW/glfw3.h>
#include "Engine/Core/Window.h"

bool GoblinEngine::GLFWInput::IsKeyPressedImpl(KeyCode keyCode)
{
    GLFWwindow* window = static_cast<GLFWwindow*>(Window::GetCurrentWindow().GetNativeWindow());
    auto state = glfwGetKey(window, keyCode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool GoblinEngine::GLFWInput::IsMouseButtonPressedImpl(MouseKeyCode button)
{
    GLFWwindow* window = static_cast<GLFWwindow*>(Window::GetCurrentWindow().GetNativeWindow());
    auto state = glfwGetKey(window, button);
    return state == GLFW_PRESS;
}

std::pair<float, float> GoblinEngine::GLFWInput::GetMousePositionImpl()
{
    GLFWwindow* window = static_cast<GLFWwindow*>(Window::GetCurrentWindow().GetNativeWindow());
    double xPos;
    double yPos;
    glfwGetCursorPos(window, &xPos, &yPos);

    return { (float)xPos, (float)yPos };
}

float GoblinEngine::GLFWInput::GetMousePositionXImpl()
{
    auto [x, y] = GetMousePositionImpl();
    return x;
}

float GoblinEngine::GLFWInput::GetMousePositionYImpl()
{
    auto [x, y] = GetMousePositionImpl();
    return y;
}
