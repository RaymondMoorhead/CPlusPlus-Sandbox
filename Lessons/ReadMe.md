# Lessons

These lessons have been written with the assumption that the reader has a firm understanding of Java, and thus mainly focuses on bridging the gaps between Java and C++ instead of starting from scratch. Thus a reader should already know primitive types, classes, method signatures, the main method, arrays, ArrayLists, and the Object Oriented Programming principles.

If you have no previous experience with programming and wish to continue, please open ```Help/ProgrammingBasics.h```.

Java and C++ are actually incredibly similar in syntax, with most differences being presentation. Methods in Java are just Functions in C++, all Java Objects are actually passed around with pointers behind the scenes, and many data structures are also implemented the same way but with different names. In short: don't overcomplicate things for yourself.

The lessons are all part of a single solution, to prevent redefinition errors some files have been removed from compilation with the ```#if 0``` preprocessor command. To enable this code you must change it to ```#if 1```, and be careful to remove any conflicting definitions.

The lessons and exercises are numbered starting from 0, the naming convention being ```##_Name``` for the main lesson, and ```##_#_Name``` for supplementary files for the same lesson.

If you need to reference operators, terminology, or other fundamental material, please see the Help folder. If you don't find what you need in there, the internet is a great source (especially cplusplus.com).

### To Get Started

1. Make sure you have Visual Studio 2019 installed
   - You can use another C++ compiler, but certain Visual Studio specific macros in use will need to be replaced with appropriate counterparts. These do not appear until Lesson `09_DifferentCodeForDifferentBuilds.cpp`.
2. Run `build.bat`
3. Enter the generated `C++Lessons` folder
4. Run `C++Lessons.sln`
5. In Visual Studio, open the drop-downs in the solution explorer: `C++Lessons`->`Source Files`
6. The lessons are in order, start with `00_Preprocessor.cpp`
7. Starting with Lesson `01_HelloWorld.cpp`, you can compile and run your code by clicking `Local Windows Debugger` at the top of Visual Studio