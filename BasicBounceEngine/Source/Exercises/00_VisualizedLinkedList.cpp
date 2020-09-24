#ifdef COMPILE_TEMPLATE_FUNCTIONS

// add to list
template <typename T>
void VisualizedLinkedList<T>::push_front(T data)
{

}

template <typename T>
void VisualizedLinkedList<T>::push_back(T data)
{

}

template <typename T>
void VisualizedLinkedList<T>::insert(T data, unsigned index)
{

}

// remove from list
template <typename T>
T VisualizedLinkedList<T>::pop_front()
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  T bad_data;
  return bad_data;
}

template <typename T>
T VisualizedLinkedList<T>::pop_back()
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  T bad_data;
  return bad_data;
}

template <typename T>
T VisualizedLinkedList<T>::remove(unsigned index)
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  T bad_data;
  return bad_data;
}

template <typename T>
void VisualizedLinkedList<T>::clear()
{

}

// access
template <typename T>
T& VisualizedLinkedList<T>::operator[](unsigned index)
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  T bad_data;
  return bad_data;

}

template <typename T>
T& VisualizedLinkedList<T>::front()
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  T bad_data;
  return bad_data;
}

template <typename T>
T& VisualizedLinkedList<T>::back()
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  T bad_data;
  return bad_data;
}

// other
template <typename T>
unsigned VisualizedLinkedList<T>::size()
{
  return 0;
}

template <typename T>
bool VisualizedLinkedList<T>::empty()
{
  return true;
}

#endif