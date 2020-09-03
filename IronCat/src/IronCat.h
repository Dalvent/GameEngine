#pragma once
// For use by GoblinEngine application.
#include "IronCat/Core/GameApplication.h"

#ifdef IC_PLATFORM_WINDOWS
	#include "IronCat/Platforms/Windows/WindowsWindow.h"
	#include "IronCat/Platforms/OpenGL/OpenGLApi.h"
#else
	#error No supported platform selected! 
#endif

// For layers.
#include "IronCat/Core/Layer.h"
#include "IronCat/ImGUI/ImGUILayer.h"

#include "IronCat/Render/RenderApi.h"
#include "IronCat/Render/Renderer.h"
#include "IronCat/Render/OrthogriphicCamera.h"

// Components
#include "IronCat/Core/Transform.h"

// Log.
#include "IronCat/Core/Log.h"
