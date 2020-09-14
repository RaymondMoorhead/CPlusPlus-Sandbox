#include "07_1_Vector.h"
#include <iostream> // cout, endl

// view "07_1_Vector.h" before continuing

#if 0
int main(int argc, char* argv[])
{
  Vector vec1(0, 0, 0);
  Vector vec2(1, 1, 1);

  // treat it like a primitive, since the compiler
  // now knows how to use the operators on it
  vec1 += vec1 -= vec2;

  std::cout << vec1 << " " << vec2 << std::endl;

  // calls operator()()
  vec1();

  std::cout << vec1 << std::endl;

  // these all call operator()(float x, float y = 0.0f, float z = 0.0f);
  // and for the missing inputs it uses the default we gave it
  vec1(1.0f);
  std::cout << vec1 << std::endl;

  vec1(1.0f, 1.0f);
  std::cout << vec1 << std::endl;

  vec1(1.0f, 1.0f, 1.0f);
  std::cout << vec1 << std::endl;
}
#endif