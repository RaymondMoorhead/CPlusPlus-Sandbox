#if 1

#include <iostream>
#include "04_1_FullReview.h"

// Here I use a special pre-procesor provided define:
// __LINE__
// which is replaced with the line in the file that it occurred in

// there is also
// __FILE__
// which gives the full path of the file it occurred in

#define FAILURE(Message) \
  {                                 \
    std::cout << "04_FullReviewDriver.cpp line " << __LINE__ << ":\n\t";\
    std::cout << Message << std::endl; \
    return -1;\
  }

int main(int argc, char* argv[])
{
  int data[10];

  // void Set(int*, int);
  for (unsigned i = 0; i < 10; ++i)
  {
    Set(&data[i], i);
    if (data[i] != i)
      FAILURE("\"void Set(int*, int)\" failed");

    // reset data
    data[i] = 0;
  }

  // void Set(int&, int);
  for (unsigned i = 0; i < 10; ++i)
  {
    Set(data[i], i);
    if (data[i] != i)
      FAILURE("\"void Set(int&, int)\" failed");
  }

  // int Get(int*);
  for (unsigned i = 0; i < 10; ++i)
    if (Get(&data[i]) != i)
      FAILURE("\"int Get(int*)\" failed");

  // int Get(int**);
  int* int_ptr;
  for (unsigned i = 0; i < 10; ++i)
  {
    int_ptr = &data[i];
    if (Get(&int_ptr) != i)
      FAILURE("\"int Get(int**)\" failed");
  }

  // int Get(int**********);
  int** int_ptr_ptr;
  int*** int_ptr_ptr_ptr;
  int**** int_ptr_ptr_ptr_ptr;
  int***** int_ptr_ptr_ptr_ptr_ptr;
  int****** int_ptr_ptr_ptr_ptr_ptr_ptr;
  int******* int_ptr_ptr_ptr_ptr_ptr_ptr_ptr;
  int******** int_ptr_ptr_ptr_ptr_ptr_ptr_ptr_ptr;
  int********* int_ptr_ptr_ptr_ptr_ptr_ptr_ptr_ptr_ptr;
  for (unsigned i = 0; i < 10; ++i)
  {
    int_ptr = &data[i];
    int_ptr_ptr = &int_ptr;
    int_ptr_ptr_ptr = &int_ptr_ptr;
    int_ptr_ptr_ptr_ptr = &int_ptr_ptr_ptr;
    int_ptr_ptr_ptr_ptr_ptr = &int_ptr_ptr_ptr_ptr;
    int_ptr_ptr_ptr_ptr_ptr_ptr = &int_ptr_ptr_ptr_ptr_ptr;
    int_ptr_ptr_ptr_ptr_ptr_ptr_ptr = &int_ptr_ptr_ptr_ptr_ptr_ptr;
    int_ptr_ptr_ptr_ptr_ptr_ptr_ptr_ptr = &int_ptr_ptr_ptr_ptr_ptr_ptr_ptr;
    int_ptr_ptr_ptr_ptr_ptr_ptr_ptr_ptr_ptr = &int_ptr_ptr_ptr_ptr_ptr_ptr_ptr_ptr;

    if (Get(&int_ptr_ptr_ptr_ptr_ptr_ptr_ptr_ptr_ptr) != i)
      FAILURE("\"int Get(int**********)\" failed");
  }

  // IntWrapper
  IntWrapper wrap;

  // unsigned IntWrapper::GetAsCopy()
  for (unsigned i = 0; i < 10; ++i)
    if ((wrap.data = i) != wrap.GetAsCopy())
      FAILURE("\"unsigned IntWrapper::GetAsCopy()\" failed");

  // unsigned* IntWrapper::GetAsPointer()
  for (unsigned i = 0; i < 10; ++i)
  {
    wrap.data = i;
    if (&wrap.data != wrap.GetAsPointer())
      FAILURE("\"unsigned* IntWrapper::GetAsPointer()\" failed");
  }

  // unsigned& IntWrapper::GetAsReference()
  for (unsigned i = 0; i < 10; ++i)
    if ((wrap.data = i) != wrap.GetAsReference())
      FAILURE("\"unsigned& IntWrapper::GetAsReference()\" failed");

  // char IntWrapper::GetAsChar()
  for (unsigned i = 0; i < 10; ++i)
    if (char('0' + (wrap.data = i)) != wrap.GetAsChar())
      FAILURE("\"char IntWrapper::GetAsChar()\" failed");

  // bool IntWrapper::GetAsBool()
  wrap.data = 0;
  if(wrap.GetAsBool())
    FAILURE("\"bool IntWrapper::GetAsBool()\" failed");

  for (unsigned i = 1; i < 10; ++i)
  {
    wrap.data = i;
    if (!wrap.GetAsBool())
      FAILURE("\"bool IntWrapper::GetAsBool()\" failed");
  }

  std::cout << "All tests completed successfully" << std::endl;
  return 0;
}
#endif