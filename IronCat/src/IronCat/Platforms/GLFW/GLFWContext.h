#pragma once
#include "IronCat/Render/GraphicsContext.h"

struct GLFWwindow;

namespace IronCat
{
	class GLFWContext : public GraphicsContext
	{
	public:
		GLFWContext(GLFWwindow* window);

		void Init() override;
		void SwapBuffer() override;
	private:
		GLFWwindow* p_window;
	};
}