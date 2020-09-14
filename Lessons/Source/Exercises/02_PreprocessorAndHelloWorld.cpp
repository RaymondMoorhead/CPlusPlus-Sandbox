#if 0

#include <iostream>

// set the values of these defines so the main code
// prints "Success"

#define LOOP_X_TIMES(X)

#define DO_IF_EVEN_LOOP(Statement)

int main(int argc, char* argv[])
{
  unsigned evenVals = 0;

  LOOP_X_TIMES(5)
    DO_IF_EVEN_LOOP(++evenVals)

  std::cout << (evenVals == 3 ? "Success" : "Failure") << std::endl;
}
#endif