#include "BasicObject.h"
#include "ImGui/imgui.h"

#define LEFT_BOUND -1.f
#define RIGHT_BOUND 1.f
#define DOWN_BOUND -1.f
#define UP_BOUND    1.f
#define CENTER      (LEFT_BOUND + RIGHT_BOUND) / 2.f, (DOWN_BOUND + UP_BOUND) / 2.f
#define QUARTER     (RIGHT_BOUND - LEFT_BOUND) / 4.f, (UP_BOUND - DOWN_BOUND) / 4.f

BasicObject::BasicObject() : use_physics(true), acceleration(0.0f, -9.8f), velocity(), position(CENTER), scale(QUARTER), bounciness(0.8f), name("NoName")
{
}

void BasicObject::Update(const float& dt)
{

  if (use_physics)
  {
    // calculate new velocity/position
    velocity += acceleration * dt;
    position += velocity * dt;

    // check collision with screen borders

    // X
    if ((position.x - scale.x) < LEFT_BOUND)
    {
      position.x = LEFT_BOUND + scale.x;
      velocity.x *= -bounciness;
    }
    else if ((position.x + scale.x) > RIGHT_BOUND)
    {
      position.x = RIGHT_BOUND - scale.x;
      velocity.x *= -bounciness;
    }

    // Y
    if ((position.y - scale.y) < DOWN_BOUND)
    {
      position.y = DOWN_BOUND + scale.y;
      velocity.y *= -bounciness;
    }
    else if ((position.y + scale.y) > UP_BOUND)
    {
      position.y = UP_BOUND - scale.y;
      velocity.y *= -bounciness;
    }
  }
}

void BasicObject::PrintImGui()
{
  ImGui::InputFloat2("Position", &position.x);
  ImGui::InputFloat2("Scale", &scale.x);
  ImGui::Checkbox("Use Physics", &use_physics);
  if (use_physics)
  {
    ImGui::InputFloat2("Velocity", &velocity.x);
    ImGui::InputFloat2("Acceleration", &acceleration.x);
    ImGui::InputFloat("Bounciness", &bounciness);
  }
}