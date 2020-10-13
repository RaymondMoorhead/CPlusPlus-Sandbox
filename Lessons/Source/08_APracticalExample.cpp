#include <iostream> // cout, endl
#include "08_2_BaseDeclarations.h"

// 08_1_Registration.inl has the filepaths and names of
// all objects that inherit from Animal. We can use this
// information to create a function that automatically
// knows how to allocate and initialize all classes in
// that file.

#define INCLUDES
#include "08_1_Registration.inl"
#undef INCLUDES

Animal* CreateAnimal(AnimalType type)
{
  // Macro that takes the class name provided and
  // allocates an object based on it
  #define REGISTER(Name)          \
    case AT_ ## Name:             \
      result = new Name;          \
      result->type = AT_ ## Name; \
      break;

  // resulting object
  Animal* result;

  // This switch statement will be expanded to be a long
  // series of cases for allocating different object types
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
  
  // allocate one of each object
  for (unsigned i = 0; i < NumberOfAnimalTypes; ++i)
  {
    animals[i] = CreateAnimal(AnimalType(i)); // C++ style cast from unsigned to AnimalType

    // print its details to prove that it is what we claim it is
    std::cout << animals[i]->GetName() << "\n";
    std::cout << "\tType Value:\t" << animals[i]->GetType() << "\n";
    std::cout << "\tFeatures:\t" << animals[i]->Features() << "\n";
    std::cout << "\tPersonality:\t" << animals[i]->Personality() << "\n";
    std::cout << "\tSpeak:\t\t" << animals[i]->Speak() << "\n\n";
  }

  // and we can do whatever else we want with them

  // and clean up
  for (unsigned i = 0; i < NumberOfAnimalTypes; ++i)
    delete animals[i];
}
#endif