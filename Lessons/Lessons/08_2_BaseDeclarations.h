// extern does not create a variable/object, but
// safety to make sure file is included only once, never duplicated
#pragma once

// fill the enum with our registration file
enum AnimalType {
#define REGISTER(Name) AT_ ## Name,
#include "08_1_Registration.inl"
#undef REGISTER
  NumberOfAnimalTypes
};

// declares that one exists that is created/set elsewhere
extern const char* AnimalTypeNames[];

// base class
class Animal {
  // knowing the type of an argument is enough for the
  // declaration, you can name it later
  friend Animal* CreateAnimal(AnimalType);

  AnimalType type;

  public:
    // these two cannot be overridden, but there's no need
    // for the inheriting types to do so.
    AnimalType GetType();
    const char* GetName();

    // when overriding a base class function in a derived class,
    // you you need to use the virtual keyword on the base function
    virtual const char* Features();

    virtual const char* Personality();

    // making a virtual function and setting it equal to zero means
    // the function has no implementation in this class. This effectively
    // makes the class an equivalent to Interfaces from Java, and this
    // function must be overridden in inheriting classes for them to
    // be instantiated.
    virtual const char* Speak() = 0;
};