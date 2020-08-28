#include "08_2_BaseDeclarations.h"
#include "08_3_Cat.h"
#include "08_4_Dog.h"
#include "08_5_Mouse.h"

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

Animal::Animal(AnimalType type_) : type(type_)
{

}

AnimalType Animal::GetType()
{
  return type;
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

Cat::Cat() : Animal(OT_Cat)
{

}

const char* Cat::Personality()
{
  return "Cats are very independent";
}

const char* Cat::Speak()
{
  return "Meow";
}

// DOG

Dog::Dog() : Animal(OT_Dog)
{

}

const char* Dog::Speak()
{
  return "Woof";
}

// MOUSE

Mouse::Mouse() : Animal(OT_Mouse)
{

}

const char* Mouse::Features()
{
  return "This animal is especially small";
}

const char* Mouse::Speak()
{
  return "Squeak";
}