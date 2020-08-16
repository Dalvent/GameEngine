#pragma once

#include "GoblinEngine/Window/Render/RenderApi.h"

struct GLFWwindow;

namespace GoblinEngine
{
    class OpenGLApi : public RenderApi
    {
    public:
        IGraphicsContext* CreateGraphicsContext(Window& window) override;
        IIndexBuffer* CreateIndexBuffer(int* indices, unsigned int count) override;
        IVertexBuffer* CreateVertexBuffer(float* vertices, unsigned int size) override;
    };
}