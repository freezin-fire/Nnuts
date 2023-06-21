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
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		cppdialect "C++17"
		systemversion "latest"
		
		defines{
			"NN_PLATFORM_WINDOWS",
			"NN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "NN_DEBUG"
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines "NN_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "NN_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs{
		"Nnuts/vendor/spdlog/include",
		"Nnuts/src",
		"%{IncludeDir.glm}"
	}

	links{
		"Nnuts"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines{
			"NN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		defines "NN_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		runtime "Release"
		defines "NN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		runtime "Release"
		defines "NN_DIST"
		optimize "On"