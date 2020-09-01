#include "pch.h"
#include "OpenGLApi.h"

#include "GoblinEngine/Window/Window.h"
#include "GoblinEngine/Window/Platforms/OpenGL/OpenGLContext.h"
#include "GoblinEngine/Window/Platforms/OpenGL/OpenGLBuffer.h"
#include "GoblinEngine/Window/Platforms/OpenGL/OpenGLVertexArray.h"
#include "GoblinEngine/Window/Platforms/OpenGL/OpenGLTexture.h"

#include <glad/glad.h>

namespace GoblinEngine
{
	void OpenGLApi::Init()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
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

	int OpenGLApi::ConvertImageInternalFormat(ImageInternalFormat format)
	{
		switch (format)
		{
		case GoblinEngine::ImageInternalFormat::RGB8: return GL_RGB8;
		case GoblinEngine::ImageInternalFormat::RGBA8: return GL_RGBA8;
		default: GE_LOG_ASSERT(true, "Unown ImageInternalFormat, can't convert to OpenGLFormat");
		}

		return 0;
	}

	int OpenGLApi::ConvertImageDataFormat(ImageDataFormat format)
	{
		switch (format)
		{
		case GoblinEngine::ImageDataFormat::RGB: return GL_RGB;
		case GoblinEngine::ImageDataFormat::RGBA: return GL_RGBA;
		default: GE_LOG_ASSERT(true, "Unown ImageDataFormat, can't convert to OpenGLFormat");
		}

		return 0;
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
	Ref<Texture2D> OpenGLApi::CreteTexture2D(const Image& image)
	{
		return Ref<Texture2D>(new OpenGLTexture2D(image));
	}
}
