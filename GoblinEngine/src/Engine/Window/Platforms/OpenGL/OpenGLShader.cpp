#include "pch.h"
#include "OpenGLShader.h"

#include <glad/glad.h>

namespace GoblinEngine
{
	OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		const GLchar* source = (const GLchar*)vertexSrc.c_str();
		glShaderSource(vertexShader, 1, &source, 0);
		glCompileShader(vertexShader);

		GLint isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLenght = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLenght);

			auto infoLog = std::vector<GLchar>(maxLenght);
			glGetShaderInfoLog(vertexShader, maxLenght, &maxLenght, &infoLog[0]);

			glDeleteShader(vertexShader);
			
			GE_CORE_ERROR("{0}", infoLog.data());
			GE_CORE_ERROR("Vertex shader compilation failure!");
			return;
		}

		int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		source = (const GLchar*)fragmentSrc.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLenght = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLenght);

			auto infoLog = std::vector<GLchar>(maxLenght);
			glGetShaderInfoLog(fragmentShader, maxLenght, &maxLenght, &infoLog[0]);

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			GE_CORE_ERROR("{0}", infoLog.data());
			GE_CORE_ERROR("Fragment shader compilation failure!");
			return;
		}

		_id = glCreateProgram();

		glAttachShader(_id, vertexShader);
		glAttachShader(_id, fragmentShader);

		glLinkProgram(_id);

		GLint isLinked = 0;
		glGetProgramiv(_id, GL_LINK_STATUS, (int*)&isLinked);

		if (isLinked == GL_FALSE)
		{
			GLint maxLenght = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLenght);

			auto infoLog = std::vector<GLchar>(maxLenght);
			glGetShaderInfoLog(fragmentShader, maxLenght, &maxLenght, &infoLog[0]);

			glDeleteProgram(_id);

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			GE_CORE_ERROR("{0}", infoLog.data());
			GE_CORE_ERROR("Shader link failure!");
			return;
		}
		glDetachShader(_id, vertexShader);
		glDetachShader(_id, fragmentShader);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(_id);
	}

	void OpenGLShader::Use() const
	{
		glUseProgram(_id);
	}
	void OpenGLShader::StopUseAnyShader()
	{
		glUseProgram(0);
	}
}