
#include <stdlib.h> // malloc

#include "04_2_ExampleClass.h"

// well, one of the main differences between C++ and java
// is that in C++ you have to manage your own memory, and
// here we are.

#if 0
int main(int argc, char* argv[])
{
  // so if you declare a variable as-is, then it's on the stack
  int i;

  // it exists only for the lifetime of the function it's in, or
  // the program if you make it a global function

  // well, anything you allocate with 'malloc' or 'new' goes on
  // the heap, which means it will last until 'free' or 'delete'
  // are called on it (or the program ends, but that's bad practice)

  // 'new' is a basic part of C++
  ExampleClass* example = new ExampleClass(5);
  example->printNum();
  delete example;

  // ...but malloc must be included from 'stdlib.h'
  example = (ExampleClass*)malloc(sizeof(ExampleClass));
  example->setNum(5);
  free(example);

  // malloc is a bit more complicated, as it requests a number
  // of bytes instead of a class, and returns a 'void*' which
  // you have to cast from, but sometimes the versatility is
  // worth it

  // As for 'sizeof', it's a fundamental function that returns
  // the number of bytes that make up an object

  // and if you do this
  example = new ExampleClass(5);
  example = nullptr; // change what we're pointing at

  // that memory we were looking at is now floating around on the heap,
  // taking up space, yet is completely inaccessible. It will only
  // go away when the program ends, and is the source of all memory
  // leaks

  // and as a reminder, dereferencing something outside of the
  // allocated bounds of your program is a crash.
  #if 0
    example = nullptr;
    *example; // crash

    // not a crash, seeing the address isn't a crime
    std::cout << example << std::endl;

    example = new ExampleClass(5);
    delete example;
    *example; // crash

    example = 0x0A1FB344F12F47F9;
    *example; // probably a crash, but who knows
  #endif
}
#endif