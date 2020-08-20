#pragma once

#include <string>
#include <glm/glm.hpp>

namespace GoblinEngine
{
	//Float
	//Float2
	//Float3
	//Float4
	//Mat3
	//Mat4
	//Int
	//Int2
	//Int3
	//Int4
	//Bool

	class Shader
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		virtual void SetUniformMat4(const std::string& name, glm::mat4 value) = 0;
	};
}