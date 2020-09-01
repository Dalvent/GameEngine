#pragma once

#include "GoblinEngine/Core/Image.h"
#include "GoblinEngine/Window/Render/GraphicsContext.h"
#include "GoblinEngine/Window/Render/Shader.h"
#include "GoblinEngine/Window/Render/Buffer.h"
#include "GoblinEngine/Window/Render/VertexArray.h"
#include "GoblinEngine/Window/Render/Texture.h"

#include <glm/glm.hpp>

namespace GoblinEngine
{
	enum class SupportedRenderApi
	{
		OpenGL = 0
	};

	class Window;

	class RenderApi
	{
	public:
		virtual void Init() = 0;

		virtual SupportedRenderApi GetUsedApi() = 0;

		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0;
		virtual void DrawIndexed(const VertexArray& vertexArray) = 0;

        virtual int ConvertImageInternalFormat(ImageInternalFormat format) = 0;
        virtual int ConvertImageDataFormat(ImageDataFormat format) = 0;
		
		virtual Scope<GraphicsContext> CreateGraphicsContext(Window& window) = 0;
		virtual Ref<IndexBuffer> CreateIndexBuffer(int* indices, unsigned int count) = 0;
		virtual Ref<VertexBuffer> CreateVertexBuffer(float* vertices, unsigned int count) = 0;
		virtual Ref<VertexArray> CreateVertexArray() = 0;
		virtual Ref<Texture2D> CreteTexture2D(const Image& image) = 0;
	private:
		SupportedRenderApi _usedApi;
	};
}