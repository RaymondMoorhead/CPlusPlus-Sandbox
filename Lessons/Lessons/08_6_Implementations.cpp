#include "08_2_BaseDeclarations.h"
#include "08_3_Cat.h"
#include "08_4_Dog.h"
#include "08_5_Mouse.h"
#include "08_6_Snake.h"

// for simplicity I implemented all of these in the same file,
// but of course the best practice is to separate things as much
// as possible

// create and set ObjectsTypeNames
const char* AnimalTypeNames[]
{
  #define REGISTER(Name) #Name,
    #include "08_1_Registration.inl"
  #undef REGISTER
  // this last string is still necessary, because the
  // last value needs to have no comma after it
  "InvalidAnimalTypeNamesIndex"
};


// and implement our class methods

// ANIMAL

AnimalType Animal::GetType()
{
  return type;
}

const char* Animal::GetName()
{
  return AnimalTypeNames[type];
}

const char* Animal::Features()
{
  return "This animal has no special features";
}

const char* Animal::Personality()
{
  return "This animal has no universal personality";
}

// CAT

const char* Cat::Personality()
{
  return "Cats are very independent";
}

const char* Cat::Speak()
{
  return "Meow";
}

// DOG

const char* Dog::Speak()
{
  return "Woof";
}

// MOUSE

const char* Mouse::Features()
{
  return "Mice are especially small";
}

const char* Mouse::Speak()
{
  return "Squeak";
}

// SNAKE

const char* Snake::Speak()
{
  return "There's a snake in my boot";
}

const char* Snake::Features()
{
  return "it's a brown scaly boy";
}