#pragma once

// This exercise is meant for practice with pointers,
// allocation, and template types. The interface you
// you must complete is based on the std::list interface
// in C++, see the link below:
//
// http://www.cplusplus.com/reference/list/list/
//
// If you don't understand what a linked list is, then
// I advise you review this video:
//
// https://youtu.be/_jQhALI4ujg
//
// If you wish to program it with more feedback
// than pass or fail, then I recommend you move to
// the BasicBounceEngine folder, and use the exercise
// 00_VisualizedLinkedList instead. If you run the
// BasicBounceEngine and select the 'Objects' menu in
// the upper left, you will be able to call your
// functions in real-time and visually see how the
// nodes are connecting.

template <typename T>
struct Node
{
  Node* prev = nullptr;
  T data;
  Node* next = nullptr;
};

template <typename T>
class LinkedList
{
  Node<T>* head_ = nullptr;
  Node<T>* tail_ = nullptr;
  unsigned size_ = 0;

  public:

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
#ifdef SOLUTION
  #include "Solutions/05_2_LinkedList.cpp"
#else
  #include "05_2_LinkedList.cpp"
#endif
#undef COMPILE_TEMPLATE_FUNCTIONS
