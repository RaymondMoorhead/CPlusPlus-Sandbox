#if 1

#include "04_1_FullReview.h"

void Set(int* to_set, int value)
{

}

void Set(int& to_set, int value)
{

}

int Get(int* data)
{
  return 0;
}

int Get(int** data)
{
  return 0;
}

int Get(int********** data)
{
  return 0;
}

unsigned IntWrapper::GetAsCopy()
{
  return 0;
}

unsigned* IntWrapper::GetAsPointer()
{
  return nullptr;
}

unsigned& IntWrapper::GetAsReference()
{
  unsigned bad_reference;
  return bad_reference;
}

char IntWrapper::GetAsChar()
{
  return 0;
}

bool IntWrapper::GetAsBool()
{
  return 0;
}

#endif