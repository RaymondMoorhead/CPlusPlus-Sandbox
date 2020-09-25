#pragma once

#include "../Core/BasicObject.h"

// Java's ArrayList and C++'s std::vector are
// identical internally, and simply have
// different names and interfaces

// Both structures maintain an internal array
// to store data, with its true size being
// 'capacity_' and used size being 'size_'.
// When objects are removed, size_ is decreased.
// When objects are added to a full array_, the
// array_ is reallocated with 'capacity_ * expansion_'
// rounded up as the new cpacity_.

// The structure here uses the Java name, and the
// C++ style functions. This is mainly because
// mathematical Vectors have already been used
// in this project, and may cause confusion.

// std::vector reference:
// http://www.cplusplus.com/reference/vector/vector/

// java.util.ArrayList reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/ArrayList.html

template <typename T>
class VisualizedArrayList : public BasicObject
{
  T* array_ = nullptr;
  unsigned size_ = 0;
  unsigned capacity_ = 0;
  float expansion_ = 1.45f;

  // allocate the new array here, if size == 0 then
  // use expansion_ to determine the new capacity
  void IncreaseCapacity_(unsigned new_size = 0);

  // used for display purposes only, ignore these
  bool subdivide_ = false;
  bool show_no_capacity_ = false;

  public:

    // these have already been filled
    VisualizedArrayList();
    void Draw() override;
    void PrintImGui() override;

    // add to list
    void push_back(T data);
    void insert(T data, unsigned index); // push element at that index farther back

    // remove from list
    T pop_back();
    T erase(unsigned index);
    void clear();

    // access
    T& operator[](unsigned index);
    T& front();
    T& back();

    // other
    unsigned size();
    unsigned capacity();
    bool empty();
    void resize(unsigned new_size); // only reallocate if (new_size > capacity_), and only allocate up to new_size
};

#define COMPILE_TEMPLATE_FUNCTIONS

// leave this, it's the draw code
#include "Solutions/01_1_VisualizedArrayListDraw.cpp"

// uncomment the code you wish to run

// your code
//#include "01_VisualizedArrayList.cpp"

// my solution
#include "Solutions/01_VisualizedArrayList.cpp"

#undef COMPILE_TEMPLATE_FUNCTIONS
