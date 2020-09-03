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
}