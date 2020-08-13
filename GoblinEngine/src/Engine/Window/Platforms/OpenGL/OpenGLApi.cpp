#include "pch.h"
#include "OpenGLApi.h"

#include "Engine/Window/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace GoblinEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* window)
		: p_window(window)
	{
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(p_window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GE_CORE_ASSERT("Failed to initialize GLAD!", status);
	}

	void OpenGLContext::SwapBuffer()
	{
		glfwSwapBuffers(p_window);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(int* indices, unsigned int count)
	{
		glGenBuffers(1, &_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * count, indices, GL_STATIC_DRAW);
	}
	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &_id);
	}
	void OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
	}
	void OpenGLIndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* data, unsigned int count)
	{
		glCreateBuffers(1, &_id);
		glBindBuffer(GL_ARRAY_BUFFER, _id);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, data, GL_STATIC_DRAW);
	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &_id);
	}
	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, _id);
	}
	void OpenGLVertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	IGraphicsContext* OpenGLApi::CreateGraphicsContext(Window& window)
	{
		return new OpenGLContext(static_cast<GLFWwindow*>(window.GetNativeWindow()));
	}
	IIndexBuffer* OpenGLApi::CreateIndexBuffer(int* indices, unsigned int count)
	{
		return new OpenGLIndexBuffer(indices, count);
	}

	IVertexBuffer* OpenGLApi::CreateVertexBuffer(float* vertices, unsigned int size)
	{
		return new OpenGLVertexBuffer(vertices, size);
	}
}
