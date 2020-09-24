#ifdef COMPILE_TEMPLATE_FUNCTIONS

// add to list
template <typename T>
void VisualizedLinkedList<T>::push_front(T data)
{
  Node<T>* cur_node = new Node<T>();
  cur_node->data = data;
  cur_node->next = head_;

  if(head_)
    head_->prev = cur_node;
  else // size == 0
    tail_ = cur_node;

  head_ = cur_node;

  ++size_;
}

template <typename T>
void VisualizedLinkedList<T>::push_back(T data)
{
  Node<T>* cur_node = new Node<T>();
  cur_node->data = data;
  cur_node->prev = tail_;

  if (tail_)
    tail_->next = cur_node;
  else // size == 0
    head_ = cur_node;

  tail_ = cur_node;

  ++size_;
}

template <typename T>
void VisualizedLinkedList<T>::insert(T data, unsigned index)
{
  if (index == 0)
  {
    push_front(data);
    return;
  }
  else if (index == size_)
  {
    push_back(data);
    return;
  }

  Node<T>* cur_node = head_;
  for (unsigned i = 0; i < index; ++i)
    cur_node = cur_node->next;

  Node<T>* to_insert = new Node<T>();
  to_insert->data = data;
  to_insert->prev = cur_node->prev;
  to_insert->next = cur_node;

  to_insert->prev->next = to_insert;
  to_insert->next->prev = to_insert;

  ++size_;
}

// remove from list
template <typename T>
T VisualizedLinkedList<T>::pop_front()
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  T result = head_->data;
  Node<T>* to_delete = head_;

  if (tail_ == head_)
    tail_ = nullptr;

  head_ = head_->next;
  if (head_)
    head_->prev = nullptr;
  delete to_delete;
  --size_;

  return result;
}

template <typename T>
T VisualizedLinkedList<T>::pop_back()
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  T result = tail_->data;
  Node<T>* to_delete = tail_;

  if (head_ == tail_)
    head_ = nullptr;

  tail_ = tail_->prev;
  if (tail_)
    tail_->next = nullptr;
  delete to_delete;
  --size_;

  return result;
}

template <typename T>
T VisualizedLinkedList<T>::remove(unsigned index)
{
  if (index == 0)
    return pop_front();
  else if (index == (size_ - 1))
    return pop_back();

  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  Node<T>* cur_node = head_;
  for (unsigned i = 0; i < index; ++i)
    cur_node = cur_node->next;
  cur_node->prev->next = cur_node->next;
  cur_node->next->prev = cur_node->prev;

  T data = cur_node->data;
  --size_;

  delete cur_node;
  return data;
}

template <typename T>
void VisualizedLinkedList<T>::clear()
{
  Node<T>* cur_node = head_;
  Node<T>* next;
  head_ = nullptr;
  tail_ = nullptr;
  while (cur_node)
  {
    next = cur_node->next;
    delete cur_node;
    cur_node = next;
  }
  size_ = 0;
}

// access
template <typename T>
T& VisualizedLinkedList<T>::operator[](unsigned index)
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  Node* cur_node = head_;
  for (unsigned i = 0; i < index; ++i)
    cur_node = cur_node->next;
  return cur_node->data;

}

template <typename T>
T& VisualizedLinkedList<T>::front()
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  return head_->data;
}

template <typename T>
T& VisualizedLinkedList<T>::back()
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  return tail_->data;
}

// other
template <typename T>
unsigned VisualizedLinkedList<T>::size()
{
  return size_;
}

template <typename T>
bool VisualizedLinkedList<T>::empty()
{
  return size_ == 0;
}

#endif