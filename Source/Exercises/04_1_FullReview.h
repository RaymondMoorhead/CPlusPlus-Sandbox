// ensures that the file can only be includd once
#pragma once

// this is important bcause if file A is included
// by file B, and file C includes files A and B,
// then file C now has two different declarations
// for the classes/functions in file A. This
// causes re-definition errors



// increase the given value by one
void Increment(int* to_increment);
void Increment(int& to_increment);

// decrease the given value by one
void Decrement(int* to_decrement);
void Decrement(int& to_decrement);

// Set the given variable to the given value
void Set(int* to_set, int value);
void Set(int& to_set, int value);

#if 0
  // the following doesn't work, because it takes in a copy
  // instead of a pointer or reference to an existing int.
  // This goes for primitives and struct/class objects
  void Set(int to_set, int value);
#endif

// Return the contents of the given pointer
// yes, in C++ you can nest pointer->pointer->data
// as much as you want
int Get(int* data);
int Get(int** data);
int Get(int********** data);


struct IntWrapper {
    unsigned data;

    unsigned GetAsCopy();
    unsigned* GetAsPointer();
    unsigned& GetAsReference();

    // Return the character representation of the
    // numerical value, ie: 0 as '0' and 1 as '1'.
    // For this exercise I will guarantee that data_
    // will be a single digit in size (ie: 0-9)
    // hint: you may consult an ascii table, but
    //       knowing the codes isn't necessary.
    //       Don't overcomplicate it
    char GetAsChar();

    // Remember in C++ that if no comparison is done,
    // the compiler will treat the value itself as a
    // bool. That is to say: if it has any '1' bits
    // then it's true, if all bits are '0' then it's
    // false
    bool GetAsBool();
};

// this function is already filled, to be used in the next ones
int ReturnNoOperation(int input);


// function pointers are special, not because they behave
// differently from other pointers- but because they have
// a much more complex type signature.
#if 0
  return_type (*func_pointer_variable_name)(func_inputs)
#endif
// which for the 'ReturnNoOperation' function above would be:
#if 0
  int (*func_pointer_variable_name)(int)
#endif
// so the name of the variable is in the middle of the type,
// and that's all this is, a type. You would then later set:
#if 0
  func_pointer_variable_name = ReturnNoOperation;
#endif


// function pointers are called exactly like normal functions.
int CallFunctionPointer(int (*func)(int), int input);

// function pointers have specific formatting as variables,
// but getting them just involves naming the function
// without calling it, ie:
// return FunctionName;   // right way
// return FunctionName(); // wrong way

// because of the strange formatting of function pointers,
// things can get weird, especially when they're a return
// value of a function
int (*GetFunctionPointer())(int);

// it helps to do this, which allows you to call a complex
// type using a simpler name. This does a bit more than
// #define's find and replace, making it more effective
// when dealing with situations like this
typedef int (*func_pointer)(int);

// now it looks much cleaner, but under the hood is exactly
// the same
func_pointer GetFunctionPointerWithTypedef();