#pragma once

#include <string>

namespace GoblinEngine
{
	class IShader
	{
	public:
		virtual void Use() = 0;
		virtual void StopUse() = 0;
		virtual void SetBool(const std::string& name, bool value) = 0;
		virtual void SetInt(const std::string& name, int value) = 0;
		virtual void SetFloat(const std::string& name, float value) = 0;
	};
}