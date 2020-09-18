// before starting, visual studio will freak out
// if it sees more than one main, so add an '#if 0'
// to '01_HelloWorld' and from here on out, change it
// to '1' if it's the file you want to compile and run

// this doesn't need '.h' at the end, because it's
// a fundamental C++ file
#include <iostream> // cout, endl

// this integer is in the global scope, anyone and everyone
// that includes this file can see it, and if two files use
// a variable of the same name, and are then included together,
// then there will be errors
int myInt1 = 10;
int myInt2 = 11;

// this is a namespace, it's where you put things when you don't
// want them to be global. Classes, functions, and variables can
// all go in namespaces
namespace MyNameSpace {
  int myInt3 = 12;
}

#if 0
int main(int argc, char* argv[])
{
  // you can access the global scope freely
  myInt1 = 9;
  
  // to access something within a namespace, type the namespace's name,
  // followed by two ':' characters, followed by the variable, class, 
  // or object you wish to use.
  MyNameSpace::myInt3 = 13;
  
  // the C++ style printouts are in the 'std' namespace
  // and they use operator overloading to get around those
  // no-automatic-string-conversion issues
  std::cout << "Hello" << ' ' << "World!" << std::endl;// 'endl' is just '\n'

  // so here we print the first global
  std::cout << "myInt1 = " << myInt1 << std::endl;

  // remember, if we want myInt3 we need to invoke the namespace
  std::cout << "MyNameSpace::myInt3 = " << MyNameSpace::myInt3 << std::endl;

  // if you have a local variable with the same name
  // as a global, and you want to access the global variant,
  // then use double ':' with no preceeding name
  int myInt2 = -1;
  std::cout << "myInt2 = " << myInt2 << std::endl;
  std::cout << "::myInt2 = " << ::myInt2 << std::endl;
}
#endif
