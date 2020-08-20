#pragma once

#include "GoblinEngine/Window/Render/VertexArray.h"
#include <vector>


namespace GoblinEngine
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void Bind() override;
		void Unbind() override;

		IndexBuffer& GetIndexBuffer() override { return *_indexBuffer; }

		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;
	private:
		std::vector<std::shared_ptr<VertexBuffer>> _vertexBuffers;
		std::shared_ptr<IndexBuffer> _indexBuffer;
		unsigned int _id;
	};
}