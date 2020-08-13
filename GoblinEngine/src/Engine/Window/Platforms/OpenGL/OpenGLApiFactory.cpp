#include "pch.h"
#include "OpenGLApiFactory.h"

#include "Engine/Window/Window.h"

#include <GLFW/glfw3.h>

namespace GoblinEngine
{
    IGraphicsContext* OpenGLApiFactory::CreateGraphicsContext(Window& window)
    {
        return new OpenGLContext(static_cast<GLFWwindow*>(window.GetNativeWindow()));
    }
    IIndexBuffer* OpenGLApiFactory::CreateIndexBuffer(int* indices, unsigned int count)
    {
        return new OpenGLIndexBuffer(indices, count);
    }
    IVertexBuffer* OpenGLApiFactory::CreateVertexBuffer(float* vertices, unsigned int size)
    {
        return new OpenGLVertexBuffer(vertices, size);
    }
}
