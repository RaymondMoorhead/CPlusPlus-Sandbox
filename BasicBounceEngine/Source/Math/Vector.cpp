#include "Vector.h"
#include <cmath>

Vector::Vector() : x(0), y(0)
{

}

Vector::Vector(Vector& rhs) : x(rhs.x), y(rhs.y)
{

}

Vector::Vector(float x_, float y_) : x(x_), y(y_)
{

}

Vector::~Vector()
{

}

Vector& Vector::operator=(const Vector& rhs)
{
  x = rhs.x;
  y = rhs.y;
  return *this;
}

Vector& Vector::operator+=(Vector& rhs)
{
  x += rhs.x;
  y += rhs.y;
  return *this;
}

Vector& Vector::operator-=(Vector& rhs)
{
  x -= rhs.x;
  y -= rhs.y;
  return *this;
}

Vector& Vector::operator*=(float scalar)
{
  x *= scalar;
  y *= scalar;
  return *this;
}

Vector& Vector::operator*=(Vector& rhs)
{
  x *= rhs.x;
  y *= rhs.y;
  return *this;
}

Vector Vector::operator+(Vector& rhs)
{
  return Vector(x + rhs.x, y + rhs.y);
}

Vector Vector::operator-(Vector& rhs)
{
  return Vector(x - rhs.x, y - rhs.y);
}

Vector Vector::operator*(float scalar)
{
  return Vector(x * scalar, y * scalar);
}

float Vector::operator*(Vector& rhs)
{
  return (x * rhs.x) + (y * rhs.y);
}

Vector Vector::operator-()
{
  return Vector(-x, -y);
}

Vector& Vector::Rotate(float radians)
{
  float c = cos(radians);
  float s = sin(radians);

  float px = (x * c) - (y * s);
  float py = (x * c) + (y * s);
  
  x = px;
  y = py;
  return *this;
}

Vector& Vector::RotateDeg(float degrees)
{
  return Rotate(degrees * 0.01745329252f /* PI / 180 */);
}

Vector& Vector::Normalize(void)
{
  float length = Length();
  x /= length;
  y /= length;
  return *this;
}

Vector Vector::GetNormalized(void)
{
  return Vector(*this).Normalize();
}

float Vector::Length(void)
{
  return sqrt(LengthSq());
}

float Vector::LengthSq(void)
{
  return *this * *this;
}

Vector Vector::Midpoint(Vector& rhs)
{
  return (*this + rhs) * .5f;
}

bool Vector::IsZero(float epsilon)
{
  return (LengthSq() < epsilon);
}