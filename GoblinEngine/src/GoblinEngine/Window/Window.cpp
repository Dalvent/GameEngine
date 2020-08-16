#include "pch.h"
#include "Window.h"

namespace GoblinEngine
{
    Window* Window::_instance = nullptr;

    Window& Window::Get()
    {
        return *_instance;
    }

    void Window::SetInstance(Window* instance)
    {
        _instance = instance;
    }

    void Window::DeleteInstance()
    {
        delete _instance;
    }
}