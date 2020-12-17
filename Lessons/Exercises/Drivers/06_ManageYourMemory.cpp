#include <stdlib.h>
#include <iostream>
#include "06_ManageYourMemory.h" // MemoryAwareClass

void MemoryAwareClass::Reset()
{
  allocate_calls_ = 0;
  deallocate_calls_ = 0;
}

unsigned MemoryAwareClass::AllocateCalls()
{
  return allocate_calls_;
}

unsigned MemoryAwareClass::DeallocateCalls()
{
  return deallocate_calls_;
}

// this function performs a meaningless action within
// the memory of a MemoryAwareClass's instance. If it
// has not been allocated properly, the program will
// crash
unsigned MemoryAwareClass::PokeMemory()
{
  return allocate_calls_ | deallocate_calls_;
}

// overload the 'new' operator
void* MemoryAwareClass::operator new(size_t size)
{
  // called on 'new MemoryAwareClass'
  ++allocate_calls_;
  return malloc(size);
}

// overload the 'new[]' operator
void* MemoryAwareClass::operator new[](size_t size)
{
  // called on 'new MemoryAwareClass[X]'
  allocate_calls_ += unsigned(size / size_t(sizeof(MemoryAwareClass)));
  return malloc(size);
}

  // overload the 'delete' operator
  void MemoryAwareClass::operator delete(void* memory)
{
  // called on 'delete memory'
  // but not called on 'delete[] memory'
  ++deallocate_calls_;
  free(memory);
}

// overload the 'delete[]' operator
void MemoryAwareClass::operator delete[](void* memory)
{
  // called on 'delete[] memory'
  ++deallocate_calls_;
  free(memory);
}

unsigned MemoryAwareClass::allocate_calls_;
unsigned MemoryAwareClass::deallocate_calls_;

// allocate one MemoryAwareClass
MemoryAwareClass* AllocateOneMemoryAwareClass();

// allocate multiple MemoryAwareClasses
MemoryAwareClass* AllocateMultipleMemoryAwareClasses(unsigned num_objects);

// allocate multiple bytes
void* AllocateBytes(unsigned num_bytes);

// deallocate one MemoryAwareClass
void DeallocateOneMemoryAwareClass(MemoryAwareClass* data);

// deallocate multiple integers
void DeallocateMultipleMemoryAwareClasses(MemoryAwareClass* data);

// deallocate multiple bytes
void DeallocateBytes(void* data);


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