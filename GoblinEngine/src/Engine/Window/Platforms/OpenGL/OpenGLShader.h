#pragma once

namespace GoblinEngine
{
	class OpenGLShader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader();

		void Use() const;
		static void StopUseAnyShader();
	private:
		unsigned int _id;
	};
}