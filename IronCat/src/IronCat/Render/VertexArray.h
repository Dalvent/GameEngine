#pragma once

#include <memory>
#include "IronCat/Render/Buffer.h"

namespace IronCat
{
	class VertexArray
	{
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		
		virtual IndexBuffer& GetIndexBuffer() const = 0;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vartexBuffer) = 0;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) = 0;
	};
}