#include "pch.h"
#include "RenderApi.h"

#include "IronCat/Platforms/OpenGL/OpenGLApi.h"

namespace IronCat
{
	Scope<RenderApi> RenderApi::_instance;

	void RenderApi::Init(SupportedRenderApiType apiType)
	{
		switch (apiType)
		{
		case SupportedRenderApiType::OpenGL:
			_instance.reset(new OpenGLApi());
			break;
		default:
			IC_LOG_CORE_ASSERT(false, "RenderApi::Init hasn't got init implementation for chosen render api");
			break;
		}
		_instance->_usedApi = apiType;
	}

	Ref<Texture2D> RenderApi::CreteTexture2D(std::string name, const Image& image)
	{
		auto texture = _instance->CreteTexture2DImpl(image);
		RenderApiLibrary::AddTexture(name, texture);
		return texture;
	}
	Ref<Shader> RenderApi::CreteShader(std::string name, const std::string filePath)
	{
		auto shader = _instance->CreteShaderImpl(filePath);
		RenderApiLibrary::AddShader(name, shader);
		return shader;
	}

	std::unordered_map<std::string, Ref<Shader>> RenderApiLibrary::_shaders;
	std::unordered_map<std::string, Ref<Texture2D>> RenderApiLibrary::_textures;
}