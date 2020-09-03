#include "pch.h"
#include "GLFWContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace IronCat
{
	GLFWContext::GLFWContext(GLFWwindow* window)
		: p_window(window)
	{
	}

	void GLFWContext::Init()
	{
		glfwMakeContextCurrent(p_window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		IC_LOG_CORE_ASSERT(status, "Failed to initialize GLAD!");
	}

	void GLFWContext::SwapBuffer()
	{
		glfwSwapBuffers(p_window);
	}
}