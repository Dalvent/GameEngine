#include "pch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace IronCat
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* data, unsigned int count)
	{
		glCreateBuffers(1, &_id);
		glBindBuffer(GL_ARRAY_BUFFER, _id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, data, GL_STATIC_DRAW);
	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &_id);
		std::cout << "vertexIsDead";
	}
	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, _id);
	}
	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(int* indices, unsigned int count) :
		_count(count)
	{
		glGenBuffers(1, &_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * count, indices, GL_STATIC_DRAW);
	}
	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &_id);
		std::cout << "indexIsDead";
	}
	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
	}
	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}