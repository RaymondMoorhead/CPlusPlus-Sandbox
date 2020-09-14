#pragma once

#include "../Math/Vector.h"

class BasicObject
{
  public:
    BasicObject();
    void Update(const float& dt);
    void PrintImGui();

    bool use_physics;
    Vector acceleration;
    Vector velocity;
    float bounciness;

    Vector position;
    Vector scale;

    const char* name;
};