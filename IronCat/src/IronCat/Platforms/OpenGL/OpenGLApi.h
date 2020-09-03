#pragma once

#include "IronCat/Render/RenderApi.h"

struct GLFWwindow;

namespace IronCat
{
    class OpenGLApi : public RenderApi
    {
    public:
        OpenGLApi();
    public:
        void SetClearColorImpl(const glm::vec4& color) override;
        void ClearImpl() override;
        void DrawIndexedImpl(const VertexArray& vertexArray) override;

        int ConvertImageInternalFormatImpl(ImageInternalFormat format) override;
        int ConvertImageDataFormatImpl(ImageDataFormat format) override;

       // Scope<GraphicsContext> CreateGraphicsContextImpl(Window& window) override;
        Ref<IndexBuffer> CreateIndexBufferImpl(int* indices, unsigned int count) override;
        Ref<VertexBuffer> CreateVertexBufferImpl(float* vertices, unsigned int size) override;
        Ref<VertexArray> CreateVertexArrayImpl() override;
        Ref<Texture2D> CreteTexture2DImpl(const Image& image) override;
        Ref<Shader> CreteShaderImpl(const std::string filePath) override;
    };
}