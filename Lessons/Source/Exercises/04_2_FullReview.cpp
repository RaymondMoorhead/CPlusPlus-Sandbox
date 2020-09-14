#if 1

#include "04_1_FullReview.h"

// the following methods can all be reolved in
// a single statement

// increase the given value by one
void Increment(int* to_increment)
{

}

// increase the given value by one
void Increment(int& to_increment)
{

}

// decrease the given value by one
void Decrement(int* to_decrement)
{

}

// decrease the given value by one
void Decrement(int& to_decrement)
{

}

// Set the given variable to the given value
void Set(int* to_set, int value)
{

}

// Set the given variable to the given value
void Set(int& to_set, int value)
{

}

// Return the contents of the given pointer
int Get(int* data)
{
  return 0;
}

// Return the contents of the given pointer
// yes, in C++ you can have pointers to pointers
int Get(int** data)
{
  return 0;
}

// Return the contents of the given pointer
// yes, in C++ you can nest pointer->pointer->data
// as much as you want
int Get(int********** data)
{
  return 0;
}

// if it's not a reference or pointer, it's a copy
unsigned IntWrapper::GetAsCopy()
{
  return 0;
}

// remember that '&var_name' gets the address
unsigned* IntWrapper::GetAsPointer()
{
  return nullptr;
}

// the signature is different from a copy, and so
// is the behavior, but the code is the same
unsigned& IntWrapper::GetAsReference()
{
  unsigned bad_reference;
  return bad_reference;
}

// Return the character representation of the
// numerical value, ie: 0 as '0' and 1 as '1'.
// For this exercise I will guarantee that data_
// will be a single digit in size (ie: 0-9)
// hint: you may consult an ascii table, but
//       knowing the codes isn't necessary.
//       Don't overcomplicate it
char IntWrapper::GetAsChar()
{
  return 0;
}

// remember in C++ that if no comparison is done,
// the compiler will treat the value itself as a
// bool. That is to say: if it has any '1' bits
// then it's true, if all bits are '0' then it's
// false
bool IntWrapper::GetAsBool()
{
  return 0;
}

// these functions are already filled, to be used in the next ones
int ReturnNoOperation(int input) { return input; }
int ReturnInputPlusOne(int input) { return input + 1; }


// function pointers are special, not because they behave
// differently from other pointers- but because they have
// a much more complex type signature.
//
// return_type (*func_pointer_variable_name)(func_inputs)
//
// which for the 'ReturnNoOperation' function above would be:
//
// int (*func_pointer_variable_name)(int)
//
// so the name of the variable is in the middle of the type,
// and that's all this is, a type. You would then later set:
// func_pointer_variable_name = ReturnNoOperation;


// remember, function pointers are called exactly like normal
// functions. Call the given function pointer and return the
// result.
int CallFunctionPointer(int (*func)(int), int input)
{
  return 0;
}

// function pointers have specific formatting as variables,
// but getting them just involves naming the function
// without calling it, ie:
// return FunctionName;   // right way
// return FunctionName(); // wrong way

// because of the strange formatting of function pointers,
// things can get weird, especially when they're a return
// value of a function
int (*GetFunctionPointer())(int)
{
  // return the function provided in 04_1_FullReview.h:
  // int ReturnNoOperation(int);
  return nullptr;
}

// now it looks much cleaner, but under the hood is exactly
// the same
func_pointer GetFunctionPointerWithTypedef()
{
  // return the function provided in 04_1_FullReview.h:
  // int ReturnNoOperation(int);
  return nullptr;
}

#endif