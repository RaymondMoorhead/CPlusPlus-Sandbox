#include "../04_1_FullReview.h"

// the following methods can all be reolved in
// a single statement

// increase the given value by one
void Increment(int* to_increment)
{
  ++(*to_increment);
}

// increase the given value by one
void Increment(int& to_increment)
{
  ++to_increment;
}

// decrease the given value by one
void Decrement(int* to_decrement)
{
  --(*to_decrement);
}

// decrease the given value by one
void Decrement(int& to_decrement)
{
  --to_decrement;
}

// Set the given variable to the given value
void Set(int* to_set, int value)
{
  *to_set = value;
}

// Set the given variable to the given value
void Set(int& to_set, int value)
{
  to_set = value;
}

// Return the contents of the given pointer
int Get(int* data)
{
  return *data;
}

// Return the contents of the given pointer
// yes, in C++ you can have pointers to pointers
int Get(int** data)
{
  return **data;
}

// Return the contents of the given pointer
// yes, in C++ you can nest pointer->pointer->data
// as much as you want
int Get(int********** data)
{
  return **********data;
}

// if it's not a reference or pointer, it's a copy
unsigned IntWrapper::GetAsCopy()
{
  return data;
}

// remember that '&var_name' gets the address
unsigned* IntWrapper::GetAsPointer()
{
  return &data;
}

// the signature is different from a copy, and so
// is the behavior, but the code is the same
unsigned& IntWrapper::GetAsReference()
{
  return data;
}

// for this exercise I will guarantee that data_
// will be a single digit in size (ie: 0-9)
char IntWrapper::GetAsChar()
{
  return '0' + data;
}

// remember in C++ that if no comparison is done,
// the compiler will treat the value itself as a
// bool. That is to say: if it has any '1' bits
// then it's true, if all bits are '0' then it's
// false
bool IntWrapper::GetAsBool()
{
  return data;
}


// function pointers are special, not because they behave
// differently from other pointers- but because they have
// a much more complex type signature.
//
// return_type (*func_pointer_variable_name)(func_inputs)
//
// which for the 'ReturnNoOperation' function in the header would be:
//
// int (*func_pointer_variable_name)(int)
//
// so the name of the variable is in the middle of the type,
// and that's all this is, a type. You would then later set:
// func_pointer_variable_name = ReturnNoOperation;


// function pointers are called exactly like normal functions.
int CallFunctionPointer(int (*func)(int), int input)
{
  return func(input);
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
  return ReturnNoOperation;
}

// now it looks much cleaner, but under the hood is exactly
// the same
func_pointer GetFunctionPointerWithTypedef()
{
  // return the function provided in 04_1_FullReview.h:
  // int ReturnNoOperation(int);
  return ReturnNoOperation;
}