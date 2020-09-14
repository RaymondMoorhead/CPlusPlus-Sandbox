#pragma once

#include "../Core/BasicObject.h"

#include <vector>

struct GLFWwindow;

class BasicGraphics
{
  public:
    BasicGraphics();
    void Initialize();
    bool Draw(float& dt, std::vector<BasicObject*>*);
    void Exit();

    // set this to point at whatever function
    // you have with imgui calls
    void (*imgui_callback)();

    GLFWwindow* window;
};