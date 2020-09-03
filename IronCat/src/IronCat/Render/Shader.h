#pragma once

#include <string>
#include <glm/glm.hpp>

namespace IronCat
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
	protected:
		std::string ReadFile(std::string path)
		{
			std::ifstream fileStream;
			fileStream.open(path);
			IC_LOG_CORE_ASSERT(fileStream.is_open(), "Can't open file");

			std::stringstream stringStream;
			stringStream << fileStream.rdbuf();
			fileStream.close();

			 return stringStream.str();
		}
	};
}