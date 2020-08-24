#include "pch.h"
#include "OpenGLApi.h"

#include "GoblinEngine/Window/Window.h"
#include "GoblinEngine/Window/Platforms/OpenGL/OpenGLContext.h"
#include "GoblinEngine/Window/Platforms/OpenGL/OpenGLBuffer.h"
#include "GoblinEngine/Window/Platforms/OpenGL/OpenGLVertexArray.h"

#include <glad/glad.h>

namespace GoblinEngine
{
	void OpenGLApi::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLApi::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLApi::DrawIndexed(const VertexArray& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	Scope<GraphicsContext> OpenGLApi::CreateGraphicsContext(Window& window)
	{
		return Scope<GraphicsContext>(new OpenGLContext(static_cast<GLFWwindow*>(window.GetNativeWindow())));
	}

	Ref<IndexBuffer> OpenGLApi::CreateIndexBuffer(int* indices, unsigned int count)
	{
		return Ref<IndexBuffer>(new OpenGLIndexBuffer(indices, count));
	}

	Ref<VertexBuffer> OpenGLApi::CreateVertexBuffer(float* vertices, unsigned int size)
	{
		return Ref<VertexBuffer>(new OpenGLVertexBuffer(vertices, size));
	}

	Ref<VertexArray> OpenGLApi::CreateVertexArray()
	{
		return Ref<VertexArray>(new OpenGLVertexArray());
	}
}
