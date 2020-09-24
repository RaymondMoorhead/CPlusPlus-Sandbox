// this is a preprocessor directive which replaces this
// line with the entire contents of the given file
#include <stdio.h> // this file has 'printf'

// <filename> means a core file or dependency
// "filename" means a local file

// you also search up and down the file structure
// "../C++Sandbox/filename"

// this is a pre-processor if-check which enables the code
// within. This is not normally necessary for C++, but in
// these lessons there are many main functions, and there
// can only be one since it is THE entry point for the application.
// In future lessons you will change this '1' to '0' and visa-versa
// to enable a different lesson to run.
#if 1

// 'main' is exactly like it is in java, except that it
// isn't in a class, and sits in the global scope
int main(int argc, char* argv[])
{
  // this is a C style print function, C++ has a different
  // way of doing things, but since C++ is essentially just
  // a bunch of extra libraries added to C, it works fine
  printf("Hello World!");

  // in case you didn't know, '\n' is a newline character.
  // in C-Style printouts you'll need it to move to the next line
  printf("\n");

  // There is no automatic or implicit toString() functionality,
  // if you want that then you'll have to do it yourself with operator
  // overloading, we'll get there eventually, but for now just know
  // that these WILL NOT WORK:
  #if 0
    // few of these will compile, those that do will crash,
    // or give output that you may not expect
    printf("Integer: " + 5);
    printf("Float: " + 2.153f);
    printf("Object: " + someObjectInstance);
    printf("String: " + "Hello World");
  #endif
}
#endif