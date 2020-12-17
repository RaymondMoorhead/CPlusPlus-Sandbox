#include <iostream>

#ifdef EXERCISE
  #include "../00_Preprocessor.h"
#else
  #include "../Solutions/00_Preprocessor.h"
#endif

int main(int argc, char* argv[])
{
  unsigned data = 0;

  DO_X_TIMES(++data, 10)

  if (data != 10)
  {
    std::cout << "Failure: Statement should have been executed 10 times, was only executed " << data << " times" << std::endl;
    return -1;
  }

  std::cout << "Success" << std::endl;
}