#pragma once
#include "GoblinEngine/Window/Render/GraphicsContext.h"

struct GLFWwindow;

namespace GoblinEngine
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* window);

		void Init() override;
		void SwapBuffer() override;
	private:
		GLFWwindow* p_window;
	};
}