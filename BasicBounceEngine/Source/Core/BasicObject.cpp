#include "BasicObject.h"
#include "ImGui/imgui.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

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

void BasicObject::Draw()
{
  // outline
  glColor4f(color[0], color[1], color[2], color[3]);
  glBegin(GL_LINE_LOOP);

  glVertex2f(position.x + scale.x, position.y + scale.y);
  glVertex2f(position.x + scale.x, position.y - scale.y);
  glVertex2f(position.x - scale.x, position.y - scale.y);
  glVertex2f(position.x - scale.x, position.y + scale.y);

  glEnd();

  // center
  glColor4f(color[0], color[1], color[2], color[3] * 0.5f);
  glBegin(GL_TRIANGLES);

  glVertex2f(position.x + scale.x, position.y + scale.y);
  glVertex2f(position.x + scale.x, position.y - scale.y);
  glVertex2f(position.x - scale.x, position.y - scale.y);

  glVertex2f(position.x - scale.x, position.y + scale.y);
  glVertex2f(position.x + scale.x, position.y + scale.y);
  glVertex2f(position.x - scale.x, position.y - scale.y);

  glEnd();

  // show_velocity's line
  if (use_physics && show_velocity)
  {
    glColor4f(1.0f - color[0], 1.0f - color[1], 1.0f - color[2], 1.0f);
    glBegin(GL_LINES);

    glVertex2f(position.x, position.y);
    glVertex2f(position.x + velocity.x, position.y + velocity.y);

    glEnd();
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

bool BasicObject::IsColliding(BasicObject& target)
{
  bool result = false;
  Vector source_corners[4];
  Vector other_maximum;
  Vector other_minimum;

  #define ASSIGN_COLLISION_VARIABLES(SOURCE, TARGET)                                      \
    source_corners[0] = Vector(SOURCE.position + SOURCE.scale);                           \
    source_corners[1] = Vector(SOURCE.position + Vector(-SOURCE.scale.x, SOURCE.scale.y));\
    source_corners[2] = Vector(SOURCE.position + Vector(SOURCE.scale.x, -SOURCE.scale.y));\
    source_corners[3] = Vector(SOURCE.position - SOURCE.scale);                           \
    other_maximum = TARGET.position + TARGET.scale;                                       \
    other_minimum = TARGET.position - TARGET.scale;

  #define RUN_TEST                                                                                      \
    for (unsigned i = 0; i < 4; ++i)                                                                    \
      result |= (source_corners[i].x <= other_maximum.x) && (source_corners[i].y <= other_maximum.y) && \
                (source_corners[i].x >= other_minimum.x) && (source_corners[i].y >= other_minimum.y);

  // check to see if any corners of the source object lie inside
  // the target object
  ASSIGN_COLLISION_VARIABLES((*this), target);
  RUN_TEST;

  // then test with the objects switched, this is necessary
  // due to the edge case of the prior target object being inside
  // the prior source object
  ASSIGN_COLLISION_VARIABLES(target, (*this));
  RUN_TEST;

  #undef ASSIGN_COLLISION_VARIABLES
  #undef RUN_TEST

  return result;
}