#pragma once
#include "GoblinEngine/Window/Render/IShader.h"
#include <fstream>

namespace GoblinEngine
{
	class OpenGLShader : IShader
	{
	public:
		OpenGLShader(const std::string& vertexPath, const std::string& fragmentPath);
		~OpenGLShader();

		void Use() override;
		void StopUse() override;
		void SetBool(const std::string& name, bool value) override;
		void SetInt(const std::string& name, int value) override;
		void SetFloat(const std::string& name, float value) override;
	private:
		unsigned int _id;
	private:
		void Init(const std::string& vertexCode, const std::string& fragmentCode);
	};
}