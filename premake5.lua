workspace "GoblinEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GoblinEngine"
    location "GoblinEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.18362.0"


        defines
        {
            "GE_PLATFORM_WINDOWS",
            "GE_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "GE_DEBUG"
        symbols "On"
    
    filter "configurations:Relese"
        defines "GE_RELEASE"
        symbols "On" 

    filter "configurations:Dis"
        defines "GE_DIST"
        symbols "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "GoblinEngine/src",
        "GoblinEngine/vendor/spdlog/include"
    }

    links
    {
        "GoblinEngine"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.18362.0"
    
    
        defines
        {
            "GE_PLATFORM_WINDOWS",
            "GE_BUILD_DLL",
        }
    
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
        
        filter "configurations:Debug"
            defines "GE_DEBUG"
            symbols "On"
        
        filter "configurations:Relese"
            defines "GE_RELEASE"
            symbols "On" 
    
        filter "configurations:Dis"
            defines "GE_DIST"
            symbols "On"