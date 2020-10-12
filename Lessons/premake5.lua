workspace("C++Lessons")
configurations {"Debug", "Release"}
platforms {"x64"}

local project_action = "UNDEFINED"
if _ACTION ~= nill then
	project_action = _ACTION
end

location ("C++Lessons")

filter "configurations:Debug"
symbols "On"

filter "configurations:Release"
optimize "On"

filter{}

project "C++Lessons"
  kind "ConsoleApp"
  language "C++"
  
  targetdir "%{cfg.buildcfg}_%{cfg.platform}"
  targetname "C++Lessons"

  files {"./Source/**.cpp", "./Source/**.h", "./Source/**.inl", "./Dependencies/**.cpp"}

  vpaths 
  {
    ["Header Files/*"] = { "./Source/**.h"},
    ["Source Files/*"] = {"./Source/**.cpp"},
    ["Helper Files/*"] = {"./Source/**.inl"},
    ["External CPP Files/*"] = {"./Dependencies/**.cpp"},
  }

  includedirs 
  {
    "./Dependencies"
  }

  libdirs
  {
    "./Dependencies/*"
  }

  links 
  {
    "pthreadVC2.lib"
  }
  
  configuration "Debug"
    links
    {
      
    }
    
  configuration "Release"
  links
  {
    
  }
	
	