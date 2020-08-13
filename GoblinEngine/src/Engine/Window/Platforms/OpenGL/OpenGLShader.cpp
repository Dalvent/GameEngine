#include "pch.h"
#include "OpenGLShader.h"

#include <glad/glad.h>

namespace GoblinEngine
{
	OpenGLShader::OpenGLShader(const std::string& vertexPath, const std::string& fragmentPath)
	{
		std::cout << vertexPath << std::endl;
		std::cout << fragmentPath << std::endl;

		// 1. retrieve the vertex/fragment source code from filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		// ensure ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			// open files
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;
			// read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			// close file handlers
			vShaderFile.close();
			fShaderFile.close();
			// convert stream into string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}

		Init(vertexCode, fragmentCode);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(_id);
	}

	void OpenGLShader::Use()
	{
		glUseProgram(_id);
	}
	void OpenGLShader::StopUse()
	{
		glUseProgram(0);
	}
	void OpenGLShader::SetBool(const std::string& name, bool value)
	{
	}
	void OpenGLShader::SetInt(const std::string& name, int value)
	{
	}
	void OpenGLShader::SetFloat(const std::string& name, float value)
	{
	}
	void OpenGLShader::Init(const std::string& vertexCode, const std::string& fragmentCode)
	{
		int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		const GLchar* source = (const GLchar*)vertexCode.c_str();
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

		source = (const GLchar*)fragmentCode.c_str();
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
}