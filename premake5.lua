workspace "Nnuts"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Nnuts/vendor/GLFW/include"

include "Nnuts/vendor/GLFW"

project "Nnuts"
	location "Nnuts"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Nnpch.h"
	pchsource "Nnuts/src/Nnpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}
	
	links{
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines{
			"NN_PLATFORM_WINDOWS",
			"NN_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		buildoptions "/MDd"
		defines "NN_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		buildoptions "/MDd"
		defines "NN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		buildoptions "/MD"
		defines "NN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs{
		"Nnuts/vendor/spdlog/include",
		"Nnuts/src"
	}

	links{
		"Nnuts"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines{
			"NN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NN_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "NN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NN_DIST"
		optimize "On"