#include "pch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace GoblinEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* window)
		: p_window(window)
	{
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(p_window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GE_LOG_CORE_ASSERT("Failed to initialize GLAD!", status);
	}

	void OpenGLContext::SwapBuffer()
	{
		glfwSwapBuffers(p_window);
	}
}