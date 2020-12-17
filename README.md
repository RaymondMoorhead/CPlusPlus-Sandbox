# CPlusPlus-Tutorial
A C++ tutorial written for those with Java beginnings.

The code has been tested only within x64 Windows 7 and x64 Windows 10 environments. The lessons will probably compile and run fine on most systems, but the BasicBounceEngine has dependencies with 'glew' and 'glfw' that have been satisfied with libraries generated specifically for 64 bit Windows systems.

### NOTE
__The code is being modified to use G++ instead of Visual Studio. The lessons have been converted, but the basic bounce engine still uses Visual Studio 2019.__

### Visual Studio
The engine uses premake5 to create a Visual Studio 2019 solution, as such you will need Visual Studio 2019 installed- but no download is necessary for premake.

To get started, run `build.bat` to generate the project, then navigate to the appropriate generated folder (ie: BasicBounceEngine) and open the `.sln` file with Visual Studio 2019. `clean.bat` will conversely remove the generated folders and files, but leave the source folder untouched.

### G++
The lessons use G++ to compile individual lessons and exercises with the provided windows `.bat` files.

To install g++ on Windows, I would recommend either following [this guide](https://www3.cs.stonybrook.edu/~alee/g++/g++.html) or as part of [Cygwin](https://www.cygwin.com/), which provides useful linux functionality to Windows.