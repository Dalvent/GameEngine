#pragma once

#include "GoblinEngine/Window/Render/Buffer.h"

namespace GoblinEngine
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* data, unsigned int count);
		~OpenGLVertexBuffer();

		void Bind() override;
		void Unbind() override;
	private:
		unsigned int _id;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(int* indices, unsigned int count);
		~OpenGLIndexBuffer();

		void Bind() override;
		void Unbind() override;

		virtual unsigned int GetCount() const { return _count; }
	private:
		unsigned int _id;
		unsigned int _count;
	};
}