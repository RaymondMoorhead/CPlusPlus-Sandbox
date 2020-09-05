// ensures that the file can only be includd once
#pragma once

// this is important bcause if file A is included
// by file B, and file C includes files A and B,
// then file C now has two different declarations
// for the classes/functions in file A. This
// causes re-definition errors



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

    // for this exercise I will guarantee that data_
    // will be a single digit in size (ie: 0-9)
    char GetAsChar();

    bool GetAsBool();
};