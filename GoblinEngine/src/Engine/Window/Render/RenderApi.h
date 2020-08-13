#pragma once

class GoblinEngine::Window;

namespace GoblinEngine
{
	class IGraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffer() = 0;
	};

	class IVertexBuffer
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};

	class IIndexBuffer
	{
	public:
		virtual void Bind()  = 0;
		virtual void Unbind() = 0;
	};

	class RenderApiFactory
	{
	public:
		virtual IGraphicsContext* CreateGraphicsContext(Window& window) = 0;
		virtual IIndexBuffer* CreateIndexBuffer(int* indices, unsigned int count) = 0;
		virtual IVertexBuffer* CreateVertexBuffer(float* vertices, unsigned int count) = 0;
	};
}