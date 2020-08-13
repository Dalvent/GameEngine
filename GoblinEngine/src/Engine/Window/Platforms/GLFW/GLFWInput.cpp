#include "pch.h"
#include "GLFWInput.h"

#include "Engine/Window/Window.h"

#include <GLFW/glfw3.h>

bool GoblinEngine::GLFWInput::IsKeyPressed(KeyCode keyCode)
{
    GLFWwindow* window = static_cast<GLFWwindow*>(GE_WINDOW.GetNativeWindow());
    auto state = glfwGetKey(window, keyCode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool GoblinEngine::GLFWInput::IsMouseButtonPressed(MouseKeyCode button)
{
    GLFWwindow* window = static_cast<GLFWwindow*>(GE_WINDOW.GetNativeWindow());
    auto state = glfwGetKey(window, button);
    return state == GLFW_PRESS;
}

std::pair<float, float> GoblinEngine::GLFWInput::GetMousePosition()
{
    GLFWwindow* window = static_cast<GLFWwindow*>(GE_WINDOW.GetNativeWindow());
    double xPos;
    double yPos;
    glfwGetCursorPos(window, &xPos, &yPos);

    return { (float)xPos, (float)yPos };
}

float GoblinEngine::GLFWInput::GetMousePositionX()
{
    auto [x, y] = GetMousePosition();
    return x;
}

float GoblinEngine::GLFWInput::GetMousePositionY()
{
    auto [x, y] = GetMousePosition();
    return y;
}
