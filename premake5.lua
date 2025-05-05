workspace "Pixelyn"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pixelyn"
	location "Pixelyn"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PX_PLATFORM_WINDOWS",
			"PX_BUILD_DLL"
		}

		-- Set the working directory for debugging
        debugdir ("$(SolutionDir)bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Sandbox")
            
        -- Set the command to run for debugging (the startup program)
        debugcommand ("$(SolutionDir)bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Sandbox/Sandbox.exe")

		postbuildcommands {
			-- Ensure the Sandbox directory exists using outputdir
			'IF NOT EXIST "$(SolutionDir)bin\\%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}\\Sandbox" (',
			'    mkdir "$(SolutionDir)bin\\%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}\\Sandbox"',
			')',

			'IF EXIST "$(SolutionDir)bin\\%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}\\Pixelyn\\Pixelyn.dll" (',
			'    echo Pixelyn.dll exists!',
			')',
    
			-- Copy Pixelyn.dll to the Sandbox directory using outputdir
			'copy /Y "$(SolutionDir)bin\\%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}\\Pixelyn\\Pixelyn.dll" "$(SolutionDir)bin\\%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}\\Sandbox\\" > nul'
		}

	filter "configurations:Debug"
		defines { "PX_DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "PX_RELEASE" }
		optimize "On"

	filter "configurations:Dist"
		defines { "PX_DIST" }
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Pixelyn/src",
		"Pixelyn/vendor/spdlog/include"
	}

	links
	{
		"Pixelyn"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines { "PX_DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "PX_RELEASE" }
		optimize "On"

	filter "configurations:Dist"
		defines { "PX_DIST" }
		optimize "On"