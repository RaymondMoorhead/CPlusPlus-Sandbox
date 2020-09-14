#pragma once

struct Vector
{
  Vector();
  Vector(Vector& rhs);
  Vector(float, float);
  ~Vector();

  float x, y;

  Vector& operator=(const Vector& rhs);

  Vector& operator+=(Vector& rhs);
  Vector& operator-=(Vector& rhs);
  Vector& operator*=(float scalar);
  Vector& operator*=(Vector& rhs); // vector scalar (x *= rhs.x, y *= rhs.y, z *= rhs.z)

  Vector operator+(Vector& rhs);
  Vector operator-(Vector& rhs);
  Vector operator*(float scalar);

  float operator*(Vector& rhs); // dot product

  Vector& Rotate(Vector& axis, float radians);
  Vector& RotateDeg(Vector& axis, float degrees);

  Vector& Normalize(void);
  Vector GetNormalized(void);

  float Length(void);
  float LengthSq(void); // squared length

  Vector Midpoint(Vector& rhs);

  bool IsZero(float epsilon = 0.0001f);
};