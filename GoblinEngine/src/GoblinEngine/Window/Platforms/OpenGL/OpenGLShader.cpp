#include "pch.h"
#include "OpenGLShader.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

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

	void OpenGLShader::Bind()
	{
		glUseProgram(_id);
	}
	void OpenGLShader::Unbind()
	{
		glUseProgram(0);
	}
	void OpenGLShader::SetUniformInt(const std::string& name, const int value)
	{
		GLint location = glGetUniformLocation(_id, name.c_str());
		glUniform1i(location, value);
	}
	void OpenGLShader::SetUniformVec3(const std::string& name, const glm::vec3& value)
	{
		GLint location = glGetUniformLocation(_id, name.c_str());
		glUniform3f(location, value.x, value.y, value.z);
	}
	void OpenGLShader::SetUniformVec4(const std::string& name, const glm::vec4& value)
	{
		GLint location = glGetUniformLocation(_id, name.c_str());
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}
	void OpenGLShader::SetUniformMat3(const std::string& name, const glm::mat3& value)
	{
		GLint location = glGetUniformLocation(_id, name.c_str());
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}
	void OpenGLShader::SetUniformMat4(const std::string& name, const glm::mat4& value)
	{
		GLint location = glGetUniformLocation(_id, name.c_str());https://www.youtube.com/watch?v=238A-bHaB20
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}

	std::string OpenGLShader::ReadFile(const std::string& filePath)
	{
		std::string code;
		std::ifstream fileStream;
		fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			fileStream.open(filePath);
			std::stringstream stringStream;
			stringStream << fileStream.rdbuf();
			fileStream.close();
			code = stringStream.str();
		}
		catch (std::ifstream::failure e)
		{
			GE_LOG_ASSERT(true, "Can't open file!");
		}
		return code;
	}

	std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess(const std::string& source)
	{
		return std::unordered_map<GLenum, std::string>();
	}

	void OpenGLShader::Compile(const std::string& vertexCode, const std::string& fragmentCode)
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

			GE_LOG_CORE_ERROR("{0}", infoLog.data());
			GE_LOG_CORE_ERROR("Vertex shader compilation failure!");
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

			GE_LOG_CORE_ERROR("{0}", infoLog.data());
			GE_LOG_CORE_ERROR("Fragment shader compilation failure!");
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

			GE_LOG_CORE_ERROR("{0}", infoLog.data());
			GE_LOG_CORE_ERROR("Shader link failure!");
			return;
		}
		glDetachShader(_id, vertexShader);
		glDetachShader(_id, fragmentShader);
	}
}