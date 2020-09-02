#include "04_1_LinkedList.h"

// the compiler will try to compile all *.cpp files
// by default, but templates are special, and so
// they shouldn't be

// specifically, when templates are compiled, an
// entirely new class is created, with every instance
// of 'T' swapped out for whatever value a List
// instance has set for it (int, string, GameObject, etc.).
// So List must be completely recompiled every time
// the header is included, because the true value of
// 'T' won't be known until then

#ifdef COMPILE_TEMPLATE_FUNCTIONS

// add to list
template <typename T>
void LinkedList<T>::push_front(T data)
{

}

template <typename T>
void LinkedList<T>::push_back(T data)
{

}

template <typename T>
void LinkedList<T>::insert(T data, unsigned index)
{

}

// remove from list
template <typename T>
T LinkedList<T>::pop_front()
{
  return T();
}

template <typename T>
T LinkedList<T>::pop_back()
{
  return T();
}

template <typename T>
T LinkedList<T>::remove(unsigned index)
{
  return T();
}

template <typename T>
void LinkedList<T>::clear()
{
  
}

// access
template <typename T>
T& LinkedList<T>::operator[](unsigned index)
{
  T bad_data;
  return bad_data;
}

template <typename T>
T& LinkedList<T>::front()
{
  T bad_data;
  return bad_data;
}

template <typename T>
T& LinkedList<T>::back()
{
  T bad_data;
  return bad_data;
}

// other
template <typename T>
unsigned LinkedList<T>::size()
{
  return 0;
}

template <typename T>
bool LinkedList<T>::empty()
{
  return false;
}

#endif