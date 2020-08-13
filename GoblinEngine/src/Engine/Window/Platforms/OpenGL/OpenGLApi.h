#pragma once

#include "Engine/Window/Render/RenderApi.h"

struct GLFWwindow;

namespace GoblinEngine
{
	class OpenGLContext : public IGraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* window);

		void Init() override;
		void SwapBuffer() override;
	private:
		GLFWwindow* p_window;
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

	class OpenGLVertexBuffer : public IVertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* data, unsigned int count);
		~OpenGLVertexBuffer();

		void Bind() override;
		void Unbind() override;
	private:
		unsigned int _id;
	};

    class OpenGLApi : public RenderApi
    {
    public:
        IGraphicsContext* CreateGraphicsContext(Window& window) override;
        IIndexBuffer* CreateIndexBuffer(int* indices, unsigned int count) override;
        IVertexBuffer* CreateVertexBuffer(float* vertices, unsigned int size) override;
    };
}