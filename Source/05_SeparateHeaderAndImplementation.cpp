// wait, where was the implementation for
// ExampleStruct and ExampleClass? Well in
// C++ it's standard to separate them. Give
// users the '.h' or 'header' file, and then
// implement it in a '.cpp' file

// it's also because if file A is included by
// file B, and file C includes both A and B,
// there will be multiple function definitions.
// Even with separate headers this is a problem,
// and a current solution these days is to use
// the pre-processor command '#pragma once' at
// the top of the file, which means it will only
// be included one time. This is exactly the
// same as doing the following:
//
// #ifndef EXAMPLE_STRUCT_H
//   #define EXAMPLE_STRUCT_H
//     // code here
// #endif

#include "04_1_ExampleStruct.h"
#include "04_2_ExampleClass.h"

#include <iostream>

// specify the source of the function, treating
// it like a namespace
void ExampleStruct::SetNum(int number)
{
  num = number;
}

void ExampleStruct::SubtractTwoFromNum()
{
  num -= 2;
}

void ExampleStruct::printNum()
{
  std::cout << num << std::endl;
}

// this constructor is using the optional member initializer list
// which allows you to, well, initialize member variables
ExampleClass::ExampleClass(int providedNum) : num(providedNum)
{
}

// to reiterate, destructors are called when an object is deleted
// or goes out-of-scope, we'll get into deleting later
ExampleClass::~ExampleClass()
{
  std::cout << "ExampleClass destructor" << std::endl;
}

int ExampleClass::getNum()
{
  return num;
}

void ExampleClass::setNum(int number)
{
  num = number;
}

void ExampleClass::printNum()
{
  std::cout << num << std::endl;
}