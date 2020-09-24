#pragma once

#include "../Core/BasicObject.h"

// A linked list is a pool of nodes, each of which knows
// the address of the one before it, after it, or both. This
// means that unlike ArrayLists/std::vectors, elements are
// added individually and there is no need for complete
// re-allocation, because they don't rely upon contiguous
// memory. *Hypothetically* LinkedLists are far faster
// at adding and removing elements because they just need
// to change the pointers instead of shifting every element.

// In practice, LinkedLists are almost always slower, with the
// exception being old computers, and this is because of cache.
// When you access an element, the processor asks for that element's
// memory address in RAM, and a large chunk before and/or after it,
// because it's likely you'll want more data in that area.
// This means that structures which use contiguous memory,
// such as ArrayLists and std::vectors, have large swaths of
// their data ready with the cpu after the first access. A
// LinkedList's elements could be anywhere in memory, so the
// data must be requested from RAM much more often.

template <typename T>
struct Node
{
  Node* prev = nullptr;
  T data;
  Node* next = nullptr;

  // used for display purposes, do not acces these
  Node();
  Vector position;
  Vector scale;
};

template <typename T>
class VisualizedLinkedList : public BasicObject
{
  Node<T>* head_ = nullptr;
  Node<T>* tail_ = nullptr;
  unsigned size_ = 0;

  // these are off-limits, used in visualization
  BasicCore* core_;

  public:

    // these have also already been filled
    VisualizedLinkedList();
    void Draw() override;
    void PrintImGui() override;

    // add to list
    void push_front(T data);
    void push_back(T data);
    void insert(T data, unsigned index); // push element at that index farther back

    // remove from list
    T pop_front();
    T pop_back();
    T remove(unsigned index);
    void clear();

    // access
    T& operator[](unsigned index);
    T& front();
    T& back();

    // other
    unsigned size();
    bool empty();
};

#define COMPILE_TEMPLATE_FUNCTIONS

// leave this, it's the draw code
#include "Solutions/00_1_VisualizedLinkedListDraw.cpp"

// uncomment the code you wish to run

// your code
//#include "00_VisualizedLinkedList.cpp"

// the solution
#include "Solutions/00_VisualizedLinkedList.cpp"

#undef COMPILE_TEMPLATE_FUNCTIONS