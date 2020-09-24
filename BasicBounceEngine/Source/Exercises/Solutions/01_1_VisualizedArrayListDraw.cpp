#ifdef COMPILE_TEMPLATE_FUNCTIONS

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <typeinfo>       // operator typeid
#include <string>         // to_string

template <typename T>
VisualizedArrayList<T>::VisualizedArrayList() : BasicObject()
{
  use_physics = false;
  name = "VisualizedArrayList";
  scale *= Vector(.1f, .1f);
  position = Vector(-1, -.5f) + Vector(scale.x, 0);
}

template <typename T>
void VisualizedArrayList<T>::Draw()
{
  if (capacity_ == 0)
  {
    glColor4f(color[0], color[1], color[2], color[3]);
    glBegin(GL_LINE_LOOP);
    glVertex2f(position.x - scale.x, position.y + scale.y);
    glVertex2f(position.x + scale.x, position.y + scale.y);
    glVertex2f(position.x + scale.x, position.y - scale.y);
    glVertex2f(position.x - scale.x, position.y - scale.y);
    glEnd();
  }
  else
    for (unsigned i = 0; i < capacity_; ++i)
    {
      float x_start;
      float x_end;

      // there are two display options here
      if (subdivide_)
      {
        // sub-divide the object area
        x_start = (position.x - scale.x) + ((float(i) / float(capacity_) * 2.0f * scale.x));
        x_end = (position.x - scale.x) + ((float(i + 1) / float(capacity_) * 2.0f * scale.x));
      }
      else
      {
        // expand continually to the right
        x_start = (position.x - scale.x) + ((float(i) * 2.0f * scale.x));
        x_end = (position.x + scale.x) + ((float(i) * 2.0f * scale.x));
      }


      if (i < size_)
      {
        glColor4f(color[0], color[1], color[2], color[3] * 0.5f);
        glBegin(GL_TRIANGLES);
        glVertex2f(x_start, position.y + scale.y);
        glVertex2f(x_end, position.y + scale.y);
        glVertex2f(x_end, position.y - scale.y);

        glVertex2f(x_start, position.y + scale.y);
        glVertex2f(x_end, position.y - scale.y);
        glVertex2f(x_start, position.y - scale.y);
        glEnd();
      }

      glColor4f(color[0], color[1], color[2], color[3]);
      glBegin(GL_LINE_LOOP);
      glVertex2f(x_start, position.y + scale.y);
      glVertex2f(x_end, position.y + scale.y);
      glVertex2f(x_end, position.y - scale.y);
      glVertex2f(x_start, position.y - scale.y);
      glEnd();
    }
}

template <typename T>
void VisualizedArrayList<T>::PrintImGui()
{
  BasicObject::PrintImGui();
  ImGui::Value("Size", size_);
  ImGui::Value("Capacity", capacity_);
  ImGui::InputFloat("Expansion", &expansion_);
  ImGui::Checkbox("Display Mode: Subdivide", &subdivide_);

  if (ImGui::CollapsingHeader("Functions"))
  {
    ImGui::Indent();
    static T data;
    static unsigned index;
    int temp;

    temp = index;
    if (ImGui::InputInt("Index/Resize", &temp))
      index = temp;

    if (ImGui::Button("push_back"))
      push_back(data);
    if (ImGui::Button("insert"))
      insert(data, index);
    if (ImGui::Button("pop_back"))
      pop_back();
    if (ImGui::Button("erase"))
      erase(index);
    if (ImGui::Button("clear"))
      clear();
    ImGui::Value("size", size());
    ImGui::Value("capacity", capacity());
    ImGui::Value("empty", empty());
    if (ImGui::Button("resize"))
      resize(index);

    ImGui::Unindent();
  }
}

#endif