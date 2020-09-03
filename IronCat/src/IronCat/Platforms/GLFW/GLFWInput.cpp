#include "pch.h"
#include "GLFWInput.h"

#include "IronCat/Window/Window.h"

#include <GLFW/glfw3.h>

bool IronCat::GLFWInput::IsKeyPressed(KeyCode keyCode)
{
    GLFWwindow* window = static_cast<GLFWwindow*>(IC_WINDOW.GetNativeWindow());
    auto state = glfwGetKey(window, keyCode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool IronCat::GLFWInput::IsMouseButtonPressed(MouseKeyCode button)
{
    GLFWwindow* window = static_cast<GLFWwindow*>(IC_WINDOW.GetNativeWindow());
    auto state = glfwGetKey(window, button);
    return state == GLFW_PRESS;
}

std::pair<float, float> IronCat::GLFWInput::GetMousePosition()
{
    GLFWwindow* window = static_cast<GLFWwindow*>(IC_WINDOW.GetNativeWindow());
    double xPos;
    double yPos;
    glfwGetCursorPos(window, &xPos, &yPos);

    return { (float)xPos, (float)yPos };
}

float IronCat::GLFWInput::GetMousePositionX()
{
    auto [x, y] = GetMousePosition();
    return x;
}

float IronCat::GLFWInput::GetMousePositionY()
{
    auto [x, y] = GetMousePosition();
    return y;
}
