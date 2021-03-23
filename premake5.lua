workspace "Evil"
	architecture "x86_64"
	startproject "EvilEditor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "Evil/Vendor/GLFW/include"
	IncludeDir["Glad"] = "Evil/Vendor/Glad/include"
	IncludeDir["ImGui"] = "Evil/Vendor/imgui"
	IncludeDir["glm"] = "Evil/Vendor/glm"
	IncludeDir["stb_image"] = "Evil/Vendor/stb_image"
	IncludeDir["entt"] = "Evil/Vendor/entt/include"

	group "Dependencies"
	include "Evil/Vendor/GLFW"
	include "Evil/Vendor/Glad"
	include "Evil/Vendor/imgui"
	group ""

	project "Evil"
		location "Evil"
		kind "StaticLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir("bin/" .. outputdir .. "/%{prj.name}")
		objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "evilpch.h"
		pchsource "Evil/src/evilpch.cpp"

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/Vendor/stb_image/**.h",
			"%{prj.name}/Vendor/stb_image/**.cpp",
			"%{prj.name}/Vendor/glm/glm/**.hpp",
			"%{prj.name}/Vendor/glm/glm/**.inl",
		}

		defines
		{
			"_CRT_SECURE_NO_WARNINGS",
			"GLFW_INCLUDE_NONE"
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/Vendor/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.Glad}",
			"%{IncludeDir.ImGui}",
			"%{IncludeDir.glm}",
			"%{IncludeDir.stb_image}",
			"%{IncludeDir.entt}"
		}

		links
		{
			"GLFW",
			"Glad",
			"ImGui",
			"opengl32.lib"
		}

		filter "system:windows"
			systemversion "latest"

			defines
			{

			}

		filter "configurations:Debug"
			defines "EVIL_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "EVIL_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "EVIL_DIST"
			runtime "Release"
			optimize "on"

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

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
			"Evil/Vendor",
			"%{IncludeDir.glm}",
			"%{IncludeDir.entt}"
		}

		links
		{
			"Evil"
		}

		filter "system:windows"
			systemversion "latest"

		filter "configurations:Debug"
			defines "EVIL_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "EVIL_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "EVIL_DIST"
			runtime "Release"
			optimize "on"

	project "EvilEditor"
		location "EvilEditor"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

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
			"Evil/Vendor",
			"%{IncludeDir.glm}",
			"%{IncludeDir.entt}"
		}

		links
		{
			"Evil"
		}

		filter "system:windows"
			systemversion "latest"

		filter "configurations:Debug"
			defines "EVIL_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "EVIL_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "EVIL_DIST"
			runtime "Release"
			optimize "on"