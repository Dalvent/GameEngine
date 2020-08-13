#pragma once

#include "Engine/Window/Render/RenderApi.h"

namespace GoblinEngine
{
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
}