#pragma once

#include "GoblinEngine/Window/Render/Buffer.h"

namespace GoblinEngine
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* data, unsigned int count);
		~OpenGLVertexBuffer();

		void Bind() const override;
		void Unbind() const override;
	private:
		unsigned int _id;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(int* indices, unsigned int count);
		~OpenGLIndexBuffer();

		void Bind() const override;
		void Unbind() const override;

		virtual unsigned int GetCount() const { return _count; }
	private:
		unsigned int _id;
		unsigned int _count;
	};
}