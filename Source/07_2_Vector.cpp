#include "07_1_Vector.h"

// 07_1_Vector.h includes ostream, and we include 07_1_Vector.h,
// so by extension we've included ostream

Vector::Vector(float x_, float y_, float z_) : x(x_), y(y_), z(z_)
{

}

// rhs is common shorthand for right-hand-side
Vector& Vector::operator+=(const Vector& rhs)
{
  x += rhs.x;
  y += rhs.y;
  z += rhs.z;

  // the 'this' variable in C++ is a pointer to struct/class instance
  return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
  x -= rhs.x;
  y -= rhs.y;
  z -= rhs.z;
  return *this;
}

Vector& Vector::operator()()
{
  x = 0;
  y = 0;
  z = 0;
  return *this;
}

// notice that we don't put the default values in a second time
// if we did it would generate a 'redefinition' error
Vector& Vector::operator()(float x_, float y_, float z_)
{
  x = x_;
  y = y_;
  z = z_;
  return *this;
}

// this function does not belong to Vector, but has access to the
// private variables because it's a 'friend' function
std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
  os << '(' << vec.x << ", " << vec.y << ", " << vec.z << ')';
  return os;
}