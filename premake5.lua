workspace "IronCat"
    architecture "x86_64"
    startproject "SandBox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "IronCat/vendor/GLFW/include"
IncludeDir["GLAD"] = "IronCat/vendor/GLAD/include"
IncludeDir["GLM"] = "IronCat/vendor/GLM"
IncludeDir["ImGUI"] = "IronCat/vendor/ImGUI"

include "IronCat/vendor/GLFW"
include "IronCat/vendor/GLAD"
include "IronCat/vendor/ImGUI"

project "IronCat"
    location "IronCat"
    kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "IronCat/src/pch.cpp"
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
    }


    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.ImGUI}"
    }

    links
    {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
	}

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "IC_PLATFORM_WINDOWS",
            "IC_BUILD_DLL",
            "IC_ENABLE_ASSERTS",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "GE_DEBUG"
        buildoptions "/MDd"
        optimize "on"
    
    filter "configurations:Relese"
        defines "GE_RELEASE"
        buildoptions "/MD"
        optimize "on" 
    
    filter "configurations:Dis"
        defines "GE_DIST"
        buildoptions "/MD"
        optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    defines
    {
        "IC_PLATFORM_WINDOWS",
        "IC_PLATFORM_WINDOWS"
    }

    includedirs
    {
        "IronCat/src",
        "IronCat/vendor/spdlog/include",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.ImGUI}"
    }

    links
    {
        "IronCat",
        "ImGui",
    }
    
    filter "system:windows"
        staticruntime "on"
        systemversion "latest"
    
    
        defines
        {
            "IC_PLATFORM_WINDOWS"
        }

        
    filter "configurations:Debug"
        defines "IC_DEBUG"
        buildoptions "/MDd"
        symbols "on"
    
    filter "configurations:Relese"
        defines "IC_RELEASE"
        buildoptions "/MD"
        optimize "on" 
    
    filter "configurations:Dis"
        defines "IC_DIST"
        buildoptions "/MD"
        optimize "on"