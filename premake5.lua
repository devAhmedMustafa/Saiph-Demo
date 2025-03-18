workspace "Saiph"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Saiph/vendor/GLFW/include"
IncludeDir["Glad"] = "Saiph/vendor/Glad/include"
IncludeDir["ImGui"] = "Saiph/vendor/imgui"
IncludeDir["glm"] = "Saiph/vendor/glm"


include "Saiph/vendor/GLFW"
include "Saiph/vendor/Glad"
include "Saiph/vendor/imgui"


project "Saiph"
	location "Saiph"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sppch.h"
	pchsource "Saiph/src/sppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",

	}

	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		buildoptions {"/utf-8"}

		defines
		{
			"SP_PLATFORM_WINDOWS",
			"SP_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"_WINDLL"
		}

		

	filter "configurations:Debug"
		defines "SP_DEBUG"
		runtime "Debug"
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "SP_RELEASE"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "SP_DIST"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"

project "SandBox"
	location "SandBox"
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

	includedirs
	{
		"$(SolutionDir)Saiph/vendor/spdlog/include",
		"$(SolutionDir)Saiph/src",
		"${SolutionDir}Saiph/vendor",
		"%{IncludeDir.glm}",
	}

	links
	{
		"Saiph"
	}

	filter "system:windows"
		systemversion "latest"
		buildoptions {"/utf-8"}

		defines
		{
			"SP_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "SP_DEBUG"
		runtime "Debug"
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "SP_RELEASE"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "SP_DIST"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"