#pragma once
#include "GoblinEngine/Window/Render/Shader.h"
#include <fstream>

#include "GoblinEngine/File/TextFile.h"

using GLenum = unsigned int;

namespace GoblinEngine
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const TextFile& glslFile);
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
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		GLenum ShaderTypeFromString(std::string type);
		void Compile(const std::string& vertexCode, const std::string& fragmentCode);
	};
}