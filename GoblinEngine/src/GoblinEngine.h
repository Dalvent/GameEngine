#pragma once

#include "pch.h"

// For use by GoblinEngine application.
#include "Engine/Core/GameApplication.h"

#ifdef GE_PLATFORM_WINDOWS
	#include "Engine/Window/Platforms/Windows/WindowsWindow.h"
	#include "Engine/Window/Platforms/OpenGL/OpenGLApi.h"
#else
	#error No supported platform selected! 
#endif

// For layers.
#include "Engine/Core/Layer.h"
#include "Engine/ImGUI/ImGUILayer.h"

// Log.
#include "Engine/Core/Log.h"

// Entry point.
#include "Engine/Core/EnteryPoint.h"