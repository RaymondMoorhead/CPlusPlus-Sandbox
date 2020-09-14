// as a reminder, the entire content of these files
// will replace these lines
#include "04_1_ExampleStruct.h"
#include "04_2_ExampleClass.h"

// view the files show above before moving down

// The way the compiler works in C++, it passes over every *.cpp
// file once, and doesn't explicitly compile *.h files. So the
// point of *.h files is to 'declare' the available structs, classes
// and functions, and the *.cpp file 'implements' them
#if 0
int main(int argc, char* argv[])
{
  ExampleStruct myStruct;
  myStruct.num = 5;

  myStruct.printNum();
  myStruct.SubtractTwoFromNum();
  myStruct.printNum();

  InheritingExampleStruct myInheritingStruct;
  myInheritingStruct.num = 10;

  myInheritingStruct.printNum();
  myInheritingStruct.SubtractTwoFromNum();
  myInheritingStruct.printNum();

  ExampleClass myClass(4);
  myClass.printNum();
  myClass.setNum(5);
  myClass.printNum();

  // polymorphism works the same here as it does in java
  ExampleStruct* myStructPointer = &myStruct;

  // if you want to call a function through a pointer, you
  // don't have to dereference it (though you can), you can
  // just use the '->' operator
  myStructPointer->printNum();

  // and you can use a pointer to a base class to manipulate
  // an inheriting class
  myStructPointer = &myInheritingStruct;
  myStructPointer->printNum();
}
#endif