#pragma once

#include <memory>
#include "GoblinEngine/Window/Render/Buffer.h"

namespace GoblinEngine
{
	class VertexArray
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		
		virtual IndexBuffer& GetIndexBuffer() = 0;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vartexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;
	};
}