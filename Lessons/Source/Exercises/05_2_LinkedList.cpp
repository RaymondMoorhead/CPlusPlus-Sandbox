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

// notice that '#include "05_1_LinkedList.h"' isn't
// anywhere in here, once again this is because of the
// unique compilation of templates. Since this file will
// only be compiled when the code is inserted at the
// bottom of 05_1_LinkedList.h, all the necessary
// declarations will be above it.

#ifdef COMPILE_TEMPLATE_FUNCTIONS

// add to list
template <typename T>
void LinkedList<T>::push_front(T data)
{
  // add a new node containing data to the front
  // of the list
}

template <typename T>
void LinkedList<T>::push_back(T data)
{
  // add a new node containing data to the back
  // of the list
}

template <typename T>
void LinkedList<T>::insert(T data, unsigned index)
{
  // add a new node containing data to the index
  // given, moving the existing data to the next
  // index
}

// remove from list
template <typename T>
T LinkedList<T>::pop_front()
{
  // delete the node at the front of the list
  return T();
}

template <typename T>
T LinkedList<T>::pop_back()
{
  // delete the node at the back of the list
  return T();
}

template <typename T>
T LinkedList<T>::remove(unsigned index)
{
  // delete the node at the given index of the list
  return T();
}

template <typename T>
void LinkedList<T>::clear()
{
  // all nodes
}

// access
template <typename T>
T& LinkedList<T>::operator[](unsigned index)
{
  // return the data in the node at the given index
  T bad_data;
  return bad_data;
}

template <typename T>
T& LinkedList<T>::front()
{
  // return the data in first node
  T bad_data;
  return bad_data;
}

template <typename T>
T& LinkedList<T>::back()
{
  // return the data in back node
  T bad_data;
  return bad_data;
}

// other
template <typename T>
unsigned LinkedList<T>::size()
{
  // return the number of nodes in the list
  return 0;
}

template <typename T>
bool LinkedList<T>::empty()
{
  // return true if there are no nodes, false otherwise
  return false;
}

#endif
