#if 1

#include <iostream>
#include "04_1_LinkedList.h"

#define RETURN(Message, ReturnVal) \
  {                                 \
    std::cout << "line " << __LINE__ << ":\n\t";\
    std::cout << Message << std::endl; \
    return ReturnVal;\
  }

int main(int argc, char* argv[])
{
  LinkedList<int> list;

  for (int i = 999; i >=0; --i)
    list.push_front(i);

  if (list.size() != 1000)
    RETURN("LinkedList::size() is returning an incorrect value, likely due to LinkedList::push_front()", -1);

  int sum = 0;
  for (unsigned i = 0; i < 1000; ++i)
  {
    if (list.size() != (1000 - i))
      RETURN("LinkedList::size() is incorrect", -1);

    sum += list.pop_front();
  }

  if (!list.empty())
    RETURN("LinkedList::empty() should return true, but doesn't", -1);

  if(sum != 499500)
    RETURN("LinkedList::pop_front() returns an incorrect value", -1);

  for (int i = 0; i < 1000; ++i)
    list.push_back(i);

  if (list.size() != 1000)
    RETURN("LinkedList::size() is returning an incorrect value, likely due to LinkedList::push_back()", -1);

  for(int i = 0; i < 1000; ++i)
    if(list[i] != i)
      RETURN("LinkedList::operator[]() returns an incorrect value", -1);

  sum = 0;
  for (unsigned i = 0; i < 1000; ++i)
  {
    if (list.size() != (1000 - i))
      RETURN("LinkedList::size() is incorrect", -1);

    sum += list.pop_back();
  }

  if (!list.empty())
    RETURN("LinkedList::empty() should return true, but doesn't", -1);

  if (sum != 499500)
    RETURN("LinkedList::pop_front() returns an incorrect value", -1);

  for (int i = 999; i >= 0; --i)
    list.push_front(i);

  if(list.remove(500) != 500)
    RETURN("LinkedList::remove() returned an incorrect value when removing from the middle", -1);

  if (list.remove(998) != 999)
    RETURN("LinkedList::remove() returned an incorrect value when removing from the back", -1);
  if (list.remove(0) != 0)
    RETURN("LinkedList::remove() returned an incorrect value when removing from the front", -1);

  list.insert(0, 0);
  if(list.front() != 0)
    RETURN("LinkedList::insert() at index 0 did not correctly add the data", -1);

  list.insert(500, 500);
  if (list[500] != 500)
    RETURN("LinkedList::insert() at index 500 did not correctly add the data", -1);

  list.insert(999, 999);
  if (list[999] != 999)
    RETURN("LinkedList::insert() at index 999 did not correctly add the data", -1);

  list.clear();

  if(!list.empty())
    RETURN("LinkedList::empty() returned false after LinkedList::clear()", -1);

  std::cout << "All tests completed successfully" << std::endl;
  return 0;
}
#endif