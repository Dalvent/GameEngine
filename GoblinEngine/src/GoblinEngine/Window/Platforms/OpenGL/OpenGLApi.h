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
        void DrawIndexed(const VertexArray& vertexArray) override;

        Scope<GraphicsContext> CreateGraphicsContext(Window& window) override;
        Ref<IndexBuffer> CreateIndexBuffer(int* indices, unsigned int count) override;
        Ref<VertexBuffer> CreateVertexBuffer(float* vertices, unsigned int size) override;
        Ref<VertexArray> CreateVertexArray() override;
    };
}