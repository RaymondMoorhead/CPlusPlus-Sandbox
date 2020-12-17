#include <stdlib.h> // malloc
#include "Drivers/06_ManageYourMemory.h" // MemoryAwareClass

// it should be noted that if there is an issue in your code, it will
// likely crash. When resolving errors please check what line of code
// in the driver is failing. It gives verbose output that should point
// you in the right direction.

// allocate one MemoryAwareClass
MemoryAwareClass* AllocateOneMemoryAwareClass()
{
}
// allocate multiple MemoryAwareClasses
MemoryAwareClass* AllocateMultipleMemoryAwareClasses(unsigned num_objects)
{
}

// allocate multiple bytes
void* AllocateBytes(unsigned num_bytes)
{
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