#ifdef COMPILE_TEMPLATE_FUNCTIONS

#include <stdlib.h>     /* srand, rand */

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../../Debug/DebugLog.h"

template <typename T>
Node<T>::Node()
{
  // generate int between 20 and 100
  // divide by 100 to set it between 0.2 and 1.0
  // divide by 8 to set it between 0.025 and 0.125
  float size = (float((rand() % 81) + 20) / 100.f) / 8.0f;
  scale = Vector(size, size);

  // generate int between 0 and 200
  // divide by 100 to set it between 0 and 2
  // subtract by 1 to set it beteen -1 and 1
  // multiply by (1 - size) so it fits in the window
  position = Vector(((float(rand() % 201) / 100.f) - 1.f) * (1.0f - size),
                    ((float(rand() % 201) / 100.f) - 1.f) * (1.0f - size));
}

template <typename T>
VisualizedLinkedList<T>::VisualizedLinkedList()
{
  srand(0);
  use_physics = false;
  name = "VisualizedLinkedList";
}

template <typename T>
void VisualizedLinkedList<T>::Draw()
{
  Node<T>* cur_node = head_;
  const float end_color[3] = { 1.f - color[0], 1.f - color[1], 1.f - color[2] };
  for (unsigned i = 0; cur_node; ++i)
  {
    float cur_color[3];

    if(i == 0)
      for (unsigned j = 0; j < 3; ++j)
        cur_color[j] = color[j];
    else if (i == (size_ - 1))
      for (unsigned j = 0; j < 3; ++j)
        cur_color[j] = end_color[j];
    else
    {
      float blend = float(i) / float(size_ - 1);
      for (unsigned j = 0; j < 3; ++j)
        cur_color[j] = (color[j] * (1.f - blend)) + (end_color[j] * blend);
    }

    // interior
    glColor4f(cur_color[0], cur_color[1], cur_color[2], color[3] * .5f);
    glBegin(GL_TRIANGLES);

    glVertex2f(cur_node->position.x + cur_node->scale.x, cur_node->position.y + cur_node->scale.y);
    glVertex2f(cur_node->position.x + cur_node->scale.x, cur_node->position.y - cur_node->scale.y);
    glVertex2f(cur_node->position.x - cur_node->scale.x, cur_node->position.y - cur_node->scale.y);

    glVertex2f(cur_node->position.x - cur_node->scale.x, cur_node->position.y + cur_node->scale.y);
    glVertex2f(cur_node->position.x + cur_node->scale.x, cur_node->position.y + cur_node->scale.y);
    glVertex2f(cur_node->position.x - cur_node->scale.x, cur_node->position.y - cur_node->scale.y);

    glEnd();

    // outline
    glColor4f(cur_color[0], cur_color[1], cur_color[2], color[3] * .5f);
    glBegin(GL_LINE_LOOP);

    glVertex2f(cur_node->position.x + cur_node->scale.x, cur_node->position.y + cur_node->scale.y);
    glVertex2f(cur_node->position.x + cur_node->scale.x, cur_node->position.y - cur_node->scale.y);
    glVertex2f(cur_node->position.x - cur_node->scale.x, cur_node->position.y - cur_node->scale.y);
    glVertex2f(cur_node->position.x - cur_node->scale.x, cur_node->position.y + cur_node->scale.y);

    glEnd();

    if (cur_node->next == nullptr)
      break;

    // connecting line
    glColor4f(1, 1, 1, 1);
    glBegin(GL_LINES);

    glVertex2f(cur_node->position.x + cur_node->scale.x, cur_node->position.y);
    glVertex2f(cur_node->next->position.x - cur_node->next->scale.x, cur_node->next->position.y);

    glEnd();

    cur_node = cur_node->next;
  }
}

template <typename T>
void VisualizedLinkedList<T>::PrintImGui()
{
  ImGui::ColorEdit4("Color", color);
  ImGui::Value("Size", size_);
  ImGui::Text("Head & Tail:");
  ImGui::SameLine();
  ImGui::Text((!head_ ? "Null" : (head_ == tail_ ? "Same" : "Different")));

  if (ImGui::CollapsingHeader("Functions"))
  {
    ImGui::Indent();
    static T data;
    static unsigned index;
    int temp;

    temp = index;
    if (ImGui::InputInt("Index", &temp))
      index = temp;

    if (ImGui::Button("push_front"))
      push_front(data);
    if (ImGui::Button("push_back"))
      push_back(data);
    if (ImGui::Button("insert"))
      insert(data, index);
    if (ImGui::Button("pop_front"))
      pop_front();
    if (ImGui::Button("pop_back"))
      pop_back();
    if (ImGui::Button("remove"))
      remove(index);
    if (ImGui::Button("clear"))
      clear();
    ImGui::Value("size", size());
    ImGui::Value("empty", empty());

    ImGui::Unindent();
  }
}

#endif