#include <stdlib.h> // malloc
#include <iostream> // cout

#if 0

// -------------------- THIS CLASS IS USED TO TEST YOUR CODE --------------------
// --------------------          DO NOT MODIFY IT            --------------------

class MemoryAwareClass
{
  static unsigned allocate_calls_;
  static unsigned deallocate_calls_;

public:
  static void Reset()
  {
    allocate_calls_ = 0;
    deallocate_calls_ = 0;
  }

  static unsigned AllocateCalls()
  {
    return allocate_calls_;
  }

  static unsigned DeallocateCalls()
  {
    return deallocate_calls_;
  }

  // this function performs a meaningless action within
  // the memory of a MemoryAwareClass's instance. If it
  // has not been allocated properly, the program will
  // crash
  unsigned PokeMemory()
  {
    return allocate_calls_ | deallocate_calls_;
  }

  // overload the 'new' operator
  void* operator new(size_t size)
  {
    // called on 'new MemoryAwareClass'
    ++allocate_calls_;
    return malloc(size);
  }

  // overload the 'new[]' operator
  void* operator new[](size_t size)
  {
    // called on 'new MemoryAwareClass[X]'
    allocate_calls_ += unsigned(size / size_t(sizeof(MemoryAwareClass)));
    return malloc(size);
  }

    // overload the 'delete' operator
    void operator delete(void* memory)
  {
    // called on 'delete memory'
    // but not called on 'delete[] memory'
    ++deallocate_calls_;
    free(memory);
  }

  // overload the 'delete[]' operator
  void operator delete[](void* memory)
  {
    // called on 'delete[] memory'
    ++deallocate_calls_;
    free(memory);
  }
};

unsigned MemoryAwareClass::allocate_calls_;
unsigned MemoryAwareClass::deallocate_calls_;

// -------------------- YOUR CODE BEGINS HERE --------------------

// it should be noted that if there is an issue in your code, it will
// likely crash. When resolving errors please check what line of code
// in main is failing. It gives verbose output that should point you
// in the right direction.

// allocate one MemoryAwareClass
MemoryAwareClass* AllocateOneMemoryAwareClass()
{
  return nullptr;
}
// allocate multiple MemoryAwareClasses
MemoryAwareClass* AllocateMultipleMemoryAwareClasses(unsigned num_objects)
{
  return nullptr;
}

// allocate multiple bytes
void* AllocateBytes(unsigned num_bytes)
{
  return nullptr;
}

// deallocate one MemoryAwareClass
void DeallocateOneMemoryAwareClass(MemoryAwareClass* data)
{
}

// deallocate multiple integers
void DeallocateMultipleMemoryAwareClasses(MemoryAwareClass* data)
{
}

// deallocate multiple bytes
void DeallocateBytes(void* data)
{
}

// -------------------- YOUR CODE ENDS HERE --------------------

int main(int argc, char* argv[])
{
#define CHECKPOINT(MESSAGE)\
    std::cout << "Line " << __LINE__ << " reached in main: " << MESSAGE << std::endl;

#define ERROR_CHECK(CONDITION, MESSAGE)                                                                                           \
    if(CONDITION)                                                                                                                 \
    {                                                                                                                             \
      std::cout << MESSAGE << std::endl;                                                                                          \
      std::cout << '\t' << MemoryAwareClass::AllocateCalls() << " MemoryAwareClasses were allocated" << std::endl;                \
      std::cout << '\t' << MemoryAwareClass::DeallocateCalls() << " deletions (single or []) called " << std::endl;               \
      return -1;                                                                                                                  \
    }

  MemoryAwareClass::Reset();

  MemoryAwareClass* data;

  // AllocateOneMemoryAwareClass
  CHECKPOINT("Calling AllocateOneMemoryAwareClass...");
  data = AllocateOneMemoryAwareClass();
  ERROR_CHECK(MemoryAwareClass::AllocateCalls() != 1, "AllocateOneMemoryAwareClass did not allocate a 'new' MemoryAwareClass");
  CHECKPOINT("AllocateOneMemoryAwareClass finished...");

  CHECKPOINT("testing allocated memory...");
  data->PokeMemory();
  CHECKPOINT("finished testing allocated memory...");

  // DeallocateOneMemoryAwareClass
  CHECKPOINT("Calling DeallocateOneMemoryAwareClass...");
  DeallocateOneMemoryAwareClass(data);
  ERROR_CHECK(MemoryAwareClass::DeallocateCalls() != 1, "DeallocateOneMemoryAwareClass did not deallocate a MemoryAwareClass with 'delete'");
  CHECKPOINT("DeallocateOneMemoryAwareClass finished...");

  MemoryAwareClass::Reset();

  // AllocateMultipleMemoryAwareClasses
  CHECKPOINT("Calling AllocateMultipleMemoryAwareClasses...");
  data = AllocateMultipleMemoryAwareClasses(10);
  ERROR_CHECK(MemoryAwareClass::AllocateCalls() != 10, "AllocateMultipleMemoryAwareClasses did not allocate 'new' MemoryAwareClasses");
  CHECKPOINT("AllocateMultipleMemoryAwareClasses finished...");

  CHECKPOINT("testing allocated memory...");
  for (unsigned i = 0; i < 10; ++i)
    data[i].PokeMemory();
  CHECKPOINT("finished testing allocated memory...");

  // DeallocateMultipleMemoryAwareClasses
  CHECKPOINT("Calling DeallocateMultipleMemoryAwareClasses...");
  DeallocateMultipleMemoryAwareClasses(data);
  ERROR_CHECK(MemoryAwareClass::DeallocateCalls() != 1, "DeallocateMultipleMemoryAwareClasses did not deallocate a MemoryAwareClasses with 'delete[]'");
  CHECKPOINT("DeallocateMultipleMemoryAwareClasses finished...");

  // AllocateBytes
  CHECKPOINT("Calling AllocateBytes...");
  data = (MemoryAwareClass*)AllocateBytes(sizeof(MemoryAwareClass));
  CHECKPOINT("AllocateBytes finished...");

  CHECKPOINT("testing allocated memory...");
  data->PokeMemory();
  CHECKPOINT("finished testing allocated memory...");

  // DeallocateBytes
  CHECKPOINT("Calling DeallocateBytes...");
  DeallocateBytes(data);
  CHECKPOINT("DeallocateBytes finished...");

  std::cout << "\tAll Tests Completed Successfully!" << std::endl;
}
#endif