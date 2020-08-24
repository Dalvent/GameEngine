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

		void Bind() const override;
		void Unbind() const override;

		IndexBuffer& GetIndexBuffer() const override { return *_indexBuffer; }

		void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;
	private:
		std::vector<std::shared_ptr<VertexBuffer>> _vertexBuffers;
		std::shared_ptr<IndexBuffer> _indexBuffer;
		unsigned int _id;
	};
}