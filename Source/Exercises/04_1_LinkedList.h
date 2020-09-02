#pragma once

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
//#include "Solutions/04_2_LinkedList.cpp"
#include "04_2_LinkedList.cpp"
#undef COMPILE_TEMPLATE_FUNCTIONS