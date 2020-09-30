workspace "Evil"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Evil/Vendor/GLFW/include"

include "Evil/Vendor/GLFW"

project "Evil"
	location "Evil"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "evilpch.h"
	pchsource "Evil/src/evilpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/Vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EVIL_PLATFORM_WINDOWS",
			"EVIL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "EVIL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EVIL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EVIL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Evil/Vendor/spdlog/include",
		"Evil/src"
	}

	links
	{
		"Evil"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EVIL_PLATFORM_WINDOWS",
		}


	filter "configurations:Debug"
		defines "EVIL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EVIL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EVIL_DIST"
		optimize "On"