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
		virtual void SetUniformVec3(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetUniformVec4(const std::string& name, const glm::vec4& value) = 0;
		virtual void SetUniformMat3(const std::string& name, const glm::mat3& value) = 0;
		virtual void SetUniformMat4(const std::string& name, const glm::mat4& value) = 0;
	};
}