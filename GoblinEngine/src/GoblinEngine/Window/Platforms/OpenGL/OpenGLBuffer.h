#pragma once

#include "GoblinEngine/Window/Render/Buffer.h"

namespace GoblinEngine
{
	class OpenGLVertexBuffer : public IVertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* data, unsigned int count);
		~OpenGLVertexBuffer();

		void Bind() override;
		void Unbind() override;

		virtual const BufferLayout& GetLayout() const { return _layout; }
		virtual void SetLayout(const BufferLayout& layout) { _layout = layout; }
	private:
		BufferLayout _layout;
		unsigned int _id;
	};

	class OpenGLIndexBuffer : public IIndexBuffer
	{
	public:
		OpenGLIndexBuffer(int* indices, unsigned int count);
		~OpenGLIndexBuffer();

		void Bind() override;
		void Unbind() override;
	private:
		unsigned int _id;
		unsigned int _count;
	};
}