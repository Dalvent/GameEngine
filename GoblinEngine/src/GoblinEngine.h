#pragma once

#include "pch.h"

// For use by GoblinEngine application.
#include "GoblinEngine/Core/GameApplication.h"

#ifdef GE_PLATFORM_WINDOWS
	#include "GoblinEngine/Window/Platforms/Windows/WindowsWindow.h"
	#include "GoblinEngine/Window/Platforms/OpenGL/OpenGLApi.h"
#else
	#error No supported platform selected! 
#endif

// For layers.
#include "GoblinEngine/Core/Layer.h"
#include "GoblinEngine/ImGUI/ImGUILayer.h"

#include "GoblinEngine/Window/Render/RenderApi.h"
#include "GoblinEngine/Window/Render/Renderer.h"
#include "GoblinEngine/Window/Render/OrthogriphicCamera.h"

// Log.
#include "GoblinEngine/Core/Log.h"

// Entry point.
#include "GoblinEngine/Core/EnteryPoint.h"
