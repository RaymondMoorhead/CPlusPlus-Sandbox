#if 0

#include <iostream>

// set the values of these defines so the main code
// prints "Success"

// write an open loop that will
// execute X times
#define LOOP_X_TIMES(X)\
  for(unsigned i = 0; i < X; ++i)

// execute the given 'Statement' if
// the loop number is even.
// HINT:  use the modulus operator
//        to determine if something
//        is even ('%')
#define DO_IF_EVEN_LOOP(Statement)\
  if((i % 2) == 0)\
    Statement;

// print "Success" using std::cout
void PrintSuccess()
{
  std::cout << "Success" << std::endl;
}

// print "Failure" using std::cout
void PrintFailure()
{
  std::cout << "Failure" << std::endl;
}

int main(int argc, char* argv[])
{
  unsigned evenVals = 0;

  LOOP_X_TIMES(5)
    DO_IF_EVEN_LOOP(++evenVals);

  if (evenVals != 3)
  {
      PrintFailure();
      return -1;
  }

  LOOP_X_TIMES(10)
    DO_IF_EVEN_LOOP(++evenVals);

  if (evenVals != 8)
  {
    PrintFailure();
    return -1;
  }

  PrintSuccess();
}
#endif