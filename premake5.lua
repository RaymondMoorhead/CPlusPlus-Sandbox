workspace("C++Sandbox")
configurations {"Debug", "Release"}
platforms {"x64"}

local project_action = "UNDEFINED"
if _ACTION ~= nill then
	project_action = _ACTION
end

location ("C++Sandbox")

filter "configurations:Debug"
defines{"DEBUG"}
symbols "On"

filter "configurations:Release"
defines{"DEBUG"}
optimize "On"

filter{}

project "C++Sandbox"
  kind "ConsoleApp"
  language "C++"
  
  targetdir "%{cfg.buildcfg}_%{cfg.platform}"
  targetname "C++Sandbox"

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
    
  }

  libdirs
  {
    
  }

  links 
  {
    
  }
  
  configuration "Debug"
    links
    {
      
    }
    
  configuration "Release"
  links
  {
    
  }
  
  
  
  --location "project_vs2013/build"
  --targetdir "project_vs2013"
  --configuration "SDL2.dll"
  --buildaction "Copy"
  
  --configuration "./Debug_x64"
  --buildaction "mkdir"
  
  --postbuildcommand 
  --{
  --  mkdir "./Debug_x64"
  --}
  
  --postbuildcommand
  --{
  --  paste "./Debug_x64"
	--}
	
	
	
	