workspace "Brisket"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcgf}-%{cfg.system}-%{cfg.architecture}"

project "Brisket"
    location "Brisket"
    kind "SharedLib"
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
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.18362.0"

        defines
        {
            "BK_PLATFORM_WINDOWS",
            "BK_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HZ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HZ_DIST"
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
            "Brisket/vendor/spdlog/include",
            "Brisket/src"
        }

        links
        {
            "Brisket"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "10.0.18362.0"

            defines
            {
                "BK_PLATFORM_WINDOWS",
            }

        filter "configurations:Debug"
            defines "HZ_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "HZ_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "HZ_DIST"
            optimize "On"

