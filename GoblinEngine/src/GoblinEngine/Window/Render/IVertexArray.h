#pragma once

#include <memory>
#include "GoblinEngine/Window/Render/Buffer.h"

namespace GoblinEngine
{
	class IVertexArray
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		
		virtual void AddVertexBuffer(const std::shared_ptr<IVertexBuffer>& vartexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IIndexBuffer>& vartexBuffer) = 0;
		virtual void SetLayout(const BufferLayout& layout) = 0;
	};
}