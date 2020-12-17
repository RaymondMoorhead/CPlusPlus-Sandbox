#pragma once

class MemoryAwareClass
{
  static unsigned allocate_calls_;
  static unsigned deallocate_calls_;

public:
  static void Reset();

  static unsigned AllocateCalls();

  static unsigned DeallocateCalls();

  // this function performs a meaningless action within
  // the memory of a MemoryAwareClass's instance. If it
  // has not been allocated properly, the program will
  // crash
  unsigned PokeMemory();

  // overload the 'new' operator
  void* operator new(size_t size);

  // overload the 'new[]' operator
  void* operator new[](size_t size);

  // overload the 'delete' operator
  void operator delete(void* memory);

  // overload the 'delete[]' operator
  void operator delete[](void* memory);
};