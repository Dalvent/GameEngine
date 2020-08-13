#pragma once

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