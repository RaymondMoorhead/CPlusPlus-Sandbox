# Lessons

These lessons have been written with the assumption that the reader has a firm understanding of Java, and thus mainly focuses on bridging the gaps between Java and C++ instead of starting from scratch. Thus a reader should already know primitive types, classes, method signatures, the main method, arrays, ArrayLists, and the Object Oriented Programming principles.

If you have no previous experience with programming and wish to continue, please open ```Help/ProgrammingBasics.h```.

Java and C++ are actually incredibly similar in syntax, with most differences being presentation. Methods in Java are just Functions in C++, all Java Objects are actually passed around with pointers behind the scenes, and many data structures are also implemented the same way but with different names. In short: don't overcomplicate things for yourself.

The lessons and exercises are numbered starting from 0, the naming convention being ```##_Name``` for the main lesson, and ```##_#_Name``` for supplementary files for the same lesson.

If you need to reference operators, terminology, or other fundamental material, please see the Help folder. If you don't find what you need in there, the internet is a great source (especially cplusplus.com).

### To Get Started

1. Make sure you have G++ installed
   - For Linux run `sudo apt-get update` followed by `sudo apt-get install g++`in the terminal.
   - For Mac run `g++` in the terminal, and select the install option.
   - For Windows use [this guide](https://www3.cs.stonybrook.edu/~alee/g++/g++.html) or install it as part of [Cygwin](https://www.cygwin.com/).
2. View the appropriate lesson in the `Lessons` folder
   - It is highly recommended that you view and write code in an application with color coding and some level of intelligent C++ auto-completion, such as Notepad++, Sublime, or Visual Studio Code.
   - The lessons are in order, start with `00_Preprocessor.cpp`
3. Run it with `compile_lesson.bat` if desired.
   - I have not provided Linux and Mac equivalent scripts yet, but most lessons will simply run with `g++ -o "CompiledLessons/Lesson_<number>.exe" "Lessons/<number>_*.cpp"`, with the exceptions being lessons 4, 5, 6, and 9. Lessons 4 and 6 also use files from lesson 5, 5 uses files from lesson 4, and lesson 6 requires macros to be defined as part of the call to `g++`. To add macros in this call, use `-D <macro_name>=<optional_macro_value>`.