// extern does not create a variable/object, but
// safety to make sure file is included only once, never duplicated
#pragma once

// fill the enum with our registration file
enum AnimalType {
#define REGISTER(Name) OT_ ## Name,
#include "08_1_Registration.inl"
#undef REGISTER
  NumberOfAnimalTypes
};

// declares that one exists that is created/set elsewhere
extern const char* AnimalTypeNames[];

// base class
class Animal {
  AnimalType type;
  public:
    // knowing the type of an argument is enough for the
    // declaration, you can name it later
    Animal(AnimalType);

    AnimalType GetType();

    // when overriding a base class function in a derived class,
    // you you need to use the virtual keyword
    virtual const char* Features();

    // using the virtual keyword, you impress upon the compiler
    // that this function is meant to be overridden
    virtual const char* Personality();

    virtual const char* Speak() = 0;
};