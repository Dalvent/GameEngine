#pragma once
#include "GoblinEngine/Window/Render/Shader.h"
#include <fstream>

namespace GoblinEngine
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexPath, const std::string& fragmentPath);
		~OpenGLShader();

		void Bind() override;
		void Unbind() override;

		void SetUniformVec3(const std::string& name, const glm::vec3& value) override;
		void SetUniformVec4(const std::string& name, const glm::vec4& value) override;
		void SetUniformMat3(const std::string& name, const glm::mat3& value) override;
		void SetUniformMat4(const std::string& name, const glm::mat4& value) override;
	private:
		unsigned int _id;
	private:
		void Init(const std::string& vertexCode, const std::string& fragmentCode);
	};
}