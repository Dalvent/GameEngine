#pragma once

#include "GoblinEngine/Window/Render/IVertexArray.h"
#include <vector>

namespace GoblinEngine
{
	class OpenGLVertexArray : public IVertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void Bind() override;
		void Unbind() override;

		void AddVertexBuffer(const std::shared_ptr<IVertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IIndexBuffer>& vartexBuffer) override;
		virtual void SetLayout(const BufferLayout& layout) override;
	private:
		std::vector<std::shared_ptr<IVertexBuffer>> _vertexBuffers;
		std::shared_ptr<IIndexBuffer> _indexBuffer;
		unsigned int _id;
	};
}