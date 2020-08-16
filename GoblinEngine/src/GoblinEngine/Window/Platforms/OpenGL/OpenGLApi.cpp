#include "pch.h"
#include "OpenGLApi.h"

#include "GoblinEngine/Window/Window.h"
#include "GoblinEngine/Window/Platforms/OpenGL/OpenGLContext.h"
#include "GoblinEngine/Window/Platforms/OpenGL/OpenGLBuffer.h"

namespace GoblinEngine
{
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
