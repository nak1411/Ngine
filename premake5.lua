workspace "Ngine"
	architecture "x86_64"
	startproject "NgineApp"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

project "Ngine"
	location "Ngine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++latest"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "nepch.h"
	pchsource "Ngine/src/nepch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/sfml/include"
	}
	
	libdirs
	{
		"%{prj.name}/vendor/sfml/lib"
	}
	
	filter "system:windows"
		cppdialect "C++latest"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"NE_PLATFORM_WINDOWS",
			"NE_BUILD_DLL"
		}
		
		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/NgineApp"
		}
		
	filter "configurations:Debug"
		defines "NE_DEBUG"
		symbols "On"
		links
		{
			"sfml-graphics-d",
			"sfml-audio-d",
			"sfml-network-d",
			"sfml-window-d",
			"sfml-system-d"
		}
	
	filter "configurations:Release"
		defines "NE_RELEASE"
		symbols "On"
		links
		{
			"sfml-graphics",
			"sfml-audio",
			"sfml-network",
			"sfml-window",
			"sfml-system"
		}
		
		
	filter "configurations:Dist"
		defines "NE_DIST"
		symbols "On"
		links
		{
			"sfml-graphics",
			"sfml-audio",
			"sfml-network",
			"sfml-window",
			"sfml-system"
		}
		
project "NgineApp"
	location "NgineApp"
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
		"Ngine/vendor/spdlog/include",
		"Ngine/vendor/sfml/include",
		"Ngine/src"
	}
	
	links
	{
		"Ngine"
	}
	
	filter "system:windows"
		cppdialect "C++latest"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"NE_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "NE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "NE_RELEASE"
		symbols "On"
		
	filter "configurations:Dist"
		defines "NE_DIST"
		symbols "On"
