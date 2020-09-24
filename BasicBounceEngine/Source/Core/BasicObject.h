#pragma once

#include "../Math/Vector.h"

class BasicObject
{
  public:
    BasicObject();
    void Update(const float& dt);
    virtual void Draw();
    virtual void PrintImGui();

    bool IsColliding(BasicObject& obj);

    Vector acceleration;  // Velocity change per second
    Vector velocity;      // Position change per second
    float bounciness;     // The percentage magnitude of the velocity kept after collision

    Vector position;      // Center of object
    Vector scale;         // Half height/width

    // We're not doing rotation here, it gets complicated.
    // So the four corners of the object are:
    //    upper_right = position + scale;
    //    upper_left  = position + Vector(-scale.x, scale.y);
    //    lower_right = position + Vector(scale.x, -scale.y);
    //    lower_left  = position - scale;

    float color[4];       // RGB color of the object, with Alpha (Opacity/Transparency)

    // I take the liberty when drawing the object to create a
    // border with the full color given, and then fill it in
    // with half the alpha given, which makes it possible to
    // make out overlapping objects

    // DEBUG OPTIONS
    const char* name;     // Used to track object
    bool use_physics;     // Enables/disables wall collisions and velocity application
    bool show_velocity;   // Generates a line from the center of the object, showing the velocity
};