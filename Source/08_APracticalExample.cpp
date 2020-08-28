#include <iostream> // cout, endl
#include "08_2_BaseDeclarations.h"

#define INCLUDES
#include "08_1_Registration.inl"
#undef INCLUDES

Animal* CreateAnimal(AnimalType type)
{
  #define REGISTER(Name) case OT_ ## Name: result = new Name(); break;

  Animal* result;
  switch (type)
  {
    #include "08_1_Registration.inl"
    default:
      result = nullptr;
  }

  // it's best practice to undefine things when not needed
  #undef REGISTER

  return result;
}

#if 0
int main(int argc, char* argv[])
{
  Animal* animals[NumberOfAnimalTypes];
  
  for (unsigned i = 0; i < NumberOfAnimalTypes; ++i)
  {
    animals[i] = CreateAnimal(AnimalType(i)); // C++ style cast from unsigned to AnimalType

    std::cout << AnimalTypeNames[animals[i]->GetType()] << ":\n";
    std::cout << "\tFeatures: " << animals[i]->Features() << "\n";
    std::cout << "\tPersonality: " << animals[i]->Personality() << "\n";
    std::cout << "\tSpeak: " << animals[i]->Speak() << "\n\n";
  }

  // and we can do whatever else we want with them

  // and clean up
  for (unsigned i = 0; i < NumberOfAnimalTypes; ++i)
    delete animals[i];
}
#endif