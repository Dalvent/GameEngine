#pragma once

#include "Engine/Window/Render/RenderApi.h"
#include "Engine/Window/Platforms/OpenGL/OpenGLContext.h"
#include "Engine/Window/Platforms/OpenGL/OpenGLIndexBuffer.h"
#include "Engine/Window/Platforms/OpenGL/OpenGLVertexBuffer.h"

class Window;

namespace GoblinEngine
{
    class OpenGLApiFactory : public RenderApiFactory
    {
        IGraphicsContext* CreateGraphicsContext(Window& window) override;
        IIndexBuffer* CreateIndexBuffer(int* indices, unsigned int count) override;
        IVertexBuffer* CreateVertexBuffer(float* vertices, unsigned int size) override;
    };
}