#pragma once

#include "GoblinEngine/Window/Render/RenderApi.h"

struct GLFWwindow;

namespace GoblinEngine
{
    class OpenGLApi : public RenderApi
    {
    public:
        void Init() override;

        SupportedRenderApi GetUsedApi() override { return SupportedRenderApi::OpenGL; }

        void SetClearColor(const glm::vec4& color) override;
        void Clear() override;
        void DrawIndexed(const VertexArray& vertexArray) override;

        int ConvertImageInternalFormat(ImageInternalFormat format) override;
        int ConvertImageDataFormat(ImageDataFormat format) override;

        Scope<GraphicsContext> CreateGraphicsContext(Window& window) override;
        Ref<IndexBuffer> CreateIndexBuffer(int* indices, unsigned int count) override;
        Ref<VertexBuffer> CreateVertexBuffer(float* vertices, unsigned int size) override;
        Ref<VertexArray> CreateVertexArray() override;
        Ref<Texture2D> CreteTexture2D(const Image& image) override;
    };
}