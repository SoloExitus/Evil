workspace "Evil"
	architecture "x64"
	startproject "Sandbox"
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
IncludeDir["Glad"] = "Evil/Vendor/Glad/include"
IncludeDir["ImGui"] = "Evil/Vendor/imgui"
IncludeDir["glm"] = "Evil/Vendor/glm"

include "Evil/Vendor/GLFW"
include "Evil/Vendor/Glad"
include "Evil/Vendor/imgui"

project "Evil"
	location "Evil"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "evilpch.h"
	pchsource "Evil/src/evilpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/Vendor/glm/glm/**.hpp",
		"%{prj.name}/Vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/Vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"EVIL_PLATFORM_WINDOWS",
			"EVIL_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "EVIL_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "EVIL_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "EVIL_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Evil/Vendor/spdlog/include",
		"Evil/src",
		"%{IncludeDir.glm}"
		
	}

	links
	{
		"Evil"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"EVIL_PLATFORM_WINDOWS",
		}


	filter "configurations:Debug"
		defines "EVIL_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "EVIL_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "EVIL_DIST"
		runtime "Release"
		optimize "On"