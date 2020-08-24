#pragma once
#include "GoblinEngine/Window/Render/GraphicsContext.h"
#include "GoblinEngine/Window/Render/Shader.h"
#include "GoblinEngine/Window/Render/Buffer.h"
#include "GoblinEngine/Window/Render/VertexArray.h"

#include <glm/glm.hpp>

namespace GoblinEngine
{
	class Window;

	class RenderApi
	{
	public:
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0;
		virtual void DrawIndexed(const VertexArray& vertexArray) = 0;
		
		virtual Scope<GraphicsContext> CreateGraphicsContext(Window& window) = 0;
		virtual Ref<IndexBuffer> CreateIndexBuffer(int* indices, unsigned int count) = 0;
		virtual Ref<VertexBuffer> CreateVertexBuffer(float* vertices, unsigned int count) = 0;
		virtual Ref<VertexArray> CreateVertexArray() = 0;
	};
}