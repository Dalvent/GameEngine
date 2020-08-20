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
		void SetUniformMat4(const std::string& name, glm::mat4 value) override;
	private:
		unsigned int _id;
	private:
		void Init(const std::string& vertexCode, const std::string& fragmentCode);
	};
}