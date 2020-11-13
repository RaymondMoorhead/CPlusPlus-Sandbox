#include <iostream> // cout, endl
#include <string> // string

// Enums are far more primitive in C++ than in java.
// Upon compilation the names become meaningless, and
// it's essentially just a number. There are ways you
// can get around this which we'll go into later
enum SampleEnum {
  Enum1,      // it defaults to 0 and increments from there
  Enum2,      // so this is 1
  Enum3,      // and this is 2
  Enum4 = 8,  // ...but at any point you can jump the pattern
  Enum5,      // this is 9
  Enum6 = 15, // ...or just set the whole thing to what you want
  Enum7 = 18
};

#if 0
int main(int argc, char* argv[])
{
  // here we also see that C++, like java, is a fairly
  // whitespace independant language. You can write whole
  // programs on a single line, or stretch instructions
  // across entire files.
  std::cout << "Enums: " << Enum1 << ' ' <<
                            Enum2 << ' ' <<
                            Enum3 << ' ' <<
                            Enum4 << ' ' <<
                            Enum5 << ' ' <<
                            Enum6 << ' ' <<
                            Enum7 << ' ' <<
                            "\n\n";

  // hooray for primitive data types

  // here we have the usual suspects
  int i;
  char c = 'a'; // we'll be using this later, so I want a definite value
  float f;
  bool b; // boolean in java, shorter name here
  double d;
  short s;
  long l; 

  // and here we can use short, long, signed, unsigned, and const
  // to further specify our type. These aren't supported for every
  // type, but you'll probably only need them on ints and chars.
  unsigned u; // same as 'unsigned int'
  unsigned short int us;
  unsigned long ul;
  const unsigned long uli = 0; // 'const' is just 'final' in java, and must be set on creation
  signed si; // same as 'int' or 'signed int'
  signed short ss;
  signed long sl;
  unsigned char uc;
  // etc, you get the idea, but it should be noted there is
  // a special integer type called a long long, where you can,
  // as you may have guessed, use the long keyword twice to
  // make a really big integer
  long long ll;
  unsigned long long int ulli;

  // now for one of the more critical parts of C++, pointers
  char* cp;

  // a pointer is not a type, but rather an address in memory
  // which 'points' to a variable of the given type. The address
  // of a variable can be acquired with the '&' symbol
  cp = &c;

  // at which point you can get the value inside with the '*' symbol
  // this is called 'dereferencing'
  *cp;

  // if you don't then what you're getting is the address it's pointing at
  std::cout << "Address: " << cp << std::endl;
  std::cout << "Dereferenced: " << *cp << "\n\n";

  // it's important to know that because pointers don't actually have
  // a value, and simply tell you where it is, they can change that
  // value at the source, and see any change of that value
  std::cout << "Pointer: " << *cp << std::endl;
  std::cout << "Base: " << c << "\n\n";

  std::cout << "Changing with pointer" << std::endl;
  *cp = 'b';

  std::cout << "Pointer: " << *cp << std::endl;
  std::cout << "Base: " << c << "\n\n";

  std::cout << "Changing with base variable" << std::endl;
  c = 'c';

  std::cout << "Pointer: " << *cp << std::endl;
  std::cout << "Base: " << c << "\n\n";

  // when a pointer is dereferenced, it knows the type it's looking
  // at, so it specifies a block of X bytes in size for operations

  // but there is also a special type of pointer
  void* vp;

  // it's used mainly in APIs when an input or return type is
  // unknown, and is usually determined by some other piece
  // of information, so it can be cast to that type

  // instead of a pointer you can have a reference. It can
  // only point to the thing that's assigned to it at creation-
  // but you don't need to dereference it
  char& cr = c;
  std::cout << "Reference: " << cr << "\n\n";

  // so, what about strings? Well, you have two options. You can
  // have C-Style string (located in the string pool), shown here.
  const char* c_string = "Hello World";
  std::cout << "C String: " << c_string << "\n\n";

  // this is a pointer to an immutable series of characters, so it is simply
  // an address and nothing more. How does it know how long it is?
  // Well, it doesn't, but there is an invisible 'null terminator'
  // at the end, so when you read it you know when to stop. The null
  // terminator is read as '\0'

  // Or if you want something a bit more easy to use
  std::string cplusplus_string = "Hello World";
  std::cout << "C++ String: " << cplusplus_string << std::endl;

  // 'string' is equivalent to a 'StringBuilder' in java.
  // Internally they're much like std::vector, which itself
  // is equivalent to ArrayList

  // std::string is also capable of doing nearly all the operations
  // you're used to

  // concatenate
  cplusplus_string += cplusplus_string;
  cplusplus_string + cplusplus_string;
  cplusplus_string.append(cplusplus_string);

  // sub-string
  cplusplus_string.substr(0, 5);

  // compare contents. It returns an integer that informs
  // whether the compared string is shorter, longer, the
  // same, and/or has different characters. If the value is 0,
  // it matches completely
  cplusplus_string.compare(cplusplus_string) == 0;

  // gets a c-style string from it
  cplusplus_string.c_str();

  // One last thing about c-style strings

  // this will compile, and output "World"
  std::cout << c_string + 6 << std::endl;
  // why? Because the pointer is looking at a character,
  // and when incremented the pointer will advance by one
  // character in memory. so where '|' is the pointer:
  // |Hello World\0
  // becomes
  // Hello |World\0

  // This is also fundamentally how arrays work in C and
  // Java, it's a pointer to the first variable in a series, and
  c_string[0];
  // is the same as
  *(c_string + 0);
  // and as long as you're operating in your allocated memory
  // space, you won't crash.
}
#endif
