#include <cmath>    // ceil

#ifdef COMPILE_TEMPLATE_FUNCTIONS

template <typename T>
void VisualizedArrayList<T>::IncreaseCapacity_(unsigned new_size)
{
  if (array_ == nullptr)
  {
    capacity_ = (new_size == 0 ? int(std::ceil(expansion_)) : new_size);
    array_ = new T[capacity_];
  }
  else
  {
    capacity_ = (new_size == 0 ? int(std::ceil(float(capacity_) * expansion_)) : new_size);
    T* new_array = new T[capacity_];
    for (unsigned i = 0; i < size_; ++i)
      new_array[i] = array_[i];
    delete[] array_;
    array_ = new_array;
  }
}

// add to list
template <typename T>
void VisualizedArrayList<T>::push_back(T data)
{
  if (array_ == nullptr || size_ == capacity_)
    IncreaseCapacity_();

  array_[size_] = data;
  ++size_;
}

template <typename T>
void VisualizedArrayList<T>::insert(T data, unsigned index)
{
  if (index == size_)
    push_back(data);
  else
  {
    if (size_ == capacity_)
      IncreaseCapacity_();
    for (unsigned i = size_; i > index; --i)
      array_[i] = array_[i - 1];
    array_[index] = data;
    ++size_;
  }
}

template <typename T>
T VisualizedArrayList<T>::pop_back()
{
  --size_;
  return array_[size_];
}

template <typename T>
T VisualizedArrayList<T>::erase(unsigned index)
{
  T return_val = array_[index];
  for (unsigned i = index; i < (size_ - 1); ++i)
    array_[i] = array_[i + 1];
  --size_;
  return return_val;
}

template <typename T>
void VisualizedArrayList<T>::clear()
{
  size_ = 0;
}

// access
template <typename T>
T& VisualizedArrayList<T>::operator[](unsigned index)
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  return array_[index];

}

template <typename T>
T& VisualizedArrayList<T>::front()
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  return array_[0];
}

template <typename T>
T& VisualizedArrayList<T>::back()
{
  // no safeties, because a minimum amount checking is
  // expected from the user of this class
  return array_[size - 1];
}

// other
template <typename T>
unsigned VisualizedArrayList<T>::size()
{
  return size_;
}

template <typename T>
unsigned VisualizedArrayList<T>::capacity()
{
  return capacity_;
}

template <typename T>
bool VisualizedArrayList<T>::empty()
{
  return size_ == 0;
}

template <typename T>
void VisualizedArrayList<T>::resize(unsigned new_size)
{
  if (new_size > capacity_)
    IncreaseCapacity_(new_size);
  size_ = new_size;
}

#endif