#pragma once

// As used here, a Vector can be used as a coordinate
// (position), a range across different axis
// (scale), or a direction and magnitude, which
// can be applied to a position to move it (velocity)
// or modify another direction and magnitude (acceleration)
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
  Vector& operator*=(Vector& rhs); // vector scalar (x *= rhs.x, y *= rhs.y)

  Vector operator+(Vector& rhs);
  Vector operator-(Vector& rhs);
  Vector operator*(float scalar);

  // dot product
  float operator*(Vector& rhs);

  // negation
  Vector operator-();

  Vector& Rotate(Vector& axis, float radians);
  Vector& RotateDeg(Vector& axis, float degrees);

  Vector& Normalize(void);
  Vector GetNormalized(void);

  float Length(void);
  float LengthSq(void); // squared length

  Vector Midpoint(Vector& rhs);

  // Because of floating point rounding errors, the
  // Vector will almost never actually be 0 in
  // magnitude/length. Thus the epsilon is used to say:
  //    "eh, if it's below this it's close enough"
  bool IsZero(float epsilon = 0.0001f);
};