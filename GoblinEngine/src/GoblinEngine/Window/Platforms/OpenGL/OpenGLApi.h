#pragma once

#include "GoblinEngine/Window/Render/RenderApi.h"

struct GLFWwindow;

namespace GoblinEngine
{
    class OpenGLApi : public RenderApi
    {
    public:
        void SetClearColor(const glm::vec4& color) override;
        void Clear() override;
        void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;

        GraphicsContext* CreateGraphicsContext(Window& window) override;
        IndexBuffer* CreateIndexBuffer(int* indices, unsigned int count) override;
        VertexBuffer* CreateVertexBuffer(float* vertices, unsigned int size) override;
        VertexArray* CreateVertexArray() override;
    };
}