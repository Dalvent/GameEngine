#pragma once
#include "GoblinEngine/Window/Render/IGraphicsContext.h"
#include "GoblinEngine/Window/Render/IShader.h"
#include "GoblinEngine/Window/Render/Buffer.h"

namespace GoblinEngine
{
	class Window;

	class RenderApi
	{
	public:
		virtual IGraphicsContext* CreateGraphicsContext(Window& window) = 0;
		virtual IIndexBuffer* CreateIndexBuffer(int* indices, unsigned int count) = 0;
		virtual IVertexBuffer* CreateVertexBuffer(float* vertices, unsigned int count) = 0;
	};
}