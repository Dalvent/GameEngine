#include "pch.h"
#include "OpenGLApi.h"

#include "IronCat/Window/Window.h"
#include "IronCat/Platforms/OpenGL/OpenGLBuffer.h"
#include "IronCat/Platforms/OpenGL/OpenGLVertexArray.h"
#include "IronCat/Platforms/OpenGL/OpenGLTexture.h"
#include "IronCat/Platforms/OpenGL/OpenGLShader.h"

#include <glad/glad.h>

namespace IronCat
{
	OpenGLApi::OpenGLApi()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLApi::SetClearColorImpl(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLApi::ClearImpl()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLApi::DrawIndexedImpl(const VertexArray& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	int OpenGLApi::ConvertImageInternalFormatImpl(ImageInternalFormat format)
	{
		switch (format)
		{
		case IronCat::ImageInternalFormat::RGB8: return GL_RGB8;
		case IronCat::ImageInternalFormat::RGBA8: return GL_RGBA8;
		default: IC_LOG_CORE_ASSERT(true, "Unown ImageInternalFormat, can't convert to OpenGLFormat");
		}

		return 0;
	}

	int OpenGLApi::ConvertImageDataFormatImpl(ImageDataFormat format)
	{
		switch (format)
		{
		case IronCat::ImageDataFormat::RGB: return GL_RGB;
		case IronCat::ImageDataFormat::RGBA: return GL_RGBA;
		default: IC_LOG_CORE_ASSERT(true, "Unown ImageDataFormat, can't convert to OpenGLFormat");
		}

		return 0;
	}

	Ref<IndexBuffer> OpenGLApi::CreateIndexBufferImpl(int* indices, unsigned int count)
	{
		return Ref<IndexBuffer>(new OpenGLIndexBuffer(indices, count));
	}

	Ref<VertexBuffer> OpenGLApi::CreateVertexBufferImpl(float* vertices, unsigned int size)
	{
		return Ref<VertexBuffer>(new OpenGLVertexBuffer(vertices, size));
	}

	Ref<VertexArray> OpenGLApi::CreateVertexArrayImpl()
	{
		return Ref<VertexArray>(new OpenGLVertexArray());
	}
	Ref<Texture2D> OpenGLApi::CreteTexture2DImpl(const Image& image)
	{
		return Ref<Texture2D>(new OpenGLTexture2D(image));
	}
	Ref<Shader> OpenGLApi::CreteShaderImpl(const std::string filePath)
	{
		return Ref<Shader>(new OpenGLShader(filePath));
	}
}