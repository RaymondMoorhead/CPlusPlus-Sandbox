#include "Core/BasicCore.h"

#include "GLFW/glfw3.h"
#include "ImGui/imgui.h"

static void IMGUI_CALLBACK()
{
  if (ImGui::Begin("Window Name"))
  {
    ImGui::Text("Hey There Friend!");
    ImGui::End(); // every window/menu must be ended
  }
}

int main(int argc, char* argv[])
{
  BasicCore core;
  core.Initialize();
  core.graphics.imgui_callback = IMGUI_CALLBACK;

  // add objects
  BasicObject test_obj;
  core.objects.push_back(&test_obj);

  // run it
  while (core.IsRunning())
  {
    core.Update();

    // add your code in this loop, it will be
    // executed once per frame. Feel free to
    // use GLFW to get the keypresses, or add
    // custome imgui calls to IMGUI_CALLBACK
    // above main

    // such as:

    // jump
    if (glfwGetKey(core.graphics.window, GLFW_KEY_SPACE) == GLFW_PRESS)
      test_obj.velocity.y = 2.0f;

    // move left/right
    // the screen goes from (-1, -1) to (1, 1)
    // X += Y * delta_time;
    // means increment X by Y amount every second
    if (glfwGetKey(core.graphics.window, GLFW_KEY_A) == GLFW_PRESS)
      test_obj.position.x -= 1.0f * core.GetDeltaTime();
    if (glfwGetKey(core.graphics.window, GLFW_KEY_D) == GLFW_PRESS)
      test_obj.position.x += 1.0f * core.GetDeltaTime();
  }


  return 0;
}

// Some additions you may consider
//
// 1- Collision detection (not resolution). When one object is in another, show this by changing their color or printing it in imgui
// 2- When the jumping object collides with another box, delete that other box
// 3- Have the jumping object shoot out smaller boxes when left mouse is clicked
