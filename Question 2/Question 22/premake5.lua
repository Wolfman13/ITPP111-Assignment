workspace "Question 22"
  configurations { "Release", "Debug" }

project "Question 22"
  kind "ConsoleApp"
  language "C++"
  targetdir "bin/%{cfg.buildcfg}"

  files { "main.cpp" }

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
