#include <ostream> // ostream

struct Vector
{
  private:
    float x, y, z;
  public:

  Vector(float x, float y, float z);

  // += and -= so you can
  // vec1 += vec2
  // vec1 -= vec2
  // note: rhs is common shorthand for right-hand-side,
  //       as the object call the function is the left side
  Vector& operator+=(const Vector& rhs);
  Vector& operator-=(const Vector& rhs);

  // call the object as if it were a function
  // myVector();
  Vector& operator()();

  // this method is using default values, if a value is ignored
  // then it will use the provided default. Be careful though,
  // as a function signature may then look exactly like another
  Vector& operator()(float x, float y = 0.0f, float z = 0.0f);

  // if we set a default value for the first input, then what
  // would it call for Vector()?
  //
  // operator()()
  //
  // or
  //
  // operator()(0, 0, 0)
  //
  // neither, the compiler complains about ambiguity



  // what's the 'friend' modifier? It means that the function or class it's
  // attached to does not actually belong to this class- but has special
  // privilages which defy normal access-specifiers. In this case it's
  // also a declaration that operator<< exists.
  friend std::ostream& operator<<(std::ostream& os, const Vector& vec);



  // you can change how nearly every operator works, both unary and binary,
  // and in pretty much any way you want
  //
  // x + b; can multiply
  // ++x; can divide it by twelve
  // -x; can set it to 23
  //
  // but mostly you use them to tell the compiler how to add, increment,
  // or negate in a way that makes sense for the class. Add two vectors,
  // increment the magnitude, flip the vector's direction, etc.
  //
  // for a full list of what you can overload, as well the signature used
  // in overloading that operator, please see the following link:
  // https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
};