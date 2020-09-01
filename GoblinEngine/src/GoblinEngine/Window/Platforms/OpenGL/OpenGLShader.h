#pragma once
#include "GoblinEngine/Window/Render/Shader.h"
#include <fstream>

using GLenum = unsigned int;

namespace GoblinEngine
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexPath, const std::string& fragmentPath);
		~OpenGLShader();

		void Bind() override;
		void Unbind() override;

		void SetUniformInt(const std::string& name, const int value);
		void SetUniformVec3(const std::string& name, const glm::vec3& value);
		void SetUniformVec4(const std::string& name, const glm::vec4& value);
		void SetUniformMat3(const std::string& name, const glm::mat3& value);
		void SetUniformMat4(const std::string& name, const glm::mat4& value);
	private:
		unsigned int _id;
	private:
		std::string ReadFile(const std::string& filePath);
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		void Compile(const std::string& vertexCode, const std::string& fragmentCode);
	};
}