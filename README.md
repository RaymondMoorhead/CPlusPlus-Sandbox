# CPlusPlus-Tutorial
A C++ tutorial written for those with Java beginnings.

The lessons and engine use premake5 to create a Visual Studio 2019 solution, as such you will need Visual Studio 2019 installed- but no download is necessary for premake.

The code has been tested only within x64 Windows 7 and x64 Windows 10 environments. The lessons will probably compile and run fine on most systems, but the BasicBounceEngine has dependencies with 'glew' and 'glfw' that have been satisfied with libraries generated specifically for 64 bit Windows systems.

To get started, run `build.bat` to generate the project, then navigate to the appropriate generated folder (ie: C++Lessons or BasicBounceEngine) and open the `.sln` file with Visual Studio 2019. `clean.bat` will conversely remove the generated folders and files, but leave the source folder untouched.
