#pragma once
#include "GoblinEngine/Window/Render/IGraphicsContext.h"

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
}