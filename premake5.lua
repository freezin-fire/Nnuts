workspace "Nnuts"
	architecture "x64"
	startproject "Sandbox"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Nnuts/vendor/GLFW/include"
IncludeDir["Glad"] = "Nnuts/vendor/Glad/include"
IncludeDir["ImGui"] = "Nnuts/vendor/imgui"
IncludeDir["glm"] = "Nnuts/vendor/glm"

group "Dependencies"
		include "Nnuts/vendor/GLFW"
		include "Nnuts/vendor/Glad"
		include "Nnuts/vendor/imgui"

group ""

project "Nnuts"
	location "Nnuts"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Nnpch.h"
	pchsource "Nnuts/src/Nnpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}
	
	defines{
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}
	
	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		systemversion "latest"
		
		defines{
			"NN_PLATFORM_WINDOWS",
			"NN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "NN_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "NN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "NN_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs{
		"Nnuts/vendor/spdlog/include",
		"Nnuts/src",
		"Nnuts/vendor",
		"%{IncludeDir.glm}"
	}

	links{
		"Nnuts"
	}

	filter "system:windows"
		systemversion "latest"
		
		defines{
			"NN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		defines "NN_DEBUG"
		symbols "on"
	
	filter "configurations:Release"
		runtime "Release"
		defines "NN_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		runtime "Release"
		defines "NN_DIST"
		optimize "on"