#include "BasicObject.h"
#include "ImGui/imgui.h"

#define LEFT_BOUND -1.f
#define RIGHT_BOUND 1.f
#define DOWN_BOUND -1.f
#define UP_BOUND    1.f
#define CENTER      (LEFT_BOUND + RIGHT_BOUND) / 2.f, (DOWN_BOUND + UP_BOUND) / 2.f
#define QUARTER     (RIGHT_BOUND - LEFT_BOUND) / 4.f, (UP_BOUND - DOWN_BOUND) / 4.f
#define EIGHTH      (RIGHT_BOUND - LEFT_BOUND) / 8.f, (UP_BOUND - DOWN_BOUND) / 8.f

BasicObject::BasicObject() : acceleration(0.0f, -9.8f), velocity(), position(CENTER), scale(EIGHTH), bounciness(0.8f), name("NoName"), use_physics(true), show_velocity(false)
{
  color[0] = 1.0f;
  color[1] = 0.0f;
  color[2] = 0.0f;
  color[3] = 0.9f;
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
  ImGui::ColorEdit4("Color", color);
  ImGui::InputFloat2("Position", &position.x);
  ImGui::InputFloat2("Scale", &scale.x);
  ImGui::Checkbox("Use Physics", &use_physics);
  if (use_physics)
  {
    ImGui::Checkbox("Show Velocity", &show_velocity);
    ImGui::InputFloat2("Velocity", &velocity.x);
    ImGui::InputFloat2("Acceleration", &acceleration.x);
    ImGui::InputFloat("Bounciness", &bounciness);
  }
}