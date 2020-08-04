#include "pch.h"
#include "WindowsPlatform.h"

namespace GoblinEngine
{
    Window* WindowsPlatform::CreatePlatformWindow(WindowProps& props)
    {
        return new WindowsWindow(props);
    }
}